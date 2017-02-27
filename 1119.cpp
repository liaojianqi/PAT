#include <cstdio>
#include <vector>
using namespace std;

const int MAXN=33;
int n;
int pre[MAXN],post[MAXN];

struct Node{
	int v;
	Node *l,*r;
	Node(int _v):v(_v),l(NULL),r(NULL){}
};
bool solve(int a,int b,int c,int d){
	if(a==b) return true;
	++a,--d;
	int i=c;
	while(post[i]!=pre[a]) ++i;
	if(i==d){
		return false;
	}else{
		return solve(a,i-c+a,c,i) && solve(i-c+a+1,b,i+1,d);
	}
}
void build(int a,int b,int c,int d,Node *&root){
	root = new Node(pre[a]);
	if(a==b) return ;
	++a,--d;
	int i=c;
	while(post[i]!=pre[a]) ++i;
	if(i==d){
		build(a,b,c,d,root->l);
	}else{
		build(a,i-c+a,c,i,root->l);
		build(i-c+a+1,b,i+1,d,root->r);
	}
}
vector<int> v;
void in_order(Node *root){
	if(root->l) in_order(root->l);
	v.push_back(root->v);
	if(root->r) in_order(root->r);
}
int main(){
	freopen("data.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
		scanf("%d",&pre[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d",&post[i]);
	if(solve(0,n-1,0,n-1)) printf("Yes\n");
	else printf("No\n");
	Node *root=NULL;
	build(0,n-1,0,n-1,root);
	in_order(root);
	for(int i=0;i<v.size();++i){
		printf("%d%c",v[i],i==v.size()-1?'\n':' ');
	}
	return 0;
}