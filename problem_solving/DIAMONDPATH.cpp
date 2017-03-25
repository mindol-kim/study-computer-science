/*
    https://algospot.com/judge/problem/read/DIAMONDPATH
    - Memoization
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<vector<int>> dp;
int N;
int dy[2] = { 1, 1 };
int dx[2] = { -1, 1 };

int dfs(int y, int x) {
    if ( (y+2 == N*2) && (x == N-1) ) {
        return A[y][x];
    }
    
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    
    for (int i=0; i<2; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if (nextX < 0 || nextY < 0 || nextX >= (N*2-1) || A[nextY][nextX] == -1)
            continue;
        
        int temp = dfs(nextY, nextX);
        if ( ret < A[y][x] + temp )
            ret = A[y][x] + temp;
    }
    
    return ret;
}

int main(void) {
    int C;
    scanf("%d", &C);
    
    while (C--) {
        scanf("%d", &N);
        A.clear();
        dp.clear();
        A.assign(N*2-1, vector<int> (N*2-1, -1));
        dp.assign(N*2-1, vector<int> (N*2-1, -1));
        for (int i=0; i<N*2-1; i++) {
            if (i < N) { // N column
                for (int j=N-1-i; j<=N-1+i; j+=2) {
                    scanf("%d", &A[i][j]);
                }
            } else {
                for (int j=i-N+1; j<=(N-1)*2-(i-(N-1)); j+=2) {
                    scanf("%d", &A[i][j]);
                }
            }
        }
        
        printf("%d\n", dfs(0, N-1));
    }
    
    return 0;
}
