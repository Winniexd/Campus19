/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:52:31 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/24 13:20:10 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	ScalarConverter::convert(argv[1]);
	return 0;
}