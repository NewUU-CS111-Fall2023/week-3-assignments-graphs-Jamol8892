#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// A struct to represent a cell in the maze
struct Cell {
    int row;
    int col;
    int spikes;
};

// A boolean array to mark visited cells
vector<vector<bool>> visited;

// A queue to store the cells to be visited
queue<Cell> q;

// A function to check if a cell is valid
bool isValid(Cell cell, int n, int m) {
    return cell.row >= 0 && cell.row < n && cell.col >= 0 && cell.col < m && !visited[cell.row][cell.col];
}

// A function to find the shortest path from the entrance to the treasure
bool FindShortestPath(vector<vector<char>> maze, int n, int m, int j) {
    // Initialize the visited array
    visited.resize(n, vector<bool>(m, false));

    // Add the entrance cell to the queue
    Cell entranceCell;
    entranceCell.row = 0;
    entranceCell.col = 0;
    entranceCell.spikes = 0;
    q.push(entranceCell);

    // While the queue is not empty
    while (!q.empty()) {
        // Get the cell at the front of the queue
        Cell cell = q.front();
        q.pop();

        // If the cell is the treasure, return true
        if (maze[cell.row][cell.col] == 'x') {
            return true;
        }

        // If the cell is a spike and Jarmtin has already been spiked j times, return false
        if (maze[cell.row][cell.col] == 's' && cell.spikes == j) {
            return false;
        }

        // Mark the cell as visited
        visited[cell.row][cell.col] = true;

        // Add the neighboring cells to the queue
        Cell neighborCell;
        neighborCell.spikes = cell.spikes;
        if (isValid(neighborCell, n, m)) {
            if (maze[neighborCell.row][neighborCell.col] == 's') {
                neighborCell.spikes++;
            }
            q.push(neighborCell);
        }
    }

    // Return false if the treasure is not reachable
    return false;
}

