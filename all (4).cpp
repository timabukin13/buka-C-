#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<pair<char, int>> conv(string str){
    vector<pair<char, int>> res ={{'q', 0}};
    pair<char, int> pa;
    char k = '0';
    int count = 0;
    for(int i = 0; i < str.size(); i++){
        
        if( k == '0'){
            k = str[i];
            res[0].first = k;
            res[0].second = 1;
        }else if(k == str[i]){
            count = count + 1;
            res[i  - count].second = res[i -count ].second + 1;
        }else{
            k = str[i];
            pa = { k, 1};
            res.push_back(pa);
        }
    }
    return res;
}

string create(char ch, int data){
    string res = "";
    for(int i = 0; i < data; i++){
        res.push_back(ch);
    }
    return res;
}


int main() {
	string str1 = "ssshjjhdq";
	vector<pair<char, int>> res1 = conv(str1);
	string str2 = "sshhhjjjhhhdq";
	vector<pair<char, int>> res2 = conv(str2);
	string str3 = "shhhjjjjhdddqq";
	vector<pair<char, int>> res3 = conv(str3);
	string fin_result = "";
	bool check = true;
	if(res1.size() == res2.size() && res2.size() == res3.size()){
	    for(int i = 0; i < res1.size(); i++){
	        if(res1[i].first != res2[i].first || res2[i].first != res3[i].first){
	            check = false;
	        }
	    }
	}
	if(check){
	    for(int i = 0; i < res1.size(); i++){
	        if(res1[i].second <= res2[i].second && res1[i].second >= res3[i].second){
	            char ch = res1[i].first;
	            int data = res1[i].second;
	            string ad = create(ch, data);
	            fin_result.append(ad);
	            
	        }else if(res1[i].second <= res3[i].second && res1[i].second >= res2[i].second){
	            char ch = res1[i].first;
	            int data = res1[i].second;
	            string ad = create(ch, data);
	            fin_result.append(ad);
	            
	        }else if(res2[i].second <= res1[i].second && res2[i].second >= res3[i].second){
	            char ch = res2[i].first;
	            int data = res2[i].second;
	            string ad = create(ch, data);
	            fin_result.append(ad);
	            
	        }else if(res2[i].second <= res3[i].second && res2[i].second >= res1[i].second){
	            char ch = res2[i].first;
	            int data = res2[i].second;
	            string ad = create(ch, data);
	            fin_result.append(ad);
	            
	        }else if(res3[i].second <= res1[i].second && res3[i].second >= res1[i].second){
	            char ch = res3[i].first;
	            int data = res3[i].second;
	            string ad = create(ch, data);
	            fin_result.append(ad);
	            
	        }else if(res3[i].second <= res2[i].second && res2[i].second >= res1[i].second){
	            char ch = res3[i].first;
	            int data = res3[i].second;
	            string ad = create(ch, data);
	            fin_result.append(ad);
	            
	        }
	    }
	    cout << fin_result;
	}else{cout<<"NO";}

}
