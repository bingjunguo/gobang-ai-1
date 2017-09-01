# Make for gobang-ai
# Time ：2017-8-30 
# Author Weifei

EXES = game.run

all: chessboard.o ai.o
	cp chessboard.o ../test/
	cp ai.o ../test/
	#rm *.o

chessboard.o:chessboard.cpp
	g++ -c "-fno-stack-protector" chessboard.cpp
ai.o:ai.cpp
	g++ -c "-fno-stack-protector" ai.cpp
clean:
	rm *.o
