/*
Brute force solution is to take another matrix and take first row and put it in to last column and so on.
*/

/*
Optimal solution is to take all the rows and save it in vector of vector, then
take every element of vector and set it to first most column of the given matrix
ans so on.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp;
        for(int i=matrix.size()-1; i>=0; i--) {
            temp.push_back(matrix[i]);
        }
        for(int i=0; i<temp.size(); i++) {
            for(int j=0; j<temp[i].size(); j++) {
                matrix[j][i] = temp[i][j];
            }
        }
    }
};