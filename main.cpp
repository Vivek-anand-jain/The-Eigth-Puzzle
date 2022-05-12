#include <bits/stdc++.h>

using namespace std;

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
        cout << "Choose level of difficulty" << endl;
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

  cout << "User input" << endl;
  // User
  return 0;
}
