
/*
    https://www.acmicpc.net/problem/2294
    dp[N] = min(dp[N-K]+1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int MAXVAL = 0x7fffffff;
vector<int> dp;
vector<int> a;

int solve() {
    dp[0] = 0;
    for (int i=1; i<=k; i++) {
        for (int j=0; j<n; j++) {
            if (i-a[j] >= 0 && dp[i-a[j]] != MAXVAL) {
                dp[i] = min(dp[i], dp[i-a[j]]+1);
            }
        }
    }
    
    return (dp[k] == MAXVAL) ? -1 : dp[k];
}

int main(void) {
    scanf("%d %d", &n, &k);
    dp.assign(k+1, MAXVAL);
    
    for (int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        a.push_back(temp);
    }
    
    printf("%d\n", solve());
    return 0;
}
