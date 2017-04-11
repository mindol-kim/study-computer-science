/*
    https://www.acmicpc.net/problem/2580
    - 스도쿠 값 넣는 문제 (백트래킹)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map(9, vector<int>(9, 0));
vector<pair<int, int>> zeroList;
int zeroIndex = 0;

/*
    현재 위치에서 입력될 수 있는 값 후보군 추출
    가로줄, 세로줄, 3x3 사각형에서 값 가져오기
*/
vector<int> get_candidate(int y, int x) {
    vector<int> ret;
    vector<bool> elements(10, false);
    
    for (int i=0; i<9; i++) {
        if (map[y][i]!=0) elements[map[y][i]] = true;
        if (map[i][x]!=0) elements[map[i][x]] = true;
    }
    
    int sy = (y/3)*3;
    int sx = (x/3)*3;
    int ey = sy+2;
    int ex = sx+2;
    
    for (int i=sy; i<=ey; i++) {
        for (int j=sx; j<=ex; j++) {
            if (map[i][j]!=0) elements[map[i][j]] = true;
        }
    }
    
    for (int i=1; i<10; i++) {
        if (!elements[i]) ret.push_back(i);
    }
    
    return ret;
}

/*
    get_candidate 함수에서 후보군을 찾은 후 재귀 호출
*/
bool go(int y, int x) {
    vector<int> cand_list = get_candidate(y, x);
    // zero 값을 가지고 있는 마지막 위치임을 나타냄
    // 단, 마지막 위치에 왔더라도 입력될 수 있는 후보군이 있어야만 정상적으로 종료할 수 있다.
    if (zeroIndex==zeroList.size() && cand_list.size() > 0) {
        map[y][x] = cand_list[0];
        return true;
    }
    
    for (int i=0; i<cand_list.size(); i++) {
        map[y][x] = cand_list[i];
        int ny = zeroList[zeroIndex].first;
        int nx = zeroList[zeroIndex].second;
        zeroIndex++;
        
        bool ret = go(ny, nx);
        if (ret) return true;
        
        zeroIndex--;
        map[y][x] = 0;
    }
    return false;
}

int main(void) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            int input;
            scanf("%d", &input);
            map[i][j] = input;
            if (input == 0) {
                zeroList.push_back(make_pair(i, j));
            }
        }
    }
    
    int ny, nx;
    ny = zeroList[zeroIndex].first;
    nx = zeroList[zeroIndex++].second;
    go(ny, nx);
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
