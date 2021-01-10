#include <stdio.h>
#include <queue>
#include <vector>
#define INF 100000
using namespace std;

void dijkstra(int start,int n);

vector<pair<int,int>> list[1001];
int dist[1001];//임의의 출발점에서 해당 인덱스 마을까지의 거리 저장(출발 지점 조정 때마다 초기화 필요)

int main(void){
    int n, m ,x;
    int start, end, weight;
    int go, back;
    int max = 0;
    scanf("%d %d %d",&n,&m,&x);
    
    for(int i = 0;i < m;i++){
        scanf("%d %d %d",&start, &end, &weight);
        list[start].push_back(make_pair(end,weight));
    }
    
    for(int i = 1;i <= n; i++){
        if(i == x)
            continue;
        dijkstra(i,n);
        go = dist[x];
        dijkstra(x,n);
        back = dist[i];
        
        if(go + back > max){
            max = go + back;
        }
    }
    printf("%d",max);
}

void dijkstra(int start, int n){
    int weight, vertex;
    for(int i = 1;i <= n;i++){
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int,int>> pq;
    
    pq.push(make_pair(0,start));
    
    while(!pq.empty()){
        //pq는 maxheap이 기본값이므로, minheap을 구현하기 위해서 weight 음수화
        //경유하는 정점과 가중치
        weight = -pq.top().first;
        vertex = pq.top().second;
        pq.pop();
        
        if(dist[vertex] < weight)
            continue;
        
        for(int i = 0;i<list[vertex].size();i++){
            //경유정점에서 갈 수 있는 정점
            int adj = list[vertex][i].first;
            //경유했을 때의 총 가중치
            int adjWeight = list[vertex][i].second + weight;
            
            if(dist[adj] > adjWeight){
                //최단경로 업데이트
                dist[adj] = adjWeight;
                pq.push(make_pair(-adjWeight,adj));
            }
        }
    }
}
