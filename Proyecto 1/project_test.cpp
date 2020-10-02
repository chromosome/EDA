#include "boyer_moore.hpp"
#include "kmp.hpp"
#include "../Laboratorio 2/brute_force_string_search.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <functional>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;

void test(string infile, function<size_t(const char*, size_t, const char*, size_t)> string_matching_alg) {
	ifstream f(infile); //taking file as inputstream
	string in;

	if(f) {
		ostringstream ss;
		ss << f.rdbuf(); // reading data
		in = ss.str();
	}

	srand(time(0));

	// For csv table
	cout << "m;time_alg;time_brute" << endl;


	int t_samples = 10;

	for (int i=0; i<20; i++) {
		string pattern = in.substr(rand()%(in.size()/3),5*(i+1));
		// cout << pattern << "\t";

		double t = 0.0;
		for (int j=0; j<t_samples; j++) {
			size_t index=0;
			auto start = clock();
			while (index<in.size()) {
				index += string_matching_alg(&in.data()[index], in.size()-index,pattern.data(), pattern.size())+1;
				// cout << index << endl;
			}
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		// break;
		}
		cout << pattern.size() << ";" << 1000*t/t_samples;

		//TESTING BRUTE FORCE
		t = 0.0;
		for (int j=0; j<t_samples; j++) {
			size_t index=0;
			auto start = clock();
			while (index<in.size()) {
				index += brute_force_string_search(&in.data()[index], in.size()-index, pattern.data(), pattern.size())+1;
				// cout << index << endl;

			}
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		// break;
		}
		cout << ";" << 1000*t/t_samples << endl;
		// break;
	}

}

int main() {
	// string txt = "I have a friend who is afraid of spiders.";//" This isn't very unusual; a lot of people are afraid of spiders. I don't really like spiders much myself. I don't mind them if I see them outside in the garden, as long as they're not too big. But if one comes in the house, especially if it's one of those really big spiders with furry legs and little red eyes, then I go 'Yeeucch' and I try to get rid of it. Usually I'll use a brush to get rid of the spider, but if I feel brave then I'll put a glass over the top of it, slide a piece of paper under the glass and then take it outside.";
	// string pattern = "who is afraid of";

	// size_t pos;// = brute_force_string_search(txt, pattern);

	// cout << txt.size() << endl;
	// cout << pos << endl;
	// cout << txt.substr(pos) << endl << endl << endl;

	// // Boyer-Moore
	// pos = boyer_moore(txt,pattern);
	// cout << pos << endl;
	// cout << txt.substr(pos) << endl;

	// cout << strcmp("A", "a") << endl;

	// kmp(txt,pattern);
	string file_text;
	// file_text = "../text database/generic.1MB";
	// file_text = "../text database/generic.10MB";
	file_text = "../text database/english.50MB";
	test(file_text, boyer_moore);
	return 0;
}




