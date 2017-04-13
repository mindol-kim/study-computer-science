/*
    https://www.acmicpc.net/problem/2580
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    주사위 각 면에 대한 값을 갖고있는 정보
    1. 상 2. 뒤 3. 우 4. 좌 5. 앞 6. 바닥
*/
vector<int> info(7, 0);
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void move(int dir) {
    if (dir == 1) {
        int temp = info[6];
        info[6] = info[3];
        info[3] = info[1];
        info[1] = info[4];
        info[4] = temp;
    } else if (dir == 2) {
        int temp = info[4];
        info[4] = info[1];
        info[1] = info[3];
        info[3] = info[6];
        info[6] = temp;
    } else if (dir == 3) {
        int temp = info[1];
        info[1] = info[5];
        info[5] = info[6];
        info[6] = info[2];
        info[2] = temp;
    } else if (dir == 4) {
        int temp = info[2];
        info[2] = info[6];
        info[6] = info[5];
        info[5] = info[1];
        info[1] = temp;
    }
}

int main(void) {
    int N, M, sx, sy, K;
    vector<vector<int>> map;
    scanf("%d %d %d %d %d", &N, &M, &sy, &sx, &K);
    
    map.assign(N, vector<int>(M, 0));
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%d", &map[i][j]);
    
    for (int i=0; i<K; i++) {
        int dir, nx, ny;
        scanf("%d", &dir);
        
        ny = sy + dy[dir];
        nx = sx + dx[dir];
        
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
            continue;
        }
        
        move(dir);
        if (map[ny][nx]==0) {
            map[ny][nx] = info[6];
        } else {
            info[6] = map[ny][nx];
            map[ny][nx] = 0;
        }
        
        sy = ny;
        sx = nx;
        printf("%d\n", info[1]);
    }
}
