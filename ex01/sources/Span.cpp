#include "Span.hpp"
#include <iostream>

Span::Span( void ) : _maxSize(0), _list( std::list<int>() ) {
	std::cout << BOLDCYAN << "Span: " << RESET;
	std::cout << BOLDYELLOW << "Default " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

Span::Span( unsigned int n ) : _maxSize( n ), _list( std::list<int>() ) {
	std::cout << BOLDCYAN << "Span: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

Span::Span( unsigned int n, int number ) : _maxSize( n ), _list( std::list<int>( n / 2, number ) ) {
	std::cout << BOLDCYAN << "Span: " << RESET;
	std::cout << BOLDYELLOW << "Type " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

Span::Span( const Span& copy ) : _maxSize( copy._maxSize ), _list( copy._list ) {
	std::cout << BOLDCYAN << "Span: " << RESET;
	std::cout << BOLDYELLOW << "Copy " << BOLDGREEN << "Constructor " << RESET;
	std::cout << "called" << std::endl;
}

// Descructor
Span::~Span( void ) {
	std::cout << BOLDCYAN << "Span: " << RESET;
	std::cout << BOLDRED << "Destructor " << RESET;
	std::cout << "called" << std::endl;
}

// Operators
Span&	Span::operator=( const Span& copy ) {
	std::cout << BOLDCYAN << "Span: " << RESET;
	std::cout << BOLDYELLOW << "Assignation " << RESET;
	std::cout << "called" << std::endl;

	if ( this != &copy ) {
		this->_maxSize = copy._maxSize;
		this->_list = copy._list;
	}
	return ( *this );
}

// Methods
// Getters
unsigned int	Span::getMaxSize( void ) const {
	return ( _maxSize );
}

// Setters
void			Span::setMaxSize( unsigned int n ) {
	_maxSize = n;
}

void			Span::addNumber( int n ) {
	if ( _list.size() == _maxSize ) {
		throw FullSpanException();
	}
	_list.push_back( n );
}

void			Span::fillWithNumber( unsigned int n, int number ) {
	if ( n > _maxSize ) {
		throw SizeTooBigException();
	}
	std::fill_n( _list.begin(), n, number );
}

int				Span::shortestSpan( void ) {
	if ( _list.size() < 2 ) {
		throw NoSpanException();
	}

	int	shortest = 2147483647;
	std::list<int>::iterator iter = _list.begin();
	std::list<int>::iterator previous = _list.begin();

	int	difference;
	for ( iter++ ; iter != _list.end(); iter++, previous++ ) {
		difference = std::abs(*previous - *iter);
		if ( difference < shortest ) {
			shortest = difference;
		}
	}
	return ( shortest );
}

int				Span::longestSpan( void ) {
	if ( _list.size() < 2 ) {
		throw NoSpanException();
	}

	int	longest = 0;
	std::list<int>::iterator iter = _list.begin();
	std::list<int>::iterator previous = _list.begin();

	int	difference;
	for ( iter++; iter != _list.end(); iter++, previous++ ) {
		difference = std::abs( *previous - *iter );
		if ( longest < difference ) {
			longest = difference;
		}
	}
	return ( longest );
}

const char*		Span::FullSpanException::what( void ) const throw() {
	return ( "Span is already at max size!" );
}

const char*		Span::NoSpanException::what( void ) const throw() {
	return ( "There's no numbers to have a span!" );
}

const char*		Span::SizeTooBigException::what( void ) const throw() {
	return ( "Size given to fill is too big!" );
}