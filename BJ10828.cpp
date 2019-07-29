#include <iostream>
#include <string>
using namespace std;

int arr[10010];
int pos=-1;


int main() {
	int N;
	int a;
	char inst[10];

	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%s", inst);
		if (inst[1] == 'u') { //push
			cin >> a;
			arr[++pos] = a;
		}
		else if (inst[0] == 'p' && inst[1] == 'o') {	//pop
			if (pos== -1) {
				cout << -1 << endl;
			}
			else 
			cout << arr[pos--] << endl;
		}
		else if (inst[0] == 's') {	//size
			if (pos == -1) {
				cout << 0 << endl;
			}
			else cout << pos+1 << endl;
		}
		else if (inst[0] == 't') {	//top
			if (pos == -1) cout << -1 << endl;
			else cout << arr[pos] << endl;
		}
		else {	//empty
			if (pos == -1) {
				cout << 1 << endl;
			}
			else cout << 0 << endl;
		}
	}
	
	return 0;
}