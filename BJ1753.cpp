/*
���� �ƴ� ����ġ�� �ִ� �׷��� ���� -> ���ͽ�Ʈ�� �̿�

w = 10 �����̹Ƿ� �ʱⰡ��ġ = V*10 + 1�� ������ �ȴ�
** �� �������̿� ���� ���� ������ ���� ��� ó������ ������ ���� �ּ�/�ִ� ����ġ�� �����Ѵ�.

adj[s] = (e,w)�� �����Ѵ�.
������ �ƹ� �ִ��� Ȯ���� ���� hash, set ��� �̿밡��. 
f=s*100+e ���� �Լ��� ã�ư��� �ش���ġ�� bool�� ���� ����
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
const int MAX_N = 20010;

//vector <pair<int, int>> adj; // end, weight �����Ϸ���.  �Ʒ��� ���� �ǹ�
struct Node {
	int idx, w;

	friend bool operator < (Node a, Node b){
		return a.w > b.w;
	}
};

int N, dist[MAX_N]; // �Ÿ� ����
vector <Node> adj[MAX_N]; // ���⼭ Node�� �������� �� �������� dist���̴�
priority_queue<Node> pq;  // ���⼭ Node�� �� ���������� �Ÿ�

int dijkstra(int s, int e) {
	// init
	for (int i = 1; i <= N; ++i) dist[i] = INF;
	dist[s] = 0;
	pq.push({ s,0 });

	// ����
	int here_idx, here_w, next_idx, next_w;
	while (!pq.empty()) {
		// Ž���� ��� ã��
		here_idx = pq.top().idx;
		here_w = pq.top().w; // ť�� �� ������ w�� �� ������ �ּҰ�. dist�� ��� ���ŵǴ� ��. �׷��Ƿ� ���ؼ� ť�� �������� ���� ����
		pq.pop(); 

		// ��������. ���� ��� ���� ���� �ؾߵǸ� ť �����ñ��� �ؾ��ϹǷ� �̺κ� ����
		if (here_idx == e) return dist[e];

		if (here_w > dist[here_idx]) continue; // Ʃ�� �ɼ�
		
		// ���� ��忡�� �̿��� ������ �ּҰŸ� ����
		for (int i = 0; i < (int)adj[here_idx].size(); ++i) {
			next_idx = adj[here_idx][i].idx;
			next_w = adj[here_idx][i].w;

			// ������� �Ÿ� + ����~���� ��� �Ÿ� < ���� ��忡 ��ϵ� �ּҰŸ� �϶� ����
			if (dist[here_idx] + next_w < dist[next_idx]) {
				dist[next_idx] = dist[here_idx] + next_w;
				pq.push({ next_idx, dist[next_idx] }); // ����
			}
		}
	}

	// ���� ���� �ȵǰ� ������ return �ž���. ����� ��
	return -1;
}


int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int V, E;
	cin >> V >> E;
	int root, a, b, we;
	scanf("%d", &root);

	for (int i = 1; i <= E; ++i) {
		scanf("%d %d %d", &a, &b, &we);
		adj[a].push_back(Node{ b,we });
	}


	for (int e = 1; e <= V; ++e) {
		int ans = dijkstra(root, e);
		if ( ans != INF) cout << ans << endl; 
		else cout << INF << endl;
	}


	return 0;
}