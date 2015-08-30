class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if((m+n)%2 == 1)
            return findKthElement(nums1,nums2,(m+n)/2+1);
         else
           {
            int mid_1 = findKthElement(nums1,nums2,(m+n)/2+1);
            int mid_2 = findKthElement(nums1,nums2,(m+n)/2);
            return (mid_1+mid_2)/2.0;
           }
    }
    
    int findKthElement(vector<int>&nums1,vector<int>&nums2,int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        //try to make sure the first set is less than the second.
        if(m>n)
          return findKthElement(nums2,nums1, k);
        if(nums1.size() == 0) return nums2[k-1];
        
        if(k==1) return min(nums1[0],nums2[0]);
        
        //be careful of the following setting.
        int pa = min(k/2,m);
        int pb = k-pa;
      
        if(nums1[pa-1]<=nums2[pb-1])
        {
           vector<int>nums1_1(nums1.begin()+pa,nums1.end());
           return findKthElement(nums1_1,nums2, k-pa);
        }
        else
        {
            vector<int>nums2_1(nums2.begin()+pb,nums2.end());
            return findKthElement(nums1,nums2_1, k-pb);
        }
    }
};
