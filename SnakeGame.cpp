#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool gameOver;
const int height = 20;
const int width = 30;
int playerX, playerY, fruitX, fruitY, score;

enum Direction {
    STOP = 0, LEFT, RIGHT, UP, DOWN
};

Direction dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    playerX = width / 2;
    playerY = height / 2;
    srand(time(NULL));
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            dir = UP;
            break;

        case 's':
            dir = DOWN;
            break;

        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;

        case 'o': // Change 'q' to 'o' for quitting
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    switch (dir) {
    case LEFT:
        playerX--;
        break;

    case RIGHT:
        playerX++;
        break;

    case UP:
        playerY--;
        break;

    case DOWN:
        playerY++;
        break;
    }

    if (playerX >= width || playerX < 0 || playerY >= height || playerY < 0) {
        gameOver = true;
    }

    if (playerX == fruitX && playerY == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

void DrawGame() {
    system("cls");
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }
            if (i == playerY && j == playerX) {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX) {
                cout << "F";
            }
            else {
                cout << " ";
            }
            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "Score:" << score << endl;
}

int main() {
    Setup();
    while (!gameOver) {
        DrawGame();
        Input();
        Logic();
        // You can add a delay here to control the game speed.
    }
    return 0;
}

