class TimeMap {
public:
    map<string, vector<pair<int, string>>> cache;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        pair<int, string> cacheValue = make_pair(timestamp, value);
        cache[key].push_back(cacheValue);
    }
    
    string get(string key, int timestamp) {
        if(cache[key].size() == 0) return "";
        
        // do binary search and find the maximum element <= timestamp
        int low = 0, high = cache[key].size()-1;
        int index = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(cache[key][mid].first <= timestamp) {
                index = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        if(index == -1) return "";
        return cache[key][index].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */