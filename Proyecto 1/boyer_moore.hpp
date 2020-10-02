#ifndef BOYER_MOORE
#define BOYER_MOORE

#include <string>
#include <algorithm>
#include <string.h>

// size_t boyer_moore(const std::string &t, const std::string &p) {
// 	// preprocess pattern
// 	std::unordered_map<char,size_t> bad_match_table;

// 	for (size_t i=0; i<p.size(); i++)
// 		bad_match_table[p[i]] = std::max(size_t(1), p.size()-i-1);

// 	// compare
// 	for (int i=0, step; i<=t.size()-p.size(); i+=step) {
// 		step = 0;

// 		for (int j=p.size()-1; j>=0; j--) {
// 			if (t[i+j]!=p[j]) {
// 				if (bad_match_table.find(t[i+j])!=bad_match_table.end()) {
// 					step = bad_match_table[t[i+j]];
// 					break;
// 				}
// 				else {
// 					step = p.size();
// 					break;
// 				}
// 			}
// 		}
// 		if (step==0) return i;
// 	}

// 	return t.size();
// }

size_t boyer_moore(const char *text, size_t n, const char *pattern, size_t m) {
	// preprocess pattern
	size_t* bad_match_table = new size_t[256];
	memset(bad_match_table,0,256*sizeof(size_t));

	for (size_t i=0; i<m; i++)
		bad_match_table[pattern[i]] = std::max(size_t(1), m-i-1);

	// compare
	for (int i=0, step; i<n-m; i+=step) {
		step = 0;

		// check pattern
		for (int j=m-1; j>=0; j--) {
			// If missmatch
			if (text[i+j]!=pattern[j]) {
				if (bad_match_table[text[i+j]]!=0) {
					step = bad_match_table[text[i+j]];
					break;
				}
				else {
					step = m;
					break;
				}
			}
		}
		if (step==0) {
			delete[] bad_match_table;
			return i;
		}
	}

	delete[] bad_match_table;
	return n;
}

#endif
