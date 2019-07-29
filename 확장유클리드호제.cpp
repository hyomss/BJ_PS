// sx + ty = c
void ext_euclid() {
	ll q, r, r1, r2, s, s1, s2, t, t1, t2;
	r1 = K, s1 = 1, t1 = 0;
	r2 = C, s2 = 0, t2 = 1;

	while (r2 != 0) {
		q = r1 / r2;
		r = r1 - r2 * q;
		s = s1 - s2 * q;
		t = t1 - t2 * q;
		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}
	ret[0] = r1;
	ret[1] = (s1 + C) % C;
	ret[2] = (t1 + K) % K;
}