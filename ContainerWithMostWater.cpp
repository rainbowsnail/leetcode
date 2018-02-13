class Solution {
public:
    int maxArea(vector<int>& height) {
        int largest = 0;
        int hsize = height.size();
        for(int i = 0; i < height.size();++i){
            int prev;
            int next;
            for(next = hsize - 1; next >= i; --next)
                if(height[next] >= height[i]) break;
            for(prev = 0; prev <= i; ++prev)
                if(height[prev] >= height[i]) break;
            int area = 0;
            if(next != i){
                area = height[i] * (next - i);
            }
            if(largest < area) largest = area;
            if(prev != i){
                area = height[i] * (i - prev);
            }
            if(largest < area) largest = area;
        }
        return largest;
    }
};
