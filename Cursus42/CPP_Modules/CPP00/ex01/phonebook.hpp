/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:53:47 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/21 10:56:50 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string	FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
		int index;
	public:
		Contact();
		~Contact();
		std::string GetInfo(std::string str);
		std::string PrintLen(std::string str);
		void View(void);
		void Add(int i);
		void Display(void);
};

class PhoneBook {
    private:
        Contact	Contacts[8];
		int	amount;
	public:
		PhoneBook();
		~PhoneBook();
		void Start(void);
		void AddContact(void);
		void Search(void);
};

#endif