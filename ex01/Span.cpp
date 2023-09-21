//
// Created by max on 9/20/23.
//


#include "Span.hpp"

Span::Span(unsigned int N) : _max_elements(N)	{
	if (VERBOSE)
		std::cout << COLOR_GREEN << "Default Constructor called" << COLOR_DEFAULT << std::endl;
}

Span::Span(const Span &src) : _max_elements(src._max_elements), _numbers(src._numbers)	{
	if (VERBOSE)
		std::cout << COLOR_PURPLE << "Copy constructor called" << COLOR_DEFAULT << std::endl;
	*this = src;
};

Span &	Span::operator=(Span const &rhs)	{
	if (VERBOSE)
		std::cout << COLOR_BLUE << "Assignment operator overload called" << COLOR_DEFAULT << std::endl;
	if (this != &rhs) {
		_max_elements = rhs._max_elements;
		_numbers = rhs._numbers;
	}
	return (*this);
};

Span::~Span()	{
	if (VERBOSE)
		std::cout << COLOR_RED << "Destructor called" << COLOR_DEFAULT << std::endl;
}

void Span::addNumber(int number) {
	if (_numbers.size() >= _max_elements) {
		throw std::runtime_error("Span is already full");
	}
	_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() <= 1) {
		throw std::runtime_error("Not enough elements to calculate shortest span");
	}
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortest) {
			shortest = span;
		}
	}
	return (shortest);
}

int Span::longestSpan() const {
	if (_numbers.size() <= 1) {
		throw std::runtime_error("Not enough elements to calculate longest span");
	}
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	return (sortedNumbers.back() - sortedNumbers.front());
}