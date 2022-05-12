#include <bits/stdc++.h>

#include "board.hpp"
#include "solver.hpp"

using namespace std;

int main() {
  int n = 3, temp;
  int puzzleMode = 1;
  int algorithm = 1;
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
  cout << "Solving following puzzle: " << endl;
  board.Print();

  cout << endl;

  cout << "Select algorithm: \n'1' for Uniform Cost Search\n'2' for A* with "
          "Misplaced Tile Heuristic\n'3' for A* with Manhattan Distance "
          "Heuristic"
       << endl;
  do {
    done = 1;
    cin >> algorithm;
    if (algorithm < 1 || algorithm > 3) {
      cout << "Invalid choice, Type \n'1' for Uniform Cost Search\n'2' for "
              "A* with Misplaced Tile Heuristic\n'3' A* with Manhattan "
              "Distance Heuristic"
           << endl;
      done = 0;
    }
  } while (done != 1);

  Solver solver;
  solver.Solve(board, algorithm);

  return 0;
}
