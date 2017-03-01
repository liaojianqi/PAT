#include <cstdio>

typedef long long ll;
const int MAXN=100003;
int n;
double num[MAXN];
double sum;

int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	scanf("%d",&n)	;
	for(int i=0;i<n;++i){
		scanf("%lf",&num[i]);
		ll l = i, r = n-1-i;
		sum += num[i]*(l*r+l+r+1);
	}
	printf("%.2f\n",sum);
	return 0;
}