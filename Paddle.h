#pragma once
#include "AbstractPaddle.h"

class Paddle : public AbstractPaddle
{
private:

public:
    Paddle(int dx, int dy) : AbstractPaddle(dx, dy) {}

    void moveUp() {
        y -= 30;
        if (y <= 50)
            y = 50;
    }
    void moveDown() {
        y += 30;
        if (y >= originalY * 2 - 60)
            y = originalY * 2 - 60;
    }

    virtual void Move() override {}
};