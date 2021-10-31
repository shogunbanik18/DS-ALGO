#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, vector<string>> phonebook;
    phonebook["Shogun"].push_back("6201241392");
    phonebook["Shogun"].push_back("612321392");
    phonebook["Shogun"].push_back("6201221392");

    phonebook["krishna"].push_back("908293902");
    phonebook["krishna"].push_back("612321392");
    phonebook["krishna"].push_back("6201221392");

    for (auto item : phonebook)
    {
        cout << item.first << endl;
        // cout << item.second << endl;
    }
    return 0;
}
