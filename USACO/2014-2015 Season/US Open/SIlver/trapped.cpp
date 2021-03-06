#include <bits/stdc++.h>

#define F0R(i, a) for(int i = 0; i < (a); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define R0F(i, a) for(int i = (a) - 1; i >= 0; i--)
#define ROF(i, a, b) for(int i = (b) - 1; i >= (a); i--)

#define ran() (rand() & 0x7FFF)
#define rand31() ((ran() << 16) | (ran() << 1) | (ran() & 1))
#define rand32() ((ran() << 17) | (ran() << 2) | (ran() & 3))
#define rand63() (((ll)ran() << 48) | ((ll)ran() << 33) | ((ll)ran() << 18) | ((ll)ran() << 3) | ((ll)ran() & 7))
#define rand64() (((ll)ran() << 49) | ((ll)ran() << 34) | ((ll)ran() << 19) | ((ll)ran() << 4) | ((ll)ran() & 15))

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define UB upper_bound
#define LB lower_bound
#define X real()
#define Y imag()

#define PI acos(-1)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define SQ(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<ull> vul;
typedef complex<ld> point;
typedef complex<ld> cld;
typedef vector<cld> vcld;

#define INF ((1LL << 63) - 1)

int n, b;
vector<pii> v;
ll res = INF;

int main() {
	ifstream fin("trapped.in");
	ofstream fout("trapped.out");
	fin >> n >> b;
	F0R(i, n) {
		int s, p;
		fin >> s >> p;
		v.PB(MP(p, s));
	}
	sort(all(v));
	int idx = UB(all(v), MP(b, 0)) - v.begin();
	int curr = idx;
	R0F(i, idx) {
		while(curr < n && v[curr].S < v[curr].F - v[i].F) curr++;
		if(curr == n) continue;
		res = min(res, (ll)max(0, v[curr].F - v[i].F - v[i].S));
	}
	curr = idx - 1;
	FOR(i, idx, n) {
		while(curr >= 0 && v[curr].S < v[i].F - v[curr].F) curr--;
		if(curr < 0) continue;
		res = min(res, (ll)max(0, v[i].F - v[curr].F - v[i].S));
	}
	if(res == INF) fout << -1 << endl;
	else fout << res << endl;

}
