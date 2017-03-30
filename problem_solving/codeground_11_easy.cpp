/*
    https://www.codeground.org/practice/practiceProbView.do?probId=11
    - limit (최대 갈 수 있는 거리) 값을 이전 요소 + K 값으로 더해가면서 수정
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    
    scanf("%d", &TC);	// cin 사용 가능
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        int N, K;
        int ans = 1, limit;
        vector<int> V;
        
        scanf("%d", &N);
        V.assign(N+1, 0);
        
        for (int i=1; i<=N; i++) {
            int input;
            scanf("%d", &input);
            V[i] = input;
        }
        V[0] = 0;
        scanf("%d", &K);
        limit = K;
        
        for (int i=1; i<=N; i++) {
            if (V[i] > limit) {
                if (V[i] > V[i-1] + K) {
                    ans = -1;
                    break;
                }
                
                limit = V[i-1] + K;
                ans++;
            }
        }
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%d\n", ans);
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
