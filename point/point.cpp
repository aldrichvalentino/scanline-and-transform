#ifndef POINT
#define POINT

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
    
    private:
        int x, y;
};

#endif