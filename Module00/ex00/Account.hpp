/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:14:37 by jinam             #+#    #+#             */
/*   Updated: 2025/03/11 15:31:30 by jinam            ###   ########.fr       */
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
	void		deposit(int amount);
	bool		withdraw(int amount);
	void		setValue(int amount);
public:
	Account();
	Account(int id, int val);
	const int		&getId() const;
	const double	&getValue() const;
	friend class Bank;
	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account);
};

#endif // !ACCOUNT_HPP
