#include <stdio.h>
#include <stdlib.h>
int dfs(int i, int j, int m, int n);

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
            visited[i][j] = -1;
        }
    }
    visited[m-1][n-1] = 1;
    count = dfs(0,0,m,n);
    printf("%d\n",count);
    
    for(int i = 0;i < m ; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
    
}

int dfs(int i, int j, int m, int n){
    
    int pos_x, pos_y;
    
    if(i == m-1 && j == n-1){
        return 1;
    }
    
    if(visited[i][j] == -1){
        visited[i][j] = 0;
        for(int k = 0; k <4; k++){
            pos_x = j + x[k];
            pos_y = i + y[k];
            
            if(pos_x >= 0 && pos_x < n && pos_y >= 0 && pos_y < m){
                if(p[pos_y][pos_x] < p[i][j]){
                    visited[i][j] += dfs(pos_y, pos_x, m, n);
                }
            }
        }
    }
    return visited[i][j];
}
