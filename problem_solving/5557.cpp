/*
    https://www.acmicpc.net/problem/5557
    dp[step][subSum]: step번째 요소, 그때의 중간합 (단, 중간합이 0보다 크거나 20보다 작아야 재귀함수를 호출한다.)
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<long long>> dp;
vector<int> A;

long long solve(int step, int subSum) {
    if (step == N)
        return (subSum == A[N]) ? 1 : 0;
    
    long long &ret = dp[step][subSum];
    if (ret != -1) return ret;
    
    ret = 0;
    if (subSum+A[step] <= 20 && subSum+A[step] >= 0)
        ret += solve(step+1, subSum+A[step]);
    
    if (subSum-A[step] <= 20 && subSum-A[step] >= 0)
        ret += solve(step+1, subSum-A[step]);
    
    return ret;
}

int main(void) {
    scanf("%d", &N);
    
    dp.assign(N+1, vector<long long>(21, -1));
    A.assign(N+1, 0);
    
    for (int i=1; i<=N; i++)
        scanf("%d", &A[i]);
    
    printf("%lld\n", solve(2, A[1]));
    return 0;
}
