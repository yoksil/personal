#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

main(){
    map<string,int> m;
    string line;
    int iteration;
    vector<int> vect;
    scanf("%d\n\n",&iteration);
    while(iteration--){
        m.clear();
        vect.clear();
        int size = 0;
        int i = 0;
        while(getline(cin, line)){
            if(line.empty()) break;
            if(m.count(line)==1){vect[m[line]] = vect[m[line]] + 1;}
            else{
                m[line] = i;vect.push_back(1);i++;
            }
            size++;
        }
        for (map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it){
            float cap = (float)vect[it->second]*100/size;
            cout << it->first;
            printf(" %.4f\n",cap);
        }
        if (iteration > 0){
			printf("\n");
		}
    }
}