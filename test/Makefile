# Make for gobang-ai
# Time ：2017-8-30 
# Author Weifei

EXES = game.run

all: main.o ai.o chessboard.o
	g++ -o EXES "-fno-stack-protector" main.o ai.o chessboard.o
	#rm *.o

main.o:main.cpp
	g++ -c "-fno-stack-protector" main.cpp
clean:
	rm *.o