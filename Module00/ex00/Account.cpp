/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:54:29 by jinam             #+#    #+#             */
/*   Updated: 2025/03/11 15:31:15 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
Account::Account()
	:id(-1), value(0)
{
}
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

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return (p_os);
}

