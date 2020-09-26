#include <iostream>
#include <stdio.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>

#include "search_algorithm.hpp"

using namespace std;

vector<unsigned> initialize_random_vec(size_t n) {
	srand(time(0));
	vector<unsigned> data(n);

	for (auto& e : data)
		e = rand()%(n*2);

	return data;
}

vector<unsigned> initialize_ordered_vec(size_t n) {
	vector<unsigned> data(n);

	for (size_t i=0; i<n; i++)
		data[i] = i;

	return data;
}

int main() {
	size_t n = 100000; // 100,000
	vector<unsigned> data;

	cout << "n;t" << endl;

	int step = 1000;
	int samples = 10000;
	int alg = 1;

	////////////////////////////////////////////////
	auto profile_microsec = [&data, samples] (function<vector<unsigned>::iterator (vector<unsigned>::iterator, vector<unsigned>::iterator, unsigned)> search) {
		double t = 0.0;
		// vector<double> times(samples);

		for (int i=0; i<samples; i++) {
			unsigned e = rand()%data.size()*2/3+data.size()/3;

			auto start = clock();
			search(data.begin(), data.end(), e);
			auto end = clock();
			t += ((double) (end - start)) / CLOCKS_PER_SEC;
			// times[i] = ((double) (end - start)) / CLOCKS_PER_SEC;
		}

		// sort(times.begin(), times.end());

		cout << data.size() << ";" << flush << 1000*t/samples;
	};

	for (int i=0; i<n; i++) {
		data.push_back(i);

		// Testing vs tamanio
		// if (data.size()%step==0) {
		// 	switch(alg) {
		// 		case 0:
		// 			profile_microsec(linear_search<vector<unsigned>::iterator, unsigned>);
		// 			break;
		// 		case 1:
		// 			profile_microsec(bin_search<vector<unsigned>::iterator, unsigned>);
		// 			break;
		// 		default:
		// 			profile_microsec(folding_search<vector<unsigned>::iterator, unsigned>);

		// 	}

		// 	cout << data.size() << endl;
		// }
	}

	int window = 1000;

	for (int i=0; i<data.size()/window; i++) {
		double t=0;

		for (int j=0; j<samples; j++) {
			unsigned e = rand()%window+i*window;

			auto start = clock();
			// linear_search(data.begin(), data.end(), e);
			// bin_search(data.begin(), data.end(), e);
			folding_search(data.begin(), data.end(), e);
			auto end = clock();
			t += ((double) (end - start)) / CLOCKS_PER_SEC;
		}

		cout << (i+1)*window << ";" << flush << 1000*t/samples << "\n";

		// Solo para la binaria y doblada con window = 10
		// if (i==100)
		// 	break;
	}

	return 0;
}

