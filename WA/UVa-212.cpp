#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;

class Room{
public:
	int id, totalTime, curOcpT, curPatient;
};

class Bed
{
public:
	int id, totalTime, curOcpT, curPatient;
};

class Patient
{
public:
	int id, roomId, roomBegin, roomOcp, bedId, bedOcp;
	string name;
};

int main(){
	int n, m, t1, t2, t3, T, k;
	while(cin >> n >> m >> T >> t1 >> t2 >> t3 >> k){
		int time, cmplt = 0;
		Patient *allPatient = new Patient[k + 1];
		queue<int> wait;
		for(int i = 1; i < k + 1; ++i){
			cin >> allPatient[i].name >> allPatient[i].roomOcp >> allPatient[i].bedOcp;
			allPatient[i].id = i;
			wait.push(i);
		}
		Room *allRoom = new Room[n + 1];
		set<int> avaRoom, ocpRoom, preRoom;
		for(int i = 1; i < n + 1; ++i){
			allRoom[i].id = i;
			allRoom[i].totalTime = allRoom[i].curOcpT = 0;
			avaRoom.insert(i);
		}
		Bed *allBed = new Bed[m + 1];
		set<int> avaBed, ocpBed, preBed;
		for(int i = 1; i < m + 1; ++i){
			allBed[i].id = i;
			allBed[i].totalTime = allBed[i].curOcpT = 0;
			avaBed.insert(i);
		}
		for(time = 0; cmplt < k; ++time){
			for(set<int>::iterator iter = ocpRoom.begin(); iter != ocpRoom.end();){
				if(++allRoom[*iter].curOcpT == allPatient[allRoom[*iter].curPatient].roomOcp){
					preRoom.insert(*iter);
					allRoom[*iter].totalTime += allRoom[*iter].curOcpT;
					allRoom[*iter].curOcpT = -1;
					int bedid = *(avaBed.begin()), patientid = allRoom[*iter].curPatient;
					allBed[bedid].curOcpT = -1;
					allBed[bedid].curPatient = patientid;
					allPatient[patientid].bedId = bedid;
					ocpBed.insert(bedid);
					avaBed.erase(bedid);
					iter = ocpRoom.erase(iter);
				}
				else ++iter;
			}
			for(set<int>::iterator iter = preRoom.begin(); iter != preRoom.end();){
				if(++allRoom[*iter].curOcpT == t2){
					allRoom[*iter].curOcpT = 0;
					avaRoom.insert(*iter);
					iter = preRoom.erase(iter);
				}
				else ++iter;
			}
			while(!avaRoom.empty() && !wait.empty()){
				int roomid = *(avaRoom.begin()), patientid = wait.front();
				allRoom[roomid].curOcpT = 0;
				allRoom[roomid].curPatient = patientid;
				ocpRoom.insert(roomid);
				allPatient[patientid].roomId = allRoom[roomid].id;
				allPatient[patientid].roomBegin = time;
				avaRoom.erase(roomid);
				wait.pop();
			}
			for(set<int>::iterator iter = ocpBed.begin(); iter != ocpBed.end();){
				if(++allBed[*iter].curOcpT == allPatient[allBed[*iter].curPatient].bedOcp + t1){
					preBed.insert(*iter);
					allBed[*iter].totalTime += allBed[*iter].curOcpT - t1;
					allBed[*iter].curOcpT = -1;
					++cmplt;
					iter = ocpBed.erase(iter);
				}
				else ++iter;
			}
			for(set<int>::iterator iter = preBed.begin(); iter != preBed.end();){
				if(++allBed[*iter].curOcpT == t3){
					avaBed.insert(*iter);
					allBed[*iter].curOcpT = 0;
					iter = preBed.erase(iter);
				}
				else ++iter;
			}
		}
		if(!time) time = 1;
		cout << " Patient          Operating Room          Recovery Room\n"
			 << " #  Name     Room#  Begin   End      Bed#  Begin    End\n"
			 << " ------------------------------------------------------\n";
		for(int i = 1; i <= k; ++i){
			int OpBeginHour = allPatient[i].roomBegin / 60 + T, OpBeginMin = allPatient[i].roomBegin % 60;
			int OpEndHour = (allPatient[i].roomBegin + allPatient[i].roomOcp) / 60 + T, 
			    OpEndMin = (allPatient[i].roomBegin + allPatient[i].roomOcp) % 60;
			int ReBeginHour = (allPatient[i].roomBegin + allPatient[i].roomOcp + t1) / 60 + T, 
				ReBeginMin = (allPatient[i].roomBegin + allPatient[i].roomOcp + t1) % 60;
			int ReEndHour = (allPatient[i].roomBegin + allPatient[i].roomOcp + t1 + allPatient[i].bedOcp) / 60 + T, 
				ReEndMin = (allPatient[i].roomBegin + allPatient[i].roomOcp + t1 + allPatient[i].bedOcp) % 60;
			printf("%2d  %-8s  %2d   %2d:%02d   %2d:%02d     %2d   %2d:%02d   %2d:%02d\n", i, allPatient[i].name.c_str(), 
				                                                                    allPatient[i].roomId, OpBeginHour, OpBeginMin,
				                                                                    OpEndHour, OpEndMin, allPatient[i].bedId,
				                                                                    ReBeginHour, ReBeginMin, ReEndHour, ReEndMin);
		}
		cout << "\n Facility Utilization\n" 
			 << " Type  # Minutes  % Used\n"
			 << " -------------------------\n";
		for(int i = 1; i <= n; ++i)
			printf(" %-4s %2d    %4d   %5.2lf\n", "Room", i, allRoom[i].totalTime, double(allRoom[i].totalTime) / time * 100);
		for(int i = 1; i <= m; ++i)
			printf(" %-4s %2d    %4d   %5.2lf\n", "Bed", i, allBed[i].totalTime, double(allBed[i].totalTime) / time * 100);
		cout << endl;
		delete [] allPatient;
		delete [] allRoom;
		delete [] allBed;
	}
	return 0;
}