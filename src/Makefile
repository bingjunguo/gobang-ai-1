# Make for gobang-ai
# Time ：2017-8-30 
# Author Weifei


all: chessboard.o ai.o main.o
	g++ -o run "-fno-stack-protector"  chessboard.o ai.o main.o
	cp chessboard.o ../test/
	cp ai.o ../test/
	rm *.o

chessboard.o:chessboard.cpp
	g++ -c "-fno-stack-protector" chessboard.cpp
ai.o:ai.cpp
	g++ -c "-fno-stack-protector" ai.cpp
main.o:main.cpp
	g++ -c "-fno-stack-protector" main.cpp
clean:
	rm *.o
