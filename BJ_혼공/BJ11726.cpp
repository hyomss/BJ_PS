/*
DP
*/
#include <iostream>
using namespace std;
const int MAX_N = 1010;
int arr[MAX_N];
int N;


int main() {
	cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= N;i++	) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 10007;
	}
	cout << arr[N];


	return 0;
}