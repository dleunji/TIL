#include <stdio.h>
#include <algorithm>
#define MAX 4000000

using namespace std;

int cards[MAX];
int tree[MAX];
int c[MAX];
int visited[MAX];
int cmp(int a,int b);
int construct(int num, int start, int end);
int find(int card,int pos);

int main(void){
    int m,n,k;
    int _card, card;
    
    scanf("%d %d %d",&n,&m,&k);
    
    for(int i=0;i<m;i++){
        scanf("%d",&cards[i]);
    }
    sort(cards, cards + m);
//    for(int i=0;i<n;i++){
//        printf("%d ",cards[i]);
//    }
//    printf("\n");
    construct(0,m-1,0);
//    for(int i = 0;i < 13;i++){
//        printf("%d ",tree[i]);
//    }
    for(int i=0;i<k;i++){
        scanf("%d",&c[i]);
    }
    
    for(int i=0;i<k;i++){
        _card = c[i] + 1;
        //printf("_card : %d\n",_card);
        while(_card<=n){
            card = find(_card,0);
            //printf("visited : %d\n",visited[card]);
            if(card !=0){
                printf("%d\n",card);
                break;
            }
            else
                _card++;
        }
    }
}
//Make Segment Tree
int construct(int start, int end, int pos){
    if(start == end){
        tree[pos] = cards[start];
        return cards[start];
    }
    int mid = start + (end - start) / 2;
    tree[pos] = construct(start,mid,pos*2+1) + construct(mid+1,end,pos*2+2);
    return tree[pos];
}

int find(int card,int pos){
    if(card > tree[pos])
        return 0;
    if(tree[pos] == 0)
        return 0;
    if(card == tree[pos]){
        if(tree[pos*2+1] + tree[pos*2+2] != tree[pos]){
            if(!visited[pos]){
                visited[pos] = 1;
                return tree[pos];
            }
        }
        else {
            return 0;
        }
    }
    int f1 = find(card,pos*2+1);
    int f2 = find(card,pos*2+2);
    if(f1!=0){
        return f1;
    }
    else if(f2!=0){
        return f2;
    }
    return 0;
}