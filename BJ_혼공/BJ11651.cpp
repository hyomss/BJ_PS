/*
Á¤·Ä
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int N;

	scanf("%d", &N);
	pair <int, int> arr[100010];
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i].second, &arr[i].first);
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", arr[i].second, arr[i].first);
	}




	return 0;
}