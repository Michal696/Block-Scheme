QMAKE="qmake-qt5"

all: gui

gui:
	@cd src && $(QMAKE) && make
	mv src/blockschema .

run: all
	./blockschema

doxygen:
	doxygen

clean:
	if [ -d "doc" ]; then rm -r doc; fi
	rm -r src/*.o
	rm src/Makefile
	rm blockschema

pack:
	zip -r xuzikv00-xsajdi00.zip *

