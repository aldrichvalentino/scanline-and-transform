CC=g++
CFLAGS=--std=c++11
default:
	@$(CC) -o main.exe main.cpp point/point.cpp line/line.cpp polygon/polygon.cpp utils/util.cpp $(CFLAGS)
run:
	@./main.exe