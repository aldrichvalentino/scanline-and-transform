#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"

using namespace std;


int main() {
    Polygon plane((char*)"objects/plane.txt");
    plane.update(300, 300);
//    for(int i = 0; i < 200; i++){
//        Util::clearScreen();

//        plane.scanLine(150, 0, 150);
  //      plane.print(0, 0, 0, 255, 0);
        //plane.scale(1.1);
    //    plane.up();
        
      //  for(int j=0; j < 50000; j++);
    //}
    
    plane.bounce(0.8);
    
    return 0;
}

