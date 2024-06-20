#pragma once
#include"AbstractPaddle.h"

enum eDir1 { STOP1 = 0, UP = 1, DOWN = 2 };

class Computer : public AbstractPaddle {

    eDir1 direction1;
public:
    Computer(int posX, int posY) : AbstractPaddle(posX, posY), direction1(DOWN) {}

    virtual void Reset() override {
        x = originalX;
        y = originalY;
        direction1 = DOWN; // Reset to start moving down
    }

    void changeDirection(eDir1 d) {
        direction1 = d;
    }

    eDir1 getDirection() {
        return direction1;
    }

    virtual void Move() override {
        if (direction1 == UP) {
            y -= 10;
            if (y <= 50) {
                direction1 = DOWN; // Switch direction to DOWN
            }
        }
        else if (direction1 == DOWN) {
            y += 10;
            if (y >= originalY * 2 - 60) {
                direction1 = UP; // Switch direction to UP
            }
        }
    }
};