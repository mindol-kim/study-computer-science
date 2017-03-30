/*
    https://www.acmicpc.net/problem/1463
    dp[N]: N을 1로 만드는데 최소 연산 횟수
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;

int solve(int N) {
    /* base condition */
    if (N==1) return 0;
    
    int &ret = dp[N];
    if (ret != 1000001) return ret;
    
    if ((N%3)==0)
        ret = min(ret, solve(N/3)+1);
    
    if ((N%2)==0)
        ret = min(ret, solve(N/2)+1);
    
    ret = min(ret, solve(N-1)+1);
    return ret;
}

int main(void) {
    int N;
    
    cin >> N;
    dp.assign(N+1, 1000001);
    cout << solve(N) << endl;
    
    return 0;
}
