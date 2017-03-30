/*
    https://www.codeground.org/practice/practiceProbView.do?probId=6
    // 2차원 배열로 풀면 메모리 제한 오류
    // 더 간단한 풀이방법 분석해보기!
*/
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    long long ans;
    int cx, cy;
    int dir; // 현재 위치의 방향 (0: 아래, 1: 위)
    int N, K;
    
    scanf("%d", &TC);	// cin 사용 가능
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        scanf("%d %d", &N, &K);
        ans = 1; cx = 0; cy = 0; dir=1;
        int currentValue = 1;
        
        for (int i=0; i<K; i++) {
            char command;
            int ny, nx;
            int addValue = 0;
            cin >> command;
            
            if (command == 'U') {
                ny = cy-1;
                nx = cx;
                
                if ((cx+cy) < N) {
                    addValue += (dir % 2 == 0) ? (cx+cy)-cx : cx;
                } else {
                    addValue += (dir % 2 == 0) ? (N-1)-cx : cx - (N - (2*N-(cx+cy)-1));
                }
                
                if ((nx+ny) < N) {
                    addValue += (dir % 2 == 0) ? (nx+ny)-nx : nx;
                } else {
                    addValue += (dir % 2 == 0) ? (N-1)-nx : nx - (N - (2*N-(nx+ny)-1));
                }
                
                addValue++;
                addValue *= -1;
            } else if (command == 'R') {
                ny = cy;
                nx = cx + 1;
                
                if ((cx+cy) < N) {
                    addValue += (dir % 2 == 0) ? cx : (cx+cy)-cx;
                } else {
                    addValue += (dir % 2 == 0) ? cx - (N - (2*N-(cx+cy)-1)) : (N-1)-cx;
                }
                
                if ((nx+ny) < N) {
                    addValue += (dir % 2 == 0) ? nx : (nx+ny)-nx;
                } else {
                    addValue += (dir % 2 == 0) ? nx - (N - (2*N-(nx+ny)-1)) : (N-1)-nx;
                }
                
                addValue++;
            } else if (command == 'D') {
                ny = cy + 1;
                nx = cx;
                
                if ((cx+cy) < N) {
                    addValue += (dir % 2 == 0) ? cx : (cx+cy)-cx;
                } else {
                    addValue += (dir % 2 == 0) ? cx - (N - (2*N-(cx+cy)-1)) : (N-1)-cx;
                }
                
                if ((nx+ny) < N) {
                    addValue += (dir % 2 == 0) ? nx : (nx+ny)-nx;
                } else {
                    addValue += (dir % 2 == 0) ? nx - (N - (2*N-(nx+ny)-1)) : (N-1)-nx;
                }
                
                addValue++;
            } else if (command == 'L') {
                ny = cy;
                nx = cx - 1;
                
                if ((cx+cy) < N) {
                    addValue += (dir % 2 == 0) ? (cx+cy)-cx : cx;
                } else {
                    addValue += (dir % 2 == 0) ? (N-1)-cx : cx - (N - (2*N-(cx+cy)-1));
                }
                
                if ((nx+ny) < N) {
                    addValue += (dir % 2 == 0) ? (nx+ny)-nx : nx;
                } else {
                    addValue += (dir % 2 == 0) ? (N-1)-nx : nx - (N - (2*N-(nx+ny)-1));
                }
                
                addValue++;
                addValue *= -1;
            }
            currentValue += addValue;
            ans += currentValue;
            cx = nx;
            cy = ny;
            dir = (dir + 1) % 2;
        }
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%lld\n", ans);
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
