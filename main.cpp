#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"

using namespace std;

int main() {
    Polygon plane((char*)"objects/plane.txt");
    plane.update(300, 300);
    for(int i = 0; i < 20; i++){
        Util::clearScreen();

        plane.scanLine(150, 0, 150);
        plane.print(0, 0, 0, 255, 0);
        plane.scale(1.1);
        plane.rotate(45);
        
        for(int j=0; j < 50000000; j++);
    }
    
    return 0;
}
