#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    // Example: Using map for ordered access
    map<int, string> orderedMap;
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[4] = "Four";
    orderedMap[2] = "Two";

    cout << "Ordered Map:\n";
    for (const auto &pair : orderedMap)
    {
        cout << pair.first << ": " << pair.second << '\n';
    }

    // Example: Using unordered_map for fast average-case performance
    unordered_map<int, string> unorderedMap;
    unorderedMap[3] = "Three";
    unorderedMap[1] = "One";
    unorderedMap[4] = "Four";
    unorderedMap[2] = "Two";

    cout << "\nUnordered Map:\n";
    for (const auto &pair : unorderedMap)
    {
        cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
