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

#include "../Laboratorio 2/SuffixArray.hpp"
#include <algorithm>

using namespace std;

string* read_txt_file(const string &infile) {
	ifstream f(infile); //taking file as inputstream

	if(f) {
		ostringstream ss;
		ss << f.rdbuf(); // reading data
		return new string(ss.str());
	}

	return nullptr;
}

void test(string infile) {
	string *in = read_txt_file(infile);

	srand(time(0));

	// For csv table
	cout << "m;boyer;kmp;time_brute" << endl;


	int t_samples = 10;
	int step = 5;

	for (int i=0; i<20; i++) {

		// TESTING BOYER MOORE
		double t = 0.0;
		for (int j=0; j<t_samples; j++) {
			string pattern = in->substr(rand()%(in->size()/3),step*(i+1));
			for (auto &c : pattern)
				c++;

			auto start = clock();
			boyer_moore(in->data(), in->size(), pattern.data(), pattern.size());
			auto end = clock();

			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << step*(i+1) << ";" << 1000*t/t_samples;

		//TESTING KMP
		t = 0.0;
		for (int j=0; j<t_samples; j++) {
			string pattern = in->substr(rand()%(in->size()/3),step*(i+1));
			for (auto &c : pattern)
				c++;


			auto start = clock();
			kmp(in->data(), in->size(), pattern.data(), pattern.size());
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << ";" << 1000*t/t_samples;

		//TESTING BRUTE FORCE
		t = 0.0;
		for (int j=0; j<t_samples; j++) {
			string pattern = in->substr(rand()%(in->size()/3),step*(i+1));
			for (auto &c : pattern)
				c++;

			auto start = clock();
			brute_force_string_search(in->data(), in->size(), pattern.data(), pattern.size());
			auto end = clock();
			t+= ((double) (end-start)) / CLOCKS_PER_SEC;
		}
		cout << ";" << 1000*t/t_samples << endl;
	}

	delete in;
}

int main() {
	// string txt = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";//" This isn't very unusual; a lot of people are afraid of spiders. I don't really like spiders much myself. I don't mind them if I see them outside in the garden, as long as they're not too big. But if one comes in the house, especially if it's one of those really big spiders with furry legs and little red eyes, then I go 'Yeeucch' and I try to get rid of it. Usually I'll use a brush to get rid of the spider, but if I feel brave then I'll put a glass over the top of it, slide a piece of paper under the glass and then take it outside.";
	string pattern = "aaa";
	// kmp(txt, pattern);

	// size_t pos;// = brute_force_string_search(txt, pattern);

	// cout << txt.size() << endl;
	// cout << pos << endl;
	// cout << txt.substr(pos) << endl << endl << endl;

	// // Boyer-Moore
	// cout << boyer_moore(txt.data(), txt.size(), pattern.data(), pattern.size()) << endl;
	// cout << pos << endl;
	// cout << txt.substr(pos) << endl;

	// cout << strcmp("A", "a") << endl;

	// kmp(txt,pattern);
	string file_text;
	// file_text = "../text database/generic.1MB";
	// file_text = "../text database/generic.10MB";
	// file_text = "../text database/generic.50MB";
	file_text = "../text database/english.50MB";
	// file_text = "../text database/dna.50MB";
	// file_text = "../text database/proteins.50MB";
	// file_text = "../text database/single_char.50MB";
	// file_text = "../text database/single_char.1MB";
	test(file_text);
	// kmp(txt.data(), txt.size(), pattern.data(), pattern.size());
	


	// size_t index=0;
	// auto start = clock();
	// while (index<txt.size()) {
	// 	index += boyer_moore(&txt.data()[index], txt.size()-index,pattern.data(), pattern.size())+1;
	// 	if(index<txt.size())
	// 	cout << txt.substr(index) << endl;
	// }

	// cout << index << "\t" << txt.size() << endl;








	// srand(time(0));
	// string* in = read_txt_file(file_text);
	// pattern = in->substr(rand()%(in->size()/10),6);
	// pattern = "f his ha";

	// cout << in->substr(798282, 8) << endl;

	// cout << pattern << endl;

	// // TESTING BOYER MOORE
	// cout << "Boyer Moore!" << endl;
	// size_t index=0;
	// while (index<in->size()) {
	// 	index += boyer_moore(&in->data()[index], in->size()-index, pattern.data(), pattern.size())+1;
	// 	cout << index << endl;
	// }
	

	// // KMP
	// cout << "KMP!" << endl;
	// index=0;
	// while (index<in->size()) {
	// 	index += kmp(&in->data()[index], in->size()-index, pattern.data(), pattern.size())+1;
	// 	cout << index << endl;
	// }


	// // BRUTE FORCE
	// cout << "Brute Force!" << endl;
	// index=0;
	// while (index<in->size()) {
	// 	index += brute_force_string_search(&in->data()[index], in->size()-index, pattern.data(), pattern.size())+1;
	// 	cout << index << endl;
	// }


	// // SUFFIX ARRAY
	// cout << "SuffixArray" << endl;
	// SuffixArray sa(*in);

	// auto indeces = sa.search(pattern);
	// sort(indeces.begin(), indeces.end());

	// for (auto &a : indeces)
	// 	cout << a+1 << endl;

	return 0;
}




