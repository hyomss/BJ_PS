#include <iostream>
using namespace std;
// 유클리드 호제법 이용

// 재귀
int gcd(int a, int b) {	
	// a = b*q +r
	// gcd(a,b) = gcd(b,r);
	int r = a % b;
	if (r == 0) return b;
	return gcd(b, r);
}

// 반복문
int gcd_loop(int a, int b) {
	int r;

	while (a%b > 0) {
		r = a%b;
		a = b;
		b = r;
	}
	return b;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	return 0;
}