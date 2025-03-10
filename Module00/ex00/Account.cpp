/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:54:29 by jinam             #+#    #+#             */
/*   Updated: 2025/03/10 18:54:41 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
Account::Account(int id, int val)
	:id(id), value(val)
{
}
const int	&Account::getId (void) const
{
	return(this->id);
}

const double	&Account::getValue(void) const
{
	return (this->value);
}

void	Account::deposit(int amount)
{
	value += amount;
}

bool	Account::withdraw(int amount)
{
	if (amount < value)
		return false;
	value -= amount;
	return true;
}

void	Account::setValue(int amount)
{
	value = amount;
}

