/*
������
�ð����⵵ = DFS�� ����. O(N+E)

< ������ �Ʒ��� Ʈ��ó�� ��ġ�غ��� ���߿� �湮�� ��尡 �Ʒ��� ���ٴ� ���� �̿� >
��� A�Ʒ����� ���� ����Ǵ� ���� �ִٸ� �� ������ A���� ���� -> �̷� ������ ������ A�� ��� �׷��� ������ X
���� A�� �ڽ��� ������ ���� ���� ��� (���� ������ �湮�� �������״ϱ� �� ���� ���� node num)�� ����
���翡 ���� low�� �����Ѵٴ°� ���� ���� ��� num�� �����Ѵٴ� ����

�̷��� low���� �����Ҷ� �ڽĿ��Լ� ���޹��� �� >= ���ڽ� �̸� ������
�ٸ� ��Ʈ�� ��� ���ް� == ��Ʈ ���� �ڽ��� �� �̻��� ���� ������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 10010;
vector <int> adj[MAX_V];

int found[MAX_V]; // �湮�� ����
int found_num = 0;
bool cut[MAX_V]; // ���������� ����

// here : ���� Ž������ ��ġ
// return : ���� Ž������ ��带 ��Ʈ�� �ϴ� sub graph�� �湮�� �� �ִ� �ֻ��� ��ġ(low)
int dfs(int here, bool is_root) {
	found[here] = ++found_num;	//	1���� ����

	int low = found[here]; // low�� �ʱⰪ�� �湮�����̶� ����

	int next, child = 0;
	for (int i = 0; i < (int)adj[here].size(); ++i) {
		next = adj[here][i];

		if (found[next] == 0) { // �̹湮 ���. dfs Ž��
			++child;
			int sub = dfs(next, false); // sub Node�� ���� �ֻ�������ȣ
			if (!is_root && sub >= found[here]) { // ������尡 ������ ������ �ٶ󺸸�
				//������
				cut[here] = true;
			}
			if (sub < low) low = sub; // low ����
		}

		else { // �̹� �湮�� ���. �翬�� ���纸�� ����.
			if (low > found[next]) low = found[next];
		}
	}
	if (is_root && child >= 2) cut[here] = true;
	return low;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//memset(found, 0, sizeof(found)); 
	int V, E;
	scanf("%d %d", &V, &E);

	int a, b, root;
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//// �̰� ���ص� ���ư��⵵ �ϴ���.. �̰� �ʿ䰡 ���� �� ���⼭ ������ �湮 ������ �������� �����ϱ�.
	//for (int i = 1; i <= V; ++i) {
	//	sort(adj[i].begin(), adj[i].end());
	//}

	// �̰� �׷����� ������ �ȵ������� �ʿ���. 
	for(int i=1; i<=V;i++)
		if(!found[i])
			dfs(i, true);

	
	int ans = 0;
	for (int i = 1; i <= V ; ++i) {
		if (cut[i]) ans++;
	}
	cout << ans << endl;

	for (int i = 1; i <= V; ++i) {
		if (cut[i]) cout << i << " " ;
	}
	

	return 0;
}
