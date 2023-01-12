#include<iostream>
#include<queue>
using namespace std;
vector<int>shortestDist(vector<int>adj[],int V){
queue<int>q;
bool visited[V];
int dist[V];
for(int i=0;i<V;i++){
 dist[i]=INT_MIN;
}
for(int i=0;i<V;i++){
 visited[i]=0;
}
q.push(0);
visited[0]=true;
while(q.empty()==false){
 int u=q.front();
 q.pop();
 for(int v:adj[u]){
   if(visited[v]==false){
     q.push(v);
     visited[v]=true;
     dist[u]=dist[v]+1;
   }
 }
}
}
