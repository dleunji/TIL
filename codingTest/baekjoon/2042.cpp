#include <iostream>

using namespace std;
typedef long long ll;
//자료형 주의
ll num[1000001];
ll tree[1000001 * 4];

ll init(int start, int end, int pos);
void update(int start, int end, int pos, int repos, int revalue);
ll sum(int start, int end, int pos, int from, int to);

int main(void){
    int m,n,k;
    int a,b,c;
    
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        cin >> num[i];
    }
    
    init(1,n,1);
    for(int i = 0;i < m + k; i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            update(1,n,1,b,c);
        }
        else {
            cin >> b >> c;
            cout << sum(1,n,1,b,c) << '\n';
        }
    }
    
}

ll init(int start, int end, int pos){
    if(start == end){
        return tree[pos] = num[start];
    }
    int mid = start + (end - start) / 2;
    tree[pos] = init(start, mid, pos * 2) + init(mid+1,end,pos * 2 + 1);
    return tree[pos];
}

void update(int start, int end, int pos, int repos, int revalue){
    if(start == end){//leaf node
        tree[pos] = revalue;
        return;
    }
    int mid = start + (end - start) / 2;
    if(start <= repos && repos <= mid){
        //If repos is in the left child, recurse on the left child
        update(start, mid, pos * 2, repos, revalue);
    }
    else{
        //If repos is in the right child, recurse on the right child
        update(mid+1, end, pos * 2+ 1, repos, revalue);
    }
    //Internal node will have the sum of both of its children
    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
ll sum(int start, int end, int pos, int from, int to){
    if(from > end || to < start){
        return 0;
    }
    if(from <= start && to >= end){
        return tree[pos];
    }
    
    int mid = start + (end - start) / 2;
    return sum(start, mid, pos * 2, from, to) + sum(mid + 1, end, pos * 2 + 1, from, to);
}
