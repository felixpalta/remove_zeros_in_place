#include <iostream>
#include <vector>
#include <initializer_list>

using VectorValues = std::initializer_list<int>;
using TestPair = std::pair<VectorValues, VectorValues>;

static const TestPair TestValues[] = {
    { {}, {} },
    { {0}, {} },
    { {0, 0, 0}, {} },
    { {1}, {1} },
    { {1, 0}, {1} },
    { {0, 1}, {1} },
    { {1, 2, 4}, {1, 2, 4} } ,
    { {0, 1, 2, 4}, {1, 2, 4} } ,
    { {0, 0, 1, 2, 4}, {1, 2, 4} } ,
    { {1, 2, 0, 4, 0, 0}, {1, 2, 4} } ,
    { {0, 1, 2, 3, 4, 0, 5, 6, 0, 0, 0, 9}, {1, 2, 3, 4, 5, 6, 9} }
};

void removeZeroesInPlace(std::vector<int> & v) {
    size_t shift = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] != 0) {
            v[i-shift] = v[i];
        } else {
            ++shift;
        }
    }
    v.resize(v.size() - shift);
}

int main()
{
    for (auto init_list_pair : TestValues) {
        std::vector<int> input(init_list_pair.first);
        std::vector<int> output(init_list_pair.second);

        auto input_copy(input);

        removeZeroesInPlace(input);
        if (input != output) {
            std::cerr << "RemoveZeroes test failed: input: ";
            for (auto i : input_copy) std::cerr << i << " ";
            std::cerr << ", Actual output: ";
            for (auto i : input) std::cerr << i << " ";
            std::cerr << ", Expected output: ";
            for (auto i : output) std::cerr << i << " ";
            return 1;
        }
    }
    std::cout << "RemoveZeroes test successful!" << std::endl;
    return 0;
}
