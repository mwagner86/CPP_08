/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:33:40 by mwagner           #+#    #+#             */
/*   Updated: 2023/09/20 15:29:12 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <ctime>
#include "easyfind.hpp"

// Populate a vector with 42 random numbers
void randomPopulateVector(std::vector<int> &myVector) {
	std::srand(std::time(0));

	for (int i = 0; i < 42; ++i) {
		int randomNumber = std::rand() % 100;
		myVector.push_back(randomNumber);
	}
}

// Populate a list with 42 random numbers
void randomPopulateList(std::list<int> &myList) {
	std::srand(std::time(0));

	for (int i = 0; i < 42; ++i) {
		int randomNumber = std::rand() % 100;
		myList.push_back(randomNumber);
	}
}

int main() {

	// Try & catch with vector
	try {
		std::vector<int> myVector;
		randomPopulateVector(myVector);

		int searchValue = 42;
		std::vector<int>::iterator result = easyfind(myVector, searchValue);

		std::cout << "Found " << searchValue << " in Vector at index " << (result - myVector.begin()) << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Caught Error in Vector: " << e.what() << std::endl;
	}

	// Try & catch with list
	try {
		std::list<int> myList;
		randomPopulateList(myList);

		int searchValue = 42;
		std::list<int>::iterator result = easyfind(myList, searchValue);

		std::cout << "Found " << searchValue << " in List at index " << std::distance(myList.begin(), result) << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Caught Error in List: " << e.what() << std::endl;
	}
	return 0;
}
