#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

int size;
vector<int> topo;

void dfs(vector<int> graph[],int node,bool visited[],bool top){
    visited[node] = true; 
    for(int i =0; i<graph[node].size();i++){
        int v = graph[node][i];
        if(!visited[v]){  
            dfs(graph,v,visited,top);
        }
    }
    if(top) topo.push_back(node);
}

main(void){
    int arcs, from,to,test;
    int times = 0;
    int cases = 1;
    cin >> test;
    while(test--){
        cin >> size >> arcs;
        vector<int> graph[size+1];
        while(arcs--){
            cin >> from >> to;
            graph[from].push_back(to);
        }
        bool visited[size+1];
        for(int i = 0;i<size+1;++i) visited[i]=false;
        for(int i = 1; i<size+1;++i){
            if(!visited[i]) dfs(graph,i,visited,true);
        }
        for(int i = 0;i<size+1;++i) visited[i]=false; 
        reverse(topo.begin(),topo.end());
        for(int i = 0; i < topo.size();i++){
            if(!visited[topo[i]]){dfs(graph,topo[i],visited,false); times++;}
        }
        printf("Case %d: %d\n",cases,times);
        cases++;
        times = 0;
        topo.clear();
   }
}