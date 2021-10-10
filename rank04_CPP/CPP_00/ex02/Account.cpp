/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louie <louie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:01:56 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/10 17:28:07 by louie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

//Getters

int	Account::getNbAccounts( void )	{return (_nbAccounts);}

int	Account::getTotalAmount( void )	{return (_totalAmount);}

int	Account::getNbDeposits( void )	{return (_totalNbDeposits);}

int	Account::getNbWithdrawals( void )	{return (_totalNbWithdrawals);}

//

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
	<< " "
	<< "accounts:" << Account::getNbAccounts()
	<< ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals" << Account::getNbWithdrawals();
}

//Constructor

Account::Account( int initial_deposit )
: _accountIndex(Account::_nbAccounts), _amount(initial_deposit), 
_nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << " "
	<< "index:" << this->_accountIndex
	<< ";amount:" << checkAmount()
	<< ";created" << std::endl;
}

//Destructor

Account::~Account( void )
{
	Account::_displayTimestamp();

	std::cout << " "
	<< "index:" << this->_accountIndex
	<< ";amount:" << checkAmount()
	<< ";closed" << std::endl;
}

int	Account::checkAmount( void ) const { return (this->_amount); }


void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();

	std::cout << " "
	<< "index:" << this->_accountIndex
	<< ";p_amount:" << checkAmount()
	<< ";";

	this->_amount += deposit;
	this->_nbDeposits += 1;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	std::cout << "deposit:" << deposit
	<< ";amount:" << checkAmount()
	<< ";nb_deposits:" << this->_nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	std::cout << " "
	<< "index:" << this->_accountIndex
	<< ";p_amount:" << checkAmount()
	<< ";";

	if ( checkAmount() < withdrawal )
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;

	std::cout << "withdrawal:" << withdrawal
	<< ";amount:" << checkAmount()
	<< ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;

	return (true);
}


void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();

	std::cout << " "
	<< "index:" << this->_accountIndex
	<< ";amount:" << checkAmount()
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}


void	Account::_displayTimestamp( void )
{
	char		buffer[18];
	time_t		rawtime;
	struct tm*	timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime( buffer, 18, "[%Y%m%d_%H%M%S]", timeinfo );
	std::cout << buffer;
}


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( void ) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {}
