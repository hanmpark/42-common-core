/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:52:03 by hanmpark          #+#    #+#             */
/*   Updated: 2024/05/03 02:11:26 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp() {
	std::time_t currentTime = std::time(nullptr);
	struct tm* timeInfo = std::localtime(&currentTime);

	char buffer[20];
	std::strftime(buffer, sizeof(char) * 20, "%Y%m%d_%H%M%S", timeInfo);
	std::cout << "[" << buffer << "] ";
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account() {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

int	Account::getNbAccounts() { return _nbAccounts; }

int	Account::getTotalAmount() { return _totalAmount; }

int	Account::getNbDeposits() { return _totalNbDeposits; }

int	Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;

	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout	<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;

	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;
	
	if (_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:" << withdrawal;

	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout	<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;

	_totalAmount -= withdrawal;
	return true;
}

int	Account::checkAmount() const { return _amount; }
