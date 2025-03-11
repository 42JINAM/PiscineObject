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

void	testNormal(void)
{
	Bank	bank;

	Account a = bank.createAccount(5000);

	bank.depositAccount(a, 5000);
	std::cout << a << std::endl;
	
}

void	testError(void)
{
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage ./ex00 [normal/error]" << std::endl;
		return (1);
	}
	std::string	str(argv[1]);
	if (str.compare("normal"))
		testNormal();
	else if (str.compare("error"))
		testError();
	return (0);
}
