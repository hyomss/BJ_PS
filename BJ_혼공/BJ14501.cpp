/*
DP
*/
#include <iostream>
#include <algorithm>
using namespace std;

int T[20];
int P[20];
int N;
int dp[20];

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		dp[i] = P[i];
	}

	for (int i = 2; i <= N; i++) {

		for (int j = 1; j < i; j++) {

			if (i - j >= T[j]) {
				dp[i] = max(P[i] + dp[j], dp[i]);
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			if (max < dp[i]) {
				max = dp[i];
			}
		}
	}
	cout << max;

	return 0;
}