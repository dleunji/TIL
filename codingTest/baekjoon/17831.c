#include <stdio.h>
#include <vector>
using namespace std;

int salesperson[200001];
int parent[200001];
int dp[200001][2];
vector <int> tree[200001];

int tree_dp(int now, int next);
int max(int n1, int n2);

int main(void){
    int n;
    scanf("%d",&n);
    
    for(int i = 2; i <= n;i++){
        scanf("%d",&parent[i]);
        tree[parent[i]].push_back(i);
    }
    for(int i = 1; i <= n;i++){
        scanf("%d",&salesperson[i]);
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 2;j++){
            dp[i][j] = -1;
        }
    }

    printf("%d\n",tree_dp(1,0));
}

int tree_dp(int now, int mentor){
    int child = 0;
    
    if(dp[now][mentor] != -1)
        return dp[now][mentor];
    //부모 노드와 멘토링 맺을 때
    if(mentor == 1){
        dp[now][mentor] = 0;
        for(int i = 0;i<tree[now].size();i++){
            child = tree[now][i];
            dp[now][mentor] += tree_dp(child,0);
        }
    }
    //부모노드와 멘토링을 맺지 않을 때
    else if(mentor == 0){
        int alone = 0;
        int syn = 0;
        dp[now][mentor] = 0;
        for(int i = 0;i<tree[now].size();i++){
            child = tree[now][i];
            alone += tree_dp(child,0);
        }
        for(int i = 0;i<tree[now].size();i++){
            child = tree[now][i];
            syn = alone - tree_dp(child,0) + tree_dp(child,1)
            + salesperson[child] * salesperson[now];
            //자식 노드 중 멘토링 관계 시너지가 가장 높은 경우를 고른다.
            dp[now][mentor] = max(dp[now][mentor], syn);
        }
        //아무와도 멘토링 관계를 맺지 않거나, 자식 노드와 시너지를 내는 경우 중 가장 값이 큰 선택.
        dp[now][mentor] = max(dp[now][mentor],alone);
    }
    return dp[now][mentor];
}

int max(int n1, int n2){
    if(n1 >= n2)
        return n1;
    else
        return n2;
}

