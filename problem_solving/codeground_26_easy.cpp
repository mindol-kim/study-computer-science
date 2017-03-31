/*
    https://www.codeground.org/practice/practiceProbView.do?probId=26
    dp[N][K]: K step으로 N bridge에 가는 방법 수
*/

#include <cstdio>
#include <iostream>
#include <vector>

#define M 1000000009
using namespace std;

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int T;
    int test_case;
    int N, K, L;
    vector<bool> bombList;
    vector<vector<long long> > dp;
    vector<long long> subSum;
    
    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        
        scanf("%d %d %d", &N, &K, &L);
        dp.clear();
        bombList.clear();
        subSum.clear();
        
        dp.assign(N+1, vector<long long>(K+1, 0));
        bombList.assign(N+1, false);
        subSum.assign(N+1, 0);
        
        for (int i=0; i<L; i++) {
            int where;
            scanf("%d", &where);
            bombList[where] = true;
        }
        
        for (int bridge=1; bridge<=N; bridge++) {
            long long sum = 0;
            if (bombList[bridge]) continue;
            for (int step=1; step<=K; step++) {
                int prevBridge = bridge - step;
                if (prevBridge == 0) {
                    dp[bridge][step] = 1;
                    sum += 1 % M;
                    break;
                } else {
                    dp[bridge][step] = subSum[prevBridge]- dp[prevBridge][step] % M;
                    sum += subSum[prevBridge]- dp[prevBridge][step] % M;
                }
            }
            
            subSum[bridge] = sum % M;
        }
        
        
        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n", test_case);
        printf("%lld\n", subSum[N]);
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

