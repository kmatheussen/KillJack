
png2ico KillJack_256x256x32.ico ../icon/KillJack.iconset/icon_16x16.png ../icon/KillJack.iconset/icon_16x16@2x.png ../icon/KillJack.iconset/icon_32x32.png ../icon/KillJack.iconset/icon_32x32@2x.png ../icon/KillJack.iconset/icon_128x128.png ../icon/KillJack.iconset/icon_248x248.png


i686-w64-mingw32-windres -i resfile.rc -o windows_icon32.o

x86_64-w64-mingw32-windres -i resfile.rc -o windows_icon64.o

