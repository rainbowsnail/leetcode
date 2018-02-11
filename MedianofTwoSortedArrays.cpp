class Solution {
public:
        static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //make vector1 be the longer one
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 < len2){
            int len1 = nums2.size();
            int len2 = nums1.size();
            return Solution::findMedianSortedArrays(nums2, nums1);
        }
        vector<int>& vector1 = nums1;
        vector<int>& vector2 = nums2;


        int max1 = (len1 + len2 + 1) / 2;
        int max2 = len2;
        
        int index2 = max2;
        int index1 = max1 - index2;
        
        int step = (len2 + 1)/2;
        
        while(true){ 
            if(len2 == 0) break;
            else if (index2 == 0) {if( vector2[index2] >= vector1[index1 - 1] ) break;}
            else if (index2 == len2) {if ( vector2[index2 - 1] <= vector1[index1]) break;}
            else if ((vector1[index1] >= vector2[index2 - 1]) && (vector2[index2] >= vector1[index1 - 1])) break;
            
            if (vector1[index1] < vector2[index2 - 1]) {
                index2 -= step;
                index1 += step;
            }else if (vector2[index2] < vector1[index1 - 1]){
                index2 += step;
                index1 -= step;
            }
            step = (step + 1) / 2;
        }
        
        double result = 0;
        
        if( (len1 + len2)%2 == 1){
            if(index1 == 0) result = vector2[index2 - 1];
            else if(index2 == 0) result = vector1[index1 - 1];
            else if(vector1[index1 - 1] >= vector2[index2 - 1]) result = vector1[index1 - 1];
            else if(vector2[index2 - 1] >= vector1[index1 - 1]) result = vector2[index2 - 1];
        }
        else if( (len1 + len2)%2 == 0){
            double small = 0, big = 0;
            if(index1 == 0) small = vector2[index2 - 1];
            else if(index2 == 0) small = vector1[index1 - 1];
            else if(vector1[index1 - 1] >= vector2[index2 - 1]) small = vector1[index1 - 1];
            else if(vector2[index2 - 1] >= vector1[index1 - 1]) small = vector2[index2 - 1];
            
            if(index1 == len1) big = vector2[index2];
            else if(index2 == len2) big = vector1[index1];
            else if(vector1[index1] <= vector2[index2]) big = vector1[index1];
            else if(vector2[index2] <= vector1[index1]) big = vector2[index2];
            
            result = small + big;
            result /= 2;
            
        }
        return result;
    }
};
