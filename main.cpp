#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"
#include <unistd.h>

using namespace std;

// Global Clip border
Line mtop(100,100,500,100);
Line mright(500,100,500,500);
Line mbottom(500,500,100,500);
Line mleft(100,500,100,100);
Clip clip(mtop, mright, mbottom, mleft);

int main() {
    Polygon plane ((char*)"objects/plane.txt");
    Polygon tire ((char*)"objects/tire.txt");
    Polygon tire2 ((char*)"objects/tire.txt");
    Polygon propeller ((char*)"objects/propeller.txt");
    Polygon propeller2 ((char*)"objects/propeller.txt");
    Polygon bullet((char*)"objects/bullet.txt");
    Polygon parachute((char*)"objects/parachuteperson.txt");
    int dx = 500;
    int dy = 150;
    parachute.update(dx, dy);

    float middlePlaneX = (plane.getTopLeft().getAxis() + plane.getBottomRight().getAxis()) / 2;
    float middlePlaneY = (plane.getTopLeft().getOrdinat() + plane.getBottomRight().getOrdinat()) / 2;
    Point middlePointPlane = Point(middlePlaneX, middlePlaneY + 400);

    plane.update(300,400);
    bullet.update(100, 1000);
    tire.scale(0.2);
    tire2.scale(0.2);
    propeller.scale(0.65);
    propeller2.scale(0.65);
    tire.update(310,314);
    tire2.update(397,314);
    propeller.update(380, 335);
    propeller2.update(220, 335);
    float i = 1;
    int j = 0;
    int u = 0;

    Point p1(100, 900);
    Point p2(1500, 900);
    Line surface(p1,p2);
    bool hit =  false;
    while(i < 1.12) {
        Util::clearScreen();
        clip.drawClipBorder(0,0,255,255,255);
        surface.print(0,0,255,255,255);
        i += 0.005;
        tire.scaleByPoint(i, middlePointPlane);
        plane.scaleByPoint(i, middlePointPlane);
        propeller.scaleByPoint(i, middlePointPlane);
        propeller2.scaleByPoint(i, middlePointPlane);
        propeller.rotate(20);
        propeller2.rotate(20);
        plane.print(0, 0, 0, 191, 255,clip);
        plane.scanLine(0, 191, 255, clip);
        tire.print(0, 0, 70, 70, 70,clip);
        tire.scanLine(130, 130, 130, clip);
        propeller.print(0, 0, 0, 128, 0, clip);
        propeller.scanLine(0, 128, 0, clip);
        propeller2.print(0, 0, 0, 128, 0, clip);
        propeller2.scanLine(0, 128, 0, clip);
        if(!plane.isHitBy(bullet)) {
            if (!hit){
                
                bullet.print(0,0,255,0,0, clip);
                bullet.scanLine(255, 0, 0, clip);
                bullet.update(30,-58);
                bullet.rotate(2.5);
            }
                tire2.scaleByPoint(i, middlePointPlane);
                tire2.print(0, 0, 70, 70, 70, clip);
                tire2.scanLine(130, 130, 130, clip);  
                usleep(100000);
        } else {
                hit = true;
                parachute.scanLine(255,108,180, clip);
                parachute.print(0,0,255,255,255, clip);
                tire2.scanLine(130, 130, 130, clip);  
                tire2.print(0, 0, 70, 70, 70, clip);
                
                j++; u++;
                if (u<=20) {
                    parachute.update(-7, -3);
                    tire2.update(3,5.5);
                    usleep(100000);
                } else {
                    parachute.update(0,2);
                    tire2.update(3,5.5);
                    usleep(100000);
                }
            } 
    }

    int height = 400;

    // if(plane.isHitBy(bullet)) {
    //     hit = true;
    // }

    if(hit) {
        while (j<=height) {
            Util::clearScreen();
            clip.drawClipBorder(0,0,255,255,255);

            surface.print(0,0,255,255,255);
            parachute.scanLine(255,108,180, clip);
            parachute.print(0,0,255,255,255, clip);
            tire2.scanLine(130, 130, 130, clip); 
            tire2.print(0, 0, 70, 70, 70, clip);
            
            if(j < 70) {
                tire2.update(2,5);
            } else if (j >= 70 && j < 85) {
                tire2.update(2,-7);
            }
            else if (j >= 85 && j < 100) {
                tire2.update(1, 7);
            }
            else if (j >= 100 && j < 115) {
                tire2.update(1, -5);
            }
            else if (j >= 115 && j < 130) {
                tire2.update(1, 5);
            }
            else if (j >= 130 && j < 145) {
                tire2.update(1, -3);
            }
            else if (j >= 145 && j < 160) {
                tire2.update(1, 3);
            }
            else if (j >= 160 && j < 175) {
                tire2.update(1, -1);
            }
            else if (j >= 175 && j < 190) {
                tire2.update(1, 1);
            }
            
            if (u<=20) {
                parachute.update(-7, -3);
                usleep(100000);
            }
            else {
                parachute.update(0,2);
                usleep(100000);
            }
            j++; u++;
        }
    }

    return 0;
}

