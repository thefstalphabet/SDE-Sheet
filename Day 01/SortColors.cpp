class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int>> pq;
        for(auto ele: nums) pq.push(ele);
        nums.clear();
        while(!pq.empty()){
            nums.push_back(pq.top());
            pq.pop();
        }
    }
};

// Dutch National flag algorithm 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int heigh = nums.size()-1;
        while(mid<=heigh) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[heigh]);
                heigh--;
            }
        }
    }
};