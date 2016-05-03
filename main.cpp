#include "las.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> s = { 1, 5, 3, 2, 4 };

    std::cout << util::longest_alternating_subsequence(s.begin(), s.end()) << std::endl;

    return 0;
}
