#include <cstdio>
#include <map>
#include <set>
using namespace std;

map<int,int> m;

bool is_prime(int t){
	for(int i=2;i<t;++i){
		if(t%i == 0) return false;
	}
	return true;
}
int main(){
	freopen("data.txt","r",stdin);
	int n,id,k;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&id);
		m[id]=i+1;
	}
	set<int> s;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&id);
		printf("%04d: ",id);
		if(m.find(id)==m.end()){
			printf("Are you kidding?\n");
		}else if(s.find(id)!=s.end()){
			printf("Checked\n");
		}else{
			int t = m[id];
			if(t==1) printf("Mystery Award\n");
			else if(is_prime(t)) printf("Minion\n");
			else printf("Chocolate\n");
			s.insert(id);
		}
	}
	return 0;
}