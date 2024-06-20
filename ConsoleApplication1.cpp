#include<iostream>
#include <windows.h> 
#include<fstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<mmsystem.h>
using namespace std;


//class AbstractPaddle {
//protected:
//    int x, y;
//    int originalX, originalY;
//
//public:
//    AbstractPaddle (int dx, int dy) : originalX(dx), originalY(dy), x(dx), y(dy) {}
//
//    virtual void Reset() {
//        x = originalX;
//        y = originalY;
//    }
//
//    int getX() const {
//        return x;
//    }
//
//    int getY() const {
//        return y;
//    }
//
//    virtual void Move() = 0; 
//};
//
//class Paddle: public AbstractPaddle
//{
//private:
//  
//public:
//    Paddle(int dx, int dy) : AbstractPaddle(dx, dy) {}
//
//    void moveUp() {
//        y -= 30;
//        if (y <= 50)
//            y = 50;
//    }
//    void moveDown() {
//        y += 30;
//        if (y >= originalY * 2 - 60)
//            y = originalY * 2 - 60;
//    }
//
//    virtual void Move() override{}
//};
//
//enum eDir1 { STOP1 = 0, UP = 1, DOWN = 2 };
//
//class Computer : public AbstractPaddle {
// 
//    eDir1 direction1;
//public:
//    Computer(int posX, int posY) : AbstractPaddle(posX, posY), direction1(DOWN) {}
//
//   virtual void Reset() override {
//        x = originalX;
//        y = originalY;
//        direction1 = DOWN; // Reset to start moving down
//    }
//
//    void changeDirection(eDir1 d) {
//        direction1 = d;
//    }
//
//    eDir1 getDirection() {
//        return direction1;
//    }
//
//    virtual void Move() override {
//        if (direction1 == UP) {
//            y -= 10;
//            if (y <= 50) {
//                direction1 = DOWN; // Switch direction to DOWN
//            }
//        }
//        else if (direction1 == DOWN) {
//            y += 10;
//            if (y >= originalY * 2 - 60) {
//                direction1 = UP; // Switch direction to UP
//            }
//        }
//    }
//};
//
//
//enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };
//class Ball
//{
//private:
//    int ball_x, ball_y;
//    int originalX, originalY;
//    eDir direction;
//public:
//    Ball(int posX, int posY)
//    {
//        originalX = posX;
//        originalY = posY;
//        ball_x = posX; ball_y = posY;
//        direction = STOP;
//    }
//    void Reset()
//    {
//        ball_x = originalX; ball_y = originalY;
//        direction = STOP;
//    }
//    void changeDirection(eDir d)
//    {
//        direction = d;
//    }
//    void randomDirection()
//    {
//        direction = (eDir)((rand() % 6) + 1);
//    }
//    int getX() {
//        return ball_x;
//    }
//    int getY() {
//        return ball_y;
//    }
//    eDir getDirection() {
//        return direction;
//    }
//    void Move() {
//        if (direction == 1)
//            ball_x -= 10;
//        else if (direction == 2) {
//            ball_x -= 10;
//            ball_y -= 10;
//        }
//        else if (direction == 3) {
//            ball_x -= 10;
//            ball_y += 10;
//        }
//        else if (direction == 4)
//            ball_x += 10;
//        else if (direction == 5) {
//            ball_x += 10;
//            ball_y -= 10;
//        }
//        else if (direction == 6) {
//            ball_x += 10;
//            ball_y += 10;
//        }
//    }
//};
//
//
//
//class Pong
//{
//private:
//    int width, height;
//    int score1, score2;
//    char s1[2], s2[2];
//    bool win;
//    char up1, down1, up2, down2;
//    bool quit = true;
//    bool computer = true;
//    bool flag = true;
//    Ball* ball;
//    Paddle* player1;
//    Paddle* player2;
//    Paddle* player;
//    Computer* computer1;
//public:
//    void GetWindowDimensions(int& width, int& height) {
//        HWND consoleHandle = GetConsoleWindow();
//        RECT rc;
//        GetClientRect(consoleHandle, &rc);
//        width = rc.right;
//        height = rc.bottom;
//    }
//    void myRect(int x1, int y1, int x2, int y2, COLORREF lineColor, COLORREF fillColor) {
//        HWND console_handle = GetConsoleWindow();
//        HDC device_context = GetDC(console_handle);
//
//        //change the color by changing the values in RGB (from 0-255)
//        HPEN pen = CreatePen(PS_SOLID, 2, lineColor);
//        SelectObject(device_context, pen);
//        HBRUSH brush = ::CreateSolidBrush(fillColor);
//        SelectObject(device_context, brush);
//
//        Rectangle(device_context, x1, y1, x2, y2);
//        DeleteObject(pen);
//        DeleteObject(brush);
//        ReleaseDC(console_handle, device_context);
//    }
//    void myEllipse(int x1, int y1, int x2, int y2, COLORREF lineColor, COLORREF fillColor) {
//        HWND console_handle = GetConsoleWindow();
//        HDC device_context = GetDC(console_handle);
//
//        //change the color by changing the values in RGB (from 0-255)
//        HPEN pen = CreatePen(PS_SOLID, 2, lineColor);
//        SelectObject(device_context, pen);
//        HBRUSH brush = ::CreateSolidBrush(fillColor);
//        SelectObject(device_context, brush);
//        Ellipse(device_context, x1, y1, x2, y2);
//        DeleteObject(pen);
//        DeleteObject(brush);
//        ReleaseDC(console_handle, device_context);
//    }
//    void myLine(int x1, int y1, int x2, int y2, COLORREF lineColor) {
//
//        HWND console_handle = GetConsoleWindow();
//        HDC device_context = GetDC(console_handle);
//
//        //change the color by changing the values in RGB (from 0-255)
//        HPEN pen = CreatePen(PS_SOLID, 2, lineColor); //2 is the width of the pen
//        SelectObject(device_context, pen);
//        MoveToEx(device_context, x1, y1, NULL);
//        LineTo(device_context, x2, y2);
//        DeleteObject(pen);
//
//        ReleaseDC(console_handle, device_context);
//    }
//    void SetWindowTitle(char Title[]) {
//        SetConsoleTitle(Title);
//    }
//    void myDrawTextWithFont(int x, int y, int ht, char str[], COLORREF lineColor, COLORREF fillColor) {
//        WCHAR wstr[20] = {};
//        for (int i = 0; i < 20 && str[i]; ++i)
//            wstr[i] = str[i];
//
//        RECT rects;
//        HFONT hFont;
//        rects.left = x;
//        rects.top = y;
//        rects.right = x + ht;
//        rects.bottom = y + ht;//(x,y,x+ht,y+ht);
//
//        HWND console_handle = GetConsoleWindow();
//        HDC device_context = GetDC(console_handle);
//        hFont = CreateFont(ht, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
//            CLIP_DEFAULT_PRECIS, 1, VARIABLE_PITCH, TEXT("Impact"));
//        SelectObject(device_context, hFont);
//
//        SetTextColor(device_context, lineColor);
//        SetBkColor(device_context, fillColor);
//        DrawText(device_context, str, -1, &rects, DT_TOP | DT_NOCLIP);
//        DeleteObject(hFont);
//        ReleaseDC(console_handle, device_context);
//    }
//    Pong() {
//        GetWindowDimensions(width, height);
//        char text[] = "Press 'p' for Player vs Player";
//        char text2[] = "Press 'c' for Player vs Computer";
//
//        char Title[] = "PONG GAME";
//        char intro[] = "PONG GAME : ";
//        char name1[] = "BY ASHARIB";
//        char rollno1[] = "BSCS-23038";
//        char gameinfo[] = "Project details : ";
//        char instructions[] = "PLAYING INSTRUCTIONS : ";
//        myDrawTextWithFont(50, 10, 35, intro, RGB(127, 255, 0), RGB(10, 10, 10));
//        myDrawTextWithFont(250, 55, 35, name1, RGB(127, 255, 0), RGB(10, 10, 10));
//        myDrawTextWithFont(250, 95, 35, rollno1, RGB(127, 255, 0), RGB(10, 10, 10));
//        myDrawTextWithFont(50, 245, 35, gameinfo, RGB(127, 255, 0), RGB(10, 10, 10));
//        myDrawTextWithFont(50, 315, 35, instructions, RGB(127, 255, 0), RGB(10, 10, 10));
//        SetWindowTitle(Title);
//        myDrawTextWithFont(250, 245, 35, Title, RGB(127, 255, 0), RGB(12, 12, 12));
//        myDrawTextWithFont(320, 360, 40, text, RGB(127, 255, 0), RGB(12, 12, 12));
//        myDrawTextWithFont(320, 405, 40, text2, RGB(127, 255, 0), RGB(12, 12, 12));
//        while (flag) {
//            if (_kbhit()) {
//                char key = _getch();
//                if (key == 'p') {
//                    quit = false;
//                    flag = false;
//                }
//                else if (key == 'c') {
//                    computer = false;
//                    flag = false;
//                }
//            }
//        }
//        up1 = 'w'; up2 = 'i';
//        down1 = 's'; down2 = 'k';
//        score1 = score2 = 0;
//        ball = new Ball(width / 2, height / 2);
//        player1 = new Paddle(20, height / 2);
//        player2 = new Paddle(width - 20, height / 2);
//        player = new Paddle(20, height / 2);
//        computer1 = new Computer(width - 20, height / 2);
//
//    }
//    ~Pong() {
//        delete ball, player1, player2, computer1, player;
//    }
//    void ScoreUp(Paddle* player) {
//        if (player == player1) {
//            score1++;
//        }
//        else if (player == player2) {
//            score2++;
//        }
//
//        ball->Reset();
//        player1->Reset();
//        player2->Reset();
//        computer1->Reset();
//
//
//        if (score1 == 10) {
//            win = true;
//            quit = true;
//            computer = true;
//        }
//        else if (score2 == 10) {
//            win = false;
//            quit = true;
//            computer = true;
//        }
//    }
//    void Display() {
//        system("cls");
//        
//
//        int ballx = ball->getX();
//        int bally = ball->getY();
//        int player1x = player1->getX();
//        int player2x = player2->getX();
//        int player1y = player1->getY();
//        int player2y = player2->getY();
//
//        char Title[] = "PONG";
//        SetWindowTitle(Title);
//        myDrawTextWithFont(width / 2, 0, 40, Title, RGB(0, 0, 255), RGB(12, 12, 12));
//        char quit[] = "Enter 'q' for quit. ";
//        myLine(0, 50, 0, height, RGB(255, 255, 255));
//        myLine(0, 50, width, 50, RGB(255, 255, 255));
//        myLine(0, height, width, height, RGB(255, 255, 255));
//        myLine(width, 50, width, height, RGB(255, 255, 255));
//
//        myRect(player1x, player1y, player1x + 10, player1y + 60, RGB(255, 255, 255), RGB(255, 255, 255));
//        myRect(player2x, player2y, player2x - 10, player2y + 60, RGB(255, 255, 255), RGB(255, 255, 255));
//
//        myEllipse(ballx, bally, ballx + 20, bally + 20, RGB(255, 0, 0), RGB(255, 0, 0));
//
//        ofstream inscore1("score1.txt");
//        inscore1 << score1;
//        inscore1.close();
//        ofstream inscore2("score2.txt");
//        inscore2 << score2;
//        inscore2.close();
//
//        ifstream outscore1("score1.txt");
//        outscore1 >> s1;
//        outscore1.close();
//        ifstream outscore2("score2.txt");
//        outscore2 >> s2;
//        outscore2.close();
//
//        myDrawTextWithFont(40, 0, 40, s2, RGB(255, 0, 0), RGB(12, 12, 12));
//        myDrawTextWithFont(width - 40, 0, 40, s1, RGB(255, 0, 0), RGB(12, 12, 12));
//        myDrawTextWithFont(10, 1000, 40, quit, RGB(255, 0, 0), RGB(12, 12, 12));
//    }
//    void vsDisplay() {
//       system("cls");
//
//        int ballx = ball->getX();
//        int bally = ball->getY();
//        int playerx = player->getX();
//        int computerx = computer1->getX();
//        int playery = player->getY();
//        int computery = computer1->getY();
//
//        char Title[] = "PONG";
//        SetWindowTitle(Title);
//        myDrawTextWithFont(width / 2, 0, 40, Title, RGB(0, 0, 255), RGB(12, 12, 12));
//
//        myLine(0, 50, 0, height, RGB(255, 255, 255));
//        myLine(0, 50, width, 50, RGB(255, 255, 255));
//        myLine(0, height, width, height, RGB(255, 255, 255));
//        myLine(width, 50, width, height, RGB(255, 255, 255));
//
//        myRect(playerx, playery, playerx + 10, playery + 60, RGB(255, 255, 255), RGB(255, 255, 255));
//        myRect(computerx, computery, computerx - 10, computery + 60, RGB(255, 255, 255), RGB(255, 255, 255));
//
//        myEllipse(ballx, bally, ballx + 20, bally + 20, RGB(255, 0, 0), RGB(255, 0, 0));
//
//        ofstream inscore1("score1.txt");
//        inscore1 << score1;
//        inscore1.close();
//        ofstream inscore2("score2.txt");
//        inscore2 << score2;
//        inscore2.close();
//
//        ifstream outscore1("score1.txt");
//        outscore1 >> s1;
//        outscore1.close();
//        ifstream outscore2("score2.txt");
//        outscore2 >> s2;
//        outscore2.close();
//        char quit[] = "Enter 'q' for quit. ";
//        myDrawTextWithFont(40, 0, 40, s2, RGB(255, 0, 0), RGB(12, 12, 12));
//        myDrawTextWithFont(width - 40, 0, 40, s1, RGB(255, 0, 0), RGB(12, 12, 12));
//        myDrawTextWithFont(10, 1000, 40, quit, RGB(255, 0, 0), RGB(12, 12, 12));
//
//    }
//    void Movement() {
//        ball->Move();
//
//        if (_kbhit()) {
//            char key1 = _getch();
//            if (key1 == up1)    // lower case 'w'
//                player1->moveUp();
//            else if (key1 == down1)  // lower case 's'
//                player1->moveDown();
//            if (key1 == up2)    // lower case 'i'
//                player2->moveUp();
//            else if (key1 == down2)   // lower case 'k'
//                player2->moveDown();
//            if (ball->getDirection() == STOP)
//                ball->randomDirection();
//            if (key1 == 'q')
//                quit = true;
//        }
//
//    }
//    void vsMovement() {
//        ball->Move();
//        computer1->Move();
//
//        if (_kbhit()) {
//            char key1 = _getch();
//            if (key1 == up1)    // lower case 'w'
//                player->moveUp();
//            else if (key1 == down1)   // lower case 's'
//                player->moveDown();
//
//            if (ball->getDirection() == STOP)
//                ball->randomDirection();
//
//            if (key1 == 'q')
//                computer = true;
//        }
//    }
//
//    void Working() {
//        int ballx = ball->getX();
//        int bally = ball->getY();
//        int player1x = player1->getX();
//        int player2x = player2->getX();
//        int player1y = player1->getY();
//        int player2y = player2->getY();
//
//        // Left paddle collision
//        if (ballx <= player1x + 10 && ballx >= player1x && bally >= player1y && bally <= player1y + 60) {
//            ball->changeDirection((eDir)((rand() % 3) + 4)); // Change direction to right
//        }
//
//        // Right paddle collision
//        if (ballx >= player2x - 10 && ballx <= player2x && bally >= player2y && bally <= player2y + 60) {
//            ball->changeDirection((eDir)((rand() % 3) + 1)); // Change direction to left
//        }
//
//        // Bottom wall collision
//        if (bally >= height - 10)
//            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
//        // Top wall collision
//        if (bally <= 50)
//            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
//        // Left wall collision
//        if (ballx <= 0)
//            ScoreUp(player1); // Increment score for player 2
//        // Right wall collision
//        if (ballx >= width)
//            ScoreUp(player2); // Increment score for player 1
//    }
//
//    void vsWorking() {
//        int ballx = ball->getX();
//        int bally = ball->getY();
//        int playerx = player->getX();
//        int computerx = computer1->getX();
//        int playery = player->getY();
//        int computery = computer1->getY();
//
//        // Left paddle collision
//        if (ballx <= playerx + 10 && ballx >= playerx && bally >= playery && bally <= playery + 60) {
//            ball->changeDirection((eDir)((rand() % 3) + 4)); // Change direction to right
//        }
//
//        // Computer paddle collision
//        if (ballx >= computerx - 10 && ballx <= computerx && bally >= computery && bally <= computery + 60) {
//            ball->changeDirection((eDir)((rand() % 3) + 1)); // Change direction to left
//        }
//
//        // Bottom wall collision
//        if (bally >= height - 10)
//            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
//        // Top wall collision
//        if (bally <= 50)
//            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
//        // Left wall collision
//        if (ballx <= 0)
//            ScoreUp(player1); // Increment score for computer
//        // Right wall collision
//        if (ballx >= width)
//            ScoreUp(player2); // Increment score for player
//    }
//
//    void Run()
//    {
//        while (!quit)
//        {
//            Display();
//            Movement();
//            Working();
//            if (win && score1 == 10) {
//                char p2win[] = "Player 2 Wins !!";
//                myDrawTextWithFont(width / 2, height - 50, 50, p2win, RGB(255, 0, 0), RGB(12, 12, 12));
//            }
//            else if (!win && score2 == 10) {
//                char p1win[] = "Player 1 Wins !!";
//                myDrawTextWithFont(width / 2, height - 50, 50, p1win, RGB(255, 0, 0), RGB(12, 12, 12));
//            }
//        }
//        while (!computer) {
//            vsDisplay();
//            vsMovement();
//            vsWorking();
//            if (win && score1 == 10) {
//                char p2win[] = "You Lose :(";
//                myDrawTextWithFont(width / 2, height - 50, 50, p2win, RGB(255, 0, 0), RGB(12, 12, 12));
//            }
//            else if (!win && score2 == 10) {
//                char p1win[] = "You Wins !!";
//                myDrawTextWithFont(width / 2, height - 50, 50, p1win, RGB(0, 255, 0), RGB(12, 12, 12));
//            }
//        }
//        char end[] = "Thank You";
//        myDrawTextWithFont(width / 2, height / 2, 50, end, RGB(255, 0, 0), RGB(12, 12, 12));
//        score1 = score2 = 0;
//    }
//};

#include"Pong.h"
int main()
{

    Pong obj;
    bool played = PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
    obj.Run();
    //bool played= PlaySound(TEXT("Accident_.wav"), NULL, SND_SYNC);

    return 0;
}





