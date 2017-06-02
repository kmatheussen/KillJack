#!/bin/sh

#https://stackoverflow.com/questions/12306223/how-to-manually-create-icns-files-using-iconutil

rm -fr KillJack.iconset
mkdir KillJack.iconset

sips -z 16 16     -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_16x16.png
sips -z 32 32     -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_16x16@2x.png
sips -z 32 32     -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_32x32.png
sips -z 64 64     -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_32x32@2x.png
sips -z 128 128   -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_128x128.png
sips -z 256 256   -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_128x128@2x.png
sips -z 256 256   -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_256x256.png
sips -z 512 512   -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_256x256@2x.png
sips -z 512 512   -s formatOptions best ../icon/KillJack.png --out KillJack.iconset/icon_512x512.png

cp ../icon/KillJack.png KillJack.iconset/icon_512x512@2x.png

iconutil -c icns KillJack.iconset

cp KillJack.icns ../KillJack.app/Contents/Resources

rm -fr ../icon/KillJack.iconset
mv KillJack.iconset ../icon/

sips -z 248 248   -s formatOptions best ../icon/KillJack.png --out ../icon/KillJack.iconset/icon_248x248.png

