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
    int people,budget,hotels,weeks,cost,beds;
    int menor = 500001;
    while(cin>>people){
        cin >> budget >> hotels >> weeks;
        for(int j = 0; j<hotels;j++){
            cin >> cost;                        
            for(int i =0; i<weeks;i++){
                cin >> beds;
                if(beds>=people){
                    int total = people*cost;
                    if(total<=budget){
                        if(total<menor) menor = total;
                    }
                }
            }
        }
        if(menor!=500001){cout << menor << endl;}
        else{cout << "stay home" << endl;}
        menor = 500001;
    }
}