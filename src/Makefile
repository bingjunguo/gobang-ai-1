# Make for gobang-ai
# Time ：2017-8-30 
# Author Weifei

EXES = game.run

all: chessboard.o 
	#g++ -o game.run "-fno-stack-protector" chessboard.o
	#rm *.o

chessboard.o:chessboard.cpp
	g++ -c "-fno-stack-protector" chessboard.cpp

clean:
	rm *.o
