/*
DFS
BFS
*/
#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;
int N;
string g[30];
int visit[30][30];
vector <int> cnt_house;
int cnt;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };

void dfs(int a, int b) {
	visit[a][b] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int gox = a + x[i], goy = b + y[i];
		if (visit[gox][goy]) { continue; }
		else if (gox >= 0 && goy >= 0 && gox < N && goy < N
			&& visit[gox][goy] == 0 && g[gox][goy] == '1') {
			dfs(gox, goy);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> g[i];
	}

	int totalnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && g[i][j] == '1') {
				totalnum++;
				cnt = 0;
				dfs(i, j);
				cnt_house.push_back(cnt);
			}
		}
	}
	sort(cnt_house.begin(), cnt_house.end());
	cout << totalnum << endl;
	for (int i = 0; i < cnt_house.size(); i++) {
		cout << cnt_house[i] << endl;
	}



	return 0;
}