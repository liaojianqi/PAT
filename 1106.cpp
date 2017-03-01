#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
	int v;
	vector<Node*> ch;
	Node(int _v = -1):v(_v){}
};
const int MAXN=100003;
int n;
double p,r;
Node nodes[MAXN];

int solve(int &num){
	queue<Node*> p,q;
	q.push(&nodes[0]);
	int cnt=0;
	num = 0;
	bool flag = false;
	while(!q.empty()){
		Node *node=q.front();
		q.pop();
		vector<Node*> &v = node->ch;
		if(v.size()==0){
			flag = true;
			++num;
		}
		for(int i=0;i<v.size();++i){
			p.push(v[i]);
		}
		if(q.empty()){
			if(flag) return cnt;
			++cnt;
			while(!p.empty()){
				q.push(p.front());
				p.pop();
			}
		}
	}
	return 0;
}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;++i){
		nodes[i].v=i;
		int k,t;
		scanf("%d",&k);
		while(k--){
			scanf("%d",&t);
			nodes[i].ch.push_back(&nodes[t]);
		}
	}
	int num = 0;
	int cnt = solve(num);
	r = ((100+r)/100);
	while(cnt--){
		p *= r;
	}
	printf("%.4f %d\n",p,num);
	return 0;
}