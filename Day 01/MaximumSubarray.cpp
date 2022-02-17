// O(N3) solution >>>>>>>>>>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                int sum = 0;
                for(int k=i; k<=j; k++){
                    sum+=nums[k];
                }
                if(maxi<sum) maxi = sum;
            }
        } return maxi;
    }
};

// O(N2) solution >>>>>>>>>>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum+=nums[j];
                if(maxi<sum) maxi = sum;
            }
        } return maxi;
    }
};

// O(N) solution >>>>>>>>>>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(auto ele: nums) {
            sum+=ele;
            if(maxi<sum) maxi = sum;
            if(sum<0) sum = 0;
        } return maxi;
    }
};