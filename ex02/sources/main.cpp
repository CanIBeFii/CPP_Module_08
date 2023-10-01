#include <iostream>
#include "MutantStack.hpp"

int	main( void ) {
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		for ( ; it != ite; ++it ) {
			std::cout << *it << std::endl;
		}

		std::stack<int> s(mstack);
	}
	{
		MutantStack<std::string> strings;

		strings.push("Hello");
		strings.push("world");

		strings.push("!");
		MutantStack<std::string>::iterator it_s = strings.begin();
		MutantStack<std::string>::iterator ite_s = strings.end();
		++it_s;
		--it_s;

		for ( ; it_s != ite_s; ++it_s ) {
			std::cout << *it_s << std::endl;
		}
		
		std::stack<std::string> strs(strings);
	}

	return ( 0 );
}