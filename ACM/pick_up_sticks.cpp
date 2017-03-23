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

#define maxsize 1000001

vector<int> g[maxsize];
bool visited[maxsize];
bool ways[maxsize];
vector<int> topo;
bool c = false;

bool dfs(int node){
    visited[node]=true;
    ways[node]=true;
    for(int i=0;i<g[node].size();++i){
        int v = g[node][i];
        if(ways[v]){c=true;break;}
        if(!visited[v]) dfs(v);
    }
    ways[node] = false;
    return c;
}

bool cycle(int size){
    for(int i=1;i<=size;++i){
        if(!visited[i]){
            bool l = dfs(i);
            if(l) return true;
        }
    }
    return false;
}

void dfstopo(int node){
    visited[node]=true;
    for(int i=0;i<g[node].size();++i){
        int v = g[node][i];
        if(!visited[v]) dfstopo(v);
    }
    topo.push_back(node);
}

void toposort(int size){
    for(int i=1;i<=size;++i){visited[i]=false;ways[i]=false;}
    topo.clear();
    for(int i=1;i<=size;++i){
        if(!visited[i]) dfstopo(i);
    }
    reverse(topo.begin(),topo.end());
    for(int i=0;i<topo.size();++i){
        cout << topo[i] << endl;
    }
}

main(){
    int from,to,size,arcs;
    while(true){
        cin >> size >> arcs;
        for(int i=1;i<=size;++i){g[i].clear();visited[i]=false;ways[i]=false;}
        if(!size && !arcs) break;
        while(arcs--){
            cin >> from >> to;
            g[from].push_back(to);
        }
        if(cycle(size)){
            cout << "IMPOSSIBLE" << endl;
        }else{
            toposort(size);
        }
        c=false;
    }
}