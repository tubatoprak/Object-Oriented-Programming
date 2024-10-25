all:begin

begin:      main.o creature.o balrog.o cyberdemon.o  demon.o elf.o human.o
	g++ main.o creature.o balrog.o cyberdemon.o  demon.o elf.o human.o -o exe

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

creature.o: creature.cpp
				g++ -std=c++11 -c creature.cpp

balrog.o: balrog.cpp
				g++ -std=c++11 -c balrog.cpp

cyberdemon.o:cyberdemon.cpp
				g++ -std=c++11 -c cyberdemon.cpp
demon.o:demon.cpp
				g++ -std=c++11 -c demon.cpp
elf.o: elf.cpp
				g++ -std=c++11 -c elf.cpp
human.o: human.cpp
				g++ -std=c++11 -c human.cpp

clean:
	rm*.o exe