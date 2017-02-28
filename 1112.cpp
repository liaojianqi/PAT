#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
short flag[128];
char s[1003];

void solve(){
	vector<char> v;
	for(int i=0;i<n;){
		char c = s[i];
		int j=i+1;
		while(j<n && s[j]==s[i]) ++j;
		int cnt=j-i;
		if(cnt%k != 0){
			flag[c] = 2;
		}else{
			if(flag[c]!=2){
				flag[c]=1;
				if(find(v.begin(),v.end(),c)==v.end()) v.push_back(c);
			}
		}
		i=j;
	}
	for(int i=0;i<v.size();++i){
		if(flag[v[i]]!=2){
			printf("%c",v[i]);
		}
	}
	printf("\n");
	for(int i=0;i<n;++i){
		char c=s[i];
		if(flag[c]!=1){
			printf("%c",c);
		}else{
			printf("%c",c);
			i+=k-1;
		}
	}
	printf("\n");
}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	scanf("%d\n%s",&k,s);
	n = strlen(s);
	solve();
	return 0;
}
