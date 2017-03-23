#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 105

vector<int> g[maxn];
bool visited[maxn];
bool firstCheck[maxn]; //The array that will save the initial state of the graph

void domain(int node){
    firstCheck[node] = true;
    for(int i =0;i<g[node].size();++i){
        int v = g[node][i];
        if(!firstCheck[v]) domain(v);
    }
}

void dfs_aux(int node){
    visited[node] = true;
    for(int i =0;i<g[node].size();++i){
        int v = g[node][i];
        if(!visited[v]) dfs_aux(v);
    }
}

void dfs(int size){
    for(int i =0;i<size;++i){
        visited[i] = true;
        if(i!=0) dfs_aux(0);
        bool dominators[size];
        for(int j=0;j<size;++j) dominators[j]=false;
        for(int j = 0;j<size;++j){
            if(firstCheck[j] && !visited[j]) dominators[j] = true; //dominators[i] means that the actual node, domain the node i
        }
        dominators[i] = firstCheck[i];
        for(int j = 0;j<size*2+1;++j){
            if(j==0 || j==size*2) cout << "+";
            else cout <<"-";
        }
        cout << endl;
        for(int j = 0;j<size*2+1;++j){
            if(j%2==0) cout << "|";
            else{
                if(dominators[(j-1)/2]==true){cout <<"Y";}
                else{ cout << "N"; }
            }
        }
        cout << endl;
        for(int j = 0; j <size;++j) visited[j] = false;
    }
    for(int j = 0;j<size*2+1;++j){
            if(j==0 || j==size*2) cout << "+";
            else cout <<"-";
    }
}

main(){
    int test, size, state;
    int cont = 1;
    cin >> test;
    while(test--){
        printf("Case %d:\n",cont);
        cont++;
        cin >> size;
        for(int i = 0; i <size;++i) firstCheck[i] = false;
        for(int i = 0; i <size;++i) visited[i] = false;
        for(int i = 0; i <size;++i) g[i].clear();

        for(int i = 0;i<size;++i){  // i represent the start node and j the end node
            for(int j = 0;j< size;++j){
                cin >> state;
                if(state==1){g[i].push_back(j);} //If read a 1 then add the arc to the graph i->j
            }
        }
        
      domain(0);
      dfs(size);
      cout << endl;
    }
}