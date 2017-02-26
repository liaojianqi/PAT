#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 205;
int G[MAXN][MAXN];
int n,m;

bool ok(vector<int> &v){
	if(v.size()!=n+1 || v[0]!=v[v.size()-1]) return false;
	set<int> s;
	for(int i=1;i<v.size();++i){
		if(s.find(v[i])!=s.end()) return false;
		if(!G[v[i]][v[i-1]]) return false;
		s.insert(v[i]);
	}
	return true;
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		--a;
		--b;
		G[a][b]=G[b][a]=1;
	}
	int k;
	scanf("%d",&k);
	while(k--){
		int t;
		scanf("%d",&t);
		vector<int> v;
		for(int i=0;i<t;++i){
			int c;
			scanf("%d",&c);
			v.push_back(--c);
		}
		if(ok(v)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}