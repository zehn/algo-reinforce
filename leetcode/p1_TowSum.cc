/**
 * Problem: Two Sum
 *
 * Description: Given an array of integers, return indices of the two numbers
 * such that they add up to a specific target. Note: You may assume that each
 * input would have exactly one solution, and you may not use the same element
 * twice.
 *
 * Example:
 *   nums = [2, 7, 11, 15], target = 9
 *   return [0, 1] (because nums[0] + nums[1] = 2 + 7 = 9)
 */
#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> location;
        std::unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); ++i) {
            int number_to_find = target - nums[i];

            if (hash.end() != hash.find(number_to_find)) {
                location.push_back(hash[number_to_find]);
                location.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }

        return location;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;

    int test_case[] = {2, 7, 11, 15};
    std::vector<int> v(test_case, test_case + sizeof(test_case) / sizeof(int)); 
    std::vector<int> result = solution.twoSum(v, 9);
    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << ' ';
    std::cout << '\n';
    return 0;
}
