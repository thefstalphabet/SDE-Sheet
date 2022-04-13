class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answers;
        
        if(intervals.size() == 0) return answers;
        
        sort(intervals.begin(), intervals.end());
       
        vector<int> temp = intervals[0];
        for(auto it: intervals) {
            if(it[0] <= temp[1]) {
                temp[1] = max(it[1], temp[1]);
            } else {
                answers.push_back(temp);
                temp = it;
            }
        }
        answers.push_back(temp);
        return answers;
    }
};