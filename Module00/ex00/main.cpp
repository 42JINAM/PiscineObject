/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:16:12 by jinam             #+#    #+#             */
/*   Updated: 2025/03/11 16:42:44 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>
#include <string>

void	createTest(void)
{
	Bank			bank;
	const Account 	&a = bank.createAccount(5000);
	const Account 	&b = bank.createAccount(10000);

	// createAccount
	std::cout << "== createAccount ==" << std::endl;
	std::cout << "a account (5000) :" << a << std::endl;
	std::cout << "b account (10000) : " << b << std::endl;
	std::cout << "Bank liquidity : " << bank.getLiquidity() << std::endl;
	std::cout << "== createAccount ==" << std::endl;
	std::cout << std::endl;
}

void	depositTest(void)
{
	Bank			bank;
	const Account 	&a = bank.createAccount(5000);

	std::cout << "== depositAccount (5000 + 10000) == " << std::endl;
	std::cout << a << std::endl;
	bank.depositAccount(a, 10000);
	std::cout << a << std::endl;
	std::cout << "== depositAccount  == " << std::endl;
	std::cout << std::endl;
}

void	modifyTest(void)
{
	Bank			bank;
	const Account	&a = bank.createAccount(5000);

	std::cout << "== modifyAccount (5000 -> 50000) ==" << std::endl;
	std::cout << a << std::endl;
	bank.modifyAccount(a, 50000);
	std::cout << a << std::endl;
	std::cout << "== modifyAccount ==" << std::endl;
	std::cout << std::endl;
}

void	loanToClientTest(void)
{
	Bank			bank;
	const Account	&a = bank.createAccount(0);

	std::cout << "== loanToAccount (0 -> 5000) ==" << std::endl;
	std::cout << a << std::endl;
	bank.setLiquidity(5000);
	std::cout << "Bank liquidity : " << bank.getLiquidity() << std::endl;
	bank.loanToCustomer(a, 5000);
	std::cout << a << std::endl;
	std::cout << "Bank liquidity : " << bank.getLiquidity() << std::endl;
	std::cout << "== loanToAccount ==" << std::endl;
	std::cout << std::endl;
}

void	deleteTest(void)
{
	Bank			bank;
	const Account	&a = bank.createAccount(500);

	std::cout << bank << std::endl;
	bank.deleteAccount(a);
	std::cout << bank << std::endl;
}

void	testNormal(void)
{
	createTest();
	depositTest();
	modifyTest();
	loanToClientTest();
	deleteTest();
}

void	depositExceptionTest(void)
{
	Bank		bank;
	Account		b(42, 5000);

	std::cout << "== depositAccount error ==" << std::endl;
	std::cout << bank << std::endl;
	bank.depositAccount(b, 5000);
	std::cout << bank << std::endl;
	std::cout << "== depositAccount error ==" << std::endl;
	std::cout << std::endl;
}

void	modifyExceptionTest(void)
{
	Bank		bank;
	Account		b(42, 5000);

	std::cout << "== modifyAccount error ==" << std::endl;
	bank.modifyAccount(b, 100000);
	std::cout << b << std::endl;
	std::cout << bank << std::endl;
	std::cout << "== modifyAccount error ==" << std::endl;
	std::cout << std::endl;
}

void	deleteExceptionTest(void)
{
	Bank			bank;
	const Account	&real_a = bank.createAccount(50000);
	Account			fake_a(0, 42);

	std::cout << "== deleteAccount error ==" << std::endl;
	std::cout << bank << std::endl;
	bank.deleteAccount(fake_a);
	std::cout << real_a << std::endl;
	std::cout << bank << std::endl;
	std::cout << "== deleteAccount error ==" << std::endl;

}



void	testError(void)
{
	depositExceptionTest();
	modifyExceptionTest();
	deleteExceptionTest();
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage ./ex00 [1. normal test 2. exception test]" << std::endl;
		return (1);
	}
	std::string	str(argv[1]);
	if (str.compare("1") == 0)
		testNormal();
	else if (str.compare("2") == 0)
		testError();
	return (0);
}
