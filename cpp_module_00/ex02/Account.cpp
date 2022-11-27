/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:22:27 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/27 16:24:46 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_nbDeposits = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	bool	valid = true;

	if (withdrawal > this->_amount)
		valid = false;

	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";

	if (valid) {
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals;
	}
	else
		std::cout << "refused";
	std::cout << std::endl;
	return valid;
}

int Account::checkAmount( void ) const {
	return (this->_amount > 0);
}

void Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

static std::ostream& field(std::ostream& o) {
    return o << std::setfill('0') << std::setw(2);
}

void Account::_displayTimestamp( void ) {
	time_t ntime = time(NULL);
    struct tm *ltime = localtime(&ntime);
    std::cout << '[';
	std::cout << field << ltime->tm_year + 1900;
	std::cout << field << ltime->tm_mon;
	std::cout << field << ltime-> tm_mday;
	std::cout << "_";
    std::cout << field << ltime->tm_hour;
	std::cout << field << ltime->tm_min;
	std::cout << field << ltime->tm_sec;
	std::cout << "] ";
}
//diff <(cut -b18- t) <(cut -b18- 19920104_091532.log)
