#include <cstdio>
#include <set>
using namespace std;

int sum(int t){
    int ans=0;
    while(t){
        ans+=(t%10);
        t/=10;
    }
    return ans;
}
int main(){
   // freopen("a.txt","r",stdin);
    set<int> s;
    int n;
    scanf("%d",&n);
    while(n--){
        int t;
        scanf("%d",&t);
        s.insert(sum(t));
    }
    printf("%d\n", s.size());
    bool first = true;
    for(set<int>::iterator it=s.begin();it!=s.end();++it){
        if(!first) printf(" ");
        first=false;
        printf("%d",*it);
    }
    printf("\n");
    return 0;
}