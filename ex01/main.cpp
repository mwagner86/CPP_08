/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:34:01 by mwagner           #+#    #+#             */
/*   Updated: 2023/09/21 11:50:41 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
// Subject main function
int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
*/

int main() {

	try {
		// Test default constructor
		Span span1(5);
		if (VERBOSE) std::cout << "\n----- Test 1: Default Constructor -----" << std::endl;

		// Test adding numbers
		span1.addNumber(10);
		span1.addNumber(3);
		span1.addNumber(8);
		span1.addNumber(15);
		span1.addNumber(1);

		// Test shortest and longest span
		std::cout << "Shortest Span: " << span1.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << span1.longestSpan() << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		// Test exception when adding more elements than allowed
		Span span2(3);
		if (VERBOSE) std::cout << "\n----- Test 2: Adding More Elements Than Allowed -----" << std::endl;
		span2.addNumber(10);
		span2.addNumber(3);
		span2.addNumber(8);
		span2.addNumber(15); // Should throw an exception

	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		// Test exception when calculating span with less than 2 elements
		Span span3(1);
		if (VERBOSE) std::cout << "\n----- Test 3: Calculating Span with Less Than 2 Elements -----" << std::endl;
		span3.addNumber(10);
		span3.shortestSpan(); // This should throw an exception
		span3.longestSpan();  // This should throw an exception

	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Test with a large number of elements
	try {
		if (VERBOSE) std::cout << "\n----- Test 4: Large Number of Elements -----" << std::endl;
		Span span4(20000);
		for (int i = 1; i <= 10000; ++i) {
			span4.addNumber(i);
		}
		std::cout << "Shortest Span: " << span4.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << span4.longestSpan() << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		// Test default constructor
		Span spanDefault(10);
		if (VERBOSE) std::cout << "\n----- Test 5: Default Constructor -----" << std::endl;

		// Test adding numbers
		spanDefault.addNumber(10);
		spanDefault.addNumber(3);
		spanDefault.addNumber(8);
		spanDefault.addNumber(15);
		spanDefault.addNumber(1);

		// Test shortest and longest span
		std::cout << "Shortest Span: " << spanDefault.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << spanDefault.longestSpan() << std::endl;

		// Test copy constructor
		Span spanCopy = spanDefault;
		if (VERBOSE) std::cout << "\n----- Test 6: Copy Constructor -----" << std::endl;

		// Test adding numbers to the copied object
		spanCopy.addNumber(7);
		spanCopy.addNumber(20);

		// Check if span1 and span2 are independent
		std::cout << "spanDefault Shortest Span: " << spanDefault.shortestSpan() << std::endl; // Should not be affected
		std::cout << "spanCopy Shortest Span: " << spanCopy.shortestSpan() << std::endl;
		std::cout << "spanDefault Longest Span: " << spanDefault.longestSpan() << std::endl;   // Should not be affected
		std::cout << "spanCopy Longest Span: " << spanCopy.longestSpan() << std::endl;

		// Test assignment operator
		Span spanAssignment(10);
		if (VERBOSE) std::cout << "\n----- Test 7: Assignment Operator -----" << std::endl;
		spanAssignment = spanDefault;

		// Test adding numbers to the assigned object
		spanAssignment.addNumber(5);
		spanAssignment.addNumber(18);

		// Check if spanDefault and spanAssignment are independent
		std::cout << "spanDefault Shortest Span: " << spanDefault.shortestSpan() << std::endl; // Should not be affected
		std::cout << "spanAssignment Shortest Span: " << spanAssignment.shortestSpan() << std::endl;
		std::cout << "spanDefault Longest Span: " << spanDefault.longestSpan() << std::endl;   // Should not be affected
		std::cout << "spanAssignment Longest Span: " << spanAssignment.longestSpan() << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	if (VERBOSE) std::cout << "\n----- Test 8: Add Multiple Numbers -----" << std::endl;

	Span spanMulti(10); // Create a Span object with a maximum of 10 elements

	int numbersToAddArray[] = {1, 9, 3, 36, 42, 128, -15, 12, 123};

	try {
		spanMulti.addRange(numbersToAddArray, numbersToAddArray + sizeof(numbersToAddArray) / sizeof(int));
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	// Check if Span works with addedRange
	std::cout << "Shortest Span: " << spanMulti.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << spanMulti.longestSpan() << std::endl;

	return 0;
}
