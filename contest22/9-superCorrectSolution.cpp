#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAXN 100005
#define INF 1000050

struct data {
	int min, max, cntMin, cntMax;
	data() {
		cntMax = cntMin  = min = max = 0;
	}
	data(const int _min, const int _cntMin, const int _max, const int _cntMax) {
		min = _min,
		max = _max,
		cntMin = _cntMin,
		cntMax = _cntMax;
	}
}

t[4 * MAXN];

int a[MAXN];
int tc, n, cmd, p, val, l, r;
data res;

data combine (const data &a, const data &b) {
	data r;
	if (a.max > b.max) {
		r.max = a.max;
		r.cntMax = a.cntMax;
	} else if (b.max > a.max) {
		r.max = b.max;
		r.cntMax = b.cntMax;
	} else {
		r.max = a.max;
		r.cntMax = a.cntMax + b.cntMax;
	}

	if (a.min < b.min) {
		r.min = a.min;
		r.cntMin = a.cntMin;
	} else if (b.min < a.min) {
		r.min = b.min;
		r.cntMin = b.cntMin;
	} else {
		r.min = a.min;
		r.cntMin = a.cntMin + b.cntMin;
	}

	return r;
}

void build (const int v, const int tl, const int tr) {
	if (tl == tr)
		t[v] = data(a[tl], 1, a[tl], 1);
	else {
		const int tm = (tl + tr) >> 1;
		build (v << 1, tl, tm);
		build ((v << 1) + 1, tm + 1, tr);
		t[v] = combine (t[v << 1], t[(v << 1) + 1]);
	}
}

data get (const int v, const int tl, const int tr, int l, int r) {
	if (l > r)
		return data (INF, 0, -INF, 0);
	if (l == tl && r == tr)
		return t[v];

	const int tm = (tl + tr) >> 1;
	return combine (
		get (v << 1, tl, tm, l, min(r, tm)),
		get ((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r)
		);
}

void update (const int v, const int tl, const int tr, const int pos, const int newVal) {
	if (tl == tr)
		t[v] = data (newVal, 1, newVal, 1);
	else {
		const int tm = (tl + tr) >> 1;
		t[v] = combine (t[v], t[v + 1]);

		if (pos <= tm)
			update (v << 1, tl, tm, pos, newVal);
		else
			update ((v << 1) + 1, tm + 1, tr, pos, newVal);

		t[v] = combine (t[v << 1], t[(v << 1) + 1]);
	}
}

int main() {
	scanf ("%d", &tc);
	while(tc--) {
		do {
			scanf ("%d", &cmd);
			switch (cmd) {
				case 1:
					scanf ("%d %d", &p, &val);
				    update(1, 0, n, p - 1, val);
					break;
				case 2:
					scanf ("%d %d", &l, &r);
					res = get(1, 0, n, l - 1, r - 1);
					printf("%d %d %d %d\n", res.min, res.cntMin, res.max, res.cntMax);
					fflush (stdout);
					break;
				case 0:
					scanf ("%d", &n);
					for(int i = 0;i < n;i++)
						scanf ("%d", &a[i]);
					build(1, 0, --n);
					break;
				case 3:
					break;
				default: printf("unknown command: %d\n", cmd);
			}
		} while(cmd != 3);
	}

	return 0;
}