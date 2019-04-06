#include<cstdio>
int main()
{
	int n=500,pn=0;
	en[0]=20;en[1]=40;en[2]=80;en[3]=160;en[4]=320;
	for(int i=0;i<5;i++){a[i]=0;p[i]=i;pb[i]=i;}
	while((n--)>0){
		a[p[pn]]++;
		if(a[p[pn]]%en[p[pn]]==0){
			int ps=p[pn],pbs=pb[ps];
			p[pn]=(ps+1)%5;
			p[pb[(ps+1)%5]]=ps;
			pb[ps]=pb[(ps+1)%5];
			pb[(ps+1)%5]=pbs;
		}
		pn=(pn+1)%5;
	}
	for(int i=0;i<5;i++)printf("%d,%d\n",a[i],p[i]+1);
	return 0;
} 
