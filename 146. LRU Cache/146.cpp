/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
//LRUCache cache = new LRUCache( 2 /* capacity * / );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

#include <list>
#include <map>
#include <assert.h>
#include <iostream>

using namespace std;

class LRUCache
{
    using Key = int;
    using Value = int;
    using Node = pair<Key, Value>;

    using Iterator = list<Node>::iterator;
    list<Node> li;
    map<Key, Iterator>mp;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        auto iter = mp.find(key);
        if (iter != mp.end())
        {
            li.splice(li.begin(), li, iter->second);
            return iter->second->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto iter = mp.find(key);
        if (iter != mp.end())
        {
            li.splice(li.begin(), li, iter->second);
            iter->second->second = value;

            return;
        }
        if (mp.size() < this->capacity)
        {
            li.insert(li.begin(), make_pair(key, value));
            mp[key] = li.begin();
        }
        else
        {
            li.insert(li.begin(), make_pair(key, value));
            mp[key] = li.begin();

            auto erase = li.back();
            mp.erase(erase.first);
            li.pop_back();
            //cout << "evicts " << erase.first << endl;
        }
    }
};


int main()
{
    int capacity = 10;
    int key = 1;
    int value = 2;

    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1

    cout << cache.get(1) << endl;
    cout << cache.get(1) << endl;
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;      // returns -1 (not found)
    cache.put(4, 4);      // evicts key 1

    cout << cache.get(1) << endl;       // returns -1 (not found)
    return 0;

    cout << cache.get(3) << endl;      // returns 3
    cout << cache.get(4) << endl;      // returns 4
}