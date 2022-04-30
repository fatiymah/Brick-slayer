# Brick-slayer
its done on Linux (Ubuntu)
(1.1) Installing libraries on Linux (Ubuntu)
You can install libraries either from the Ubuntu software center or from command line. We recommend 
command line and provide the file “install-libraries.sh” to automate the complete installation 
procedure. To install libraries: 
1. Simply run the terminal and go to directory which contains the file downloaded file “installlibraries.sh”. 
2. Run the command
bash install-libraries.sh 
3. Provide the password and wait for the libraries to be installed. If you get an error that libglew1.6-dev 
cannot be found, try installing an older version, such as libglew1.5-dev by issuing following on command 
line 
sudo apt-get install libglew1.5-dev 
4. If you have any other flavour of Linux. You can follow similar procedure to install “OpenGL” libraries.
1.2. Compiling and Executing 
To compile the game (skeleton) each time you will be using “g++”. However to automate the 
compilation and linking process we use a program “make”. Make takes as an input a file containing the 
names of files to compile and libraries to link. This file is named as “Makefile” in the game folder and 
contains the detail of all the libraries that game uses and need to linked.

/////////////////////////
MAKEFILE:

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -Werror

OBJS =		game.o

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage



TARGET =	game


$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

////////////////////////
