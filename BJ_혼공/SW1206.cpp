#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	for (int t = 1; t <= 10; t++) {
		int L;
		int arr[1010];

		cin >> L;
		for (int i = 0; i < L; i++) {
			cin >> arr[i];
		}

		int ans = 0;
		int maxl, maxr, maxt;
		for (int i = 2; i < L - 2; i++) {
			maxl = max(arr[i - 2], arr[i - 1]);
			maxr = max(arr[i + 1], arr[i + 2]);
			maxt = max(maxl, maxr);
			if (arr[i] > maxt) ans += arr[i] - maxt;
		}
		cout << "#"<<t<<" "<< ans << endl;
	}

	return 0;
}