/*
이항계수 + DP
*/

#include <iostream>
using namespace std;

const int MAX_N = 1002;
int arr[MAX_N][MAX_N] = { 0 };


int main() {
	int N, K;

	cin >> N >> K;


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (j == 0 || j == i) {
				arr[i][j] = 1;
				continue;
			}
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) %10007;
		}
	}

	cout << arr[N][K]  << endl;
	
	return 0;
}