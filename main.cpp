#include<cstdio>
#include"Feistel.h"
int main()
{
	MyFeistel* tester=new MyFeistel(0);
	Address test1=tester->encrypt(0x123456781234FFFF,0x8465384308272361);
	Address test2=tester->decrypt(test1,0x8465384308272361);
	printf("test1=%llx\ntest2=%llx\n",test1,test2);
} 
