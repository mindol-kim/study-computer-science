/*
    https://www.hackerrank.com/challenges/knightl-on-chessboard
    bfs problem
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N;

bool canMove(int y, int x) {
    if ( y<0 || y>N-1 || x<0 || x>N-1)
        return false;
    else
        return true;
}

int bfs(int a, int b) {
    vector<vector<bool>> visited;
    queue<pair<pair<int, int>, int>> q; // y, x, count
    
    visited.assign(N, vector<bool>(N, false));
    visited[0][0] = true;
    
    q.push(make_pair(make_pair(0, 0), 0));
    
    while (!q.empty()) {
        int currentY = q.front().first.first;
        int currentX = q.front().first.second;
        int currentK = q.front().second;
        
        q.pop();
        if (currentY == N-1 && currentX == N-1)
            return currentK;
        
        for (int i=0; i<4; i++) {
            int nextY, nextX;
            nextY = currentY + ((i < 2) ? a : -a);
            nextX = currentX + ((i %2 == 0) ? b : -b);
            
            if (canMove(nextY, nextX) && !visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push(make_pair(make_pair(nextY, nextX), currentK+1));
            }
        }
        
        for (int i=0; i<4; i++) {
            int nextY, nextX;
            nextY = currentY + ((i < 2) ? b : -b);
            nextX = currentX + ((i %2 == 0) ? a : -a);
            
            if (canMove(nextY, nextX) && !visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push(make_pair(make_pair(nextY, nextX), currentK+1));
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> N;
    
    for (int i=1; i<N; i++) {
        for (int j=1; j<N; j++) {
            cout << bfs(i, j) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
