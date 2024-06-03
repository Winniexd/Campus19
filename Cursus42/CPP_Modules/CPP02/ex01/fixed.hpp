/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:28:56 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 13:51:11 by mdreesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
class Fixed {
    private :
        int fixed;
        static const int bits = 8;
    public :
        Fixed(void);
        Fixed(const int nb);
        Fixed(const float fl);
        ~Fixed();
        Fixed(const Fixed &f);
        Fixed& operator=(const Fixed &f);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, Fixed const &f);
