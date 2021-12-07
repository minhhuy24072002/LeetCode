class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nxt=0;
        for (int a:nums)
        {
            if (a!=0) 
            {
                nums[nxt]=a;
                nxt++;
            }
        }
        for (int i=nxt;i<nums.size();i++) nums[i]=0;
        //return nums;
        
    }
};