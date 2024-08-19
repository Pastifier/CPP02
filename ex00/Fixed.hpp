/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:27:14 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/19 05:17:26 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
class Fixed
{
private:
	int _fixedPointValue;
	static int const _mantissaBitNum = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};
