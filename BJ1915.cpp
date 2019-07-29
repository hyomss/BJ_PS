/*
DP
로직 못 짬.. 근데 이문제에나 쓸수 있을거같은뎅
*/

#include <iostream>
using namespace std;
int N, M;
char arr[1001][1001];
int a[1001][1001] = { 0 };
int dp[1001][1001] = { 0 };

int Min(int a, int b, int c) {
	a = a < b ? a : b;
	return a < c ? a : c;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		for (int j = 1; j <= M; j++) {
			a[i][j] = arr[i][j-1] - '0';
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (a[i][j] == 1) {
				dp[i][j] = Min(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]) + 1;
				if (ans < dp[i][j]) ans = dp[i][j];
			}
		}
	}

	cout << ans*ans << endl;

	return 0;
}