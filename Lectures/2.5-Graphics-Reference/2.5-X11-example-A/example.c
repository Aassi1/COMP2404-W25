#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h> 

using namespace std;

int main() {
  Display *display;
  Window   win;
  GC       gc;
  
  // Opens connection to X server
  display = XOpenDisplay(NULL);

  // Create a simple window
  win = XCreateSimpleWindow(display,    // our connection to server
			    RootWindow(display, 0),       // parent window (none in this example)
			    0, 0,	                        // x,y (w.r.t. parent ... ignored here)
			    170,200,	                    // width, height
			    0, 		                        // border width
			    0x000000,                     // border color (ignored in this example)
                            0xFFFFFF);  // background color = WHITE

  // Set the name of the window
  XStoreName(display, win, "Rectangle Example");

  // Get the graphics context
  gc = XCreateGC(display, win, 0, NULL);

  // Make it visible
  XMapWindow(display, win);
  XFlush(display);
  usleep(20000);  // sleep for 20 milliseconds.
  sleep(1);



  cout<<"Drawing rectangle"<<endl;
  XSetForeground(display, gc, 0xFFD966); 
  XFillRectangle(display, win, gc, 10, 90, 100, 100);
  XFlush(display);

  sleep(2);  // sleep for 2 seconds.
  // Draw the roof

  XSetForeground(display, gc, 0x000000); 
  XFillRectangle(display, win, gc, 0,0,170,200);  

  
  cout<<"Drawing rectangle"<<endl;
  XSetForeground(display, gc, 0xFFD966); 
  XFillRectangle(display, win, gc, 10, 90, 100, 100);

  XSetForeground(display, gc, 0xFFFFFF); 
  XSetBackground(display, gc, 0x000000);
  XDrawString(display, win, gc, 20, 100, "Bird House", 10);
  XDrawString(display, win, gc, 20, 110, "Some other string", strlen("Some other string"));
  XDrawImageString(display, win, gc, 20, 120, "Another string", strlen("Another string"));
  XFlush(display);

  // Wait until the user presses a key on the keyboard
  getchar();

  // Clean up and close the window
  XFreeGC(display, gc);
  XUnmapWindow(display, win);
  XDestroyWindow(display, win);
  XCloseDisplay(display);
}

