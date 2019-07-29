#include <iostream>
using namespace std;
// 유클리드 호제법 이용

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

	int a, b, r, s;
	cin >> a >> b >> r >> s;

	int  g = gcd_loop(b, s);
	int s_b = b / g;
	int s_s = s / g;
	long lcm = g * s_b * s_s;

	int ans_top, ans_bot;

	ans_bot = lcm;
	ans_top = a*s_s + r*s_b;
	int ans_g = gcd_loop(ans_top, ans_bot);
	cout << ans_top/ans_g << " " << ans_bot/ans_g;

	return 0;
}