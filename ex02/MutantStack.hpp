/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:30:43 by mwagner           #+#    #+#             */
/*   Updated: 2023/09/21 20:31:13 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	iterator begin() {
		return(std::stack<T>::c.begin());
	}
	iterator end() {
		return(std::stack<T>::c.end());
	}
	reverse_iterator rev_begin()	{
		return(std::stack<T>::c.rbegin());
	}
	reverse_iterator rev_end() {
		return(std::stack<T>::c.rend());
	}
};

#endif //EX02_MUTANTSTACK_HPP
