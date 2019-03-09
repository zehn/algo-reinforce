/**
 * Problem: Longest Substring Without Repeating Characters
 *
 * Description: Given a string, find the length of the longest substring without repeating characters.
 * Example:
 *   Input: "abcabcbb"
 *   Output: 3
 *   Explanation: The anwser is "abc", with the length 3
 *
 *   Input: "bbbbbb"
 *   Output: 1
 *
 *   Input: "pwwkew"
 *   Output: 3
 *   Explanation: The answer is "wke", with the length of 3. 
 *                Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length = 0, start = -1;
        std::vector<int> dict(265, -1);
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            length = std::max(length, i - start);
        }
        return length;
    }
};
