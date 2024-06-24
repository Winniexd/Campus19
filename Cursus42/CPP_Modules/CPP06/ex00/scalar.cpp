/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:00:10 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/24 13:44:45 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

void ScalarConverter::convert(char *arg) {
	std::cout << typeid(*arg).name() << std::endl;
}