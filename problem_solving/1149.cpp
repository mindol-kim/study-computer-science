/*
    https://www.acmicpc.net/problem/1149
    dp[n][rgb]: n번째 위치에서 rgb를 선택했을 때의 최소값 (memoization!)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> A;
vector<vector<long long>> dp;
int N;

/*
    red: 0, green: 1, blue: 2
*/
long long dfs(int n, int rgb) {
    long long &ret = dp[n][rgb];
    if (ret != -1) return ret;
    if (n == N-1) return A[n][rgb];
    
    for (int i=0; i<3; i++) {
        if (i==rgb) continue;
        long long temp = dfs(n+1, i);
        
        if (ret == -1 || ret > A[n][rgb] + temp)
            ret = A[n][rgb]+temp;
    }
    
    return ret;
}

long long dfsAll() {
    long long ret = 0;
    for (int i=0; i<3; i++) {
        long long temp = dfs(0, i);
        if (ret == 0 || ret > temp)
            ret = temp;
    }
    
    return ret;
}

int main(void) {
    cin >> N;
    A.assign(N, vector<long long>(3, 0));
    dp.assign(N, vector<long long>(3, -1));
    
    for (int i=0; i<N; i++)
        for (int j=0; j<3; j++)
            cin >> A[i][j];
    
    cout << dfsAll() << endl;
    return 0;
}
