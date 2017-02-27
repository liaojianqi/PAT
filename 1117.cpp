#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100003;
int n,num[MAXN];

int solve(){
	int l=0,r=n+1;
	while(r-l>1){
		int mid=(l+r)/2;
		int index = (num+n) - upper_bound(num,num+n,mid);
		if(index<mid){
			r=mid;
		}else{
			l=mid;
		}
	}
	return l;
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&num[i]);
	sort(num,num+n);
	printf("%d\n",solve());
	return 0;
}