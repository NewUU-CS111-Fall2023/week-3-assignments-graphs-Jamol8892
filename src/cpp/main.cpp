/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

#include "task_2.h"
#include "task_3.h"

using namespace std;

int main() {
    cout << "Task 2" << endl;
    int n, m;
    int j;
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

    cout << "Task 3" << endl;
    // call for task 3
    int a, b;
    cin >> a >> b;

    if (!isPossible(a, b)) {
        cout << "NO";
    } else {
        vector<int> sequence = findTransformationSequence(a, b);

        cout << "YES" << endl;
        cout << sequence.size() << endl;
        for (int i = 0; i < sequence.size(); i++) {
            cout << sequence[i] << " ";
        }
        cout << endl;
        return 0;
    }
}
