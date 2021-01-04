#include <stdio.h>
#include <vector>
using namespace std;

int ppl[10001];
int visited[10001];
int dp[2][10001];
vector <int> adj[10001];

void dfs(int num);
int max(int n1, int n2);

int main(void){
    int n;
    scanf("%d",&n);
    int v1, v2;
    
    for(int i = 0;i < n;i++){
        scanf("%d", &ppl[i+1]);
        visited[i+1] = -1;
    }
    for(int i = 0;i < n -1 ;i++){
        scanf("%d %d", &v1, &v2);
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    dfs(1);
    printf("%d\n", max(dp[0][1], dp[1][1]));
}

void dfs(int num){
    int adjacent;
    visited[num] = 0;
    for(int i = 0; i < adj[num].size();i++){
        adjacent = adj[num][i];
        if (visited[adjacent] != -1)
            continue;
        else {
            dfs(adjacent);
            //만약 현재 노드 선택 안 하면 인접 노드 선택할 수도, 안 할 수도
            dp[0][num] += max(dp[0][adjacent], dp[1][adjacent]);
            //만약 현재 노드 선택할 경우, 인접 노드의 값 선택 금지
            dp[1][num] += dp[0][adjacent];
        }
    }
    dp[1][num] += ppl[num];
}

int max(int n1, int n2){
    if(n1 >= n2)
        return n1;
    else
        return n2;
}

