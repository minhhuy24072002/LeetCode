class TimeMap {
public:
    map<string, vector<pair<string, int>>> Map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        this->Map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = this->Map[key].size() - 1, mid;
        string res = "";
        while (l <= r) {
            mid = (l + r) / 2;
            if (this->Map[key][mid].second <= timestamp) {
                res = this->Map[key][mid].first;
                l = mid + 1;
            } else r = mid - 1;
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */