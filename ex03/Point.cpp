/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:37:02 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/19 06:21:12 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(Point const& other) : _x(other._x), _y(other._y)
{
}

Point& Point::operator=(Point const& other)
{
	(void)other;
	return (*this);
}

bool Point::operator==(Point const& other) const {
	return (_x.toFloat() == other._x.toFloat()
			&& _y.toFloat() == other._y.toFloat());
}

Point::~Point()
{
}

Fixed const& Point::getX() const
{
	return _x;
}

Fixed const& Point::getY() const
{
	return _y;
}
