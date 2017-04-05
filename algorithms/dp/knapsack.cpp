
/*
    knapsack problem (dynamic programming)
    OPT(j, W) (j: item 종류, W: 넣을 수 있는 가방의 용량)
    OPT의 경우의 수는 3가지가 있다.
    1. j==0 || W==0 => item이 더 이상 없거나, 더 이상 넣을 수 있는 가방의 용량이 없는 경우
    2. if (weight[j] > W) OPT(j-1, W) => j번째 item의 무게가 가방의 용량보다 큰 경우
    3. max(OPT(j-1, W), weight[j]+OPT(j-1, W-weight[j]) => 가방에 j번째 item을 넣거나 넣지 않거나
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> weight;

int solve(int n, int W) {
    vector<vector<int>> dp;
    dp.assign(n+1, vector<int>(W+1, 0));
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=W; j++) {
            if (i > j) {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            
            dp[i][j] = max(dp[i-1][j], weight[i]+dp[i-1][j-i]);
        }
    }
    
    return dp[n][W];
}

int main(void) {
    int n = 4, W = 6;
    weight.assign(n+1, 0);
    
    weight[1] = 30;
    weight[2] = 40;
    weight[3] = 45;
    weight[4] = 100;
    
    printf("%d\n", solve(n, W));
    
    return 0;
}
