#include <iostream>
#include <string>
#include <vector>
#include <bitset>


using namespace std;


vector<char> conv(const string& bin_str) {
    vector<char> result;
    string temp = bin_str;
    
    while (temp.length() % 8 != 0) {
        temp += '0';
    }
    
    for (size_t i = 0; i < temp.size(); i += 8) {
        string byte_str = temp.substr(i, 8);
        bitset<8> bits(byte_str);
        result.push_back(static_cast<char>(bits.to_ulong()));
    }
    
    return result;
}

int main() {
    string input;
    cout << "Введите строку: ";
    cin >> input;
    vector<char> bytes = conv(input);
    cout << "В виде символов:     ";
    for (auto b : bytes){
    cout << static_cast<char>(b);
    }
    return 0;
}
