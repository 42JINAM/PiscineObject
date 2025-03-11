/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:08:07 by jinam             #+#    #+#             */
/*   Updated: 2025/03/11 16:15:51 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"
#include "Account.hpp"
Bank::Bank()
{
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

Bank::accountIter	Bank::findClientAccount(int id)
{
	accountIter	it;
	for (it = this->clientAccounts.begin(); it != this->clientAccounts.end();it++)
	{
		Account	*acc = *it;
		if (acc->id == id)
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

const Account&	Bank::createAccount(int value)
{
	Account *newAccount = new Account(nextAccountId++, value * 0.95);
	this->liquidity += value * 0.05;
	this->clientAccounts.push_back(newAccount);
	return (*newAccount);
}

void	Bank::deleteAccount(const Account &account)
{
	accountIter	iter = findClientAccount(account.id);

	if (iter != this->clientAccounts.end())
		this->clientAccounts.erase(iter);
}

void	Bank::modifyAccount(const Account &account, int value)
{
	accountIter	iter = findClientAccount(account.id);
	
	if (iter != this->clientAccounts.end())
	{
		Account	*acc = *iter;

		acc->setValue(value);
	}
}

void	Bank::depositAccount(const Account &account, int value)
{
	accountIter	iter = findClientAccount(account.id);

	if (iter != this->clientAccounts.end())
	{
		Account	*acc = *iter;

		this->liquidity += value * 0.05;
		acc->deposit(value * 0.95);
	}
}

bool	Bank::loanToCustomer(const Account &account, int value)
{
	accountIter	iter = findClientAccount(account.id);

	if (value > this->liquidity || iter == this->clientAccounts.end())
		return (false);
	this->liquidity -= value;
	depositAccount(account, value);
	return (true);
}
void			displayAccount(const Account &account)
{
}

