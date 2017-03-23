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

main(){
    int test;
    cin >> test;
    int i = test;
    int index = 0;
    bool finish=false;
    vector<string> v;
    string str;
    while(test--){
        cin >> str;
        v.push_back(str);
    }
    while(true){
        for(int j=0;j<4;j++){
            cout << v[index] <<": Happy" << endl; index++;
            if(index==i){finish=true; index=0;}
            cout << v[index] <<": birthday" << endl; index++;
            if(index==i){finish=true; index=0;}
            cout << v[index] <<": to" << endl; index++;
            if(index==i){finish=true; index=0;}
            if(j==2){ cout << v[index] <<": Rujia" << endl; index++;}
            else{ cout << v[index] <<": you" << endl; index++;}
            if(index==i){finish=true; index=0;}
        }
        if(finish) break;
    }
}