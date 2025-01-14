#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <unistd.h>

int main() {
  Display *display;
  Window   win;
  GC       gc;
  XPoint   polygon[4];
  
  // Opens connection to X server
  display = XOpenDisplay(NULL);

  // Create a simple window
  win = XCreateSimpleWindow(display,                 // our connection to server
			    RootWindow(display, 0),  // parent window (none in this example)
			    0, 0,	             // x,y (w.r.t. parent ... ignored here)
			    170,200,	             // width, height
			    0, 		             // border width
			    0x000000,                // border color (ignored in this example)
                            0xFFFFFF);               // background color = WHITE

  // Set the name of the window
  XStoreName(display, win, "Bird House");

  // Get the graphics context
  gc = XCreateGC(display, win, 0, NULL);

  // Make it visible
  XMapWindow(display, win);
  XFlush(display);
  usleep(20000);  // sleep for 20 milliseconds.
  sleep(1);
  // Draw the main box
  polygon[0].x = 110;
  polygon[0].y = 90;
  polygon[1].x = 130;
  polygon[1].y = 70;
  polygon[2].x = 130;
  polygon[2].y = 170;
  polygon[3].x = 110;
  polygon[3].y = 190;
  XSetForeground(display, gc, 0x7F6000);
  XFillPolygon(display, win, gc, polygon, 4, Convex, CoordModeOrigin);
  XFlush(display);
  sleep(2);
  XSetForeground(display, gc, 0xFFD966); 
  XFillRectangle(display, win, gc, 10, 90, 100, 100);
  XFlush(display);

  sleep(2);  // sleep for 2 seconds.
  // Draw the roof
  XSetForeground(display, gc, 0x92D050); 
  polygon[0].x = 10;
  polygon[0].y = 90;
  polygon[1].x = 60;
  polygon[1].y = 10;
  polygon[2].x = 110;
  polygon[2].y = 90;
  XFillPolygon(display, win, gc, polygon, 3, Convex, CoordModeOrigin);
  XFlush(display);
  sleep(2);  // sleep for 2 seconds.

  XSetForeground(display, gc, 0x385723); 
  polygon[0].x = 60;
  polygon[0].y = 10;
  polygon[1].x = 130;
  polygon[1].y = 70;
  polygon[2].x = 110;
  polygon[2].y = 90;
  XFillPolygon(display, win, gc, polygon, 3, Convex, CoordModeOrigin);
  XFlush(display);
  sleep(2);  // sleep for 2 seconds.

  // Draw the hole
  XSetForeground(display, gc, 0x000000); 
  XFillArc(display, win, gc, 45, 125, 30, 30, 0, 360*64);
  XFlush(display);
  sleep(2);  // sleep for 2 seconds.

  // Draw the perch
  XSetForeground(display, gc, 0x843C0C); 
  polygon[0].x = 58;
  polygon[0].y = 174;
  polygon[1].x = 63;
  polygon[1].y = 177;
  polygon[2].x = 50;
  polygon[2].y = 187;
  polygon[3].x = 45;
  polygon[3].y = 184;
  XFillPolygon(display, win, gc, polygon, 4, Convex, CoordModeOrigin);
  XFlush(display);
  XSetForeground(display, gc, 0xC55A11); 
  XFillArc(display, win, gc, 43, 183, 7, 7, 0, 360*64);
  XFlush(display);

  // Wait until the user presses a key on the keyboard
  getchar();

  // Clean up and close the window
  XFreeGC(display, gc);
  XUnmapWindow(display, win);
  XDestroyWindow(display, win);
  XCloseDisplay(display);
}

