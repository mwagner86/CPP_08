/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:52:04 by mwagner           #+#    #+#             */
/*   Updated: 2023/09/21 11:52:07 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_SPAN_HPP
#define EX01_SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

#include "colors.hpp"


class Span {

public:

	Span(unsigned int N);
	Span(const Span & src);
	Span & operator=(const Span & rhs);
	~Span();
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;


private:

	unsigned int _max_elements;
	std::vector<int> _numbers;

};

#endif //EX01_SPAN_HPP
