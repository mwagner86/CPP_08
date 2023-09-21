/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:34:12 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/13 20:34:13 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

/*

// Subject main function
int main()
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
 	// [...]


	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
*/

/*
// changed container from Stack to list
int main() {
	std::list<int> myList; // Use std::list<int> instead of MutantStack<int>

	myList.push_back(5); // Use push_back() instead of push()
	myList.push_back(17);

	std::cout << myList.back() << std::endl; // Use back() instead of top()

	myList.pop_back(); // Use pop_back() instead of pop()

	std::cout << myList.size() << std::endl;

	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	// [...]

	myList.push_back(0); // Use push_back() to add elements to the end of the list

	std::list<int>::iterator it = myList.begin();
	std::list<int>::iterator ite = myList.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int, std::list<int> > s(myList); // Use std::stack with std::list as the container

	return 0;
}*/

int main() {
	// Create a MutantStack and a std::stack of integers
	MutantStack<int> mutantStack;
	std::stack<int> stdStack;

	// Push some elements onto both stacks
	for (int i = 1; i <= 10; ++i) {
		mutantStack.push(i);
		stdStack.push(i);
	}

	std::cout << "Testing MutantStack:" << std::endl;

	// Iterate through MutantStack using iterators
	MutantStack<int>::iterator mutantIt;
	for (mutantIt = mutantStack.begin(); mutantIt != mutantStack.end(); ++mutantIt) {
		std::cout << *mutantIt << " ";
	}
	std::cout << std::endl;

	// Iterate through MutantStack in reverse using reverse iterators
	MutantStack<int>::reverse_iterator mutantRevIt;
	for (mutantRevIt = mutantStack.rev_begin(); mutantRevIt != mutantStack.rev_end(); ++mutantRevIt) {
		std::cout << *mutantRevIt << " ";
	}
	std::cout << std::endl;

	std::cout << "Testing std::stack:" << std::endl;

	// Iterate through std::stack (only forward iteration is possible)
	while (!stdStack.empty()) {
		std::cout << stdStack.top() << " ";
		stdStack.pop();
	}
	std::cout << std::endl;

	return 0;
}