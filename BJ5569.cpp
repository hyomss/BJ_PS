/*
**********넘 어려워ㅠ 다시 확인
*/

/*
DP
점화식, 초기값, DP배열
*/
#include <iostream>
using namespace std;

int dp[101][101][2][2];	//	[i][j][dir][해당 dir로 움직인 횟수];
int w, h; // 100
int m = 100000;

int main() {
	cin >> w >> h;
	//(1,1) -> (w,h)
	
	for (int i = 2; i <= w; i++) dp[i][1][0][0] = 1;
	for (int i = 2; i <= h; i++) dp[1][i][1][0] = 1;

	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			dp[i][j][0][0] = dp[i - 1][j][0][0] + dp[i - 1][j][0][1] % m;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			dp[i][j][1][0] = dp[i][j - 1][1][0] + dp[i][j - 1][1][1] % m;
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			ans += dp[w][h][i][j];
	}
	cout << ans%m;

	return 0;
}