#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

struct Node{
	int v;
	Node *l,*r;
	Node(int _v):v(_v),l(NULL),r(NULL){}
};
Node *root;
int ans[1003];
Node* insert(Node *root, int num){
	if(!root){
		root = new Node(num);
		return root;
	}
	if(num <= root->v){
		root->l = insert(root->l, num);
	}else{
		root->r = insert(root->r, num);
	}
	return root;
}
void solve(){
	queue<Node*> p,q;
	int index = 0;
	q.push(root);
	while(!q.empty()){
		Node *node = q.front();
		q.pop();
		++ans[index];
		if(node->l) p.push(node->l);
		if(node->r) p.push(node->r);
		if(q.empty()){
			++index;
			while(!p.empty()){
				q.push(p.front());
				p.pop();
			}
		}
	}
	if(index == 1){
		printf("%d + %d = %d\n", ans[index-1], 0, ans[index-1]);
	}else{
		printf("%d + %d = %d\n", ans[index-1], ans[index-2], ans[index-1]+ans[index-2]);
	}
}
int main(){
	freopen("data.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--){
		int t;
		scanf("%d",&t);
		root = insert(root, t);
	}
	solve();
	return 0;
}