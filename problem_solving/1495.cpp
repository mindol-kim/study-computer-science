/*
    https://www.acmicpc.net/problem/1495
    dp[step][vol]: 현재 step에서 volume 값을 갖는 memoization
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<vector<int>> dp;

int N, S, M;

int solve(int step, int vol) {
    if (step == N+1) return vol;
    
    int &ret = dp[step][vol];
    if (ret != -2) return ret;
    
    if (vol+A[step] >= 0 && vol+A[step] <= M)
        ret = max(ret, solve(step+1, vol+A[step]));
    
    if (vol-A[step] >= 0 && vol-A[step] <= M)
        ret = max(ret, solve(step+1, vol-A[step]));
    
    return (ret == -2) ? -1 : ret; // 볼륨을 조절하지 못했을 경우, -1로 변경해야 제대로된 memoization이 가능하다.
}

int main(void) {
    scanf("%d %d %d", &N, &S, &M);
    
    A.assign(N+1, 0);
    dp.assign(N+1, vector<int>(M+1, -2));
    
    for (int i=1; i<=N; i++)
        scanf("%d", &A[i]);
    
    printf("%d\n", solve(1, S));
    return 0;
}
