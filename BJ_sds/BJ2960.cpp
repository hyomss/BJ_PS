#include<iostream>
#include<cstdio>
using namespace std;


const int MAX_N = 1000;
int a[MAX_N];
int N, K, cnt;

void eratos() {
	cnt = 0;
	for (int i = 2; i <= N; ++i) {
		a[i] = i;
	}
	for (int i = 2; i <= N; ++i) {
		if (a[i] != i) continue;
		if (i*i > N) break;
		for (long long j = i; j <= N; j += i) {
			if (a[j] != -1) {	// ����� ����
				a[j] = -1; // �����
				cnt++;
				if (cnt == K) { cout << j;  break; }
			}
		}
	}
	//for (int i = 2; i < N; ++i) {
	//	if (a[i] == i) cout << i;
	//}
}

int main() {
	cin >> N >> K;
	eratos();

	return 0;
}