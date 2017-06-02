#!/bin/sh

#https://stackoverflow.com/questions/12306223/how-to-manually-create-icns-files-using-iconutil

rm -fr KillJack.iconset
mkdir KillJack.iconset

sips -z 16 16     ../icon/KillJack.png --out KillJack.iconset/icon_16x16.png
sips -z 32 32     ../icon/KillJack.png --out KillJack.iconset/icon_16x16@2x.png
sips -z 32 32     ../icon/KillJack.png --out KillJack.iconset/icon_32x32.png
sips -z 64 64     ../icon/KillJack.png --out KillJack.iconset/icon_32x32@2x.png
sips -z 128 128   ../icon/KillJack.png --out KillJack.iconset/icon_128x128.png
sips -z 256 256   ../icon/KillJack.png --out KillJack.iconset/icon_128x128@2x.png
sips -z 256 256   ../icon/KillJack.png --out KillJack.iconset/icon_256x256.png
sips -z 512 512   ../icon/KillJack.png --out KillJack.iconset/icon_256x256@2x.png
sips -z 512 512   ../icon/KillJack.png --out KillJack.iconset/icon_512x512.png

cp ../icon/KillJack.png KillJack.iconset/icon_512x512@2x.png

iconutil -c icns KillJack.iconset

cp KillJack.icns ../KillJack.app/Contents/Resources

