#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

queue <int> arr;
queue <int> tmp_arr;
int cnt[105] = { 0, };
queue <int> ans;

int outnum() {
	int max = -1, ret;
	for (int i = 0; i < 10; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			ret = i;
		}
	}
	return ret;
}

void queuechg(int out) {
	int cur = -1, twice = 0;
	while (!arr.empty()) {
		int cur = arr.front();
		arr.pop();
		if (cur == out & !twice) {
			twice++;
			continue;
		}
		tmp_arr.push(cur);
	}

	
}

int main() {
	freopen("input.txt", "r", stdin);

	int N, num;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i == 8) {
			int k = 0;
		}
		cin >> s;
		if (s[0] == 'e') {
			cin >> num;
			arr.push(num);
			cnt[num]++;
		}
		else if (s[0] == 'd') {
			int out = outnum();
			queuechg(out);
			cnt[out]--;
			//cout << out << " ";
			ans.push(out);
		}
	}

	while (!ans.empty()) {
		int cur = ans.front();
		ans.pop();
		cout << cur << " ";
	}



	return 0;
}