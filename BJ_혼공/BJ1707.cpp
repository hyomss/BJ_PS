/*
DFS
*/
// 엄청 헤멤 
#include <iostream>
#include <vector>
#include <memory.h>
#include<string>
using namespace std;

string chk;
const int MAX_N = 20010;
int K, V, E;
vector <int> g[MAX_N];
int visit[MAX_N]; // 0,1,2

void dfs(int root) {
	int nxt;
	for (int i = 0; i < (int)g[root].size(); i++) {
		nxt = g[root][i];

		if (visit[nxt] != 0) { // 이미 방문함. 
			if (visit[root] == visit[nxt]) {
				chk = "NO";
				break;
			}
			continue;
		}
		if (visit[nxt] == 0) {
			visit[nxt] = 2;
			if (visit[root] == 2) {
				visit[nxt] = 1;
			}
			dfs(nxt);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> K;
	int e1, e2;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &V, &E);

		memset(visit, 0, sizeof(visit));
		memset(g, 0, sizeof(g));

		for (int j = 0; j < E; j++) {
			scanf("%d %d", &e1, &e2);
			g[e1].push_back(e2);
			g[e2].push_back(e1);
		}
		//visit[e1] = 1;
		chk = "YES";
		for (int i = 1; i <= V; i++) {		//	그래프 끊겼을 경우가 있다면 꼭 추가하기
			if (visit[i] == 0) {
				visit[i] = 1;
				dfs(i);
			}
		}
		cout << chk << endl;
	}
	return 0;
}