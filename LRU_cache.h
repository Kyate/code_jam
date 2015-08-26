/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
*/
class LRUCache{
public:
/***********************website ***************************************/
 LRUCache(int capacity) : size(capacity) {}

    int get(int key) {
        auto it = table.find(key);
        if (it == table.cend()) { return -1; }
        move_to_front(it);
        return it->second.second;
    }

    void set(int key, int value) {
        auto it = table.find(key);
        if (it != table.cend()) {
            it->second.second = value;
            move_to_front(it);
            return;
        }
        if (table.size() == size) {
            table.erase(lru_data.back());
            lru_data.pop_back();
        }
        lru_data.emplace_front(key);
        table[key] = {lru_data.begin(), value};
    }
private:
    typedef unordered_map<int, pair<typename list<int>::iterator, int> > Table;
    list<int> lru_data;
    Table table;
    int size;

    void move_to_front(const typename Table::iterator& it) {
        lru_data.erase(it->second.first);
        lru_data.emplace_front(it->first);
        it->second.first = lru_data.begin();
    }
};
