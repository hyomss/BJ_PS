/*
�ð����⵵ : O(VE)
���� ����ġ�� �ִ� ���.
*/
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_N = 20010;

struct Node {
	int idx, w;

	friend bool operator < (Node a, Node b) {
		return a.w > b.w;
	}
};

int N, dist[MAX_N]; // �Ÿ� ����
vector <Node> adj[MAX_N]; // ���⼭ Node�� �������� �� �������� dist���̴�


int bellman(int s) {
	for (int i = 1; i <= N; ++i) dist[i] = INF;
	dist[s] = 0;


	bool updated; // Ʃ�׿ɼ�
	for (int re = 1; re <= N - 1; ++re) {
		updated = false; 
		for (int here = 1; here <= N; ++here) {	//	 ��� ��� Ž��
			for (int i = 0; i< (int)adj[here].size(); ++here) {
				int next = adj[here][i].idx;
				
				// ��������� �ִܰŸ� + ����~���� �̵��Ÿ� < ���������� �ִܰŸ�
				if (dist[here] != INF && dist[here] + adj[here][i].w < dist[next]) {	// �տ� INF������ INF��忡�� INF���� w=-10���� ���� ��� dest�� weight���� INF-10���� ������Ʈ�� �Ǿ������. �׷��� ������ �����ɷ� INF�� �����ϴµ� ������ INF-10���� ���� ���͹�����. 
					dist[next] = dist[here] + adj[here][i].w;
					updated = true; // ������Ʈ �ƴ��� Ȯ��
				}
			}
		}
		// ���� ������ �� ���� �ؾߵǰ� �ƴϸ� break;
		if (!updated) break; 
	}
	
	if(update == true) return -1; // ���� ����Ŭ 
	return 1;
}
