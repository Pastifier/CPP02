/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:07:13 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/19 04:41:38 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0b00000000000000000000000000000000;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

// 00000001 00000000 00000000 00000000

Fixed::Fixed(const int initWith)
{
	std::cout << "Int constructor called";
	_rawBits = initWith << _fractionalBitNum;
	if (initWith >= 0b00000001000000000000000000000000
		|| (initWith & 0b10000000000000000000000000000000) == 0b10000000000000000000000000000000)
		std::cout << ", but overflow will occur";
	std::cout << std::endl;
}

Fixed::Fixed(const float initWith)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = _myRoundF(initWith * (1 << _fractionalBitNum));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other) {
		_rawBits = other._rawBits;
	}
	return (*this);
}

float Fixed::toFloat() const
{
	return (float)_rawBits / (1 << _fractionalBitNum);
}

int Fixed::toInt() const
{
	return _rawBits >> _fractionalBitNum;
}

float Fixed::_myRoundF(const float val) const
{
	int signBit;
	int biasedExponent;

	union bitFieldFI {
		float repF;
		__uint32_t repI;
	}	bitField;
	bitField.repF = val;


	signBit = bitField.repI & 0x80000000;
	biasedExponent = (int)((bitField.repI & 0x7f800000) >> 23) - 127;

	if (biasedExponent < 23) {
		if (biasedExponent < 0) {
			bitField.repI &= 0x80000000;
			if (biasedExponent == -1)
				bitField.repI |= ((__uint32_t)127 << 23);
		} else {
			unsigned int signAndExpMask = 0x007fffff >> biasedExponent;
			if ((bitField.repI & signAndExpMask) == 0)
				return val;
			bitField.repI += 0x00400000 >> biasedExponent;
			bitField.repI &= ~signAndExpMask;
		}
	} else {
		if (biasedExponent == 128) {
			std::cout << "WARNING: " << val << " is not a normalised value!" << std::endl;
			return val + val;
		} else
			return val;
	}

	return bitField.repF;
}

// But how does the exponent tell us the number of fractional bits? Why does it work like that?
std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum)
{
	os << fixedNum.toFloat();
	return os;
}
