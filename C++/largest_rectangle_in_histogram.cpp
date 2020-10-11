# https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
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