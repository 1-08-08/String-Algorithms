/* Problem: we have to count the number of times a given pattern is appearing in a string.
                            Algorithm: knuth-Morris-Pratt.
                                Time Complexity: O(n)
                                Space Complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

// Prefix function concept is used. pre[i] stores the length of longest proper prefix of string s, such that s[0,..,pre[i]-1] == s[i-pre[i]+1,..i].
void KMP(string txt, string pat) {
	string s = pat + "#" + txt;
	int n = (int)s.size(), m = (int)pat.size(), ret = 0;
	vector<int> pre(n), vec;
	for (int i = 1, j = 1; i < n; i++, j = i) {
		while (j > 0 && s[i] != s[pre[j - 1]])
			j = pre[j - 1];
		if (j == 0)
			pre[i] = 0;
		else
			pre[i] = pre[j - 1] + 1;
		if (pre[i] == m)
			ret++, vec.push_back(i - 2 * m);
	}
	cout << ret << "\n";
	for (auto & i : vec)
		cout << i << " ";
	cout << "\n";
}

int main() {

	string pat, txt;
	cin >> txt >> pat;
	KMP(txt, pat);

	return 0;
}