/*
BFSDFS
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N =	1010;
int N, M, root;
vector <int> adj[MAX_N];
int visit[MAX_N];

void dfs(int node) {
	visit[node] = 1;
	cout << node << " ";

	int nxt;
	for (int i = 0; i < (int)adj[node].size(); i++) {
		nxt = adj[node][i];
		if (visit[nxt] == 1) continue;
		else dfs(nxt);
	}
}

void bfs(int start) {
	int visit[MAX_N] = { 0 }; // ÃÊ±âÈ­

	queue <int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int node = q.front();
		cout << node << " ";

		q.pop();
		int nxt;
		for (int i = 0; i < adj[node].size(); i++) {
			nxt = adj[node][i];
			if (visit[nxt] == 0) {
				q.push(nxt);
				visit[nxt] = 1;
			}
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> N >> M >> root;

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(root);
	cout << endl;
	bfs(root);


	return 0;
}