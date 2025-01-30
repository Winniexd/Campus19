/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:08:22 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/29 18:48:35 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_HPP
#define FIND_HPP
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int n) {
    return (std::find(container.begin(), container.end(), n));
}

#endif