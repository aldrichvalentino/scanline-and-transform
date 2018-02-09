#ifndef LINE
#define LINE

#include "../point/point.cpp"

using namespace std;

class Line {
    public:
        Line() {

        }
        
        Line(Point p1, Point p2) {
            this->p1.setAxis(p1.getAxis());
            this->p1.setOrdinat(p1.getOrdinat());
            this->p2.setAxis(p2.getAxis());
            this->p2.setOrdinat(p2.getOrdinat());
        }

        Point getFirstPoint() {
            return p1;
        }

        Point getSecondPoint() {
            return p2;
        }

        Point setFirstPoint(Point p1) {
            this->p1 = p1;
        }

        Point setSecondPoint(Point p2) {
            this->p2 = p2;
        }

    private:
        Point p1, p2;
};

#endif