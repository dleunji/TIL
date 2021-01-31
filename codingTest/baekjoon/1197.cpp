#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void kruskal(void);
int Find(int a);
void Union(int a, int b);

//weight , starting vertex, end vertex
priority_queue<pair<int, pair<int,int>>> edges;
int parent[10001];
int V,E;
int cnt = 0;
int sum = 0;

int main(void){
    int a, b, weight;
    cin >> V >> E;
    
    for(int i = 0;i < E;i++){
        cin >> a >> b >> weight;
        edges.push(make_pair(-weight, make_pair(a,b)));
    }
    kruskal();
}

void kruskal(void){
    int weight;
    int a,b;
    for(int i = 1; i <= V;i++){
        parent[i] = i;
    }
    while(cnt != V-1){
        weight = - edges.top().first;
        a = edges.top().second.first;
        b = edges.top().second.second;
        if(Find(a) != Find(b)){
            sum += weight;
            cnt++;
            Union(a,b);
        }
        edges.pop();
    }
    cout << sum << '\n';
}

int Find(int a){
    if(a == parent[a]){
        return a;
    }
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    if(a != b)
        parent[b] = a;
}
