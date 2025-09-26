/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:59:42 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/01 17:25:07 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::insertionSortPairs(list<list<unsigned int> > &pairs) {
	list<list<unsigned int> >::iterator	i, j, tmp;
	list<unsigned int>					key;

	for (i = pairs.begin(); i != pairs.end(); i++) {
		if (i == pairs.begin())
			continue;
		key = *i;
		j = i;
		j--;
		while (j->back() > key.back()) {
			tmp = j;
			*++tmp = *j;
			if (j == pairs.begin()) {
				*j = key;
				break;
			}
			j--;
			if (j->back() < key.back()) {
				*++j = key;
				break;
			}
		}
	}
}

list<list<unsigned int> >	PmergeMe::createPairs(list<unsigned int> const &nums, size_t n) {
	list<list<unsigned int> >	sortedPairs;
	list<unsigned int>::const_iterator	it1 = nums.begin(), it2;

	for (size_t i = 0; i < n; i += 2) {
		it2 = it1;
		std::advance(it2, 1);
		list<unsigned int>	tempList;
		if (*it1 > *it2) {
			tempList.push_back(*it2);
			tempList.push_back(*it1);
		} else {
			tempList.push_back(*it1);
			tempList.push_back(*it2);
		}
		sortedPairs.push_back(tempList);
		std::advance(it2, 1);
		it1 = it2;
	}
	insertionSortPairs(sortedPairs);
	return sortedPairs;
}

list<size_t>	PmergeMe::buildJacobSthalSequenceList(size_t size) {
	list<size_t>	sequence;

	for (size_t i = 3; jacobsthalNumbers(i) < size - 1; i++) {
		sequence.push_back(jacobsthalNumbers(i));
	}
	return sequence;
}

list<unsigned int> PmergeMe::create_s(list<list<unsigned int> > const &pairs) {
	list<unsigned int> s, pend;

	for (list<list<unsigned int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++) {
		pend.push_back(it->front());
		s.push_back(it->back());
	}
	s.push_front(pend.front());

	list<size_t> jacobSthalSequence = buildJacobSthalSequenceList(pend.size());
	list<size_t> indexSequence(1, 0);
	size_t i = 0;

	while (indexSequence.size() != pend.size()) {
		if (std::find(indexSequence.begin(), indexSequence.end(), i) != indexSequence.end()) {
			if (!jacobSthalSequence.empty()) {
				i = jacobSthalSequence.front() - 1;
				jacobSthalSequence.pop_front();
			} else {
				i = pend.size() - 1;
			}
		}
		indexSequence.push_back(i);
		list<unsigned int>::iterator	tmp = pend.begin();
		std::advance(tmp, i);
		s.insert(std::upper_bound(s.begin(), s.end(), *tmp), *tmp);
		i--;
	}
	return s;
}

void	PmergeMe::fordJohnson(list<unsigned int> &nums) {
	unsigned int	straggler = 0;
	bool			isOdd;

	if ((isOdd = nums.size() % 2 != 0)) {
		straggler = nums.back();
		nums.pop_back();
	}
	list<list<unsigned int> >	pairs = createPairs(nums, nums.size());
	nums = create_s(pairs);
	if (isOdd)
		nums.insert(std::lower_bound(nums.begin(), nums.end(), straggler), straggler);
}
