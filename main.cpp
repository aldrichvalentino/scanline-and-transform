#include <iostream>

#include "polygon/polygon.cpp"

using namespace std;

int main() {
    Polygon polygon((char*)"objects/square.txt");
    polygon.print();

    return 0;
}