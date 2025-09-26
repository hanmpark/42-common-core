/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:26:13 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/01 17:25:39 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <cctype>
# include <limits>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::list;

class PmergeMe {
private:
	double					_timeVec;
	double					_timeLst;
	vector<unsigned int>	_vec;
	list<unsigned int>		_lst;

	// Private methods

	void	isUnsignedInteger(const string str);
	void	checkDuplicate(vector<unsigned int> nums);

	size_t							jacobsthalNumbers(size_t n);
	vector<size_t>					buildJacobSthalSequenceVector(size_t size);
	list<size_t>					buildJacobSthalSequenceList(size_t size);

	void							insertionSortPairs(vector<vector<unsigned int> > &pairs, size_t n);
	vector<vector<unsigned int> >	createPairs(vector<unsigned int> const &nums, size_t n);
	vector<unsigned int>			create_s(vector<vector<unsigned int> > const &pairs);
	void							fordJohnson(vector<unsigned int> &nums);

	void							insertionSortPairs(list<list<unsigned int> > &pairs);
	list<list<unsigned int> >		createPairs(list<unsigned int> const &nums, size_t n);
	list<unsigned int>				create_s(list<list<unsigned int> > const &pairs);
	void							fordJohnson(list<unsigned int> &nums);

	void	insertionSort(list<unsigned int> &nums);
	void	mergeInsertionSort(list<unsigned int> &nums);

	PmergeMe();

public:
	PmergeMe(PmergeMe const &copy);
	~PmergeMe();
	PmergeMe	&operator=(PmergeMe const &rhs);

	PmergeMe(int const &argc, char **argv);

	// Public methods

	void	executeMergeInsertion();

	// Exceptions

	class NotUnsignedIntegerException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
	class FoundDuplicateException : public std::exception {
	public:
		virtual char const	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, vector<unsigned int> &vec);
std::ostream	&operator<<(std::ostream &o, list<unsigned int> &lst);

#endif
