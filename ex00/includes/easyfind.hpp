#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int&	easyfind( T container, int num ) {
	typename T::iterator	iter;

	iter = find( container.begin(), container.end(), num );

	if ( iter == container.end() ) {
		throw std::exception();
	}

	return ( *iter );
}

#endif