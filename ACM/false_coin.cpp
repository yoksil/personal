#include <vector>
#include <iostream>

using namespace std;

#define maxn 105
bool coin_total[maxn];
bool coin_temp[maxn];

main(){
    int test;
    cin >> test;
    while(test--){
        int coins , weights;
        cin >> coins >> weights;
        for(int i=0;i<coins;++i) coin_total[i] = false;
        while(weights--){
            int numbers;
            cin >> numbers;  // The numbres of coins in each side
            for(int i=0;i<coins;++i) coin_temp[i] = false;
            for(int i=0;i<numbers*2;++i){
                int actual;
                cin >> actual;  // The actual coin
                coin_temp[actual-1] = true;
            }
            char value;
            cin >> value;
            if(value=='='){
                for(int i =0;i<coins;++i) if(coin_temp[i]) coin_total[i]=true;
            }else{
                for(int i=0;i<coins;++i){
                    if(!coin_temp[i] && !coin_total[i]) coin_total[i]=true;
                }
            }
        }
        
        int fake;
        int times = 0;
        for(int i=0;i<coins;++i){
            if(coin_total[i]==false){fake = i+1; times++;}
            if(times>1) break;
        }
        if(times<2) cout << fake << endl;
        else cout << "0" << endl;
        if(test!=0) cout << endl;
    }
}