/*
    - 주어진 수를 1, 2, 4, 8, 16, 32, 64의 덧셈으로 조합 만들기
*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(int N, int m, int index, vector<int> &picked) {
    
    if (N==0) {
        /*
            조합 출력
            전역 변수에 저장하고 싶다면, 이곳에서 처리!
        */
        for (int i=0; i<picked.size(); i++)
            printf("%d ", picked[i]);
        printf("\n");
        return;
    }
    
    for (int i=0; i<=N/m; i++) {
        int remaining = N-(i*m);
        if (remaining==0 || remaining%(2*m)==0) {
            picked[index] = i;
            dfs(remaining, m*2, index+1, picked);
            picked[index] = 0;
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);
    
    vector<int> picked(7);
    dfs(N, 1, 0, picked);
    
    return 0;
}
