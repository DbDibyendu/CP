
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Coordinate {
  int x, y;
};

class Dice {
public:
  int randomNumber() {
    return rand() % 6 + 1; // Simulates a dice roll (1-6)
  }
};

class Player {
public:
  int pIndex;
  Coordinate currPos;
  void move(map<Coordinate, Coordinate> snake,
            map<Coordinate, Coordinate> ladder) {

    Dice *d = new Dice;
    int val = d->randomNumber();
    int newX, newY;
    if (currPos.x + val > 10) {
      newY = currPos.y + 1;
      newX = currPos.x + val - 9;
    }
    int newX = currPos.x;
  }
};

class SnakeGame {
private:
  vector<vector<int>> cells;
  map<Coordinate, Coordinate> snake;
  map<Coordinate, Coordinate> ladder;

  int turn = 0;
  SnakeGame() { cells.resize(100, vector<int>(100, 0)); }

public:
  void printMethod() {
    for (auto x : this->cells) {
      for (auto y : x) {
        cout << y << " ";
      }
      cout << endl;
    }
    cout << "Board printed!" << endl;
  }
};
