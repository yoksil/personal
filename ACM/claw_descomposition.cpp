#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bipartite(vector<int> graph[], int size,int start){	
  vector<int> back(size+1);
  queue<int> q;
  int painted[size+1];
  for(int i = 0; i < size+1;i++){
  	painted[i] = 0;
  }
  q.push(start);
  int actualP = 1;
  int n;
  int colorActual;
  painted[start] = actualP;
  while(!q.empty()){
    n = q.front();
    actualP = painted[n];
    if(actualP==1){colorActual = 2;}else{colorActual=1;}
    q.pop();
    for(int i = 0; i < graph[n].size();i++){
      if(painted[graph[n][i]] == actualP) return false;
      if(painted[graph[n][i]] == 0){
        painted[graph[n][i]] = colorActual;
        q.push(graph[n][i]);
      }
    }
  }
  return true;	
}
main(void){
int size, arcs;
  while(true){
	  cin >> size;
	  if(size==0){break;}else{
		  vector<int> graph[size+1];	
		  int from, to;
		  cin >> from >> to;
		  int start = from;
		  graph[from].push_back(to);
		  graph[to].push_back(from);
      while(true){
		cin >> from >> to;
        if(from==0 && to==0) break;
		graph[from].push_back(to);
        graph[to].push_back(from);
      }
		    if(bipartite(graph,size,from)){
		      cout << "YES" << endl;
		    }
		    else{
		      cout << "NO" << endl;
		    }
		}
	}
}
