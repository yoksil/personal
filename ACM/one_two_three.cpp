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
    string str;
    cin >> test;
    while(test--){
        cin >> str;
        if(str.size()==5){
            cout << "3" <<endl;
        }
        else if((str[0]=='t' && str[1]=='w') || (str[1]=='w' && str[2]=='o') || (str[0]=='t' && str[2]=='o') ){
            cout << "2" << endl;
        }
        else if((str[0]=='o' && str[1]=='n') || (str[1]=='n' && str[2]=='e') || (str[0]=='o' && str[2]=='e') ){
            cout << "1" << endl;
        }
    }
}