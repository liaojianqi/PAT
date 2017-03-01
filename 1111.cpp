#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
#define INF 100000000

const int MAXN=503;
int n,m,s,e,G[MAXN][MAXN],time[MAXN][MAXN];
int d[MAXN],cnt[MAXN],path[MAXN];
bool used[MAXN];

void dijkstra(int (&G)[MAXN][MAXN]){
	for(int i=0;i<n;++i){
		d[i]=INF;
		cnt[i]=INF;
		used[i]=false;
	}
	d[s]=0;
	cnt[s]=1;
	while(true){
		int minV=INF,minI=-1;
		for(int i=0;i<m;++i){
			if(!used[i] && d[i]<minV){
				minV = d[i];
				minI=i;
			}
		}
		if(minI==-1) break ;
		used[minI]=true;
		for(int i=0;i<n;++i){
			if(!used[i] && G[minI][i]){
				if(d[minI] + G[minI][i]<d[i]){
					d[i] = d[minI] + G[minI][i];
					path[i] = minI;	
					cnt[i] = cnt[minI]+1;
				}else if(d[minI] + G[minI][i]==d[i] && cnt[minI]+1<cnt[i]){
					cnt[i]=cnt[minI]+1;
					path[i] = minI;	
				}
			}
		}
	}
}
void dijkstra1(){
	for(int i=0;i<n;++i){
		cnt[i]=INF;
		used[i]=false;
	}
	cnt[s]=0;
	while(true){
		int minV=INF,minI=-1;
		for(int i=0;i<m;++i){
			if(!used[i] && cnt[i]<minV){
				minV = cnt[i];
				minI=i;
			}
		}
		if(minI==-1) break ;
		used[minI]=true;
		for(int i=0;i<n;++i){
			if(!used[i] && G[minI][i]){
				if(cnt[minI] + G[minI][i]<cnt[i]){
					cnt[i] = cnt[minI] + G[minI][i];
					path[i] = minI;	
				}else if(cnt[minI] + G[minI][i]==cnt[i] && d[minI]+time[minI][i]<d[i]){
					path[i] = minI;	
				}
			}
		}
	}
}
void get_path(vector<int> &v){
	int t = e;
	while(t != s){
		v.push_back(t);
		t = path[t];
	}
}
void print(vector<int> &v){
	for(int i=v.size()-1;i>=0;--i){
		printf(" -> %d",v[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b,f,l,t;
		scanf("%d %d %d %d %d",&a,&b,&f,&l,&t);
		G[a][b] = l;
		time[a][b] = t;
		if(!f){
			G[b][a]=l;
			time[b][a]=t;
		}
	}
	scanf("%d %d",&s,&e);
	
	vector<int> v1,v2;

	dijkstra(time);
	int min_time = d[e];
	get_path(v1);

	dijkstra1();
	int min_length = cnt[e];
	get_path(v2);
	if(v1==v2){
		printf("Distance = %d; Time = %d: %d",min_length,min_time,s);
		print(v1);
	}else{
		printf("Distance = %d: %d",min_length,s);
		print(v2);
		printf("Time = %d: %d",min_time,s);
		print(v1);
	}

	return 0;
}