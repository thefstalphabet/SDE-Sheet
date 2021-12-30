/*
>> Solution using brute force approach <<
- The approach is to iterate on matrix and when there is a element having value 0, we store there indexes in array
- Then, after the iteration we iterate to the array and convert all the rows and columns that are passing thought that ele having zero
- Time complexity is = O(m*n) for linearly traversing the array * O(m+n) for traversing the entire column & row
- Space complexity is = O(n) as we are taking an extra array
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        if(rows==0) return;        
        // array to store the indexes of ele having zero value
        vector<pair<int,int>> arr; 
        // iterating on matrix
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == 0)
                    arr.push_back({i,j});
            }
        }
        // iterating on array, where we store indixes where we found ele having value 0
        for(auto ele: arr){
            for(int i=0; i<cols; i++){
                matrix[ele.first][i] = 0;    
            }
            for(int j=0; j<rows; j++){
                matrix[j][ele.second] = 0;
            }
        }
    }
};

/*
>> Better approach <<
- The approach is to take two dummy arrays one of size of rows, and second of size of columns
- Then, iterate on matrix and when there is a element having value 0, then we set 0 in dum1[i] and dum2[j]
- After that we again iterate on matrix and check if the dummy arrays having 0's or not 
- If any one have 0 then we convert the matrix element into 0
- Time complexity is = O(m*n + m*n) coz we linearly traversing the array twice
- Space complexity is = O(n) + O(m) for taking two dummy arrays
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // num of rows, num of colum
        int rows = matrix.size(), cols = matrix[0].size();
        // one dummy array for rows and one for column
        vector<int> dum1(rows, -1), dum2(cols, -1);
        // iterating to the matrix
        for(int i=0; i<rows; i++){ // for rows
            for(int j=0; j<cols; j++){ // for columns
                if(matrix[i][j]==0){
                    dum1[i] = 0;
                    dum2[j] = 0;
                }
            }
        }
        for(int i=0; i<rows; i++){ // for rows
            for(int j=0; j<cols; j++){ // for columns
                if(dum1[i]==0 || dum2[j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

/*
>> Optimization of better approach <<
- The approach is to take the 0th row as first dummy array and 0th column as second dummy array
- Then, we also take a flag initialy as true, 
- if the 0th column eles having value 0 then we set it to false and convert all the column ele into 0
- Then, iterate on matrix and when there is a element having value 0, then we set 0 in dum1[i][0] and dum2[0][j]
- Then, we iterate on matrix form the backside
- And check if the dummy arrays having 0's or not
- If any one have 0 then we convert the matrix ele into 0
- Time complexity is = O(m*n + m*n) coz we linearly traversing the array twice
- Space complexity is = O(1) coz we did change in the same matrix itself
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // num of rows, num of colum
        int rows = matrix.size(), cols = matrix[0].size();
        // the flag is true initialy, when there are 0 in the first column of the matrix flag got false
        int flag = true;
        // iterating to the matrix
        for(int i=0; i<rows; i++){ // for rows
            // if any ele in first col is 0, then we set the flag as false
            if(matrix[i][0] == 0) flag = false;
            for(int j=1; j<cols; j++){ // for columns
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // iterating on matrix from the backside
        for(int i=rows-1; i>=0; i--){ // for rows
            for(int j=cols-1; j>=1; j--){ // for columns
                // if there is a ele having 0 on 0th column or 0th row, then we set current ele as 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            // if the 0th column eles having 0 value then we set whole column as 0
            if(flag == false){
                matrix[i][0] = 0;
            }
        }
    }
};