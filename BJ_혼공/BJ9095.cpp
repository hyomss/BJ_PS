/*
DP
*/
#include <iostream>
using namespace std;
int dp[12];

int main() {
	int T, N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 4; j <= N; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[N] << endl;
	}
	return 0;
}