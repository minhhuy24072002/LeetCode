class Solution {

public:
    map <vector <int>,int > mp;
    vector<vector<int>> res;
    vector<int> candidate;
    
    void dp(vector <int> a, int sum, int target)
    {
        for (auto x: candidate)
        if (x+sum<=target)
        {
            a.push_back(x);
            vector <int> b;
            b=a;
            sort(b.begin(),b.end());
            sum+=x;
            if (sum==target && mp[b]==0) { res.push_back(b); mp[b]=1; }
            else if (sum<target) dp(a, sum, target);
            sum-=x;
            a.pop_back();
            
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        candidate = candidates;
        dp(vector <int>(), 0, target);
        return(res);
    }
};