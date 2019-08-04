#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int arr[1000001];
int dp[1000001];
vector <int> tmp;

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	dp[1] = 1;
	for (int n = 2; n <= N; n++) {
		for (int k = 1; k < n; k++) {
			if (dp[k] < dp[n])
				tmp.push_back(dp[n]+1);
		}
		std::reverse(tmp.begin(), tmp.end());
		dp[n] = tmp[0];
		tmp.clear();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans;


	return 0;
}