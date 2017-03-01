#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN=10003;
int m,n,num[MAXN][MAXN],p,x[MAXN];

bool cmp(const int &a,const int &b){
	return a>b;
}
void solve(){
	int index = 0;
	int i=0,j=0,s=0;
	while(true){
		// printf("--\n");
		i=j=s;
		for(;j<n-s;++j){
			num[i][j]=x[index++];
			if(index>=p) return ;
		}
		--j;
		++i;
		for(;i<m-s;++i){
			num[i][j]=x[index++];
			if(index>=p) return ;
		}
		--i;
		--j;
		for(;j>=s;--j){
			num[i][j]=x[index++];	
			if(index>=p) return ;
		}
		++j;
		--i;
		for(;i>s;--i){
			num[i][j]=x[index++];
			if(index>=p) return ;		
		}	
		++s;
	}
	
}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	scanf("%d",&p);
	for(int i=0;i<p;++i)
		scanf("%d",&x[i]);
	sort(x,x+p,cmp);
	//get m,n m>=n
	n = sqrt(p);
	// printf("n=%d\n",n);
	while(p%n != 0) --n;
	m=p/n;
	// printf("m=%d,n=%d\n", );
	solve();
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			printf("%d%c",num[i][j],j==n-1?'\n':' ');
		}
	}
	return 0;
}