/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:26:53 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/26 20:42:57 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *arr, int len, void (*func)(T &arg)) {
    for (int i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T>
void printValTemplate(T &val) {
    std::cout << val << std::endl;
}

#endif