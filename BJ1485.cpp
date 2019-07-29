#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;

int x[4];
int y[4];

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> x[j] >> y[j];
		}
		
		int num;
		vector<int> v;
		for (int r = 0; r < 4; r++) {
			for (int s = r + 1; s < 4; s++) {
				num = pow((x[r] - x[s]), 2) + pow((y[r] - y[s]), 2);
				v.push_back(num);
			}
		}
		sort(v.begin(), v.end());
		
		cout << (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5]) << endl;
		v.clear();
	}

	return 0;
}