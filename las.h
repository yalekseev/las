#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

namespace util {

/* O(n^2) */
template <typename Iterator>
int longest_alternating_subsequence(Iterator begin, Iterator end) {
    if (begin == end) {
        return 0;
    }

    std::vector<std::pair<int, int>> t(std::distance(begin, end) + 1);
    for (auto &p : t) {
        p.first = 1;
        p.second = 1;
    }

    auto max_length = 0;

    auto tIt1 = t.begin();
    for (Iterator sIt1 = std::next(begin); sIt1 != end; ++sIt1, ++tIt1) {
        auto tIt2 = t.begin();
        for (Iterator sIt2 = begin; sIt2 != sIt1; ++sIt2, ++tIt2) {
            if (*sIt1 > *sIt2) {
                if (tIt1->first < tIt2->second + 1) {
                    tIt1->first = tIt2->second + 1;
                }
            } else {
                if (tIt1->second < tIt2->first + 1) {
                    tIt1->second = tIt2->first + 1;
                }
            }
        }

        if (max_length < std::max(tIt1->first, tIt1->second)) {
            max_length = std::max(tIt1->first, tIt1->second);
        }
    }

    return max_length;
}

} // namespace util
