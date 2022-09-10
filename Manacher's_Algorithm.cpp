/* Problem: we have to count the number of palindromic substrings of a given string.
                          Algorithm: Manacher's Algorithm.
                                Time Complexity: O(n)
                                Space Complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

// Return the number of odd length palindromic substrings of string s.
int oddLenManacher(string s) {
	s = '#' + s + '$';
	int n = (int)s.length();
	vector<int> d(n);
// d[i] stores the maximum value such that s[i-d[i]+1,....,s[i+d[i]]-1] is a palindrome.
	int l = 1, r = 1, ret = 0;
// r is the maximum index upto which string s is scanned.
	for (int i = 1, j; i < n - 1; i++) {
		d[i] = max(0, min(r - i, d[l + r - i]));
		while (s[i - d[i]] == s[i + d[i]])
			d[i]++;
		if (r < i + d[i]) {
			l = i - d[i];
			r = i + d[i];
		}
		ret += d[i];
	}
	return ret;
}

// Return the number of even length palindromic substrings of string s.
int evenLenManacher(string s) {
	string s1 = "#";
	for (int i = 0; i < (int)s.length(); i++) {
		s1.push_back(s[i]);
		s1.push_back('@');
	}
	s1.pop_back();
	s1.push_back('$');
// number of even length palindromic substrings of s is equal to the number of odd length substrings of s1 at the special character '@'.
	int n = (int)s1.length();
	vector<int> d(n);
	int l = 1, r = 1, ret = 0;
	for (int i = 1; i < n - 1; i++) {
		d[i] = max(0, min(r, d[l + r - i]));
		while (s1[i - d[i]] == s1[i + d[i]])
			d[i]++;
		if (r < i + d[i]) {
			l = i - d[i];
			r = i + d[i];
		}
// if current character is '@', then only add its contribution to answer.
		if (!(i & 1))
			ret += (d[i] - 1) / 2;
	}
	return ret;
}

int main() {

	string s;
	cin >> s;
	int res = 0;
	res = (oddLenManacher(s) + evenLenManacher(s));
	cout << res << "\n";

	return 0;
}