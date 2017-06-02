
P=i686-w64-mingw32.static
PKG=$(P)\-pkg-config
CXX=$(P)-g++

all: Kill\ Jack.exe

Kill\ Jack.exe: ../KillJack.cpp windows_icon32.o Makefile
	$(CXX) -g ../KillJack.cpp `$(PKG) --cflags Qt5Gui --cflags Qt5Widgets --libs Qt5Gui` -DFOR_WINDOWS -std=gnu++11 -Wall -mwindows windows_icon32.o -o Kill\ Jack.exe

windows_icon32.o: create_icon.sh resfile.rc KillJack_256x256x32.ico ../icon/KillJack.iconset/icon_248x248.png
	./create_icon.sh

KillJack_linux: ../KillJack.cpp
	g++ -g ../KillJack.cpp `pkg-config --cflags Qt5Gui --cflags Qt5Widgets --libs Qt5Gui` -DFOR_LINUX -std=gnu++11 -Wall -o KillJack_linux

