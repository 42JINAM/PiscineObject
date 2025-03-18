/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:35:12 by jinam             #+#    #+#             */
/*   Updated: 2025/03/12 21:08:13 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
# define VECTOR2_HPP

class	Vector2
{
private:
	float	x;
	float	y;
public:
	Vector2(float x, float y);
	const float	&getX(void);
	const float	&getY(void);
	void	setX(float x);
	void	setY(float y);
	void	resize(float x, float y);
};
#endif
