/*
    https://www.codeground.org/practice/practiceProbView.do?probId=44
    - dfs basic problem
*/
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > G;
vector<int> cached;
int N;

bool dfs(int here, int value) {
    bool ret = true;
    cached[here] = value;
    
    for (int i=0; i<G[here].size(); i++) {
        int there = G[here][i];
        if (cached[there]!=0 && value == cached[there])
            return false;
        if (cached[there]==0) {
            ret = dfs(there, (value%2)+1);
            if (!ret) return ret;
        }
    }
    
    return ret;
}

bool dfsAll() {
    bool ret = true;
    
    for (int i=1; i<=N; i++) {
        if (cached[i]==0) {
            ret = dfs(i, 1);
            if (!ret) return ret;
        }
    }
    return ret;
}

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int T, L;
    int test_case;
    
    scanf("%d", &T);
    for(test_case = 1; test_case <= T; test_case++) {
        scanf("%d", &N);
        scanf("%d", &L);
        
        G.clear();
        cached.clear();
        
        G.assign(N+1, vector<int>(0));
        cached.assign(N+1, 0);
        for (int i=0; i<L; i++) {
            int h, t;
            scanf("%d %d", &h, &t);
            G[h].push_back(t);
            G[t].push_back(h);
        }
        
        printf("Case #%d\n", test_case);
        printf("%d\n", dfsAll());
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
