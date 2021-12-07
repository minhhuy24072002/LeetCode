class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=nums.size();
        for (int i=0,j=0;i<nums.size();i++)
            if (nums[i]==val) cnt--;
        else
        {
            nums[j]=nums[i];
            j++;
        }
        return cnt;
    }
};