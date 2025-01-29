/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:19:02 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/26 15:28:55 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <iostream>

template <typename T>
void swap(T x, T y) {
    T z = x;
    x = y;
    y = z;
}

template <typename T>
T min(T x, T y) {
    return (x < y ? x: y);
}

template <typename T>
T max(T x, T y) {
    return (x > y ? x: y);
}

#endif