/*
K=100 K^3µµ µÉµí

*/


#include <iostream>
#include <algorithm>

using namespace std;
int list[100010];

int main() {
	int K, N;
	int arr[110];
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		list[i] = arr[i];
	}
	int cnt = K;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			list[cnt++] = arr[i] * arr[j];
		}
	}
	sort(list, list + K* K);
	cout << list[N - 1];

	return 0;
}