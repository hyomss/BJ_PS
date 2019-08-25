/*
DP
*/
#include <iostream>
using namespace std;
int T, N;

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	long long dp[101] = { 0,1,1,1,2,2,3,4,5,7, };

	for (int j = 0; j < T; j++) {
		cin >> N;
		for (int i = 10; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		cout << dp[N] << endl;
	}
	return 0;
}