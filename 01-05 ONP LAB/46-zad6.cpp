#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Coord {
    int x, y;
};

const vector<Coord> moves = {
        {0,  1},
        {1,  0},
        {-1, 0},
        {0,  -1}
};

Coord randMove() {
    return moves[rand() % moves.size()];
}

bool outOfBounds(Coord size, Coord pos) {
    return pos.x >= size.x || pos.x < 0 || pos.y >= size.y || pos.y < 0;
}

//bez rogow
bool onBorder(Coord size, Coord pos) {
    return ((pos.x == size.x - 1 || pos.x == 0) && (pos.y != 0 && pos.y != size.y - 1)) ||
           ((pos.y == size.y - 1 || pos.y == 0) && (pos.x != 0 && pos.x != size.x - 1));
}

Coord sumCoord(Coord a, Coord b) {
    return {a.x + b.x, a.y + b.y};
}

void fill2DArrWith(Coord size, int **arr, int num) {
    for (int x = 0; x < size.x; x++) {
        for (int y = 0; y < size.y; y++) {
            arr[y][x] = num;
        }
    }
}

int **create2DArr(Coord size) {
    int **arr;
    arr = new int *[size.y];
    for (int i = 0; i < size.y; i++) {
        arr[i] = new int[size.x];
    }

    return arr;
}

int **randomWalker(Coord size, int walkerCount, int moveCount) {
    int **grid = create2DArr(size);
    bool madeExit = false;
    fill2DArrWith(size, grid, 0);

    for (int walker = 0; (walker < walkerCount || !madeExit); walker++) {
        Coord walkerPos = {size.x / 2, size.y / 2};
        grid[walkerPos.y][walkerPos.x] = 1;

        for (int move = 0; move < moveCount; move++) {
            Coord currMove = randMove();

            walkerPos = sumCoord(walkerPos, currMove);

            if (outOfBounds(size, walkerPos)) break;

            if (onBorder(size, walkerPos)) {
                if (madeExit) {
                    break;
                }
                madeExit = true;
            }

            grid[walkerPos.y][walkerPos.x] = 1;

        }
    }

    return grid;
}

void print(int **arr, Coord size) {
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            cout << arr[y][x] << " ";
        }

        cout << endl;
    }
}

int main() {
    Coord size = {10, 20};
    int walkerCount = 10;
    int moveCount = 12;
    int **grid = randomWalker(size, walkerCount, moveCount);

    print(grid, size);
}