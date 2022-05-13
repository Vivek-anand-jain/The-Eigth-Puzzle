using comp = std::function<bool(Board&, Board&)>;

bool UniformCostSearch(Board& lhs, Board& rhs) {
  return (lhs.GetDepth() > rhs.GetDepth());
}

bool AStarMisplaced(Board& lhs, Board& rhs) {
  return (lhs.GetDepth() + lhs.MisplacedTiles()) >
         (rhs.GetDepth() + rhs.MisplacedTiles());
}

bool AStarManhattan(Board& lhs, Board& rhs) {
  return (lhs.GetDepth() + lhs.ManhattanDistance()) >
         (rhs.GetDepth() + rhs.ManhattanDistance());
}

class Solver {
 public:
  Solver() {}

  priority_queue<Board, vector<Board>, comp> GetQueueingFunc(int algo) {
    if (algo == 1) {
      cout << "Using Uniform Cost Search \n";
      priority_queue<Board, vector<Board>, comp> q(UniformCostSearch);
      return q;
    } else if (algo == 2) {
      cout << "Using ASTAR with Misplaced \n";
      priority_queue<Board, vector<Board>, comp> q(AStarMisplaced);
      return q;
    }
    cout << "Using AStar with Manhattan \n";
    priority_queue<Board, vector<Board>, comp> q(AStarManhattan);
    return q;
  }

  void Solve(Board board, int algorithm) {
    uint32_t maxQueueSize = 1;
    uint32_t nodesExpanded = 0;

    int found = -1;
    board.SetDepth(0);
    set<string> seen;
    seen.insert(board.ToString());

    auto q = GetQueueingFunc(algorithm);
    q.push(board);

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    auto start = std::chrono::high_resolution_clock::now();
    while (!q.empty()) {
      Board oldBoard = q.top();
      q.pop();
      int currDepth = oldBoard.GetDepth();

      if (oldBoard.IsGoalState()) {
        found = currDepth;
        break;
      }
      nodesExpanded++;

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
        maxQueueSize = max<uint32_t>(maxQueueSize, q.size());
        seen.insert(newBoard.ToString());
      }
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = finish - start;
    std::cout << "Elapsed Time: " << elapsed.count() << " milliseconds"
              << std::endl;
    if (found == -1) {
      cout << "No solution " << std::endl;
    } else {
      cout << "Found at " << found << endl;
    }
    cout << "Max Queue Size: " << maxQueueSize << endl;
    cout << "Nodes expanded: " << nodesExpanded << endl;
  }
};
