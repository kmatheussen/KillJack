
all: target_osx target_linux target_windows

clean:
	rm -f bin_osx/Kill\ Jack.app/Contents/MacOS/*~ bin_osx/Kill\ Jack.app/Contents/MacOS/killjack.sh bin_linux/killjack.sh bin_windows/Kill\ Jack.exe
	$(MAKE) -C windows clean

target_osx:
	mkdir -p bin_osx
	rm -f bin_osx/Kill\ Jack.app/Contents/MacOS/*~ 
	cp killjack.sh bin_osx/Kill\ Jack.app/Contents/MacOS/


target_linux:
	rm -f bin_linux/*~
	cp killjack.sh bin_linux/


target_windows:
	rm -f bin_windows/*~
	$(MAKE) -C windows
	cp windows/Kill\ Jack.exe bin_windows/
