/*
DP
점화식, 초기값, DP배열
*/

#include <iostream>
using namespace std;

int dp[101][101];	//	[i][j][dir][해당 dir로 움직인 횟수];
int stat[101][101];
int w, h; // 100
int m = 100000;

int main() {
	int N;
	cin >> w >> h >> N;
	//(1,1) -> (w,h)

	for (int i = 2; i <= w; i++) dp[i][1][0] = 1;
	for (int i = 2; i <= h; i++) dp[1][i][1] = 1;

	for (int i = 2; i <= w; ) {
		for (int j = 2; j <= h; ) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (stat[i][j] == 1) { stat[i][j] == 0; j++; }
			else { stat[i][j] == 1; i++; }
		}
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
			ans += dp[w][h][i];
	}
	cout << ans%m;

	return 0;
}