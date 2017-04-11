/*
    https://www.acmicpc.net/problem/2589
    - map을 순회해서 땅(L)이 있는 곳에서 bfs를 진행한다
    - 진행하면서 가장 큰 값(가장 거리가 긴)을 찾아 답으로 추출
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> dis; // 거리 정보를 갖고 있는 배열 (만약 바다라면 -1 값을 갖게된다.)

int C, R;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
    vector<vector<bool>> visited;
    queue<pair<pair<int, int>, int>> q;
    
    visited.assign(C, vector<bool>(R, false));
    q.push(make_pair(make_pair(y, x), 0));
    
    while (!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int k = q.front().second;
        
        q.pop();
        
        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny < 0 || ny >= C || nx < 0 || nx >= R) continue;
            if (map[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                if (dis[y][x] < k+1) dis[y][x] = k+1;
                q.push(make_pair(make_pair(ny, nx), k+1));
            }
        }
    }
    
}

void solve() {
    int ans=0;
    for (int i=0; i<C; i++) {
        for (int j=0; j<R; j++) {
            if (map[i][j] == 1) {
                bfs(i, j);
                if (dis[i][j] > ans)
                    ans = dis[i][j];
            }
        }
    }
    
    printf("%d\n", ans);
}

int main(void) {
    scanf("%d %d", &C, &R);
    map.assign(C, vector<int>(R, 0));
    dis.assign(C, vector<int>(R, -1));
    
    for (int i=0; i<C; i++) {
        for (int j=0; j<R; j++) {
            char c;
            cin >> c;
            if (c == 'L') map[i][j] = 1;
        }
    }
    
    solve();
    return 0;
}
