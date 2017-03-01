#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	int v;
	Node *l,*r,*p;
	Node (int _v = -1):v(_v),l(NULL),r(NULL),p(NULL){}
};
Node *root;
const int MAXN=22;
int n;
Node nodes[MAXN];

bool is_complete(Node *&ans){
	queue<Node*> p,q;
	q.push(root);
	int cnt=0;
	vector<Node*> v[MAXN];
	while(!q.empty()){
		Node *node=q.front();
		q.pop();
		v[cnt].push_back(node);
		// printf("%d ",node->v);
		if(node->l) p.push(node->l);
		if(node->r) p.push(node->r);
		if(q.empty()){
			++cnt;
			// printf("\n");
			while(!p.empty()){
				q.push(p.front());
				p.pop();
			}
		}
	}
 
	int expect = 1;
	for(int i=0;i<cnt-1;++i){
		if(v[i].size() != expect){
			ans = root;
			return false;
		}
		expect*=2;
	}

	vector<Node*> &vv = v[cnt-2];
	int i=vv.size()-1;
	while(!vv[i]->l && !vv[i]->r) --i;
	if(vv[i]->r && !vv[i]->l){
		ans = root;
		return false;
	}else{
		--i;
		while(i>=0){
			if(!vv[i]->l || !vv[i]->r){
				ans = root;
				return false;
			}
			--i;
		}
		ans = new Node(v[cnt-1].back()->v);
		return true;
	}
}
int convert(const char *s){
	int ans=0;
	int i=0;
	while(s[i] != '\0'){
		ans = ans*10 + (s[i]-'0');
		++i;
	}
	return ans;
}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	scanf("%d\n",&n);
	char l[4],r[4];
	for(int i=0;i<n;++i){
		nodes[i].v=i;
		scanf("%s %s",&l,&r);
		// printf("l=%s,r=%s\n",l,r);
		if(l[0] != '-'){
			int ll = convert(l);
			nodes[i].l = &nodes[ll];
			nodes[ll].p=&nodes[i];
		}
		if(r[0]!='-'){
			int rr = convert(r);
			nodes[i].r = &nodes[rr];
			nodes[rr].p=&nodes[i];
		}
	}
	if(n==1){
		printf("YES %d\n",nodes[0].v);
		return 0;
	}
	root = &nodes[0];
	while(root->p) root=root->p;
	Node *ans;
	if(is_complete(ans)){
		printf("YES %d\n",ans->v);
	}else{
		printf("NO %d\n",ans->v);
	}
	return 0;
}