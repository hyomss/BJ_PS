#include <iostream>
using namespace std;
// ��Ŭ���� ȣ���� �̿�

// ���
int gcd(int a, int b) {	
	// a = b*q +r
	// gcd(a,b) = gcd(b,r);
	int r = a % b;
	if (r == 0) return b;
	return gcd(b, r);
}

// �ݺ���
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