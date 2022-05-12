#include <bits/stdc++.h>

#include "board.hpp"

using namespace std;

vector<vector<int>> DefaultPuzzle() {
  int done = 1;
  int puzzle;
  do {
    done = 1;
    cout << "Enter one of the depth: 0, 2, 4, 8, 12, 16, 20, 24" << endl;
    cin >> puzzle;
    switch (puzzle) {
      case 0:
        return {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
      case 2:
        return {{1, 2, 3}, {4, 5, 6}, {0, 7, 8}};
      case 4:
        return {{1, 2, 3}, {5, 0, 6}, {4, 7, 8}};
      case 8:
        return {{1, 3, 6}, {5, 0, 2}, {4, 7, 8}};
      case 12:
        return {{1, 3, 6}, {5, 0, 7}, {4, 8, 2}};
      case 16:
        return {{1, 6, 7}, {5, 0, 3}, {4, 8, 2}};
      case 20:
        return {{7, 1, 2}, {4, 8, 5}, {6, 3, 0}};
      case 24:
        return {{0, 7, 2}, {4, 6, 1}, {3, 5, 8}};
      default:
        done = 0;
    }
  } while (done != 1);
}

int main() {
  int n = 3, temp;
  int puzzleMode = 1;
  vector<vector<int>> vec;
  cout << "Welcome to my CS205 8-Puzzle Solver. Type '1' to use a default "
          "puzzle, or '2' to create your own."
       << endl;

  int done = 1;

  do {
    done = 1;
    cin >> puzzleMode;
    switch (puzzleMode) {
      case 1:
        vec = DefaultPuzzle();
        break;
      case 2:
        cout << "Enter 3 * 3 puzzle, zero means blank" << endl;
        for (int i = 0; i < n; i++) {
          vector<int> row;
          for (int j = 0; j < n; j++) {
            cin >> temp;
            row.push_back(temp);
          }
          vec.push_back(row);
        }
        break;
      default:
        cout << "Invalid choice, Type '1' to use a default puzzle, or '2' to "
                "create your own."
             << endl;
        done = 0;
    }
  } while (done != 1);

  Board board(vec);
  board.Print();

  return 0;
}
