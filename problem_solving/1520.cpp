
/*
    https://www.acmicpc.net/problem/1520
    dfs + memoization
*/

#include <iostream>
#include <vector>

using namespace std;

int M, N;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<vector<int>> MAP;
vector<vector<int>> dp;

long long solve(int y, int x) {
    if (y == M && x == N)
        return 1;
    
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    
    ret = 0;
    for (int i=0; i<4; i++) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        
        if (nextY < 0 || nextY > M || nextX < 0 || nextX > N) {
            continue;
        }
        
        if (MAP[y][x] > MAP[nextY][nextX]) {
            ret += solve(nextY, nextX);
        }
    }
    
    return ret;
}

int main(void) {
    scanf("%d %d", &M, &N);
    MAP.assign(M+1, vector<int> (N+1, 0));
    dp.assign(M+1, vector<int> (N+1, -1));
    
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++) {
            int input;
            scanf("%d", &input);
            MAP[i][j] = input;
        }
    }
    
    printf("%lld\n", solve(1, 1));
}
