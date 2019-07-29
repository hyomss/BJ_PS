/*
lca구할 떄 parents를 [자식][2^n]부모를 2차원 배열로 저장해서 쭉쭉 올라가면 빠르게 구하도록 한다
p[7][6] = [p[7][5]][5] -> 즉 64칸 올라간 부모는 32칸 올라간 부모의 32칸 올라간 부모. 이런식으로 memoization
100칸 위를 구해야한다면 64+32+. . 하면 lgN안에 도달 가능
이때 root보다 더 위로 올라가게 되면 초기값이 0이기 때문에 어차피 안올라간다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int LGN = 13;
const int MAX_N = 10000;
vector<int> adj[MAX_N];	// 인접 리스트
int lv[MAX_N], parent[MAX_N][LGN],v[MAX_N];

// 전처리 과정
void dfs(int here){
	v[here] = 1;
	int next;	// 이거 선언안하고 그냥 adj로 코드쓰면 메모리 조금 아낄 수 있다.
	for (int i = 0; i < (int)adj[here].size(); ++i) {
		next = adj[here][i];
		if (v[next]) continue;

		lv[next] = lv[here] + 1;

		parent[next][0] = here;
		for (int j = 1; j < LGN; ++j) { // dfs 도는 도중에 부모 정보도 같이 전달

			parent[next][j] = parent[parent[next][j - 1]][j - 1];
		}

		dfs(next);
	}
}

int lca(int a, int b) {
	int tmp;
	if (lv[a] > lv[b]) {	// 아래 진행을 위해 늘 a<b로 고정
		swap(a, b);
	}

	for (int i = LGN; i >= 0; i--) {
		if (lv[b] - lv[a] >= (1 << i)) {
			b = parent[b][i]; // b에서 2^i만큼 위에 있는 부모로 한번에 점프
		}
	}

	if (a == b) return a;	//	같아지면 return

	for (int i = LGN; i >= 0; --i) {
		if (parent[a][i] != parent[b][i]) {	//	부모가 다르면 아직 갈라져있음. 올라가도 된다
			a = parent[a][i];
			b = parent[b][i];
		}
	}
}

int main() {
	freopen("Input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	lv[1] = 0;	// root node
	dfs(1); // 아무점이나 root로 그냥 지정



	return 0;
}