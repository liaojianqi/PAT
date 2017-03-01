#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

struct Node{
	int h;
	char name[9];
};
bool operator< (const Node &a, const Node &b){
	if(a.h==b.h){
		return strcmp(a.name,b.name) < 0;
	}
	return a.h>b.h;
}
const int MAXN=10003;
int n,k,m;
Node nodes[MAXN];

void solve(){
	int cnt=0;
	m = n/k;
	for(int i=0;i<k;++i){
		deque<int> dq;
		int t = m ;
		if(i==0) t = m + n%k;
		bool right = false;
		int real = (t%2==0?(t-1):t);
		for(int i=0;i<real;++i){
			if(right) dq.push_front(cnt++);
			else dq.push_back(cnt++);
			right = !right;
		}
		if(t%2==0){
			dq.push_front(cnt++);
		}
		for(int j=0;j<dq.size();++j){
			printf("%s%c",nodes[dq[j]].name,j==dq.size()-1?'\n':' ');
		}
	}
}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);	
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%s %d",nodes[i].name,&nodes[i].h);
		// printf("%s %d\n",nodes[i].name,nodes[i].h);
	}
	sort(nodes,nodes+n);
	// for(int i=0;i<n;++i){
	// 	printf("%s %d\n",nodes[i].name,nodes[i].h);
	// }
	solve();
	return 0;
}