all:begin

begin:      main.o gtucontainer.o gtuset.o gtuiterator.o  gtuiteratorconst.o gtuvector.o
	g++ main.o gtucontainer.o gtuset.o gtuiterator.o  gtuiteratorconst.o gtuvector.o -o exe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

gtucontainer.o: gtucontainer.cpp
				g++ -std=c++11 -c gtucontainer.cpp

gtuset.o: gtuset.cpp
				g++ -std=c++11 -c gtuset.cpp

gtuiterator.o:gtuiterator.cpp
				g++ -std=c++11 -c gtuiterator.cpp
gtuiteratorconst.o:gtuiteratorconst.cpp
				g++ -std=c++11 -c gtuiteratorconst.cpp
gtuvector.o: gtuvector.cpp
				g++ -std=c++11 -c gtuvector.cpp

clean:
	rm*.o exe
