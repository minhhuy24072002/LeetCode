class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0, res = 0, curr;
        map<int, int> mark;
        
        for (int i = 0; i < nums.size(); i++) {
            mark[nums[i]] = 1;
        }
        
        for (int i = 0; i < nums.size(); i++)
            if (!(mark[nums[i] - 1]) && mark[nums[i]] != 2) {
                count = 1;
                curr = nums[i];
                while (mark[curr + 1] > 0) {
                    cout << curr << endl;
                    count++;
                    curr++;
                }
                mark[nums[i]] = 2;
                res = max(res, count);
            }
        
        return res;
    }
};