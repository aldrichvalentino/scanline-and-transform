#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"

using namespace std;


int main() {
    Polygon bullet((char*)"objects/bullet.txt");
    bullet.update(100, 1000);
//    for(int i = 0; i < 200; i++){
//        Util::clearScreen();

//        bullet.scanLine(150, 0, 150);
  //      bullet.print(0, 0, 0, 255, 0);
        //bullet.scale(1.1);
    //    bullet.up();
        
      //  for(int j=0; j < 50000; j++);
    //}
    
    for(int i = 0; i < 1000; i++){
        //bullet.scanLine(150, 0, 150);
        bullet.print(0,0,0,255,0);

        bullet.update(30,-50);
        if(i % 2 == 0) bullet.rotate(5);

        for(int j=0; j < 50000000; j++);
        Util::clearScreen();
        
    }
    
    
    return 0;
}

