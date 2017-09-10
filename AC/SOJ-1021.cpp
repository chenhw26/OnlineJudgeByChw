#include <iostream>
#include <stack>
using namespace std;
int main(){
    int N, couples[200010];
    while(cin >> N, N){
        stack<int> buf;
        for(int i = 0; i < N; ++i){
            int husb, wife;
            cin >> husb >> wife;
            couples[husb] = wife;
            couples[wife] = husb;
        }
        for(int i = 1; i <= 2 * N; ++i){
            if(buf.empty() || couples[buf.top()] != i) buf.push(i);
            else buf.pop();
        }
        cout << (buf.empty()? "Yes": "No") << endl;
    }
    return 0;
}