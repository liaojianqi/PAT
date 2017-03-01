#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000
struct Node{
	int e,l;
	Node(int _e,int _l):e(_e),l(_l){}
};
const int MAXN = 503;
int n,m,s,e,dt[MAXN],dl[MAXN],path[MAXN],time[MAXN];
vector<Node> Gl[MAXN],Gt[MAXN];

bool operator<(const Node &a,const Node &b){
	return a.l > b.l;
}

void dijkstra_t(){
	fill(dl,dl+n,INF);
	fill(dt,dt+n,INF);
	priority_queue<Node> pq;
	pq.push(Node(s,0));
	dl[s] = 1;
	while(!pq.empty()){
		Node node = pq.top();
		pq.pop();
		if(dt[node.e] < node.l) continue;
		dt[node.e] = node.l;
		vector<Node> &v = Gt[node.e];
		for(int i=0;i<v.size();++i){
			Node &tmp = Gt[node.e][i];
			if(dt[node.e] + tmp.l < dt[tmp.e]){
				dt[tmp.e] = dt[node.e] + tmp.l;
				path[tmp.e] = node.e;
				dl[tmp.e] = dl[node.e]+1;
				pq.push(Node(tmp.e, dt[tmp.e]));
			}else if(dt[node.e] + tmp.l == dt[tmp.e]){
				if(dl[node.e]+1<dl[tmp.e]){
					dl[tmp.e] = dl[node.e]+1;
					path[tmp.e] = node.e;
				}
			}
		}
	}
}
void dijkstra_l(){
	fill(dl,dl+n,INF);
	fill(time,time+n,INF);
	priority_queue<Node> pq;
	pq.push(Node(s,0));
	time[s]=0;
	while(!pq.empty()){
		Node node = pq.top();
		pq.pop();
		if(dl[node.e] < node.l) continue;
		dl[node.e] = node.l;
		vector<Node> &v = Gl[node.e];
		for(int i=0;i<v.size();++i){
			Node &tmp = Gl[node.e][i];
			if(dl[node.e] + tmp.l < dl[tmp.e]){
				dl[tmp.e] = dl[node.e] + tmp.l;
				path[tmp.e] = node.e;
				pq.push(Node(tmp.e, dl[tmp.e]));
				time[tmp.e] = time[node.e] + Gt[node.e][i].l;
			}else if(dl[node.e] + tmp.l == dl[tmp.e]){
				if(time[node.e]+Gt[node.e][i].l<time[tmp.e]){ 
					time[tmp.e] = time[node.e]+Gt[node.e][i].l;
					path[tmp.e] = node.e;
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
		Gl[a].push_back(Node(b,l));
		Gt[a].push_back(Node(b,t));
		if(!f){
			Gl[b].push_back(Node(a,l));
			Gt[b].push_back(Node(a,t));
		}
	}
	scanf("%d %d",&s,&e);
	vector<int> vt,vl;
	dijkstra_t();
	get_path(vt);
	dijkstra_l();
	get_path(vl);
	if(vt == vl){
		printf("Distance = %d; Time = %d: %d",dl[e],dt[e],s);
		print(vl);
	}else{
		printf("Distance = %d: %d",dl[e],s);
		print(vl);
		printf("Time = %d: %d",dt[e],s);
		print(vt);
	}
	return 0;
}