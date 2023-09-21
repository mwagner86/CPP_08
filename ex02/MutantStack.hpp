//
// Created by max on 9/21/23.
//

#ifndef EX02_MUTANTSTACK_HPP
#define EX02_MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>	{

public:
	MutantStack() {};
	MutantStack(const MutantStack & src) {
		*this = src;
	};
	MutantStack & operator=(const MutantStack & rhs)	{
		std::stack<T>::operator=(rhs);
		return (*this);
	}
	virtual ~MutantStack() {};

	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;

	iterator begin(void) {
		return(std::stack<T>::c.begin());
	}
	iterator end(void) {
		return(std::stack<T>::c.end());
	}
	reverse_iterator rev_begin(void)	{
		return(std::stack<T>::c.rbegin());
	}
	reverse_iterator rev_end(void) {
		return(std::stack<T>::c.rend());
	}

};

#endif //EX02_MUTANTSTACK_HPP
