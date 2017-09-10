#include <iostream>
#include <string>
#include <set>
using namespace std;

char couples[100];

string gen_dna(const string &dna){
    string ans;
    for(char c: dna) ans.append(1, couples[c]);
    return ans;
}

int main(){
    couples['A'] = 'T'; couples['T'] = 'A'; couples['C'] = 'G'; couples['G'] = 'C';
    int T, n;
    cin >> T;
    while(T--){
        multiset<string> dnas;
        cin >> n;
        int ans = 0;
        while(n--){
            string dna;
            cin >> dna;
            multiset<string>::iterator it = dnas.find(gen_dna(dna));
            if(it != dnas.end()){
                dnas.erase(it);
                ++ans;
            }
            else dnas.insert(dna);
        }
        cout << ans << endl;
    }
    return 0;
}                                 