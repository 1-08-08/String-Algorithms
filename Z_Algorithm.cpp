/* Problem: we have to count the number of times a given pattern is appearing in a string.
                               Algorithm: Z-Algorithm.
                                Time Complexity: O(n)
                                Space Complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

// z[i] stores the length of longest proper prefix of string s, such that s[0,..,z[i]-1] == s[i,..i+z[i]-1].
void Z_algo(string txt, string pat) {
	string s = pat + "#" + txt;
	int n = (int)s.size(), m = (int)pat.size(), ret = 0;
	vector<int> z(n), vec;
	int l = 1, r = 1;
	for (int i = 1; i < n; i++) {
		z[i] = max(0, min(r - i, z[i - l]));
		while (s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] > r) {
			l = i - z[i] + 1;
			r = i + z[i] - 1;
		}
		if (z[i] == m)
			ret++, vec.push_back(i - m - 1);
	}
	cout << ret << "\n";
	for (auto & i : vec)
		cout << i << " ";
	cout << "\n";
}

int main() {

	string pat, txt;
	cin >> txt >> pat;
	Z_algo(txt, pat);

	return 0;
}