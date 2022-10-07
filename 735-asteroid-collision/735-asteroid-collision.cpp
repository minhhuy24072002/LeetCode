class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> afterCollision;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) {
                while (afterCollision.size() > 0 && afterCollision.back() > 0 && -asteroids[i] > afterCollision.back()) {
                     afterCollision.pop_back();
                }
                if (afterCollision.size() == 0 || afterCollision.back() < 0) {
                    afterCollision.push_back(asteroids[i]);
                }
                if (-asteroids[i] == afterCollision.back()) {
                    afterCollision.pop_back();
                }
            } else {
                afterCollision.push_back(asteroids[i]);
            }
        }
        return afterCollision;
    }
};