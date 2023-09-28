#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
size_t	easyfind( T container, int num ) {
	for ( size_t i = 0; i < container.size(); i++ ) {
		if ( container[i] == num )
			return ( i );
	}
	throw std::exception();
}

#endif