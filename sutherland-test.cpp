/* code reference: https://www.thecrazyprogrammer.com/2017/02/cohen-sutherland-line-clipping-algorithm.html */

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#include "line/line.cpp"
#include "utils/util.cpp"
#include "polygon/polygon.cpp"

using namespace std;
  
int main()
{
    Line l1(100,100,500,100);
    Line l2(500,100,500,500);
    Line l3(500,500,100,500);
    Line l4(100,500,100,100);
    Clip cl(l1, l2, l3, l4);
    
//     int v, gm;
//     Point p1, p2;
//     int x, y;
//     //PT p1,p2,p3,p4,ptemp;
    
//     cout<<"\nEnter x1 and y1\n";
//     cin>> x >> y;
//     p1.setAxis(x); p1.setOrdinat(y);
//     cout<<"\nEnter x2 and y2\n";
//     cin>> x >> y;
//     p2.setAxis(x); p2.setOrdinat(y);
//     Line line(p1, p2);
    
    
//     Util::clearScreen();
//     cl.drawClipBorder(0,0,255,255,255);
//     usleep(500000);
    
//     line.print(0,0,255,255,255);
//     usleep(500000);
//     Util::clearScreen();
    
//     usleep(500000);
//     cl.setCodeForPoint(p1);
//     cl.setCodeForPoint(p2);
//     line.setFirstPoint(p1);
//     line.setSecondPoint(p2);
//     v= cl.isVisible(p1, p2);
//     cout << v << endl;
//     usleep(500000);
    
//     switch(v)
//     {
//     case 0: cl.drawClipBorder(0, 0, 255,255,255);
//             usleep(500000);
//             line.print(0,0,255,255,255);
//             break;
//     case 1: cl.drawClipBorder(0, 0, 255,255,255);
//             usleep(500000);
//             break;
//     case 2: cl.resetEndPoint(p1, p2);
//             cl.resetEndPoint(p2, p1);
//             line.setFirstPoint(p1);
//             line.setSecondPoint(p2);
//             cl.drawClipBorder(0,0,255,255,255);
//             usleep(500000);
//             line.print(0,0,255,255,255);
//             break;
//     }
    
//     usleep(500000);
    Polygon square((char*)"objects/plane.txt");
    //Polygon square1((char*)"objects/tire.txt");
    

    for(int i = 0; i < 100; i++){
        Util::clearScreen();
        //cout << i << endl;
        square.print(0,0,255,255,255,cl);
        square.scanLine(255,25,25,cl);
        
        //square1.print(0,0,255,255,255,cl);
        //square1.scanLine(255,25,25,cl);
        
        cl.drawClipBorder(0,0,255,255,255);
        square.update(5,5);
        //square1.update(5,5);
        
        usleep(50000);
    }

    return 0;
}
