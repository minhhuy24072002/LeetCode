class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mark;
        int count, res = 0, curr;
        
        for (int i = 0; i < nums.size(); i++) {
            mark[nums[i]] = 1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!mark[nums[i] - 1] && mark[nums[i]] != 2) {
                count = 0;
                curr = nums[i];
                    
                while (mark[curr] > 0) {
                    count++;
                    curr++;
                }
                cout << nums[i] << ' ' << count << endl;
                
                mark[nums[i]] = 2;
                res = max(res, count);
            }
        }
        
        return res;
    }
};