#include "solution.h"
#include <deque>
#include <algorithm>
#include <iostream>
#include <assert.h>

int material(const std::vector<int>& spaceship) {
	std::deque<std::pair<int, int>> relevantColumns;
	int previousHeight = 0;
	int leftHeighest = 0;
	int leftHeighestIndex = -1;
	// spikes queue should never be empty as it would require checking in a few places
	relevantColumns.push_back({ leftHeighestIndex, leftHeighest });

	// create a deque of columns that are relevant
	for (int i = 0; i < spaceship.size(); i++) {
		int height = spaceship[i];

		if (height > previousHeight) {
			auto indexHeightPair = relevantColumns.back();
			while (indexHeightPair.second <= height && leftHeighestIndex < indexHeightPair.first) {
				relevantColumns.pop_back();
				indexHeightPair = relevantColumns.back();
			}
			relevantColumns.push_back({ i, height });
		}

		if (height >= leftHeighest) {
			leftHeighest = height;
			leftHeighestIndex = i;
		}

		previousHeight = height;
	}

	int result = 0;
	auto start = relevantColumns.front();
	auto end = start;
	relevantColumns.pop_front();

	// sum all possible liquid blocks between relevant columns
	while (!relevantColumns.empty()) {
		start = end;
		end = relevantColumns.front();
		relevantColumns.pop_front();
		int height = std::min(start.second, end.second);

		for (int i = start.first + 1; i < end.first; i++) {
			result += height - spaceship[i];
		}
	}

	return result;
}

void testMaterial() {

	// given examples
	int material1 = material({ 6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3 });
	assert(material1 == 83);
	int material2 = material({ 6, 2, 1, 1, 8, 0, 5, 5, 0, 1, 8, 9, 6, 9, 4, 8, 0, 0 });
	assert(material2 == 50);

	// my own test cases
	int material3 = material({ });
	assert(material3 == 0);
	int material4 = material({ 10 });
	assert(material4 == 0);
	int material5 = material({ 1, 2, 3, 4 });
	assert(material5 == 0);
	int material6 = material({ 4, 3, 2, 1, 0 });
	assert(material6 == 0);
	int material7 = material({ 4, 3, 2, 1, 0, 4 });
	assert(material7 == 10);
	int material8 = material({ 2, 1, 2, 1, 2 });
	assert(material8 == 2);
}
