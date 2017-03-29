/*
    https://www.codeground.org/practice/practiceProbView.do?probId=4
    - 다트 게임 (단순 구현)
 */

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.141592

int score[20] = { 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10 };

int main(int argc, char** argv) {
    
    setbuf(stdout, NULL);
    int TC;
    int test_case;
    int A, B, C, D, E, N;
    double theta, r;
    int ans;
    
    scanf("%d", &TC);	// cin 사용 가능
    for(test_case = 1; test_case <= TC; test_case++) {
        scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
        scanf("%d", &N);
        
        ans = 0;
        
        for (int i=0; i<N; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            
            theta = atan2(y, x) * 180 / PI;
            if (theta < 0) theta += 360;
            
            theta += 9;
            if (theta >= 360) theta -= 360;
            int index = theta / 18;
            
            double r = sqrt((x*x) + (y*y));
            if (r <= A)
                ans += 50;
            else if (r >= B && r <= C)
                ans += 3 * score[index];
            else if (r >= D && r <= E)
                ans += 2 * score[index];
            else if (r <= E)
                ans += score[index];
            
        }
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%d\n", ans);
    }

    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
