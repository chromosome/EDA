#ifndef SUFFIX_ARRAY
#define SUFFIX_ARRAY

#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

class SuffixArray {
public:
	SuffixArray(const std::string &txt);
	~SuffixArray();

	std::vector<size_t> search(const std::string &pattern);

private:	
	char *_txt;
	size_t *_arr;
	size_t _size;

};

#include "SuffixArray.cpp"

#endif

