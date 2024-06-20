#pragma once
class AbstractPaddle {
protected:
    int x, y;
    int originalX, originalY;

public:
    AbstractPaddle(int dx, int dy) : originalX(dx), originalY(dy), x(dx), y(dy) {}

    virtual void Reset() {
        x = originalX;
        y = originalY;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    virtual void Move() = 0;
};