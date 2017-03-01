/* 诸如1. .1 这样的数据也是合法的(坑) ,最后一组数据估计就有1.这样的形式 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

bool is_digit(char c){
	return (c>='0' && c<='9');
}
bool ok(const char *s, double &ans){
	int intV=0,doubleV=0,cnt=1;
	bool neg = false;
	if(*s == '-'){
		++s;
		neg=true;
	}
	while(*s!='\0' && is_digit(*s)){	
		intV = intV*10 + (*s - '0');
		if(intV > 1000) return false;
		++s;
	}
	if(*s == '\0'){
		ans = intV;
		if(neg) ans=-ans;
		// printf("ans=%f\n",ans);
		return true;
	}
	if(*s == '.'){
		++s;
		// if(*s == '\0') return false;
		while(*s!='\0' && is_digit(*s)){
			doubleV = doubleV*10 + (*s - '0');
			cnt*=10;
			if(cnt>100) return false;
			++s;
		}
		if(*s != '\0') return false;
		ans = intV + doubleV/(double)cnt;
		if(ans>1000) return false;
		if(neg) ans=-ans;
		return true;
	}else{
		return false;
	}

}
int main(int argc, char const *argv[]){
	freopen("data.txt","r",stdin);
	int n,cnt=0;
	double sum=0;
	char s[1000];
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		double dd;
		if(ok(s,dd)){
			// printf("dd=%f\n",dd);
			sum+=dd;
			++cnt;
		}else{
			printf("ERROR: %s is not a legal number\n",s);
		}
	}
	if(cnt==0){
		printf("The average of 0 numbers is Undefined\n");
	}else if(cnt==1){
		printf("The average of 1 number is %.2lf\n",sum);
	}else{
		printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
	}
	return 0;
}