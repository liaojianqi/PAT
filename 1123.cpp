#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
	int v, level;
	Node *l,*r,*p;
	Node(int _v=0):v(_v),level(1),l(NULL),r(NULL),p(NULL){}
};
Node *root;
vector<Node*> v[22];
int cur;
void update(Node *node){
	int a=0,b=0;
	if(node->l) a = node->l->level;
	if(node->r) b = node->r->level;
	node->level = max(a,b) + 1;
}
bool left_bigger_right(Node *node){
	int a = node->l?node->l->level:0, b = node->r?node->r->level:0;
	return a>b;
}
bool balance(Node *node){
	int a = node->l?node->l->level:0, b = node->r?node->r->level:0;
	a-=b;
	if(a<0) a=-a;
	return a<=1;
}
void rotateRight(Node *node){
	Node *p = node->p, *c = node->l;
	node->l = c->r;
	if(c->r) c->r->p=node;
	c->r=node;
	node->p=c;
	c->p=p;
	if(!p){
		root=c;
	}else{
		if(p->l && p->l==node) p->l=c;
		else p->r=c;
	}
	update(node);
	update(c);
}
void rotateLeft(Node *node){
	Node *p = node->p, *c = node->r;
	node->r=c->l;
	if(c->l) c->l->p=node;
	c->l=node;
	node->p=c;
	c->p=p;
	if(!p){
		root=c;
	}else{
		if(p->l && p->l==node) p->l=c;
		else p->r=c;
	}
	update(node);
	update(c);
}
/* 如果num存在，返回num的父亲节点；如果num不存在，返回num应该插入的父亲节点 */
Node* search(Node *root, int num){
	if(root->v==num) return root->p; 
	if(num < root->v){
		if(root->l == NULL || root->l->v==num) return root;
		return search(root->l, num);
	}else{
		if(root->r == NULL || root->r->v==num) return root;
		return search(root->r, num);
	}
}
void insert(int num){
	if(!root){
		root = new Node(num);
		return ;
	}
	Node *node = search(root, num);
	if(node==NULL || (node->l && node->l->v==num) 
			|| (node->r && node->r->v==num)) return ;
	if(num < node->v){
		node->l = new Node(num);
		node->l->p=node;
	}else{
		node->r = new Node(num);
		node->r->p=node;
	}
	while(node){
		update(node);
		if(balance(node)){
			node = node->p;
		}else{
			break;
		}
	}
	if(!node) return ;
	//rotate
	if(left_bigger_right(node)){
		Node *c = node->l;
		if(left_bigger_right(c)){//ll
			rotateRight(node);
		}else{//lr
			rotateLeft(c);
			rotateRight(node);
		}
	}else{
		Node *c = node->r;
		if(left_bigger_right(c)){//rl
			rotateRight(c);
			rotateLeft(node);
		}else{//rr
			rotateLeft(node);
		}
	}
}
bool complete(){
	// printf("cur = %d\n",cur);
	for(int i=0;i<cur-2;++i){
		vector<Node*> &vv = v[i];
		for(int j=0;j<vv.size();++j){
			if(vv[j]->l==NULL || vv[j]->r==NULL) return false;
		}
	}
	// printf("---\n");
	vector<Node*> &vv = v[cur-2];
	int i = vv.size()-1;
	while(i>=0){
		if(!vv[i]->l && !vv[i]->r){
			--i;
		}else{
			break;
		}
	}
	if(i<0) return true;
	if(!vv[i]->l && vv[i]->r){
		return false;
	}else{
		--i;
		while(i>=0){
			if(vv[i]->l==NULL || vv[i]->r==NULL) return false;
			--i;
		}
		return true;
	}
}
void solve(){	
	queue<Node*> p, q;
	q.push(root);
	while(!q.empty()){
		Node *node=q.front();
		q.pop();
		v[cur].push_back(node);
		if(node->l) p.push(node->l);
		if(node->r) p.push(node->r);
		if(q.empty()){
			++cur;
			while(!p.empty()){
				q.push(p.front());
				p.pop();
			}
		}
	}
	bool first=true;
	for(int i=0;i<cur;++i){
		vector<Node*> &vv = v[i];
		for(int j=0;j<vv.size();++j){
			if(!first) printf(" ");
			first = false;
			printf("%d",vv[j]->v);
		}
		// printf("\n");
	}
	printf("\n");
	if(complete()) printf("YES\n");
	else printf("NO\n");
}
int main(){
	freopen("data.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--){
		int t;
		scanf("%d",&t);
		insert(t);
	}
	solve();
	return 0;
}