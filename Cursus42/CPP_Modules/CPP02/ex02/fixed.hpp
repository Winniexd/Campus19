/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreesen <mdreesen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:28:56 by mdreesen          #+#    #+#             */
/*   Updated: 2024/06/03 17:51:13 by mdreesen         ###   ########.fr       */
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
        Fixed operator+(const Fixed &f);
        Fixed operator-(const Fixed &f);
        Fixed operator*(const Fixed &f);
        Fixed operator/(const Fixed &f);
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(Fixed const &a, Fixed const &b);
        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(Fixed const &a, Fixed const &b);
        bool operator>(const Fixed &f);
        bool operator>=(const Fixed &f);
        bool operator<=(const Fixed &f);
        bool operator<(const Fixed &f);
        bool operator==(const Fixed &f);
        bool operator!=(const Fixed &f);
};

std::ostream& operator<<(std::ostream &out, Fixed const &f);
