/*
>> Solution using brute force approach <<
- The approach is to find all the permutations of given array and store them in a vector of vector
- Then search for input array from all permutations
- Then print the permutation present right after the input array
- Time complexity is = O(n*n!), n represents the number of elements present in the input array and n! for searching input array from all possible permutations.
- Space complexity is = O(1) Since we are not using any extra spaces except stack spaces for recursion calls.
*/

/*
>> Solution using in-build function <<
C++ provides an in-built function called next_permutation().
which directly returns the lexicographically next greater permutation of the input.
*/

/*
>> solution using no extra space <<
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int k, l;
        
        // first iter for the such ele that can be smaler than his left ele
        for(k = len - 2; k>=0; k--) {
            if(nums[k] < nums[k+1]) {
                break;
            }
        }
        
        if(k < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (l = len-1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};