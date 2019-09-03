/**
 * Problem: Reverse Integer
 *
 * Given a 32-bit signed integer, reverse digits of an integer
 *
 * Example:
 *      input: 123      output: 321
 *      input: -123     output: -321
 *      input: 120      output: 21
 */
class Solution {
public:
    int reverse(int x) {
        int min = -2147483648;
        int max = 2147483647;
        int y = 0;

        while (x) {
            if (y > max / 10 || y < min / 10)
                return 0;
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return y;
    }
};
