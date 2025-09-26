/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:28:05 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/01 17:27:51 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Canonical form

PmergeMe::PmergeMe(PmergeMe const &copy) {
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		_timeVec = rhs._timeVec;
		_timeLst = rhs._timeLst;
		_vec = rhs._vec;
		_lst = rhs._lst;
	}
	return *this;
}

PmergeMe::PmergeMe(int const &argc, char **argv) : _timeVec(0.0), _timeLst(0.0) {
	for (int i = 1; i < argc; i++) {
		isUnsignedInteger(static_cast<string>(argv[i]));
		_vec.push_back(static_cast<unsigned int>(strtoul(argv[i], NULL, 10)));
		_lst.push_back(static_cast<unsigned int>(strtoul(argv[i], NULL, 10)));
	}
	checkDuplicate(_vec);
}

// Private methods

size_t	PmergeMe::jacobsthalNumbers(size_t n) {
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	}
	return jacobsthalNumbers(n - 1) + 2 * jacobsthalNumbers(n - 2);
}

void	PmergeMe::checkDuplicate(vector<unsigned int> nums) {
	std::sort(nums.begin(), nums.end());
	for (size_t i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1]) {
			throw FoundDuplicateException();
		}
	}
}

void	PmergeMe::isUnsignedInteger(const string str) {
	if (str.empty() || str.length() > 10)
		throw NotUnsignedIntegerException();

	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (it == str.begin() && (*it == '0' || (!isdigit(*it) && *it == '+'))) {
			throw NotUnsignedIntegerException();
		} else if (!isdigit(*it)) {
			throw NotUnsignedIntegerException();
		}
	}

	unsigned long long	value = strtoull(str.c_str(), NULL, 10);

	if (value > static_cast<unsigned long long>(std::numeric_limits<unsigned int>::max()))
		throw NotUnsignedIntegerException();
}

// Public methods

void	PmergeMe::executeMergeInsertion() {
	clock_t	start, end;

	cout << "Before:  " << _vec << endl;
	start = clock();
	fordJohnson(_vec);
	end = clock();
	_timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	fordJohnson(_lst);
	end = clock();
	_timeLst = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	cout << "After :  " << _lst << endl;
	// cout << "After :  " << _vec << endl;
	cout << "Time to process a range of " << _vec.size() << " elements with std::vector<unsigned int> : " << _timeVec << " us" << endl;
	cout << "Time to process a range of " << _lst.size() << " elements with std::list<unsigned int>   : " << _timeLst << " us" << endl;
}

// Exceptions

char const	*PmergeMe::NotUnsignedIntegerException::what() const throw () {
	return "Argument is not an unsigned integer.";
}

char const	*PmergeMe::FoundDuplicateException::what() const throw () {
	return "Found a duplicate.";
}

std::ostream	&operator<<(std::ostream &o, vector<unsigned int> &vec) {
	vector<unsigned int>::const_iterator	it;

	for (it = vec.begin(); it != vec.end(); it++) {
		cout << *it << (it + 1 != vec.end() ? " " : "");
	}

	return o;
}

std::ostream	&operator<<(std::ostream &o, list<unsigned int> &lst) {
	list<unsigned int>::const_iterator	it;

	for (it = lst.begin(); it != lst.end(); it++) {
		cout << *it << " ";
	}

	return o;
}
