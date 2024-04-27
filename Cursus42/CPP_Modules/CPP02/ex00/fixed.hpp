/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:28:56 by mdreesen          #+#    #+#             */
/*   Updated: 2024/04/27 14:32:28 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
    private :
        int f;
        static const int bits = 8;
    public :
        Fixed();
        ~Fixed();
        Fixed(Fixed &f);
        Fixed& operator=(Fixed &f);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};