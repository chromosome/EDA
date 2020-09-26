#include "SuffixArray.hpp"


// Constructor
SuffixArray::SuffixArray(const std::string &txt) {
	_size = txt.size()+1;
	_txt = new char[_size];
	_arr = new size_t[_size];

	// Set arrays
	strcpy(_txt, txt.c_str());
	for (size_t i=0; i<_size; i++) _arr[i] = i;
	std::sort(_arr, _arr+_size, [&](size_t a, size_t b) { return strcmp(_txt+a,_txt+b)<0; });
}

// Destructor
SuffixArray::~SuffixArray() {
	delete[] _txt;
	delete[] _arr;
}

// Search
std::vector<size_t> SuffixArray::search(const std::string &pattern) {
	size_t p_s = pattern.size();
	auto lb = std::lower_bound(_arr, _arr+_size, pattern.c_str(), [&](size_t a,const char* b) { return strcmp(_txt+a,b)<0; });
	auto ub = std::upper_bound(lb, _arr+_size, pattern.c_str(), [&](const char* b,size_t a) { return strncmp(b,_txt+a, p_s)<0; });

	return std::vector<size_t>(lb,ub);
}


