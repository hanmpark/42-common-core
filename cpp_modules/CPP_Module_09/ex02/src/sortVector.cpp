/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:49:16 by hanmpark          #+#    #+#             */
/*   Updated: 2024/04/01 02:54:03 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	PmergeMe::insertionSortPairs(vector<vector<unsigned int> > &pairs, size_t n) {
	vector<unsigned int>	key;
	int						j;

	for (size_t i = 1; i < n; i++) {
		key = pairs[i];
		j = i - 1;
		while (j >= 0 && pairs[j][1] > key[1]) {
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}
}

vector<vector<unsigned int> >	PmergeMe::createPairs(vector<unsigned int> const &nums, size_t n) {
	vector<vector<unsigned int> >	sortedPairs(n / 2);
	size_t							j = 0;

	for (size_t i = 0; i < n; i += 2) {
		if (nums[i] > nums[i + 1]) {
			sortedPairs[j].push_back(nums[i + 1]);
			sortedPairs[j].push_back(nums[i]);
		} else {
			sortedPairs[j].push_back(nums[i]);
			sortedPairs[j].push_back(nums[i + 1]);
		}
		j++;
	}
	insertionSortPairs(sortedPairs, n / 2);
	return sortedPairs;
}

vector<size_t>	PmergeMe::buildJacobSthalSequenceVector(size_t size) {
	vector<size_t>	sequence;

	for (size_t i = 3; jacobsthalNumbers(i) < size - 1; i++) {
		sequence.push_back(jacobsthalNumbers(i));
	}
	return sequence;
}

vector<unsigned int> PmergeMe::create_s(vector<vector<unsigned int> > const &pairs) {
	vector<unsigned int>	s, pend;

	for (size_t i = 0; i < pairs.size(); i++) {
		pend.push_back(pairs[i][0]);
		s.push_back(pairs[i][1]);
	}
	s.insert(s.begin(), pend[0]);

	vector<size_t>	jacobSthalSequence = buildJacobSthalSequenceVector(pend.size()), indexSequence(1, 0);
	size_t			i = 0;

	while (indexSequence.size() != pend.size()) {
		if (std::find(indexSequence.begin(), indexSequence.end(), i) != indexSequence.end()) {
			if (!jacobSthalSequence.empty()) {
				i = jacobSthalSequence[0] - 1;
				jacobSthalSequence.erase(jacobSthalSequence.begin());
			} else {
				i = pend.size() - 1;
			}
		}
		indexSequence.push_back(i);
		s.insert(std::upper_bound(s.begin(), s.end(), pend[i]), pend[i]);
		i--;
	}
	return s;
}

void	PmergeMe::fordJohnson(vector<unsigned int> &nums) {
	unsigned int	straggler = 0;
	bool			isOdd;

	if ((isOdd = nums.size() % 2 != 0)) {
		straggler = nums.back();
		nums.pop_back();
	}
	vector<vector<unsigned int> >	pairs = createPairs(nums, nums.size());
	nums = create_s(pairs);
	if (isOdd)
		nums.insert(std::lower_bound(nums.begin(), nums.end(), straggler), straggler);
}
