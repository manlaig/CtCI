#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> group(std::vector<string> arr)
{
    unordered_map<string, vector<string>> groups;

    for(const string& s : arr)
    {
        string cop = s;
        sort(cop.begin(), cop.end());
        groups[cop].push_back(s);
    }

    vector<vector<string>> out(groups.size());
    int i = 0;
    for(const pair<string, vector<string>>& p : groups)
    {
        out[i++] = move(p.second);
    }
    return out;
}

int main()
{
    auto groups = group({"hello", "eholl", "hell", "lhel", "world", "worldd"});
    for(const auto& vec : groups)
    {
        for(const string& s : vec)
            cout << s << " ";
        cout << endl;
    }
}