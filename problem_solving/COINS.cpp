/*
    https://algospot.com/judge/problem/read/COINS
    dp[N] = dp[N - A[i]]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> coins;

const int mod = 1000000007;

int solve(int M, int C) {
    dp[0] = 1;
    for (int i=0; i<C; i++) {
        for (int j=1; j<=M; j++) {
            if (j -coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= 1000000007;
            }
        }
    }
    
    return dp[M];
}

int main(void) {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int M, C;
        scanf("%d %d", &M, &C);
        dp.assign(M+1, 0);
        coins.assign(C, 0);
        
        for (int i=0; i<C; i++)
            scanf("%d", &coins[i]);
        
        printf("%d\n", solve(M, C));
    }
    
    return 0;
}
