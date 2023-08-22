#pragma once

void set_kbd(int);
void cleanup_kbd();

void injectKeyEvent(uint16_t, uint16_t);
int keysym2scancode(rfbKeySym key, rfbClientPtr cl);
