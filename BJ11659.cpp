/*
DP
*/

#include <iostream>
using namespace std;
int N, M;
int arr[100001];
int sum[100001] = { 0 };

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i-1] + arr[i];
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}


	return 0;
}