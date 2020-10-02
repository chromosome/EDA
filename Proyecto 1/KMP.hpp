#ifndef KMP
#define KMP

#include <string>
#include <vector>

#include <iostream>

size_t kmp(const std::string &text, const std::string &pattern) {
	// Preprocess pattern
	std::vector<size_t> table(pattern.size());
	table[0] = 0;
	size_t i = 0;

	for (size_t j=1; j<pattern.size(); j++) {
		while (i>0 and pattern[i]!=pattern[j])
			i = table[i];
		if (pattern[i]==pattern[j])
			i++;
		table[j] = i;
	}

	// Process text with pattern
	// i = 0;
	// for (size_t j=1; j<text.size(); j++) {
	// 	while (i>0 and pattern[i]!=pattern[j])
	// 		i = table[i];
	// 	if (pattern[i]==pattern[j])
	// 		i++;
	// 	if (i==pattern.size())
	// }

	std::cout << pattern << std::endl;
	for (auto&i : table)
		std::cout << i;
	std::cout << std::endl;

	return 0;
}

#endif
