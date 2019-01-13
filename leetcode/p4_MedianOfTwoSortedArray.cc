/**
 * Problem: Median of Two Sorted Array
 *
 * Description: There are two arrays nums1 and nums2 of size m and n
 * respectively. Find the median of the two sorted arrays. The overall run time
 * complexity should be O(log(m+n). Note: You may assume nums1 and nums2 can not be both empty.
 *
 * Example 1:
 *   nums1 = [1, 3]
 *   nums2 = [2]
 *   The median is 2.0
 *
 *   nums1 = [1, 2]
 *   nums2 = [3, 4]
 *   The median is  (2 + 3) / 2 = 2.5
 */
#include <vector>
#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int m = static_cast<int>(nums1.size());
        int n = static_cast<int>(nums2.size());
        int max_of_left;
        int min_of_right;

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int min = 0, max = m;
        while (min < max) {
            int x = (min + max) / 2;
            int y = (m + n + 1) / 2 - x;
            if (y != 0 && x != m && nums2[y - 1] > nums1[x]) {
                min = x + 1;
            } else if (x != 0 && y != n && nums1[x - 1] > nums2[y]) {
                max = x - 1;
            } else {
                if (x == 0) {
                    max_of_left = nums2[y - 1];
                } else if (y == 0) {
                    max_of_left = nums1[x - 1];
                } else {
                    max_of_left = std::max(nums1[x - 1], nums2[y - 1]);
                }

                if (((m + n) % 2) == 1)
                    min_of_right = nums2[y];
                if (x == m) {
                    min_of_right = nums1[x];
                } else if (y == n) {
                    min_of_right = std::min(nums1[x], nums2[y]); 
                }
            }
        }

        return (min_of_right + max_of_left) / 2.0; 
    }

};

int main(int argc, char* argv[])
{
    Solution solution;
    
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}
