#include <iostream>
#include <queue>
using namespace std;

queue <int> arr;

int main(){
		int N;
		int a;
		char inst[10];

		cin >> N;
		for (int i = 0; i < N; i++) {
			scanf("%s", inst);
			if (inst[1] == 'u') { //push
				cin >> a;
				arr.push(a);
			}
			else if (inst[0] == 'p' && inst[1] == 'o') {	//pop
				if (arr.empty()) cout << -1 << endl;
				else { 
					cout << arr.front() << endl; 
					arr.pop(); 
				}
			}
			else if (inst[0] == 'f') {	//front
				if (arr.empty()) cout << -1 << endl;
				else cout << arr.front() << endl;
			}
			else if (inst[0] == 'b') {	//back
				if (arr.empty()) cout << -1 << endl;
				else cout << arr.back() << endl;
			}
			else if (inst[0] == 's') {	//size
				cout << arr.size()<< endl;
			}
			else {	//empty
				if(arr.empty()) cout << 1<< endl;
				else cout << 0 << endl;
			}
		}

	return 0;
}