#include <iostream>

using namespace std;

main(){
	int times, a, b;
	cin >> times;
	while(times--){
		cin >> a >> b;
		if(a>b){
			cout <<">"<< endl;
		}else if(a<b){
			cout << "<" << endl;
		}
		else{
			cout << "=" << endl;
		}
	}
}
