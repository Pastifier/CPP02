/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:57:42 by ebinjama          #+#    #+#             */
/*   Updated: 2024/08/19 06:23:00 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed cross_product(Point const a, Point const b, Point const c);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = cross_product(a, b, c);
	Fixed abp = cross_product(a, b, point);
	Fixed bcp = cross_product(b, c, point);
	Fixed cap = cross_product(c, a, point);

	if (( abc >= 0 && abp >= 0 && bcp >= 0 && cap >= 0 )
		|| ( abc <= 0 && abp <= 0 && bcp <= 0 && cap <= 0 ))
		return true;
	return false;
}

Fixed cross_product(Point const a, Point const b, Point const c)
{
	Fixed x1 = b.getX() - a.getX();
	Fixed y1 = b.getY() - a.getY();
	Fixed x2 = c.getX() - a.getX();
	Fixed y2 = c.getY() - a.getY();

	return (x1 * y2 - x2 * y1);
}
