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

vector<int> g[105];
bool visited[105];
vector<int> topo;

void dfs(int node){
    visited[node] = true;
    for(int i = 0; i < g[node].size();++i){
        int v = g[node][i];
        if(!visited[v]) dfs(v);
    }
    topo.push_back(node);
}

main(){
    int from, to, size, arcs;
    while(true){
        cin >> size >> arcs;
        if(size==0 && arcs==0) break;
        for(int i=0;i<size+1;++i) visited[i] = false;
        while(arcs--){
            cin >> from >> to;
            g[from].push_back(to);
        }  

        for(int i=1;i<size+1;++i){ if(!visited[i]) dfs(i);}

        reverse(topo.begin(),topo.end());
        
        for(int i = 0; i<topo.size()-1;++i) printf("%d ",topo[i]);
        printf("%d\n",topo[topo.size()-1]);
        topo.clear();
        for(int i=0;i<size+1;++i) g[i].clear();
    }  
   
}
