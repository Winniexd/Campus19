/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:53:47 by mdreesen          #+#    #+#             */
/*   Updated: 2024/02/17 17:25:57 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class Contact {
	private:
		std::string	FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
		int index;
	public:
		void Init(int i);
		std::string GetInfo(std::string str);
};

class PhoneBook {
    private:
        Contact	Contacts[8];
	public:
		void Start(void);
		void AddContact(void);
		void Search(void);
};

#endif