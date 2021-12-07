class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int numSeats = seats.size();
        int res = 0;
        
        vector <int> leftPerson(numSeats), rightPerson(numSeats);
        
        for (int i = 0; i < numSeats; i++) {
            if (seats[i] == 1) {
                leftPerson[i] = i;
            } else if (i > 0) {
                leftPerson[i] = leftPerson[i - 1];
            }
        }
                                
        for (int i = numSeats - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                rightPerson[i] = i;
            } else if (i < numSeats - 1){
                rightPerson[i] = rightPerson[i + 1];
            }
        }
        
        leftPerson[0] = -(1e5);
        rightPerson[numSeats - 1] = (1e5);
        
        for (int i = 0; i < numSeats; i++) {
            if (seats[i] == 0) {
                res = max(res , min(i - leftPerson[i], rightPerson[i] - i));
            }
        }
        
        return res;
    }
};