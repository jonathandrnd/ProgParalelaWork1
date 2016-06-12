#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<vector>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<set>
#include<ctime>
#include<omp.h>
using namespace std;
bool visited[31];
double dis[31][31];

int main(){
    
	int n=12;
	
	for(int i=0;i<n;i++)dis[i][i]=0;
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			dis[i][j]=rand()%100;
			dis[j][i]=dis[i][j];
		}
	
	stack<pair<pair<int,double>,int> >S;
	double dev=1e+10;
	
	for(int i=n-1;i>=1;i--){
		S.push(make_pair(make_pair(i,dis[0][i]),1<<i));
	}
	  
	while(S.size()!=0){
		pair<pair<int,double>,int>p =S.top();
		S.pop();
		int id=p.first.first;
		double distance=p.first.second;
		int mask=p.second;
		
		if( __builtin_popcount(mask) ==n-1){
			dev=min(dev, distance+dis[id][0]);
		}else{
			for(int i=n-1;i>0;i--)
				if( (mask&(1<<i))==0 )
					S.push( make_pair(make_pair(i,distance+dis[id][i]),mask|(1<<i)  )  );
		}
	}

	printf("%.10lf\n",dev);
	
    return 0;
}

