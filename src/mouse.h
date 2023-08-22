#pragma once

void set_mouse(int mouse_dv_fd, int vnc_rotate);
void cleanup_mouse();
void injectMouseEvent(struct fb_var_screeninfo *scrinfo, int buttonMask, int x, int y);
