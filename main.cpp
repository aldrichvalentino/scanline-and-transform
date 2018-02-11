#include <iostream>

#include "polygon/polygon.cpp"
#include "utils/util.cpp"
#include <unistd.h>

using namespace std;


int main() {
    Polygon plane ((char*)"objects/plane.txt");
    Polygon tire ((char*)"objects/tire.txt");
    Polygon tire2 ((char*)"objects/tire.txt");
    Polygon propeller ((char*)"objects/propeller.txt");
    Polygon propeller2 ((char*)"objects/propeller.txt");
    float middlePlaneX = (plane.getTopLeft().getAxis() + plane.getBottomRight().getAxis()) / 2;
    float middlePlaneY = (plane.getTopLeft().getOrdinat() + plane.getBottomRight().getOrdinat()) / 2;
    Point middlePointPlane = Point(middlePlaneX, middlePlaneY + 750);
    plane.update(250,500);
    tire.scale(0.2);
    tire2.scale(0.2);
    propeller.scale(0.65);
    propeller2.scale(0.65);
    tire.update(260,414);
    tire2.update(347,414);
    propeller.update(330, 435);
    propeller2.update(170, 435);
    printf("x = %d, y = %d", tire2.getTopLeft().getAxis(), tire2.getTopLeft().getOrdinat());
    float i = 1;
    while(i < 2) {
        cout << i << endl;
        Util::clearScreen();
        i += 0.005;
        tire.scaleByPoint(i, middlePointPlane);
        tire2.scaleByPoint(i, middlePointPlane);
        plane.scaleByPoint(i, middlePointPlane);
        propeller.scaleByPoint(i, middlePointPlane);
        propeller2.scaleByPoint(i, middlePointPlane);
        propeller.rotate(20);
        propeller2.rotate(20);
        plane.print(0, 0, 255, 255, 255);
        plane.scanLine(0, 255, 0);
        tire.print(0, 0, 0, 255, 0);
        tire.scanLine(150, 0, 150);
        tire2.print(0, 0, 0, 255, 0);
        tire2.scanLine(150, 0, 150);
        propeller.print(0, 0, 255, 255, 255);
        propeller.scanLine(0, 0, 255);
        propeller2.print(0, 0, 255, 255, 255);
        propeller2.scanLine(0, 0, 255);           
        usleep(100000);
    }

    return 0;
}

