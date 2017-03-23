#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define maxn 105
#define edge pair<int, int>
#define point pair<int, int>
#define INF 1 << 30

int d[maxn];
vector<edge> g[maxn];
int limit, cell, cont; //Global variables to save the time limit ,the safe cell, and the numbers of mice

void dijkstra(int node,int size){
    for(int j = 0;j<=size;++j) d[j]=INF;
    d[node] = 0;
    priority_queue < point, vector<point>, greater<point> > q;
    q.push(point(0,node));
    while(!q.empty()){
        int w = q.top().first;
        int curr = q.top().second;
        q.pop();
        if(w>d[curr]) continue;
        for(int i=0; i<g[curr].size();++i){
            int nextN = g[curr][i].first;  //Next node
            int nextW = g[curr][i].second; //Next Weight
            if(d[curr]+nextW < d[nextN]){
                d[nextN] = d[curr] + nextW;
                q.push(point(d[nextN],nextN));
            }

        }
    }
}

main(){
    int test;
    cin >> test;
    int size, arcs;
    while(test--){
        limit = cell = cont = 0;
        cin >> size >> cell >> limit >> arcs;
        for(int i=0;i<=size;++i) g[i].clear();
        while(arcs--){
            int from, to , w;
            cin >> from >> to >> w;
            g[from].push_back(edge(to,w));
        }
        for(int i=1;i<=size;++i){
            dijkstra(i,size);
            if(d[cell]<=limit) cont++; //If the distance is less than the limit, then there is one more mouse
        }
        cout << cont << endl;
        if(test!=0) cout << endl;
    }
}