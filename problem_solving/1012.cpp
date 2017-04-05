/*
    https://www.acmicpc.net/problem/1012
    basic bfs problem
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int M, N;
vector<vector<int> > map;

void go(int y, int x) {
    queue<pair<int, int>> qq;
    qq.push(make_pair(y, x));
    
    while (!qq.empty()) {
        int cy = qq.front().first;
        int cx = qq.front().second;
        
        qq.pop();
        for (int dir=0; dir<4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            
            if (map[ny][nx] == 1) {
                map[ny][nx] = 0;
                qq.push(make_pair(ny, nx));
            }
        }
    }
}

int solve() {
    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j] == 1) {
                go(i, j);
                ans++;
            }
        }
    }
    return ans;
}

int main(void) {
    int T, K;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d %d", &M, &N, &K);
        map.assign(N, vector<int>(M, 0));
        
        for (int i=0; i<K; i++) {
            int y, x;
            scanf("%d %d", &x, &y);
            map[y][x] = 1;
        }
        
        printf("%d\n", solve());
    }
    
    return 0;
}
