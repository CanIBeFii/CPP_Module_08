#include <iostream>
#include "../includes/Span.hpp"

int	main( void ) {
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		//Span	span( 10000000, 10 );
		Span	span( 10000000 );
		span.fillWithNumber( 999950, 10 );

		span.addNumber( 17 );
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

		span.addNumber( 3000 );

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;

	}

	{
		Span	span( 1000000 );

		try {
			span.fillWithNumber( 1000001, 42 );
		} catch ( Span::SizeTooBigException& e ) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}


	{
		Span	span( 5 );

		try {
			span.shortestSpan();
		} catch ( Span::NoSpanException& e ) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		Span	span( 5 );

		try {
			span.longestSpan();
		} catch ( Span::NoSpanException& e ) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		Span	span( 5 );

		try {
			span.addNumber(6);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(11);
			span.addNumber(6);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(11);
		} catch ( Span::FullSpanException& e ) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return ( 0 );
}