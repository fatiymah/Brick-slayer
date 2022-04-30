# Brick-slayer
For the interaction with your game you will be using arrow keys on your keyboard . Each key on your keyboard have associated ASCII code. You will be making using 
of these ASCII codes to check which key is pressed and will take appropriate action corresponding the 
pushed key. E.g. to move the board right you will check for the pressed key if the pressed key is left 
arrow you will move the board left (change its position). Keyboard keys are divided in two main groups: 
printable characters (such as a, b, tab, etc.) and non-printable ones (such as arrow keys, ctrl, etc.). 
Graphics library will call your corresponding registered functions whenever any printable and nonprintable key from your keyboard is pressed. In the  code we have registered two different 
functions to graphics library. These two functions are called whenever either a printable or 
non-printable ASCII key is pressed .
Finally, once you have done the drawing and animation of objects on your canvas. Your final goal will be 
to detect collisions (collision test) between objects and take necessary actions, e.g. to check whether 
ball and a brick are colliding or not, if yes than render the brick invisible. Collision detection can be 
simple as well as complex. In this game, you will be first implementing a very simple procedure for 
finding collision between two objects. Once done, you can improve your collision detection algorithm to 
make your game more realistic as in video. The simplest way to find collision between a sphere (ball) 
and a rectangle (board or bricks) consists of two steps. In the first step we find the enclosing square of 
the ball – How ?. Now once we have found the bounding square of the ball, the problem of collision 
detection between ball and board (or bricks) can be treated as finding collision between two rectangles.





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
