#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"

using namespace std;


int main() {
    Polygon plane((char*)"objects/bullet.txt");
    plane.update(100, 700);
//    for(int i = 0; i < 200; i++){
//        Util::clearScreen();

//        plane.scanLine(150, 0, 150);
  //      plane.print(0, 0, 0, 255, 0);
        //plane.scale(1.1);
    //    plane.up();
        
      //  for(int j=0; j < 50000; j++);
    //}
    
    for(int i = 0; i < 1000; i++){
        plane.scanLine(150, 0, 150);
        plane.print(0,0,0,255,0);

        plane.update(30,-50);
        if(i % 2 == 0) plane.rotate(5);

        for(int j=0; j < 50000000; j++);
        Util::clearScreen();
        
    }
    
    
    return 0;
}

