#include <string>
#include "SuffixArray.hpp"
#include "brute_force_string_search.hpp"
#include <iostream>
#include <vector>
#include<fstream>
#include<sstream>
#include <ctime>

#define TEXT_FILE "database/english.50MB"

using namespace std;

// BUILDING TEST
void pre_processing_testing(string in) {
	// For csv table
	cout << "n;time" << endl;

	int n = 20;
	int t_samples = 10;

	for (int i=1; i<=n; i++) {
		string substr_in = in.substr(0,(in.size()/n)*i);

		double t = 0.0;
		for (int j=0; j<t_samples; j++) {
			auto start = clock();
			SuffixArray build_test(substr_in);
			auto end = clock();
			t += ((double) (end - start)) / CLOCKS_PER_SEC;
		}

		cout << substr_in.size() << ";" << t/t_samples << endl;
	}
}

// TESTING WITH MOST COMMON WORDS IN ENGLISH
void most_common_english_words_test(SuffixArray &sa, string &txt) {
	const char *eng[] = {"the","be","to","of","and","a","in","that","have","I"};

	vector<string> most_common;
	for (int i=0; i<10; i++)
		most_common.push_back(eng[i]);

	cout << "word;time_sa;time_bf" << endl;

	int t_samples = 10;

	for (int i=0; i<most_common.size(); i++) {
		// TESTING SUFFIX ARRAY
		double t = 0.0;
		for (int j=0; j<t_samples; j++) {
			auto start = clock();
			sa.search(most_common[i]);
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << most_common[i] << ";" << 1000*t/t_samples;

		//TESTING BRUTE FORCE
		t = 0.0;
		for (int j=0; j<t_samples; j++) {
			auto start = clock();
			brute_force_string_search(txt, most_common[i]);
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << ";" << 1000*t/t_samples << endl;
	}
}

// RANDOMIZING THE PATTERN AND TESTING
void fixed_size_pattern_var(SuffixArray &sa, string &txt) {
	// Generate 20 patterns with variable size
	// without "\n"
	vector<string> patterns(20);
	srand(time(0));

	for (int i=0; i<20; i++) {
		do {
			patterns[i] = txt.substr(rand()%(txt.size()/4), rand()%100);
		} while (brute_force_string_search(patterns[i], string("\n"))!=0);
		cout << i << "\t" << patterns[i] << endl;
	}

	cout << "p_size;time_sa;time_bf" << endl;

	int t_samples = 10;

	for (int i=0; i<patterns.size(); i++) {
		// TESTING SUFFIX ARRAY
		double t = 0.0;
		for (int j=0; j<t_samples; j++) {
			auto start = clock();
			sa.search(patterns[i]);
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << patterns[i].size() << ";" << 1000*t/t_samples;

		//TESTING BRUTE FORCE
		t = 0.0;
		for (int j=0; j<t_samples; j++) {
			auto start = clock();
			brute_force_string_search(txt, patterns[i]);
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << ";" << 1000*t/t_samples << endl;
	}
}

// TESTING VARING SIZE ON TXT AND PATTERN
void varing_size_varing_pattern_size(string txt) {
	cout << "n;time_sa;time_bf" << endl;

	int n = 20;
	size_t t_samples = 20;

	for (int i=1; i<=n; i++) {
		string substr_in = txt.substr(0,(txt.size()/n)*i);

		SuffixArray build_test(substr_in);

		double t = 0.0;
		for (int j=0; j<t_samples; j++) {
			// Random pattern
			string pattern;
			do {
				pattern = txt.substr(rand()%(txt.size()/4), rand()%100);
			} while (brute_force_string_search(pattern, string("\n"))!=0);

			auto start = clock();
			build_test.search(pattern);
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << substr_in.size() << ";" << 1000*t/t_samples;

		//TESTING BRUTE FORCE
		t = 0.0;
		for (int j=0; j<t_samples; j++) {
			// Random pattern
			string pattern;
			do {
				pattern = txt.substr(rand()%(txt.size()/4), rand()%100);
			} while (brute_force_string_search(pattern, string("\n"))!=0);
			
			auto start = clock();
			brute_force_string_search(substr_in, pattern);
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << ";" << 1000*t/t_samples << endl;

	}
}

int main() {
	// Testing Area
	// READING TXT FILE
	ifstream f(TEXT_FILE); //taking file as inputstream
	string in;

	if(f) {
		ostringstream ss;
		ss << f.rdbuf(); // reading data
		in = ss.str();
	}

	pre_processing_testing(in);
	varing_size_varing_pattern_size(in);

	SuffixArray sa_test(in);
	most_common_english_words_test(sa_test,in);
	fixed_size_pattern_var(sa_test,in);

	return 0;
}

