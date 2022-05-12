class Solver {
 public:
  Solver() {}

  void Solve(Board board) {
    board.SetDepth(0);
    set<string> seen;
    seen.insert(board.ToString());

    cout << "Uniform cost search \n";
    queue<Board> q;
    q.push(board);

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    while (!q.empty()) {
      Board oldBoard = q.front();
      q.pop();
      int currDepth = oldBoard.GetDepth();

      if (oldBoard.IsGoalState()) {
        cout << "Found at " << currDepth << endl;
        return;
      }

      for (int i = 0; i < 4; i++) {
        int xx = dx[i] + oldBoard.BlankX();
        int yy = dy[i] + oldBoard.BlankY();

        if (xx < 0 || xx >= board.Size() || yy < 0 || yy >= board.Size()) {
          continue;
        }

        Board newBoard = oldBoard.Swap(xx, yy);
        if (seen.find(newBoard.ToString()) != seen.end()) {
          continue;
        }
        newBoard.SetDepth(currDepth + 1);
        q.push(newBoard);
        seen.insert(newBoard.ToString());
      }
    }
    cout << "No solution " << std::endl;
  }
};
