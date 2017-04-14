/*
    나눠진 부분을 최소한의 횟수로 연결시키는 방법
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int number = 2;
int N, M;

void dfs(int y, int x) {
    map[y][x] = number;
    
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (map[ny][nx] == 1)
            dfs(ny, nx);
    }
}

void setting() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j]==1) {
                dfs(i, j);
                number++;
            }
        }
    }
}

int solve() {
    queue<pair<pair<int, int>, int>> q;
    int ans = 0x7fffffff;


    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j]==2)
                q.push(make_pair(make_pair(i, j), 0));
        }
    }

    while (!q.empty()) {
        int cy, cx, k;
        cy = q.front().first.first;
        cx = q.front().first.second;
        k = q.front().second;

        q.pop();


        if (k > ans) continue;

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (map[ny][nx] == 0) {
                map[ny][nx] = -1;
                q.push(make_pair(make_pair(ny, nx), k+1));
            }
            if (map[ny][nx] == 3) {
                ans = min(ans, k);
            }
        }
    }

    return ans;
}

int main(void) {
    scanf("%d %d", &N, &M);
    map.assign(N, vector<int>(M, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char c;
            cin >> c;
            if (c=='.')
                map[i][j] = 0;
            else
                map[i][j] = 1;
        }
    }
    
    setting();
    printf("%d\n", solve());
    
    return 0;
}
