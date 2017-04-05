/*
    https://www.codeground.org/practice/practiceProbView.do?probId=45
    - 입력되는 값을 계속해서 누적해서 더한다음 최대값을 찾는다.
    - 누적되는 배열: sumList
    - cached는 합의 중복이 생기는 문제를 해결하기 위해 만듬
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
    
    scanf("%d", &T);
    
    for(test_case = 1; test_case <= T; test_case++) {
        int N, M;
        int ans = 0;
        vector<bool> cached(100001, false);
        vector<int> sumList;
        sumList.push_back(0);
        
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; i++) {
            int num;
            scanf("%d", &num);
            
            int nList = sumList.size();
            for (int j=0; j<nList; j++) {
                int sum = sumList[j] + num;
                if (sum <= M && !cached[sum]) {
                    cached[sum] = true;
                    sumList.push_back(sum);
                    ans = max(ans, sum);
                }
            }
        }
        
        printf("Case #%d\n", test_case);
        printf("%d\n", ans);
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
