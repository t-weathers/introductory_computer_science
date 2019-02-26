all:main

insect.o:insect.h insect.cpp
	g++ -c insect.cpp -o insect.o

ant.o:ant.h ant.cpp
	g++ -c ant.cpp -o ant.o

bee.o:bee.h bee.cpp
	g++ -c bee.cpp -o bee.o

harvester.o:harvester.h harvester.cpp
	g++ -c harvester.cpp -o harvester.o

fire.o:fire.h fire.cpp
	g++ -c fire.cpp -o fire.o

thrower.o:thrower.h thrower.cpp
	g++ -c thrower.cpp -o thrower.o

long_thrower.o:long_thrower.h long_thrower.cpp
	g++ -c long_thrower.cpp -o long_thrower.o

short_thrower.o:short_thrower.h short_thrower.cpp
	g++ -c short_thrower.cpp -o short_thrower.o

bodyguard.o:bodyguard.h bodyguard.cpp
	g++ -c bodyguard.cpp -o bodyguard.o

wall.o:wall.h wall.cpp
	g++ -c wall.cpp -o wall.o

space.o:space.h space.cpp
	g++ -c space.cpp -o space.o

ninja.o:ninja.h ninja.cpp
	g++ -c ninja.cpp -o ninja.o

game.o:game.h game.cpp
	g++ -c game.cpp -o game.o

main: insect.o ant.o bee.o harvester.o space.o fire.o thrower.o long_thrower.o short_thrower.o bodyguard.o wall.o ninja.o game.o main.cpp
	g++ insect.o ant.o bee.o harvester.o space.o fire.o thrower.o long_thrower.o short_thrower.o bodyguard.o wall.o ninja.o game.o main.cpp -o main
clean:
	rm -f *.o
