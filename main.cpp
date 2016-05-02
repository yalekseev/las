#include "las.h"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 5, 4 };

    std::cout << util::longest_alternating_subsequence(v.begin(), v.end()) << std::endl;

    return 0;
}
