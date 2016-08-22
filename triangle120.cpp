class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    for (int i = triangle.size() - 2; i >= 0; --i)
      for (int j = 0; j < i + 1; ++j){
        if(triangle[i+1][j] > triangle[i+1][j+1]){
          triangle[i][j] += triangle[i+1][j+1];
        }else{
          triangle[i][j] += triangle[i+1][j];
        }
      }
    
    return triangle[0][0];
  }
};