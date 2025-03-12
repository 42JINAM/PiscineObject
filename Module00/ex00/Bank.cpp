/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:08:07 by jinam             #+#    #+#             */
/*   Updated: 2025/03/11 16:40:18 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"
#include "Account.hpp"
#include <iostream>
#include <ostream>
Bank::Bank()
{
	this->liquidity = 0;
	this->nextAccountId = 0;
}

Bank::~Bank()
{
	accountIter it;
	for (it = this->clientAccounts.begin();it != this->clientAccounts.end();it++)
	{
		delete *it;
	}
}

Bank::Bank(double amount)
 : liquidity(amount)
{
}

Bank::accountIter	Bank::findClientAccount(const Account *account)
{
	accountIter	it;
	for (it = this->clientAccounts.begin(); it != this->clientAccounts.end();it++)
	{
		const Account	*acc = *it;
		if (acc == account)
			return it;
	}
	return clientAccounts.end();
}

void	Bank::setLiquidity(double amount)
{
	this->liquidity = amount;
}

const double	&Bank::getLiquidity(void)
{
	return (this->liquidity);
}

const Account&	Bank::createAccount(double value)
{
	Account *newAccount = new Account(nextAccountId++, value * 0.95);
	this->liquidity += value * 0.05;
	this->clientAccounts.push_back(newAccount);
	return (*newAccount);
}

void	Bank::deleteAccount(const Account &account)
{
	accountIter	iter = findClientAccount(&account);

	if (iter != this->clientAccounts.end())
		this->clientAccounts.erase(iter);
}

void	Bank::modifyAccount(const Account &account, int value)
{
	accountIter	iter = findClientAccount(&account);
	
	if (iter != this->clientAccounts.end())
	{
		Account	*acc = *iter;

		acc->setValue(value);
	}
}

void	Bank::depositAccount(const Account &account, int value)
{
	accountIter	iter = findClientAccount(&account);

	if (iter != this->clientAccounts.end())
	{
		Account	*acc = *iter;

		this->liquidity += value * 0.05;
		acc->deposit(value * 0.95);
	}
}

bool	Bank::loanToCustomer(const Account &account, int value)
{
	accountIter	iter = findClientAccount(&account);

	if (value > this->liquidity || iter == this->clientAccounts.end())
		return (false);
	this->liquidity -= value;
	depositAccount(account, value);
	return (true);
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;
    for (size_t i = 0; i < p_bank.clientAccounts.size(); ++i)
    {
        p_os << *(p_bank.clientAccounts[i]) << std::endl;
    }
    return p_os;
}

