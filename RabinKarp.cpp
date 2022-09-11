/* Problem: we have to count the number of times a given pattern is appearing in a string.
                            Algorithm: RabinKarp Algorithm.
                                Time Complexity: O(n)
                                Space Complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int mod = 1000000007;
vector<int> pw(MAXN), inv(MAXN), hsh(MAXN);

int exp(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1)
			ret = 1ll * ret * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return ret;
}

void RabinKarp(string s, string pat) {

// power of 31 is used in case, only one case of letters is present in the string (lowercase/ uppercase). if both case of letters is present in the string, then power of 53 will be used.
	pw[0] = 1;
	for (int i = 1; i <= MAXN; i++)
		pw[i] = (1ll * 31 * pw[i - 1]) % mod;

	inv[MAXN - 1] = exp(pw[MAXN - 1], mod - 2);
	for (int i = MAXN - 2; i >= 0; i--)
		inv[i] = (1ll * inv[i + 1] * 31) % mod;

	int n = (int)s.size(), m = (int)pat.size(), pat_hsh = 0;
	for (int i = 0; i < m; i++)
		pat_hsh = (pat_hsh + 1ll * (pat[i] - 'a' + 1) * pw[i + 1] % mod) % mod;
	for (int i = 0; i < n; i++)
		hsh[i + 1] = (hsh[i] + 1ll * (s[i] - 'a' + 1) * pw[i + 1] % mod) % mod;

	int cnt = 0;
	for (int i = 0; i + m <= n; i++) {
		int cur_hsh = hsh[i + m] - hsh[i];
		if (cur_hsh < 0)
			cur_hsh += mod;
		cur_hsh = (1ll * cur_hsh * inv[i]) % mod;
		if (cur_hsh == pat_hsh)
			cnt++;
	}
	cout << cnt << "\n";
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	string pat, s;
	cin >> s >> pat;
	RabinKarp(s, pat);

	return 0;
}