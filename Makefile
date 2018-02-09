default:
	@g++ -o main.exe main.cpp point/point.cpp line/line.cpp polygon/polygon.cpp --std=c++11
run:
	@./main.exe