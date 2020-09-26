/*
Template search algorithms
*/

#ifndef SEARCH_ALGORITHM
#define SEARCH_ALGORITHM

template<class T, class E>
T linear_search(T begin, T end, E e);

template<class T, class E>
T bin_search(T begin, T end, E e);

template<class T, class E>
T folding_search(T begin, T end, E e);

#include "search_algorithm.cpp"

#endif

