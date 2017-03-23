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
	typedef pair<int,int> point;
	int rows, columns;
	int g1[1001][1001];
	int g2[1001][1001];
	point J;

	void bfs1(int row, int column){
	    queue<point> q;
	    g1[row][column] = 0;
	    q.push(point(row,column));
	    while(!q.empty()){
	        int r = q.front().first;
	        int c = q.front().second;
	        q.pop();
	        int d = g1[r][c]+1;
	        if(r-1>=0 && g1[r-1][c]!=-1){
	            if(g1[r-1][c]>d || g1[r-1][c]==0){
	                g1[r-1][c] = d;
	                q.push(point(r-1,c));
	            }
	        }
	        if(r+1<rows && g1[r+1][c]!=-1){
	            if(g1[r+1][c]>d || g1[r+1][c]==0){
	                g1[r+1][c] = d;
	                q.push(point(r+1,c));
	            }
	        }
	        if(c-1>=0 && g1[r][c-1]!=-1){
	            if(g1[r][c-1]>d || g1[r][c-1]==0){
	                g1[r][c-1] = d;
	                q.push(point(r,c-1));
	            }
	        }
	        if(c+1<columns && g1[r][c+1]!=-1){
	            if(g1[r][c+1]>d || g1[r][c+1]==0){
	                g1[r][c+1] = d;
	                q.push(point(r,c+1));
	            }
	        }
	        if(d==1) g1[row][column] = -2;
	    }
	}
	
    void bfs2(int row, int column){
	    queue<point> q;
	    g2[row][column] = 0;
	    q.push(point(row,column));
	    while(!q.empty()){
	        int r = q.front().first;
	        int c = q.front().second;
	        q.pop();
	        int d = g2[r][c]+1;
		        if(r-1>=0 && g2[r-1][c]!=-1){
	            if(g2[r-1][c]>d || g2[r-1][c]==0){
	                g2[r-1][c] = d;
	                q.push(point(r-1,c));
	            }
	        }
	        if(r+1<rows && g2[r+1][c]!=-1){
	            if(g2[r+1][c]>d || g2[r+1][c]==0){
	                g2[r+1][c] = d;
	                q.push(point(r+1,c));
	            }
	        }
	        if(c-1>=0 && g2[r][c-1]!=-1){
	            if(g2[r][c-1]>d || g2[r][c-1]==0){
	                g2[r][c-1] = d;
	                q.push(point(r,c-1));
	            }
	        }
	        if(c+1<columns && g2[r][c+1]!=-1){
	            if(g2[r][c+1]>d || g2[r][c+1]==0){
	                g2[r][c+1] = d;
	                q.push(point(r,c+1));
	            }
	        }
	        if(d==1) g2[row][column] = -2;
	    }
	}

	void read(){
	    string str;
        vector<point> v1,v2;
	    for(int i=0;i<rows;++i){
	        cin >> str;
	        for(int j=0;j<columns;++j){
	            if(str[j]=='#') {g1[i][j]=-1; g2[i][j]=-1;}
	            if(str[j]=='F') {g1[i][j]=-2;v1.push_back(point(i,j));}
	            if(str[j]=='J') {g2[i][j]=-2;v2.push_back(point(i,j));J=point(i,j);}
	        }
	    }
	    for(int i = 0;i<v1.size();++i) bfs1(v1[i].first,v1[i].second);
        for(int i = 0;i<v2.size();++i) bfs2(v2[i].first,v2[i].second);
	}
	
    vector<int> verify(){
            bool possible = false;
            vector<int> v;
			int a = J.first;
			int b = J.second;
			if(a==0 || b==0 || a==rows-1 || b==columns-1){
				v.push_back(0);
				return v;
			}
            for(int i = 0;i<columns;++i){
                if(g2[0][i]>0){
                    if(g2[0][i]<g1[0][i] || g1[0][i]==0) v.push_back(g2[0][i]);}} 
            for(int i = 0;i<rows;++i){
                if(g2[i][columns-1]>0){
                    if(g2[i][columns-1]<g1[i][columns-1] || g1[i][columns-1]==0) v.push_back(g2[i][columns-1]);}}
            for(int i = 0;i<columns;++i){
                if(g2[rows-1][i]>0){
                    if(g2[rows-1][i]<g1[rows-1][i] || g1[rows-1][i]==0) v.push_back(g2[rows-1][i]);}}
            for(int i = 0;i<rows;++i){
                if(g2[i][0]>0){
                    if(g2[i][0]<g1[i][0] || g1[i][0]==0) v.push_back(g2[i][0]);}} 
            return v;
    }
	main(){
	    int test;
	    cin >> test;
	    while(test--){
	        cin >> rows >> columns;
	        for(int i =0;i<rows;++i) for(int j=0;j<columns;++j){g1[i][j]=0;g2[i][j]=0;}
	        read();
	        vector<int> v = verify();
            if(v.empty()){
                cout << "IMPOSSIBLE" << endl;
            }else{
                sort(v.begin(),v.end());
                cout << v[0]+1 << endl;
            }
            v.clear();
	    }
	}
