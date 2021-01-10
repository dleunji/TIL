#include <stdio.h>
#include <algorithm>
#define MAX 4000000

using namespace std;

int cards[MAX];
int visited[MAX];
int c[MAX];

int main(void){
    int m,n,k;
    int card;
    
    scanf("%d %d %d",&n,&m,&k);
    
    for(int i=0;i<m;i++){
        scanf("%d",&card);
        cards[card] = 1;
    }
    
    for(int i = 0;i<k;i++){
        scanf("%d",&c[i]);
    }
    
    for(int i = 0;i<k;i++){
        card = c[i] + 1;
        while(card<=n){
            if(cards[card] == 1&& visited[card]==0){
                visited[card] = 1;
                printf("%d\n",card);
                break;
            }
            else{
                card++;
            }
        }
    }
}
