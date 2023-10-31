#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
  int row;
  int col;
  int spikes;
};

vector<vector<bool>> visited;

queue<Cell> q;

bool isValid(Cell cell, int n, int m) {
  return cell.row >= 0 && cell.row < n && cell.col >= 0 && cell.col < m && !visited[cell.row][cell.col];
}

bool FindShortestPath(vector<vector<char>> maze, int n, int m, int j) {
  visited.resize(n, vector<bool>(m, false));

  Cell entranceCell;
  entranceCell.row = 0;
  entranceCell.col = 0;
  entranceCell.spikes = 0;
  q.push(entranceCell);

  while (!q.empty()) {
    Cell cell = q.front();
    q.pop();

    if (maze[cell.row][cell.col] == 'x') {
      return true;
    }

    if (maze[cell.row][cell.col] == 's' && cell.spikes == j) {
      return false;
    }

    visited[cell.row][cell.col] = true;

    Cell neighborCell;
    neighborCell.spikes = cell.spikes;
    if (isValid(neighborCell, n, m)) {
      if (maze[neighborCell.row][neighborCell.col] == 's') {
        neighborCell.spikes++;
      }
      q.push(neighborCell);
    }
  }

  return false;
}

int main() {
  int n, m, j;
  cin >> n >> m >> j;

  vector<vector<char>> maze(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> maze[i][j];
    }
  }
  bool success = FindShortestPath(maze, n, m, j);

  if (success) {
    cout << "SUCCESS" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
