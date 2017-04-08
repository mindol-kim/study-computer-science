/*
    https://www.acmicpc.net/problem/10875
*/

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> horizontal;
vector<pair<pair<int, int>, int>> vertical;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

/*
 return value: -1이면 부딪히는 경로가 없다는 의미
 그 외의 숫자일경우 부딪혔다는 의미이므로 해당 값까지만 더하고 더 이상 진행하지 않음을 의미
 */
int go_horizontal(int sy, int sx, int ey, int ex, int dir) {
    int ret = -1;
    
    if (dir == 1) { // '->'
        for (int i=0; i<horizontal.size(); i++) {
            int hori_y = horizontal[i].first;
            int hori_sx = horizontal[i].second.first;
            
            if (sy == hori_y && hori_sx >= sx && hori_sx <= ex) {
                int temp = hori_sx - sx;
                if (ret == -1 || ret > temp)
                    ret = temp;
            }
        }
        
        for (int i=0; i<vertical.size(); i++) {
            int vert_x = vertical[i].second;
            int vert_sy = vertical[i].first.first;
            int vert_ey = vertical[i].first.second;
            
            if (vert_x > sx && vert_x <= ex && sy >= vert_sy && sy <= vert_ey) {
                int temp = vert_x - sx;
                if (ret == -1 || ret > temp)
                    ret = temp;
            }
        }
    } else if (dir == 3) { // '<-'
        for (int i=0; i<horizontal.size(); i++) {
            int hori_y = horizontal[i].first;
            int hori_ex = horizontal[i].second.second;
            
            if (sy == hori_y && hori_ex >= ex && hori_ex <= sx) {
                int temp = sx - hori_ex;
                if (ret == -1 || ret > temp)
                    ret = temp;
            }
        }
        
        for (int i=0; i<vertical.size(); i++) {
            int vert_x = vertical[i].second;
            int vert_sy = vertical[i].first.first;
            int vert_ey = vertical[i].first.second;
            
            if (vert_x >= ex && vert_x < sx && sy >= vert_sy && sy <= vert_ey) {
                int temp = sx - vert_x;
                if (ret == -1 || ret > temp)
                    ret = temp;
            }
        }
    }
    
    return ret;
}

int go_vertical(int sy, int sx, int ey, int ex, int dir) {
    int ret = -1;
    
    if (dir == 0) { // up
        for (int i=0; i<vertical.size(); i++) {
            int vert_x = vertical[i].second;
            int vert_ey = vertical[i].first.second;
            
            if (vert_x == sx && vert_ey >= ey && vert_ey <= sy) {
                int temp = sy - vert_ey;
                if (ret == -1 || ret > temp)
                    ret = temp;
            }
        }
        
        for (int i=0; i<horizontal.size(); i++) {
            int hori_y = horizontal[i].first;
            int hori_sx = horizontal[i].second.first;
            int hori_ex = horizontal[i].second.second;
            
            if (hori_y >= ey && hori_y < sy && sx >= hori_sx && sx <= hori_ex) {
                int temp = sy - hori_y;
                if (ret == -1 || ret > temp)
                    ret = temp;
            }
        }
    } else if (dir == 2) {
        for (int i=0; i<vertical.size(); i++) {
            int vert_x = vertical[i].second;
            int vert_sy = vertical[i].first.first;
            
            if (vert_x == sx && vert_sy >= sy && vert_sy <= ey) {
                int temp = vert_sy - sy;
                if (ret == -1 || ret > temp)
                    ret = temp;
            }
        }
        
        for (int i=0; i<horizontal.size(); i++) {
            int hori_y = horizontal[i].first;
            int hori_sx = horizontal[i].second.first;
            int hori_ex = horizontal[i].second.second;
            
            if (hori_y > sy && hori_y <= ey && sx >= hori_sx && sx <= hori_ex) {
                int temp = hori_y - sy;
                if (ret == -1 || ret > temp)
                    ret = temp;
            }
        }
    }
    
    return ret;
    
}

int main(void) {
    int L, N;
    long long ans = 0;
    int cx, cy, dir;
    cin >> L >> N;
    
    cx=L, cy=L, dir=1;
    horizontal.push_back(make_pair(-1, make_pair(-1, 2*L+1)));
    horizontal.push_back(make_pair(2*L+1, make_pair(-1, 2*L+1)));
    vertical.push_back(make_pair(make_pair(-1, 2*L+1), -1));
    vertical.push_back(make_pair(make_pair(-1, 2*L+1), 2*L+1));
    
    while (N--) {
        int n; char c;
        cin >> n >> c;
        
        int nx, ny, ret=-1;
        ny = cy + (dy[dir] * n);
        nx = cx + (dx[dir] * n);
        
        if (dir == 1 || dir == 3) {
            ret = go_horizontal(cy, cx, ny, nx, dir);
            if (ret == -1) {
                ans += n;
                int startX=cx, endX=nx;
                if (dir == 3) {
                    startX=nx;
                    endX=cx;
                }
                horizontal.push_back(make_pair(cy, make_pair(startX, endX)));
            } else {
                ans += ret;
                break;
            }
        } else if (dir == 0 || dir == 2) {
            ret = go_vertical(cy, cx, ny, nx, dir);
            if (ret == -1) {
                ans += n;
                int startY=cy, endY=ny;
                if (dir == 0) {
                    startY=ny;
                    endY=cy;
                }
                
                vertical.push_back(make_pair(make_pair(startY, endY), cx));
            } else {
                ans += ret;
                break;
            }
        }
        
        if (c=='L') {
            dir = (dir==0) ? 3 : --dir;
        } else if (c=='R') {
            dir = (dir==3) ? 0 : ++dir;
        }
        
        cy = ny;
        cx = nx;
        
        if (N==0) {
            if (dir == 0) {
                ny = -1;
                nx = cx;
                
                ret = go_vertical(cy, cx, ny, nx, dir);
            } else if (dir == 1) {
                ny = cy;
                nx = 2*L+1;
                
                ret = go_horizontal(cy, cx, ny, nx, dir);
            } else if (dir == 2) {
                ny = 2*L+1;
                nx = cx;
                
                ret = go_vertical(cy, cx, ny, nx, dir);
            } else if (dir == 3) {
                ny = cy;
                nx = -1;
                
                ret = go_horizontal(cy, cx, ny, nx, dir);
            }
            
            ans += (ret == -1) ? n : ret;
        }
    }
    
    if (ans == 0) ans = L+1;
    cout << ans << endl;
    return 0;
}
