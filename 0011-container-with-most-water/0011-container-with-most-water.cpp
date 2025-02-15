class Solution {
public:
    int maxArea(vector<int>& height) {
        int a = 0;
        int b = height.size()-1;
        int answer = min(height[a],height[b]) * (b-a);
        while(a < b) {
            answer = max(answer, min(height[a],height[b]) * (b-a));
            if(height[a] < height[b])
                a++;
            else
                b--;
            
        }
        return answer;
    }
};