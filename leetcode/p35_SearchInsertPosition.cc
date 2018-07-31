/*
 * Problem: Search Insert Position
 *
 * Description: Give a stroed array and a target value, return the index if the
 * target is found. if not, return the index where it would be if it were
 * inserted in order.
 *
 * Examples:
 *   Input: [1, 3, 5, 6], 5
 *   Output: 2
 *
 *   Input: [1, 3, 5, 6], 2
 *   Output: 1
 *
 *   Input: [1, 3, 5, 6], 7
 *   Output: 4
 *
 *   Input: [1, 3, 5, 6], 0
 *   Output: 0
 */
#include <vector>
#include <iostream>

struct TestCase {
    std::vector<int> array;
    int target;
};

static TestCase cases[] = {
    { {1, 3, 5, 6}, 5 },
    { {1, 3, 5, 6}, 2 },
    { {1, 3, 5, 6}, 7 },
    { {1, 3, 5, 6}, 0 },
};

static const unsigned cases_nb = sizeof(cases) / sizeof(TestCase);

class Solution {
public:
    /**
     *
     */
    int SearchInsert_v1(std::vector<int>& nums, int target) 
    {
        std::vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); ++it) {
            if (*it >= target) {
                break;
            }
        }
        return (it - nums.begin()); 
    }

    /**
     *
     */
    int SearchInsert_v2(std::vector<int>& nums, int target)
    {
        std::vector<int>::iterator it;
        // returns an iterator pointing to the first element in the range
        // [first, last) that is less than value, or last if no such element is
        // found.
        it = std::lower_bound(nums.begin(), nums.end(), target);
        return (it - nums.begin());
    }
};


int main(int argc, char* argv[])
{
    int output;
    Solution solution;
    for (unsigned i = 0; i < cases_nb; ++i) {
        output = solution.SearchInsert_v1(cases[i].array, cases[i].target);
        std::cout << "v1 output: " << output << ", ";
        output = solution.SearchInsert_v2(cases[i].array, cases[i].target);
        std::cout << "v2 output: " << output << '\n';
    }
    return 0;
}

