class Solution {
public:
    long long numPairsDivisibleBy60(vector<int>& time) {
        map<int, long long> remainders;
        long long res = 0;
        
        for (int i = 0; i < time.size(); i++) {
            remainders[time[i] % 60]++;
        }
        
        for (auto remainder : remainders) {
            if ((60 - remainder.first) % 60 != remainder.first) {
                res += (remainder.second * remainders[60 - remainder.first]);
                remainders[60 - remainder.first] = 0;
            } else {
                res += remainder.second * (remainder.second - 1) / 2;
            }
        }
        return res;
    }
};