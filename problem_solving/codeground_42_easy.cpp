/*
    https://www.codeground.org/practice/practiceProbView.do?probId=42
    ex) 1 2 3 4 5
    - 앞에서 count를 늘러가면서, S보다 크거나 같으면 멈춘후 답 후보군에 현재의 카운트 값을 넣는다.
    - 앞 요소 값과 count 값을 감소시키면서, 변경된 카운트 값을 넣는다.
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int T;
    int test_case;
    
    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        int N, S;
        scanf("%d %d", &N, &S);
        vector<int> A(N);
        vector<int> candidate;
        
        for (int index=0; index<N; index++)
            scanf("%d", &A[index]);
        
        int sum = 0;
        int count = 0;
        for (int index=0; index<N; index++) {
            sum += A[index];
            count++;
            while (sum >= S) {
                candidate.push_back(count);
                sum -= A[index-count+1];
                count--;
            }
        }
        
        int ans = 0;
        
        if (candidate.size() != 0) {
            sort(candidate.begin(), candidate.end());
            ans = candidate[0];
        }
        
        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("#testcase%d\n", test_case);
        printf("%d\n", ans);
        
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
