#include <bits/stdc++.h>

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
  return {};
}

class Board {
 public:
  Board(vector<vector<int>> vec) {
    m_board = vec;
    m_N = vec.size();
    for (int i = 0; i < m_N; i++) {
      for (int j = 0; j < m_N; j++) {
        if (m_board[i][j] == 0) {
          m_blankPosI = i;
          m_blankPosJ = j;
        }
      }
    }
  }

  int BlankX() { return m_blankPosI; }

  int BlankY() { return m_blankPosJ; }

  void SetBlankPosI(int ii) { m_blankPosI = ii; }

  void SetBlankPosJ(int jj) { m_blankPosJ = jj; }

  void Print() {
    for (int i = 0; i < m_N; i++) {
      for (int j = 0; j < m_N; j++) {
        cout << m_board[i][j] << " ";
      }
      cout << endl;
    }
  }

  bool IsGoalState() {
    for (int i = 0; i < m_N; i++) {
      for (int j = 0; j < m_N; j++) {
        if (m_goal[i][j] != m_board[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  Board Swap(int xx, int yy) {
    auto board = m_board;
    swap(board[xx][yy], board[m_blankPosI][m_blankPosJ]);
    return Board(board);
  }

  string ToString() {
    string str;
    for (int i = 0; i < m_N; i++) {
      for (int j = 0; j < m_N; j++) {
        str.append(to_string(m_board[i][j]));
      }
    }
    return str;
  }

  int Size() { return m_N; }

  void SetDepth(int depth) { m_depth = depth; }

  int GetDepth() { return m_depth; }

 private:
  vector<vector<int>> m_board;
  vector<vector<int>> m_goal{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
  int m_N;
  int m_blankPosI, m_blankPosJ;
  int m_depth{0};
};
