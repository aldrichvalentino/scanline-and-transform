#ifndef POINT
#define POINT
#define PI 3.14159265
#include <math.h>

using namespace std;

class Point {
    public:
        Point() {
            x = 0;
            y = 0;
        }
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }

        Point(const Point& p) {
            this->x = p.x;
            this->y = p.y;
        }

        int getAxis() {
            return this->x;
        }

        int getOrdinat() {
            return this->y;
        }

        void setAxis(int x) {
            this->x = x;
        }

        void setOrdinat(int y) {
            this->y = y;
        }
        
        void rotate(int degree, int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
            double val = PI/180;
            float sinus = sin(degree*val);
            float minsin = -sinus;
            float cosinus = cos(degree*val);
            float centerX = ((topLeftX + bottomRightX) / 2);
            float centerY = ((topLeftY + bottomRightY) / 2);
            
            float tempx = getAxis() - centerX;
            float tempy = getOrdinat() - centerY;
            float finalx = (tempx * cosinus + tempy * minsin) + centerX; 
            float finaly = (tempx * sinus + tempy * cosinus) + centerY;
            //round to int
            setAxis(int(nearbyint(finalx)));
            setOrdinat(int(nearbyint(finaly)));
        }

        void scale(int scale, int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
            float centerX = ((topLeftX + bottomRightX) / 2);
            float centerY = ((topLeftY + bottomRightY) / 2);
            
            float finalx = scale * (getAxis() - centerX) + centerX;
            float finaly = scale * (getOrdinat() - centerY) + centerY;
            setAxis(int(nearbyint(finalx)));
            setOrdinat(int(nearbyint(finaly)));
        }

        void update(int divx, int divy) {
            x += divx;
            y += divy;
        }
    
    private:
        int x, y;
};

#endif