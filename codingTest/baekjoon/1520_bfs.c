#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>
using namespace std;

int dfs(int i, int j, int m, int n);
void bfs(int i, int j, int m, int n);

int p[500][500];
int visited[500][500];

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main(void){
    int m , n;
    int count;
    scanf("%d %d", &m, &n);
    
    for(int i = 0;i < m ; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &p[i][j]);
            //visited[i][j] = -1;
        }
    }
    bfs(0,0,m,n);
    printf("%d\n",visited[m-1][n-1]);
    
}


void bfs(int a, int b, int m, int n){
    int pos_x, pos_y;
    int i, j;
    queue<pair<int,int>> q;
    
    q.push(make_pair(a,b));
    //visited[a][b] = 1;
    
    while(!q.empty()){
        pair <int,int> pair = q.front();
        q.pop();
        i = pair.first;
        j = pair.second;
    
        for(int k = 0; k <4; k++){
            pos_x = j + x[k];
            pos_y = i + y[k];

            if(pos_x >= 0 && pos_x < n && pos_y >= 0 && pos_y < m){
                if(p[pos_y][pos_x] < p[i][j]){
                    visited[pos_y][pos_x]++;
                    q.push(make_pair(pos_y, pos_x));
                }
            }
        }
            
    }
    
}