#include <iostream>
using namespace std;

const int MAX_N = 4000001;
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

int main() {


	return 0;	
}