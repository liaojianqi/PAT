#include <cstdio>
#include <set>
using namespace std;

const int MAXN=10003;
int n,par[MAXN],height[MAXN];

void init(){
	for(int i=0;i<MAXN;++i){
		par[i]=i;
		height[i]=0;
	}
}
int find(int x){
	if(x==par[x]) return x;
	return par[x]=find(par[x]);
}
bool same(int a,int b){
	a=find(a),b=find(b);
	return a==b;
}
void unite(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return ;
	if(height[a]<height[b]){
		par[a]=b;
	}else{
		par[b]=a;
		if(height[a]==height[b]) ++height[a];
	}
}

int main(){
	freopen("data.txt","r",stdin);
	init();
	set<int> tree,birds;
	scanf("%d",&n);
	while(n--){
		int t,x,y;
		scanf("%d",&t);
		scanf("%d",&x);
		birds.insert(--x);
		while(--t){
			scanf("%d",&y);
			birds.insert(--y);
			unite(x,y);
		}
	}
	for(int i=0;i<birds.size();++i){
		tree.insert(find(i));
	}
	printf("%d %d\n",tree.size(),birds.size());
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d %d",&a,&b);
		--a;--b;
		if(same(a,b)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}