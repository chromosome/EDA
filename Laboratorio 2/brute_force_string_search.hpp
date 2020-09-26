#ifndef BRUTE_FORCE_STRING_SEARCH
#define BRUTE_FORCE_STRING_SEARCH

#include <string>

size_t brute_force_string_search(const std::string &t, const std::string &p) {
	size_t i,j, n=0;

	for (i=0; i<t.size(); i++) {
		for (j=0; j<p.size(); j++)
			if (t[i+j]!=p[j])
				break;

		if (j==p.size()) n++;
		// 	break;
	}

	// return i;
	return n;
}

#endif

