#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        
    }
    
    // time: O(1), space: O(1)
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    // time: O(log(n)), space: O(1)
    string get(string key, int timestamp) {
        if(!store.count(key)) return "";

        string result = "";

        int left = 0;
        int right = store[key].size() - 1;

        vector<pair<int, string>> &v = store[key];

        while(left <= right){
            int mid = (left + right) / 2;
            int mid_timestamp = v[mid].first;

            if(mid_timestamp == timestamp) return v[mid].second;
            if(mid_timestamp < timestamp) left = mid + 1;


            if(mid_timestamp > timestamp) right = mid - 1;
        }

        if(right < 0) return "";

        return v[right].second;
    }
};

// you store, key, value, and time
// each key can have multiple values, but at different timestamps

// the get function, uses the key and the timestamp to return value

// both, key, timestamp, are unique

// option1: hashmap with key is the map key, and each key has values, each with different timestamps
// you find the key with a certain timestamp, and return the value
// so the problem here is the inner data structure, maybe it is another hashmap, binary search

// options2: hashmap with timestamp as the map key, and each timestamp has a value
// but the problem here is that the timestamp can be not in the map, so we will need to find the one below it
// and associated with the key provided to the function


// option3: a hashmap, with key as the key and a pair or the last timestamp value, and another hashmap
// if the value is not found inside the inner hashmap, which has the timestamp as its key, 
// we return the first stored value associated with the last timestamp



/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */