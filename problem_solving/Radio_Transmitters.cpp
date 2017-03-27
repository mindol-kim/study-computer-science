/*
    https://www.hackerrank.com/challenges/hackerland-radio-transmitters
    - 주어진 값을 먼저 정렬한 후, 왼쪽부터 주어진 범위 내에서 세울 수 있는 위치를 찾는다.
    - 찾은 위치에서 커버할 수 있는 범위까지 찾고, 다음 위치부터 다시 순회하면 된다.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, K;
    int nCount = 0;
    vector<int> A;
    scanf("%d %d", &N, &K);
    A.assign(N, 0);
    
    for (int i=0; i<N; i++)
        scanf("%d", &A[i]);
    
    sort(A.begin(), A.end());
    
    int index=0;
    while (index<N) {
        int subIndex;
        if (index==N-1) {
            nCount++;
            break;
        }
        
        for (subIndex=index+1; subIndex<N; subIndex++) {
            if (A[subIndex] - A[index] > K)
                break;
        }
        
        index = subIndex-1;
        
        nCount++;
        for (subIndex=index+1; subIndex<N; subIndex++) {
            if (A[subIndex] - A[index] > K)
                break;
        }
        
        index = subIndex;
    }
    printf("%d\n", nCount);
    return 0;
}

