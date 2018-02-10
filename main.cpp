#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"

using namespace std;

int main() {
    Polygon plane((char*)"objects/plane.txt");
    plane.update(300, 300);
    for(int i = 0; i < 3; i++){
        Util::clearScreen();

        plane.scanLine(150, 0, 150);
        plane.print(0, 0, 0, 255, 0);
        plane.scale(2);
        
        for(int j=0; j < 500000000; j++);
    }

    return 0;
}
