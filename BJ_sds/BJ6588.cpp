#include <iostream>
using namespace std;

const int MAX_N = 1000001;
int arr[MAX_N];

void eratos(int N) {

	for (int i = 2; i < N; ++i) {
		arr[i] = i;
	}

	for (int i = 2; i < N; ++i) {
		if (arr[i] != i) continue;
		if ((long long)i * i > N) break;
		for (int j = i * i; j < N; j += i) {
			if (arr[j] == j) arr[j] = i;
		}
	}
}

void goldbach(int n) {
	int mid = n >> 1;
	for (int i = 3; i <= mid; ++i) {
		if (arr[i] == i && arr[n - i] == n - i) {
			printf("%d = %d + %d\n", n, i, n - i);
			return;
		}
	}
	printf("Goldbach's conjecture is wrong.");
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int n;
	eratos(MAX_N);

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		goldbach(n);
	}
	return 0;
}