/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:28:56 by mdreesen          #+#    #+#             */
/*   Updated: 2024/04/27 15:07:46 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed {
    private :
        int f;
        static const int bits = 8;
    public :
        Fixed(const int nb);
        Fixed(const float fl);
        ~Fixed();
        Fixed(Fixed &f);
        Fixed& operator=(Fixed &f);
        Fixed& operator<<(Fixed &f);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(Fixed &f, std::ostream &out);
