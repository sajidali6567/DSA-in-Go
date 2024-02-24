class TimeMap {
public:
    map<string, vector<pair<int, string>>> cache;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        cache[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string value; // empty string
        if(cache[key].size() == 0) return value;
        
        int low = 0, high = cache[key].size()-1;
        int index = binarySearch(low, high, timestamp, cache[key]);
        
        if(index == -1) return value;
        return cache[key][index].second;
    }
    
    // do binary search and find the index of maximum element <= timestamp
    // -1 if not found
    int binarySearch(int low, int high, int timestamp, vector<pair<int, string>>& cacheValues) {
        int index = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(cacheValues[mid].first <= timestamp) {
                index = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return index;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */