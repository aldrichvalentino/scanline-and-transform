#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"
#include <unistd.h>

using namespace std;


int main() {
    Polygon parachute((char*)"objects/parachuteperson.txt");
    int dx = 200;
    int dy = 200;
    parachute.update(dx, dy);
//    for(int i = 0; i < 200; i++){
//        Util::clearScreen();

//        plane.scanLine(150, 0, 150);
  //      plane.print(0, 0, 0, 255, 0);
        //plane.scale(1.1);
    //    plane.up();
        
      //  for(int j=0; j < 50000; j++);
    //}
    int height = 300;
    int i = 0;
    int u = 0;

    while (i<=height) {
    	Util::clearScreen();
    	parachute.scanLine(255,255,255);
    	parachute.print(0,0,0,255,0);
    	if (u<=35) {
    		parachute.update(-3, -3);
    		usleep(100000);
    	} else if (u>35 && u<=55){
    		parachute.update(-2, -1);
    		usleep(100000);
    	}
    	else {
    		parachute.fall();
    		usleep(1000);
    	}
    	
    	i++; u++;
    }
    
    return 0;
}

