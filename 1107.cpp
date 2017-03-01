#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN=2003;
int n,par[MAXN],r[MAXN];

void init(){
	for(int i=n;i<MAXN;++i)
		par[i]=i;
}
int find(int x){
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
void unite(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return ;
	if(r[a]<r[b]) par[a]=b;
	else{
		par[b]=a;
		if(r[a]==r[b]) ++r[a];
	}
}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	init();
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int k,t;
		scanf("%d:",&k);
		while(k--){
			scanf("%d",&t);
			unite(i,t+n);
		}
	}
	map<int,int> m;
	for(int i=0;i<n;++i){
		int x = find(i);
		if(m.find(x)==m.end()){
			m[x] = 1;
		}else{
			++m[x];
		}
	}
	printf("%d\n",m.size());
	vector<int> v;
	for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
		v.push_back(it->second);
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;--i){
		printf("%d%c",v[i],i==0?'\n':' ');
	}
	return 0;
}