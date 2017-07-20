#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
using namespace std;
int main(){
	string tmp,t1,t2,cmd;
	set<string> shlv,rtn;
	map<string,string> author;
	while(getline(cin,tmp),tmp!="END"){
		int len=tmp.length(),ok=0;
		for(int i=0;i<len;++i){
			if(tmp[i]=='"') ++ok;
			if(ok==2){
				tmp[i+1]=tmp[i+4]='\n';
				break;
			}
		}
		tmp+='\n';
		stringstream ss(tmp);
		getline(ss,t1);
		getline(ss,t2);
		getline(ss,t2);
		author[t1]=t2;
		shlv.insert(t2+t1);
	}
	while(cin>>cmd,cmd!="END"){
		if(cmd[0]=='B'){
			cin.get();
			getline(cin,tmp);
			shlv.erase(author[tmp]+tmp);
		}
		else if(cmd[0]=='R'){
			cin.get();
			getline(cin,tmp);
			rtn.insert(author[tmp]+tmp);
		}
		else if(cmd[0]=='S'){
			for(set<string>::iterator i=rtn.begin();i!=rtn.end();++i){
				shlv.insert(*i);
				set<string>::iterator j;
				for(j=shlv.begin();*j!=*i;++j);
				cout<<"Put ";
				if(j==shlv.begin()){
					int ok=0,k=0,len=(*j).length();
					for(;k<len;++k){
						if((*j)[k]=='"') ++ok;
						if(ok) cout<<(*j)[k];
					}
					cout<<" first\n";
				}
				else{
					int ok=0,k=0,len=(*j).length();
					for(;k<len;++k){
						if((*j)[k]=='"') ++ok;
						if(ok) cout<<(*j)[k];
					}
					cout<<" after ";
					--j; len=(*j).length();
					for(ok=k=0;k<len;++k){
						if((*j)[k]=='"') ++ok;
						if(ok) cout<<(*j)[k];
					}
					cout<<endl;
				}
			}
			rtn.clear();
			cout<<"END\n";
		}
	}
	return 0;
}