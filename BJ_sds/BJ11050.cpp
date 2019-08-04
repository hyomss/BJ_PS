/*
이항계수
*/

#include <iostream>
using namespace std;

int fac(int n) {
	if (n == 1 || n==0)	return 1;
	else return n*fac(n - 1);
}

int main() {
	int N, K;

	cin >> N >> K;
	cout << fac(N) /( fac(N - K) * fac(K)) << endl;


	return 0;
}