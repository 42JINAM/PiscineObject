/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:43:51 by jinam             #+#    #+#             */
/*   Updated: 2025/03/12 21:09:03 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.hpp"
#include <cstdlib>
#include <iostream>
Vector2::Vector2(float x, float y)
{
	setX(x);
	setY(y);
}

void	Vector2::setX(float x)
{
	if (x < 0)
	{
		std::cout << "WRONG INPUT X (X < 0)" << std::endl;
		exit(0);
	}
	this->x = x;
}

void	Vector2::setY(float y)
{
	if (y < 0)
	{
		std::cout << "WRONG INPUT Y (Y < 0)" << std::endl;
		exit(0);
	}
	this->y = y;
}

const float	&Vector2::getX(void)
{
	return (this->x);
}

const float	&Vector2::getY(void)
{
	return (this->y);
}

void	Vector2::resize(float x, float y)
{
	if (x > this->x)
		this->x = x;
	if (y > this->y)
		this->y = y;
}
