#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <cmath>
#include <algorithm>

class Span {
	public:
		// Constructors
		Span( void );
		Span( unsigned int n );
		Span( unsigned int n, int number );
		Span( const Span& copy );

		// Destructor
		~Span( void );

		// Operators
		Span&	operator=( const Span& copy );

		// Methods
		// Getters
		unsigned int	getMaxSize( void ) const;

		// Setters
		void			setMaxSize( unsigned int n );

		void			addNumber( int n );
		void			fillWithNumber( unsigned int n, int number);
		int				shortestSpan( void );
		int				longestSpan( void );

		// Exceptions
		class FullSpanException : public std::exception {
			public:
				virtual const char*	what( void ) const throw();
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char*	what( void ) const throw();
		};

		class SizeTooBigException : public std::exception {
			public:
				virtual const char*	what( void ) const throw();
		};

	private:
		unsigned int	_maxSize;
		std::list<int>	_list;
};

template <typename T>
int		difference( T a, T b ) {
	return ( std::abs( a - b ) );
}

// Colors
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */

#endif