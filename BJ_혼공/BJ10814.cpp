/*
정렬
*/
#include <iostream>
#include <algorithm>
#include<string>
#include<vector>
using namespace std;

bool cmp(pair<int, string> a, pair <int, string> b)
{
	return a.first < b.first;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int N;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	scanf("%d", &N);
	vector<pair <int, string>> arr(N);
	/*
정렬
*/
#include <iostream>
#include <algorithm>
#include<string>
#include<vector>
	using namespace std;

	bool cmp(pair<int, string> a, pair <int, string> b)
	{
		return a.first < b.first;
	}


	int main(void)
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);

		int N;
		vector<pair<int, string>> v;

		cin >> N;
		v.resize(N);

		for (int i = 0; i < N; i++)
			cin >> v[i].first >> v[i].second;

		stable_sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++)
			cout << v[i].first << " " << v[i].second << "\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	stable_sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i].first << " " << arr[i].second << endl;
	}

	return 0;
}