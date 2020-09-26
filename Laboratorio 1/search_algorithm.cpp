#include "search_algorithm.hpp"

template<class T, class E>
T linear_search(T begin, T end, E e) {
	T iter;

	for (iter=begin; iter!=end; iter++)
		if (*iter == e) break;

	return iter;
}

template<class T, class E>
T bin_search(T begin, T end, E e) {
	size_t l = std::distance(begin, end);
	T not_found = end;

	while (l>0) {
		if (*(begin+l/2) == e) return begin+l/2;
		else if (*(begin+l/2)<e) begin += l/2+1;
		else end = begin+l/2;

		l = std::distance(begin, end);
	}

	return not_found;
}

template<class T, class E>
T folding_search(T begin, T end, E e) {
	size_t l = 1;
	T not_found = end;

	while(l<std::distance(begin,end)) {
		if (*(begin+l-1) == e) return begin+l-1;
		else if (*(begin+l-1) > e) break;
		l *= 2;
	}

	end = l<std::distance(begin, end) ? begin+l-1 : end;
	begin += l/2;
	l = std::distance(begin, end);

	while (l>0) {
		if (*(begin+l/2) == e) return begin+l/2;
		else if (*(begin+l/2)<e) begin += l/2+1;
		else end = begin+l/2;

		l = std::distance(begin, end);
	}

	return not_found;
}

