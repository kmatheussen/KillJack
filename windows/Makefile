
P=x86_64-w64-mingw32.static
#i686-w64-mingw32.static
PKG=$(P)\-pkg-config
CXX=$(P)-g++

all: Kill\ Jack.exe

clean:
	rm *.o

QW = -ldwmapi -lwinspool -lQt5EventDispatcherSupport -lQt5AccessibilitySupport -lQt5FontDatabaseSupport -lQt5ThemeSupport -lcomdlg32 -loleaut32 -limm32 -lopengl32 -luuid -ladvapi32 -lshell32 -luser32 -lkernel32 -lmpr -lpcre16 -lharfbuzz -lcairo -lgobject-2.0 -lfontconfig -lusp10 -lmsimg32 -lgdi32 -lpixman-1 -lffi -lexpat -lfreetype -lbz2 -lpng16 -lz -lharfbuzz_too -lglib-2.0 -lws2_32 -lole32 -lwinmm -lshlwapi -lpcre -lintl -liconv -lwtsapi32

Kill\ Jack.exe: ../KillJack.cpp windows_icon64.o Makefile
	$(CXX) -g ../KillJack.cpp `$(PKG) --libs Qt5Core| awk '{split($$1,a,"-L"); print a[2]}'`/../plugins/platforms/libqwindows.a $(QW) `$(PKG) --cflags Qt5Gui --cflags Qt5Widgets --libs Qt5Gui --libs Qt5Widgets --libs Qt5Core --static` -lQt5WindowsUIAutomationSupport -DFOR_WINDOWS -std=gnu++11 -Wall windows_icon64.o -o Kill\ Jack.exe -mwindows #-mconsole # -mwindows 
	$(P)-strip Kill\ Jack.exe

windows_icon64.o: create_icon.sh resfile.rc KillJack_256x256x32.ico ../icon/KillJack.iconset/icon_248x248.png
	./create_icon.sh

KillJack_linux: ../KillJack.cpp
	g++ -g ../KillJack.cpp `pkg-config --cflags Qt5Gui --cflags Qt5Widgets --libs Qt5Gui` -DFOR_LINUX -std=gnu++11 -Wall -o KillJack_linux

