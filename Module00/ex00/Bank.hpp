/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:09:16 by jinam             #+#    #+#             */
/*   Updated: 2025/03/10 17:32:36 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_H
# define BANK_H

#include "Account.hpp"
#include <vector>
class Bank
{
private:
	double					liquidity;
	std::vector<Account *>	clientAccounts;
	int						nextAccountId;
private:
	Account	&findClientAccount(int id);

public:
	Bank();
	~Bank();
	const Account&	createAccount(int value);
	void			deleteAccount(const Account &account);
	void			modifyAccount(const Account &account, int value);
	bool			loanToCustomer(const Account &account, int value);
	void			displayAccount(const Account &account);
};

#endif // !BANK_H
