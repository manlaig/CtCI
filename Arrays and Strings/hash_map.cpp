#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

/*
    This is a hashmap implementation somewhat equivalent to unordered_map in C++
*/

template <typename Key, typename Value>
class Map
{
public:
    Map() : map(SIZE) {}

    void add(Key k, Value&& v)
    {
        size_t hash = std::hash<Key>{}(k) % SIZE;
        map[hash].push_back({k, v});
    }

    void print()
    {
        for(int i = 0; i < SIZE; i++)
        {
            for(Entry entry : map[i])
                cout << "(" << entry.key << ", " << entry.val << ")\n";
        }
    }

    Value get(Key k)
    {
        size_t hash = std::hash<Key>{}(k) % SIZE;
        for(Entry e : map[hash])
            if(e.key == k)
                return e.val;
        return {};
    }

private:
    struct Entry
    {
        Key key;
        Value val;
    };

    const size_t SIZE = 100;
    vector<list<Entry>> map;
};

int main()
{
    Map<string, string> map;
    map.add("hello", "world");
    map.add("test1", "test2");
    map.print();
    cout << map.get("hello") << endl;
    cout << map.get("test1") << endl;
}