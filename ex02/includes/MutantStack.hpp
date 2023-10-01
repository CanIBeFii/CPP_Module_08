#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

// Colors
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		// Constructors
		MutantStack( void ) : std::stack<T>() {
			std::cout << BOLDCYAN << "MutantStack: " << RESET;
			std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
			std::cout << "called" << std::endl;
		};
		MutantStack( const MutantStack& copy ) : std::stack<T>( copy ) {
			std::cout << BOLDCYAN << "MutantStack: " << RESET;
			std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
			std::cout << "called" << std::endl;
		};
		
		// Destructor
		~MutantStack( void ) {
			std::cout << BOLDCYAN << "MutantStack: " << RESET;
			std::cout << BOLDRED << "Destructor " << RESET;
			std::cout << "called" << std::endl;
		};

		// Operators
		MutantStack&	operator=( const MutantStack& copy ) {
			std::cout << BOLDCYAN << "MutantStack: " << RESET;
			std::cout << BOLDYELLOW << "Assignation " << RESET;
			std::cout << "called" << std::endl;

			if ( this != &copy ) {
				std::stack<T>::operator=( copy );
			}
			return ( *this );
		};
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		// Methods
		iterator begin( void ) {
			return ( std::stack<T>::c.begin() );
		};

		iterator end( void ) {
			return ( std::stack<T>::c.end() );
		};
};

#endif