/*
    https://www.codeground.org/practice/practiceProbView.do?probId=2
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparison(int a, int b) {
    return a > b;
}

int main(int argc, char** argv) {
    
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    
    scanf("%d", &TC);	// cin 사용 가능
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        int N, ans = 0;
        int maxValue = 0;
        vector<int> V;
        scanf("%d", &N);
        
        for (int i=0; i<N; i++) {
            int input;
            scanf("%d", &input);
            V.push_back(input);
        }
        
        // 내림차순으로 정렬한 뒤, 획득할 수 있는 최소 값을 구한다.
        sort(V.begin(), V.end(), comparison);
        int earn = 1;
        for (int i=0; i<N; i++) {
            maxValue = max(maxValue, V[i]+earn);
            earn++;
        }
        
        for (int i=0; i<N; i++) {
            // 다음에서 1등했을 때, 획득할 수 있는 최대 값보다 크다면 1등이 가능하다.
            if (V[i] + N >= maxValue)
                ans++;
        }
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%d\n", ans);
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
