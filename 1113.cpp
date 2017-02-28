#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100003;
int n,num[MAXN];

int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	scanf("%d",&n)	;
	for(int i=0;i<n;++i){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int s1=0,s2=0,n1=n/2,n2=n-n/2;
	for(int i=0;i<n1;++i)
		s1+=num[i];
	for(int i=n1;i<n;++i)
		s2+=num[i];
	printf("%d %d\n",n2-n1,s2-s1);
	return 0;
}