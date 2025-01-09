sys_exit equ 1
sys_read equ 3
sys_write equ 4
stdin equ 0
stdout equ 1

section .bss
   num1 resb 2
   num2 resb 2
   res resb 1

section	.data
   msg1 db 'Enter a digit '       ;string to be printed
   len1 equ $ - msg1             ;length of the string
   msg2 db 'Enter a 2nd digit '   ;string to be printed
   len2 equ $ - msg2             ;length of the string
   msg3 db 'Sum: '               ;string to be printed
   len3 equ $ - msg3             ;length of the string

section	.text
   global _start            ;must be declared for linker (ld)
	
_start:	                   ;tells linker entry point  
      
   mov   ecx, msg1         ;message to write
   mov   edx, len1         ;message length
   mov	eax, 4             ;system call number (sys_write)
   mov	ebx, stdout    
   int	0x80               ;call kernel

   mov   eax, sys_read
   mov   ebx, stdin
   mov   ecx, num1
   mov   edx, 2
   int	0x80               ;call kernel

   mov	eax, sys_write     ;message length
   mov	ebx, stdout        ;message to write
   mov   ecx, msg2
   mov   edx, len2
   mov	eax,4              ;system call number (sys_write)
   int	0x80               ;call kernel

   mov   eax, sys_read
   mov   ebx, stdin
   mov   ecx, num2
   mov   edx, 2            
   int	0x80               ;call kernel
   
   mov	eax, sys_write     ;message length
   mov	ebx, stdout        ;message to write
   mov   ecx, msg3
   mov   edx, len3
   mov	eax,4              ;system call number (sys_write)
   int	0x80               ;call kernel

   mov   eax, [num1]
   mov   ebx, [num2]
   sub   eax, '0'
   sub   ebx, '0'

   add   eax, ebx
   add   eax, '0'
   mov   [res], eax

   mov	eax, sys_write     ;message length
   mov	ebx, stdout        ;message to write
   mov   ecx, res
   mov   edx, 1
   int	0x80               ;call kernel

	
   mov	eax,1              ;system call number (sys_exit)
   int	0x80               ;call kernel

