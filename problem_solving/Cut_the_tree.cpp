/*
    https://www.hackerrank.com/challenges/cut-the-tree
    dp[N] = vertex N부터 leaf 노드까지의 합
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<int>> tree;
vector<int> data;
vector<long long> dp;
vector<pair<int, int>> cutList;

int N;

long long dfs(int vertex) {
    long long &ret = dp[vertex];
    ret = data[vertex];
    visited[vertex] = true;
    
    for (int i=1; i<tree[vertex].size(); i++) {
        int there = tree[vertex][i];
        
        if (!visited[there])
            ret += dfs(there);
    }
    
    return ret;
}

int main() {
    scanf("%d", &N);
    tree.assign(N+1, vector<int>(1, 0));
    data.assign(N+1, 0);
    dp.assign(N+1, -1);
    
    for (int i=1; i<=N; i++)
        scanf("%d", &data[i]);
    
    for (int i=1; i<N; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
        cutList.push_back(make_pair(v1, v2));
    }
    
    visited.clear();
    visited.assign(N+1, false);
    
    long long total = dfs(1);
    long long ans = total;
    
    for (int i=0; i<N; i++) {
        int v1, v2;
        v1 = cutList[i].first;
        v2 = cutList[i].second;
        
        long long value = dp[v2];
        long long diff = abs(value - (total-value));
        
        ans = min(ans, diff);
    }
    
    cout << ans << endl;
    return 0;
}
