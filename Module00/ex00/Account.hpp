/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:14:37 by jinam             #+#    #+#             */
/*   Updated: 2025/03/11 16:41:02 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <ostream>
class Bank;
class Account
{
private:
	const int		id;
	double			value;

private:
	void		deposit(double amount);
	bool		withdraw(double amount);
	void		setValue(double amount);
public:
	Account();
	Account(int id, double val);
	const int		&getId() const;
	const double	&getValue() const;
	friend class Bank;
	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
};

#endif // !ACCOUNT_HPP
