/**std
 * by pfy
 * in 2018-04-22
**/

#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

inline LL pow_mod(LL a,LL b,LL mod)
{
	a%=mod;
	LL ans=1;
	for(; b; b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}

const LL mod=1e9+7;

inline LL solve1(LL a,LL b)
{
	return pow_mod(a,pow_mod(a,b-1,mod-1),mod);
}

inline LL solve2(LL n)
{
	if(n<=1)return 0;
	if(n&1)	return (solve2(n>>1)+solve2((n>>1)+1)+(n>>1))%mod;
	else	return ((solve2(n>>1)<<1)%mod+(n>>1)%mod);
}

struct mat
{
	LL a[3][3],r,c;
};

inline mat mul(mat x,mat y)
{
	mat p;
	memset(&p,0,sizeof(p));
	p.r=x.r,p.c=x.c;
	for(register int i=0; i<=x.r; ++i)
		for(register int j=0; j<y.c; ++j)
			for(register int k=0; k<x.c; ++k)
				p.a[i][j]=(p.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
	return p;
}

inline LL fast(LL k)
{
	mat p,ans;
	memset(&p,0,sizeof(p));
	memset(&ans,0,sizeof(ans));
	p.r=p.c=2;
	p.a[0][0]=p.a[0][1]=p.a[1][0]=1;
	ans.r=1;
	ans.c=2;
	ans.a[0][0]=ans.a[0][1]=1;
	for(; k; k>>=1,p=mul(p,p))if(k&1)ans=mul(ans,p);
	return ans.a[0][0];
}

inline LL gcd(LL a,LL b)
{
	while(b)
	{
		a%=b;
		LL t=a;
		a=b;
		b=t;
	}
	return a;
}

LL sol3(LL n,LL m)
{
	n=gcd(n,m);
	if(n<=2) return 1;
	else return fast(n-2);
}

inline LL calc(LL a,LL b,LL c)
{
	return sol3(solve1(a,b),solve2(c));
}

int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
#if 0
	SXDAKZJOI^_^
#endif
	LL a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld",calc(a,b,c));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
