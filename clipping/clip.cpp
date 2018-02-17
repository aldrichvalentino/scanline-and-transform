#ifndef CLIP
#define CLIP

#include <iostream>
#include "../line/line.cpp"

using namespace std;

class Clip {
    public:
        Clip() {

        };

        Clip(Line topBorder, Line bottomBorder, Line leftBorder, Line rightBorder) {
            this->topBorder.setFirstPoint(topBorder.getFirstPoint());
            this->topBorder.setSecondPoint(topBorder.getSecondPoint());
            
            this->bottomBorder.setFirstPoint(bottomBorder.getFirstPoint());
            this->bottomBorder.setSecondPoint(bottomBorder.getSecondPoint());
            
            this->leftBorder.setFirstPoint(leftBorder.getFirstPoint());
            this->leftBorder.setSecondPoint(leftBorder.getSecondPoint());
            
            this->rightBorder.setFirstPoint(rightBorder.getFirstPoint());
            this->rightBorder.setSecondPoint(rightBorder.getSecondPoint());
        }

        void drawClipBorder(int divx, int divy, int r, int g, int b) {
            topBorder.print(divx, divy, r, g, b);
            bottomBorder.print(divx, divy, r, g, b);
            leftBorder.print(divx, divy, r, g, b);
            rightBorder.print(divx, divy, r, g, b);
        }

    private:
        Line topBorder;
        Line bottomBorder;
        Line leftBorder;
        Line rightBorder;
};

#endif
