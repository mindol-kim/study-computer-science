/*
    https://www.codeground.org/practice/practiceProbView.do?probId=12
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<pair<int, int> > S;
int ROOM[1000][1000];
bool cache[1000][1000];
int N;
int dirOne[4] = { 1, 0, 3, 2 };
int dirTwo[4] = { 3, 2, 1, 0 };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x, int dir) {
    if ( y<0 || x<0 || y>=N || x>=N )
        return;
    
    if (ROOM[y][x] == 0) {
        dfs(y+dy[dir], x+dx[dir], dir);
    } else if (ROOM[y][x] == 1) {
        cache[y][x] = true;
        dfs(y+dy[dirOne[dir]], x+dx[dirOne[dir]], dirOne[dir]);
    } else if (ROOM[y][x] == 2) {
        cache[y][x] = true;
        dfs(y+dy[dirTwo[dir]], x+dx[dirTwo[dir]], dirTwo[dir]);
    }
}

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    
    scanf("%d", &TC);	// cin 사용 가능
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        scanf("%d", &N);
        
        for (int i=0; i<N; i++) {
            int input;
            for (int j=0; j<N; j++) {
                scanf("%1d", &input);
                ROOM[i][j] = input;
                cache[i][j] = false;
            }
        }
        
        dfs(0, 0, 1);
        
        int ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (cache[i][j])
                    ans++;
            }
        }
        
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%d\n", ans);
        
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
