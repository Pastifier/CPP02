/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:06:45 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/19 05:18:11 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
public:
	Fixed(const int initWith);
	Fixed(const float initWith);
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++(void);
	Fixed& operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static Fixed const& min(Fixed const& a, Fixed const& b);
	static Fixed const& max(Fixed const& a, Fixed const& b);
	
	float toFloat(void) const;
	int toInt(void) const;
private:
	static int const _fractionalBitNum = 8;
	int _rawBits;
	float _myRoundF(const float val) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum);