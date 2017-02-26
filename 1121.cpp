/* 如果总数是0第二行不应该有 */
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=100000;
int num[MAXN];

int main(){
	// freopen("data.txt","r",stdin);
	memset(num,-1,sizeof(num));
	int n,m;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d %d",&a,&b);
		num[a]=b;
		num[b]=a;
	}
	set<int> s,ans;
	scanf("%d",&m);
	while(m--){
		int t;
		scanf("%d",&t);
		s.insert(t);
	}
	for(set<int>::iterator it=s.begin();it!=s.end();++it){
		if((num[*it]==-1) || (s.find(num[*it])==s.end()))
			ans.insert(*it);
	}
	printf("%d\n",ans.size());
	for(set<int>::iterator it=ans.begin();it!=ans.end();++it){
		if(it!=ans.begin())
			printf(" ");
		printf("%05d",*it);
	}
	if(ans.size()!=0)
		printf("\n");
	return 0;
}