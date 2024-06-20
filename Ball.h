#pragma once
#include<iostream>

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
class Ball
{
private:
    int ball_x, ball_y;
    int originalX, originalY;
    eDir direction;
public:
    Ball(int posX, int posY)
    {
        originalX = posX;
        originalY = posY;
        ball_x = posX; ball_y = posY;
        direction = STOP;
    }
    void Reset()
    {
        ball_x = originalX; ball_y = originalY;
        direction = STOP;
    }
    void changeDirection(eDir d)
    {
        direction = d;
    }
    void randomDirection()
    {
        direction = (eDir)((rand() % 6) + 1);
    }
    int getX() {
        return ball_x;
    }
    int getY() {
        return ball_y;
    }
    eDir getDirection() {
        return direction;
    }
    void Move() {
        if (direction == 1)
            ball_x -= 10;
        else if (direction == 2) {
            ball_x -= 10;
            ball_y -= 10;
        }
        else if (direction == 3) {
            ball_x -= 10;
            ball_y += 10;
        }
        else if (direction == 4)
            ball_x += 10;
        else if (direction == 5) {
            ball_x += 10;
            ball_y -= 10;
        }
        else if (direction == 6) {
            ball_x += 10;
            ball_y += 10;
        }
    }
};