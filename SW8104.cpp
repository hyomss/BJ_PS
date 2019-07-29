#include <iostream>
#include <algorithm>
using namespace std;

int T, N,K;
int arr[21];

int sigma(int n, int k) { // 1~n*k±îÁö
	return  ((1 + (n*k)) * (n*k) / 2); // (1+n) * n  / 2
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		cout << "#" << i + 1 << " ";
		if (N % 2 == 0) {	//Â¦¼ö
			for (int i = 0; i < K; i++) {
				int sum = sigma(N, K);
				cout << sum / K << " ";
			}
		}
		else { //È¦¼ö
			int sum = sigma(N - 1, K);
			for (int i = 0; i < K; i++) {
				cout << sum / K + ((N - 1)*K + (i + 1)) << " ";
			}
		}
	}



	return 0;
}