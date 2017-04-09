/*
    - (1,1) -> (N,N) 최소한의 경로를 찾는 알고리즘
    - basic bfs problem
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<vector<int>> A;

int bfs() {
    queue<pair<int, int>> q;
    vector<vector<int>> sum;
    sum.assign(N, vector<int>(N, 0x7fffffff));
    
    sum[0][0] = 0;
    q.push(make_pair(0, 0));
    
    while (!q.empty()) {
        int cx, cy;
        cy = q.front().first;
        cx = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (sum[ny][nx] <= sum[cy][cx] + A[ny][nx]) continue;
            
            sum[ny][nx] = sum[cy][cx] + A[ny][nx];
            q.push(make_pair(ny, nx));
        }
    }
    
    return sum[N-1][N-1];;
}

int main(void) {
    cin >> N;
    A.assign(N, vector<int>(N, 0));
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> A[i][j];
    
    cout << bfs() << endl;
    return 0;
}
