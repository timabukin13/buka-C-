#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> lzw_in(string input, vector<string> base_alph) {
    unordered_map<string, int> dict;

    for (int i = 0; i < base_alph.size(); i++) {
        dict[base_alph[i]] = i;
    }
    string cur;
    vector<int> res;
    for (char j : input) {
        string temp = cur + j;
        if (dict.count(temp)) {
            cur = temp;
        }else {
            res.push_back(dict[cur]);
            dict[temp] = dict.size();
            cur = string(1, j);
        }
    }
    if (!cur.empty()) {
        res.push_back(dict[cur]);
    }
    return res;
}

int main() {
    string str = "abcbc";
    vector<string> base_alph = {"a", "b", "c"};

    vector<int> res = lzw_in(str, base_alph);
    for (int i = 0; i < res.size(); i ++){
        cout << res[i] << " ";} 
    return 0;
}
