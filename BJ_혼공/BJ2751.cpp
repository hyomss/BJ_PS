/*¸ô¶ó¿ä....*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
	scanf("%d",&N);
	int a;
	vector <int> arr;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < (int)arr.size(); i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}