#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

typedef pair<int,int> edge;
typedef pair<int,int> dist_node;

#define maxsize 20005
const int INF = 1 << 30;

vector <edge> g[maxsize];
int d[maxsize];
int p[maxsize]; // p is used to verify if there is a route to the desired node

void dijkstra(int s, int n){
    for(int i =0;i<=n;++i){d[i]=INF;p[i]=-1;}
    priority_queue <dist_node, vector<dist_node>, greater<dist_node> > q;
    d[s]=0;
    q.push(dist_node(0,s));
    while(!q.empty()){
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();
        if(dist>d[cur]) continue;
        for(int i=0;i<g[cur].size();++i){
            int next = g[cur][i].first;
            int w = g[cur][i].second;
            if(d[cur]+w <   d[next]){
                d[next] = d[cur] + w;
                p[next] = cur;
                q.push(dist_node(d[next],next));
            }
        }
    }
}

main(){
    int test, size,arcs,start,terminate;
    cin >> test;
    int cont = 1;
    while(test--){
        cin >> size >> arcs >> start >> terminate;
        for(int i =0;i<=size;++i) g[i].clear();
        while(arcs--){
            int from,to,weight;
            cin >> from >> to >> weight;
            g[from].push_back(edge(to,weight));
            g[to].push_back(edge(from,weight));
        }
        dijkstra(start,size);
        if(p[terminate]==-1){
            printf("Case #%d: unreachable\n",cont);
        }else{
            printf("Case #%d: %d\n",cont,d[terminate]);
        }
        cont++;
    }
}