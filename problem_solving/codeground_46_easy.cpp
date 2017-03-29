#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int> > cost;
int N, M, K;

int dfs(int here, int sum, int &dest) {
    int ret = 0x7fffffff;
    if (here == dest) {
        return sum;
    }
    
    visited[here] = true;
    for (int there=1; there<=N; there++) {
        if (cost[here][there] != -1 && !visited[there]) {
            int temp = dfs(there, sum + cost[here][there], dest);
            if (ret > temp) {
                ret = temp;
            }
        }
    }
    
    return ret;
}

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int T;
    int test_case;
    
    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        scanf("%d %d %d", &N, &M, &K);
        cost.assign(N+1, vector<int>(N+1, -1));
        
        for (int i=0; i<M; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            cost[a][b] = c;
            cost[b][a] = c;
        }
        
        int p;
        int ans = 0;
        scanf("%d", &p);
        for (int i=0; i<p; i++) {
            int start, dest;
            scanf("%d %d", &start, &dest);
            visited.clear();
            visited.assign(N+1, false);
            int totalCost = dfs(start, 0, dest);
            if (totalCost > K)
                ans++;
        }
        
        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n", test_case);
        printf("%d\n", ans);
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
