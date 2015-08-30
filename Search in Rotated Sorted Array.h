class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        if(N==0) return -1;
       
        int left = 0;
        int right = N-1;
        while(left<=right)
        {
            
            int mid = (left+right)/2;
         
            if(target == nums[mid])
              return mid;
            if(nums[mid]<nums[right])
            {
                if (target>nums[mid] && target <= nums[right])
                    left = mid+1; 
                else 
                    right = mid-1;
            }
            
            else if(nums[mid]>nums[right])
           {
                 if (target<nums[mid] && target >= nums[left])
                    right = mid-1; 
                 else 
                    left = mid+1;
            }
            else
                right--;
            
        }
        return -1;
    }
};
