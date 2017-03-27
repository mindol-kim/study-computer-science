
/*
    https://algospot.com/judge/problem/read/NUMBERGAME
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> data;
vector<vector<int>> dp;

int solve(int left, int right) {
    if (left > right) return 0;
    int& ret = dp[left][right];
    if (ret != -1) return ret;
    
    ret = max(data[left] - solve(left+1, right), data[right] - solve(left, right -1));
    
    if (right - left >= 1) {
        ret = max(ret, -solve(left+2, right));
        ret = max(ret, -solve(left, right-2));
    }
    
    return ret;
}

int main(void) {
    int C;
    scanf("%d", &C);
    
    while (C--) {
        int N;
        scanf("%d", &N);
        
        data.clear();
        dp.clear();
        
        data.assign(N, -1);
        dp.assign(N+1, vector<int>(N+1, -1));
        
        for (int i=0; i<N; i++) {
            scanf("%d", &data[i]);
        }
        printf("%d\n", solve(0, N-1));
    }
}
