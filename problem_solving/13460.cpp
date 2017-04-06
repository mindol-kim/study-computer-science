/*
    https://www.acmicpc.net/problem/13460
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int gy, gx;
vector<vector<int> > map;

pair<int, int> move(int y, int x, int dir) {
    while (true) {
        y += dy[dir];
        x += dx[dir];
        
        if (map[y][x] == -1 || map[y][x] == 1 || map[y][x] == 2) { // 벽이나 공에 부딪힐경우에는 방금 전 위치로 돌아가고 break
            y -= dy[dir];
            x -= dx[dir];
            break;
        }
        
        if (y == gy && x == gx) { // goal 이면 해당 위치에서 나오기
            break;
        }
    }
    
    return make_pair(y, x);
}

/*
    <map>
    -1: 막힘, 0: 이동 가능, 1: 빨간공, 2: 파란공
*/
int go(int ry, int rx, int by, int bx) { // the x, y position of red and blue
    int ans=-1;
    queue<pair<vector<int>, int>> qq; // vector[0]: 빨간색공 y, vector[1]: 빨간색공 x, vector[2]: 파란색공 y, vector[3]: 파란색공 x
    
    // initialize
    vector<int> init;
    init.push_back(ry);
    init.push_back(rx);
    init.push_back(by);
    init.push_back(bx);
    qq.push(make_pair(init, 0));
    
    while (!qq.empty()) {
        vector<int> pos = qq.front().first;
        int k = qq.front().second;
        qq.pop();
        
        int cRy = pos[0]; // current ry
        int cRx = pos[1];
        int cBy = pos[2];
        int cBx = pos[3];
        int nRy, nRx, nBy, nBx;
        
        
        if (cRy == gy && cRx == gx) {
            ans = k;
            break;
        }
        
        for (int dir=0; dir<4; dir++) {
            pair<int, int> newPos;
            bool isRedFirst = false;
            if (dir==0) { // 상
                if (cRy > cBy) { // y값이 작은공부터 먼저 이동
                    newPos = move(cBy, cBx, dir);
                } else {
                    newPos = move(cRy, cRx, dir);
                    isRedFirst = true;
                }
            } else if (dir==1) { // 우
                if (cRx > cBx) { // x값이 큰 공부터 먼저 이동
                    newPos = move(cRy, cRx, dir);
                    isRedFirst = true;
                } else {
                    newPos = move(cBy, cBx, dir);
                }
            } else if (dir==2) { // 하
                if (cRy < cBy) { // y값이 큰 공부터 먼저 이동
                    newPos = move(cBy, cBx, dir);
                } else {
                    newPos = move(cRy, cRx, dir);
                    isRedFirst = true;
                }
            } else if (dir==3) { // 좌
                if (cRx < cBx) { // // x값이 작은공부터 먼저 이동
                    newPos = move(cRy, cRx, dir);
                    isRedFirst = true;
                } else {
                    newPos = move(cBy, cBx, dir);
                }
            }
            
            if (isRedFirst) { // 빨간공이 먼저 이동한 경우
                nRy = newPos.first; nRx = newPos.second;
                
                if (nRy != gy || nRx != gx) // 빨간공이 구멍에 들어가지 않을 경우 임시적으로 1로 설정
                    map[nRy][nRx] = 1;
                
                newPos = move(cBy, cBx, dir);
                nBy = newPos.first; nBx = newPos.second;
                
            } else {
                nBy = newPos.first; nBx = newPos.second;
                map[nBy][nBx] = 2;
                
                newPos = move(cRy, cRx, dir);
                nRy = newPos.first; nRx = newPos.second;
            }
            
            map[nRy][nRx] = 0;
            map[nBy][nBx] = 0;
            
            if (cRy == nRy && cRx == nRx && cBy == nBy && cBx == nBx) // 움직임이 없을 경우 큐에 추가하지 않는다.
                continue;
            
            if (k==10)
                continue;
            
            if (nBy != gy || nBx != gx) { // 파란색 공이 골인에 들어가지 않을경우에만 다음 queue에 insert!
                vector<int> temp(4);
                temp[0] = nRy; temp[1] = nRx; temp[2] = nBy; temp[3] = nBx;
                qq.push(make_pair(temp, k+1));
            }
            
        }
        
    }
    
    
    return ans;
}

int main(void) {
    int N, M;
    int blueY=0, blueX=0, redY=0, redX=0;
    scanf("%d %d", &N, &M);
    map.assign(N, vector<int>(M, -1));
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                map[i][j] = -1;
            } else if (c == 'O') {
                map[i][j] = 0;
                gy = i;
                gx = j;
            } else if (c == 'R') {
                map[i][j] = 0;
                redY = i;
                redX = j;
            } else if (c == 'B') {
                map[i][j] = 0;
                blueY = i;
                blueX = j;
            } else if (c == '.') {
                map[i][j] = 0;
            }
        }
    }
    
    printf("%d\n", go(redY, redX, blueY, blueX));
    return 0;
}
