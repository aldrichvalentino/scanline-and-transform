#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"

using namespace std;


void bounce(Polygon p,float ratio){
	float height = 200;
	while (height * ratio > 0) {
		for (int i = 0; i < height; ++i){
			Util::clearScreen();

			p.scanLine(150, 0, 150);
			p.print(0, 0, 0, 255, 0);
			p.fall();
		}
		height *= ratio;
		for (int i = 0; i < height; ++i){
			Util::clearScreen();

			p.scanLine(150, 0, 150);
			p.print(0, 0, 0, 255, 0);
			p.up();
		}
	}
}


int main() {
    Polygon plane((char*)"objects/tire.txt");
    plane.update(300, 300);
//    for(int i = 0; i < 200; i++){
//        Util::clearScreen();

//        plane.scanLine(150, 0, 150);
  //      plane.print(0, 0, 0, 255, 0);
        //plane.scale(1.1);
    //    plane.up();
        
      //  for(int j=0; j < 50000; j++);
    //}
    
    bounce(plane,0.8);
    
    return 0;
}

