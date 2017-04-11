
/*
    위상정렬: 노드간의 선후관계가 있을 때 정렬하는 방법
    - 간선(i, j)가 존재한다면, 반드시 정점 i는 정점 j보다 먼저 정렬되야한다.
    - dfs를 이용하면 쉽게 위상정렬이 가능하다
    - dfs의 최종 방문순서를 연결 리스트에 넣은 후, 연결 리스트의 역순이 위상정렬의 결과가 된다.
*/
#include <iostream>
#define MAX_NODE 6

using namespace std;

int map[MAX_NODE+1][MAX_NODE+1];
int ans[MAX_NODE];
int ans_count=1;
bool visited[MAX_NODE+1];

void dfs(int here) {
    visited[here] = true;
    
    for (int there=1; there<=MAX_NODE; there++)
        if (!visited[there] && map[here][there]==1)
            dfs(there);
    
    ans[ans_count++] = here;
}

void topological_sort() {
    for (int i=1; i<=MAX_NODE; i++)
        visited[i] = false;
    
    for (int i=1; i<=MAX_NODE; i++) {
        if (!visited[i])
            dfs(i);
    }
    
    for (int i=MAX_NODE; i>=1; i--)
        cout << ans[i] << " ";
    
    cout << endl;
}

int main(void) {
    int edge_count;
    cin >> edge_count;
    
    for (int i=0; i<edge_count; i++) {
        int to, from;
        cin >> to >> from;
        map[to][from] = 1;
    }
    
    topological_sort();
    return 0;
}
