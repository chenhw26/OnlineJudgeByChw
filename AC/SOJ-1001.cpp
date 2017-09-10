#include <iostream>
#include <string>
#include <map>
#define LL long long
using namespace std;

map<string, LL> mem;

LL count(const string &t, LL pos, LL ans, LL len){
    if(pos >= len) return 1;
    if(t[pos] == '0') return 0;
    else{
       	LL num;
       	if(mem.count(t.substr(pos + 1))) num = mem[t.substr(pos + 1)];
       	else{ 
       		num = count(t, pos + 1, 0, len);
       		mem[t.substr(pos + 1)] = num;
       	}
       	ans += num;        
        if(pos < len - 1){
            if(t[pos] == '1' || (t[pos] == '2' && t[pos + 1] < '7')){
            	LL num;
        		if(mem.count(t.substr(pos + 2))) num = mem[t.substr(pos + 2)];
        		else{
        			num = count(t, pos + 2, 0, len);
        			mem[t.substr(pos + 2)] = num;
        		}
        		ans += num;
        	}
        }
        return ans;
    }
}

int main(){
    string temp;
    while(cin >> temp, temp != "0"){
        LL len = temp.length();
        cout << count(temp, 0, 0, len) << endl;
    }
    return 0;
}                                 