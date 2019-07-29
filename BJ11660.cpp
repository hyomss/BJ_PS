/*
DP
*/
#include <iostream>
using namespace std;
int N, M;
int num, sum[1025][1025] = { 0 };

int main() {
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + num;
		}

	}
	int a1, a2, b1, b2;
	for (int r = 0; r < M; r++) {
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		printf("%d\n", sum[b1][b2] - sum[a1 - 1][b2] - sum[b1][a2 - 1] + sum[a1 - 1][a2 - 1]);
	}

	return 0;
}