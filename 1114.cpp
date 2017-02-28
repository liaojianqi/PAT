#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct Family{
	int id,cnt;
	double sets,area;
};
bool operator< (const Family &a, const Family &b){
	if(a.area == b.area)
		return a.id < b.id;
	return a.area > b.area;
}
struct People{
	bool appear;
	double sets,area;
	People():sets(0),area(0),appear(false){}
};
const int MAXN=10000;
int n,par[MAXN],height[MAXN];
People peoples[MAXN];

void init(){
	for(int i=0;i<MAXN;++i)
		par[i]=i;
}
int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}
void unite(int a,int b){
	a = find(a),b=find(b);
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
	scanf("%d",&n);
	init();
	// set<int> appear;
	for(int i=0;i<n;++i){
		int id,f,m,k,c;
		scanf("%d %d %d %d",&id,&f,&m,&k);
		peoples[id].appear = true;
		if(f!=-1){
			unite(id,f);
			peoples[f].appear = true;
		}
		if(m!=-1){
			unite(id,m);
			peoples[m].appear = true;
		}
		for(int j=0;j<k;++j){
			scanf("%d",&c);
			unite(id,c);
			peoples[c].appear = true;
		}
		scanf("%lf %lf",&peoples[id].sets,&peoples[id].area);
	}
	map<int,Family> mm;
	for(int i=0;i<MAXN;++i){
		People &p = peoples[i];
		if(!peoples[i].appear) continue;
		int x = find(i);
		if(mm.find(x)==mm.end()){
			mm[x] = Family();
			mm[x].id=i;
			mm[x].sets=p.sets;
			mm[x].area=p.area;
			mm[x].cnt=1;
		}else{
			Family &f = mm[x];
			// if(i < f.id) f.id = i;
			f.sets += p.sets;
			f.area += p.area;
			++f.cnt;
		}
	}
	set<Family> families;
	for(map<int,Family>::iterator it=mm.begin();it!=mm.end();++it){
		Family f = it->second;
		f.sets/=f.cnt;
		f.area/=f.cnt;
		families.insert(f);
	}
	printf("%d\n",families.size());
	for(set<Family>::iterator it=families.begin();it!=families.end();++it){
		printf("%04d %d %.3f %.3f\n", it->id, it->cnt, it->sets, it->area);
	}
	return 0;
}