/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:06:45 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/19 04:33:15 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	float toFloat(void) const;
	int toInt(void) const;
private:
	static int const _fractionalBitNum = 8;
	int _rawBits;
	float _myRoundF(const float val) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum);