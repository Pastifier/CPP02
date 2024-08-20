/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:07:13 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/19 05:06:22 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <exception>

Fixed::Fixed()
{
	_rawBits = 0b00000000000000000000000000000000;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

// 00000001 00000000 00000000 00000000

Fixed::Fixed(const int initWith)
{
	_rawBits = initWith << _fractionalBitNum;
	if (initWith >= 0b00000001000000000000000000000000
		|| (initWith & 0b10000000000000000000000000000000) == 0b10000000000000000000000000000000)
		std::cout << "WARNING: object of type `Fixed` experienced overflow and/or bit-loss" << std::endl;
}

Fixed::Fixed(const float initWith)
{
	_rawBits = _myRoundF(initWith * (1 << _fractionalBitNum));
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other) {
		_rawBits = other._rawBits;
	}
	return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
	return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const
{
	return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
	return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	result._rawBits = _rawBits + other._rawBits;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	result._rawBits = _rawBits - other._rawBits;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;

	result._rawBits = ((long)_rawBits * (long)other._rawBits) >> _fractionalBitNum;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;

	if (other._rawBits == 0) 
		throw std::invalid_argument("Fixed-point exception: dividing by zero");
	result._rawBits = ((long)_rawBits << _fractionalBitNum) / other._rawBits;
	return result;
}

Fixed& Fixed::operator++(void)
{
	_rawBits++;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	_rawBits--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_rawBits++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_rawBits--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	return a < b ? a : b;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	return a > b ? a : b;
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
	int biasedExponent;

	union bitFieldFI {
		float repF;
		__uint32_t repI;
	}	bitField;
	bitField.repF = val;


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
			// return val + val;
			throw std::invalid_argument("Fixed-point exception: initialising with non-normalised floating-point value");
		} else
			return val;
	}

	return bitField.repF;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum)
{
	os << fixedNum.toFloat();
	return os;
}
