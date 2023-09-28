#include "easyfind.hpp"
#include <vector>

int	main( void ) {
	{
		std::vector<int>	vec;

		vec.push_back( 10 );
		vec.push_back( 123 );
		vec.push_back( 29816 );
		vec.push_back( 3 );
		vec.push_back( 4 );
		vec.push_back( 3 );

		int num = easyfind( vec, 3 );
		std::cout << "First occurence of 3 in the vector is at: " << num << std::endl;
	}
	{
		std::vector<int>	vec;

		vec.push_back( 0 );
		vec.push_back( 1 );
		vec.push_back( 2 );
		vec.push_back( 3 );
		vec.push_back( 4 );
		vec.push_back( 3 );

		try {
			int num = easyfind( vec, 5 );
			std::cout << "First occurence of 5 in the vector is at: " << num << std::endl;
		} catch ( std::exception& e ) {
			std::cout << "Couldn't find occurence of 5" << std::endl;
		}
	}

}