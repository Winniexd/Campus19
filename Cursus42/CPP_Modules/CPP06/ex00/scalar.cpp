/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:00:10 by mdreesen          #+#    #+#             */
/*   Updated: 2025/01/25 12:15:36 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

void convertChar(std::string arg) {
	std::cout << "char: " << arg[0] << std::endl;
	std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(arg[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(arg[0]) << std::endl;
}

void convertInt(std::string arg) {
	int val = atoi(arg.c_str());
	if (val < 0 || val > 127)
		std::cout << "char: impossible" << std::endl;
	else if (val <= 32 || val == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(val) << std::endl;
	std::cout << "int: " << val << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

void convertFloat(std::string arg) {
	int val = atof(arg.c_str());
	if (val < 0 || val > 127)
		std::cout << "char: impossible" << std::endl;
	else if (val <= 32 || val == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(val) << std::endl;
	std::cout << "int: " << val << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

void convertDouble(std::string arg) {
	int val = atof(arg.c_str());
	if (val < 0 || val > 127)
		std::cout << "char: impossible" << std::endl;
	else if (val <= 32 || val == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(val) << std::endl;
	std::cout << "int: " << val << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

void printError() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: 0" << std::endl;
	std::cout << "float: 0" << std::endl;
	std::cout << "double: 0" << std::endl;
}

void convertMinInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}

void convertPlusInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}

void convertNan() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void parseArg(std::string arg) {
	size_t len = arg.length();

	if (std::isprint(arg[0]) && !isdigit(arg[0])) {
		if (len == 1)
			convertChar(arg);
		else if (arg == "-inf" || arg == "-inff")
			convertMinInf();
		else if (arg == "+inf" || arg == "+inff")
			convertPlusInf();
		else if (arg == "nan" || arg == "nanf")
			convertNan();
		else
			printError();
	}
	else if (arg[len - 1] == 'f') {
		unsigned int i = 0;
		while (isdigit(arg[i]) || arg[i] == '.')
			i++;
		if (i == len - 1)
			convertFloat(arg);
	}
	else if (arg.find('.') != std::string::npos) {
		unsigned int i = 0;
		while (isdigit(arg[i]) || arg[i] == '.')
			i++;
		if (i == len)
			convertDouble(arg);
	}
	else if (isdigit(arg[0])) {
		unsigned int i = 0;
		while (isdigit(arg[i]))
			i++;
		if (i == len)
			convertInt(arg);
	}
	else
		printError();
}

void ScalarConverter::convert(std::string arg) {
	parseArg(arg);
}