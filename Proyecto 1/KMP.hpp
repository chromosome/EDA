#ifndef KMP
#define KMP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

auto kmp(const char *text, size_t n, const char *pattern, size_t m) -> size_t {
	int lps[m+1];

	lps[0] = -1;
	int i = 0;
	int j = -1;
	while (i < m) {
		while ((j >= 0) && (pattern[i] != pattern[j]))
			j = lps[j];

		++j;
		++i;

		lps[i] = j;
	}

	i = 0;
	j = 0;
	while (i < n) {
		while ((j >= 0) && (text[i] != pattern[j]))
			j = lps[j];

		++i;
		++j;

		if (j == m)
			return i-m;
	}

	return i;
}

#endif
