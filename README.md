# esa-vnc-server

ESA VNC server for Linux framebuffer devices.

The goal is to access remote embedded Linux systems without X.
Implemented features: remote display, touchscreen, keyboard, rotation
Not implemented: file transfer, ..

Working configurations:

without rotation:
- [x]  1 bit/pixel
- [x]  8 bit/pixel
- [x]  16 bit/pixel
- [x]  24 bit/pixel
- [x]  32 bit/pixel

with rotation:
- [ ]  1 bit/pixel
- [ ]  8 bit/pixel
- [x]  16 bit/pixel
- [ ]  24 bit/pixel
- [ ]  32 bit/pixel

The code is based on a LibVNC example for Android:
https://github.com/LibVNC/libvncserver/blob/master/examples/androidvncserver.c

And on the original repository:
https://github.com/ponty/framebuffer-vncserver

### build

Dependency (for linux desktop):

	sudo apt-get install libvncserver-dev

### NOTE: Before building LibVNCServer or esa-vnc-server make sure to source the right environment for the target device!
### ----- Example for ktn: source /opt/kontron/stm32mp/environment-setup-cortexa7t2hf-neon-vfpv4-ktn-linux-gnueabi

For a device diffrent then linux desktop libvncserver must be compile from source for that device.

LibVNCServer source is available at: https://github.com/LibVNC/libvncserver

There are 2 options: CMake or qmake

Using cmake:

	mkdir -p build && cd build
	cmake ..
	make
	
Using qmake:

	mkdir -p buildqt && cd buildqt
	qmake ../esa-vnc-server.pro
	make

You can also open the .pro with QtCreator and compile with the desired kit. 

### command-line help 

	./esa-vnc-server [-f device] [-p port] [-t touchscreen] [-k keyboard] [-r rotation] [-R touchscreen rotation] [-F FPS] [-v] [-c +W+H] [-h]
	-p port: VNC port, default is 5900
	-f device: framebuffer device node, default is /dev/fb0
	-t device: touchscreen device node (example:/dev/input/event2)
	-c degrees: width height clipping, it is +W+H or -W-H or -W+H or +W-H where W and H are numbers
	-r degrees: framebuffer rotation, default is 0
	-R degrees: touchscreen rotation, default is same as framebuffer rotation
	-F FPS: Maximum target FPS, default is 10
	-v: verbose
	-s: silent mode - info and errors are not printed; tty mode is set to KD_GRAPHICS
	-b: the process is executed in background
	-h: print this help
