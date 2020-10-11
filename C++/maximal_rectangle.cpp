# https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0){
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>prev(n,0);
        vector<int>now;
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    now.push_back(1+prev[j]);
                }else{
                    now.push_back(0);
                }
                
                
            }
        
            maxArea = max(maxArea,largestRectangleArea(now));
            prev = now;
            
            now.clear();
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        int tp;
        int i=0;
        int tempArea=0;
        stack<int>s;
        while(i<heights.size()){
            if(s.empty() || heights[i]>=heights[s.top()]){
                s.push(i++);
            }
            else{
                tp = s.top();
                s.pop();
                tempArea = heights[tp]*(s.empty()?i:i-s.top()-1);
                
                if(maxArea<tempArea){
                    maxArea = tempArea;
                }
            }
            
        }
        while(!s.empty()){
            tp = s.top();
            s.pop();
            tempArea = heights[tp]*(s.empty()?i:i-s.top()-1);
            if(maxArea<tempArea){
                    maxArea = tempArea;
            }
        }
        
        return maxArea;
    }
    
};