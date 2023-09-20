/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:27:05 by mwagner           #+#    #+#             */
/*   Updated: 2023/09/20 15:27:08 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator result = std::find(container.begin(), container.end(), value);

	if (result == container.end()) {
		throw std::runtime_error("Value not found in container");
	}
	return result;
}

#endif //EASYFIND_HPP