#include <iostream>
#include <string>
//#include <iostream>

using namespace std;

bool OpCheck(char a){
    if(a == '*' || a == '/' || a == '+' || a == '-'){return true;}
    return false;
}
bool IntCheck(char a){
    if(a == '1' || a == '4' || a == '2' || a == '3' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9'){return true;}
    return false;
}
bool Check(string str){
    int state = 0;
    int counter = 0;
    for(int i = 0; i < str.length(); i ++){
        char g = str[i];
        if(state == 0 && g == '('){state = 1;counter+=1;}
        else if(state == 0 && IntCheck(g)){state = 2;}
        else if(state == 1 && IntCheck(g)){state = 2;}
        else if(state == 2 && (IntCheck(g) || g =='0')){state = 2;}
        else if(state == 2 && OpCheck(g)){state = 3;}
        else if(state == 3 && g == '('){state = 1;counter+=1;}
        else if(state == 3 && IntCheck(g)){state = 4;}
        else if(state == 4 && (IntCheck(g) || g =='0')){state = 4;}
        else if(state == 4 && OpCheck(g)){state = 3;}
        else if(state == 4 && g == ')'){state = 5;counter-=1;}
        else if(state == 5 && OpCheck(g)){state = 3;}
        else if(state == 5 &&g == ')'){state = 5;counter-=1;}
        else{cout<<"No";return false;}
    
    }
    if((state == 5 || state == 4) && counter == 0){cout<<"Yes";return true;}
    else{cout<<"No";return false;}
    
}
int main() {
	string str = "";
	cin >> str;
	bool res = Check(str);
	
	return 0;

}
