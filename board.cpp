#include <bits/stdc++.h>

using namespace std;

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

 private:
  vector<vector<int>> m_board;
  int m_N;
  int m_blankPosI, m_blankPosJ;
};
