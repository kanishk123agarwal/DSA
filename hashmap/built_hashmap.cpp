#include<vector>
using namespace std;
class MyHashMap {
public:
    vector<pair<int,int>>map;
    MyHashMap() {
        
    }
    void put(int key, int value) 
    {
        for(int i=0;i<map.size();i++)
        {
            if(map[i].first==key)
                map[i].second=value;
        }
        map.push_back({key,value});
    }
    
    int get(int key) 
    {
        for(int i=0;i<map.size();i++)
        {
            if(map[i].first==key)
                return map[i].second;
        }
        return -1;
    }
    
    void remove(int key) 
    {
        for(int i=0;i<map.size();i++)
        {
            if(map[i].first==key)
            {
                map[i].second=-1;
                break;
            } 
        }
    }
};