
all: osx linux windows


osx:
	rm -f bin_osx/KillJack.app/Contents/MacOS/*~
	cp killjack.sh bin_osx/KillJack.app/Contents/MacOS/


linux:
	mkdir -f bin_linux
	cp killjack.sh bin_linux/


windows:
	mkdir -f bin_windows
