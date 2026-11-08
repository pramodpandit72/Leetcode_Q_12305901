class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);

            maxArea = max(maxArea, w * h);

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;


        // int maxArea = 0;

        // for(int i = 0; i < height.size(); i++) {
        //     for(int j = i + 1; j < height.size(); j++) {
        //         int w = j - i;
        //         int h = min(height[i], height[j]);

        //         maxArea = max(maxArea, h * w);
        //     }
        // }
        // return maxArea;
    }
};