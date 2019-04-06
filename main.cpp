#include<cstdio>
#include"Feistel.h"
int main()
{
	MyFeistel* tester=new MyFeistel();
	Address test1=tester->encrypt(0x1234567812345678,0x8465384308272361);
	Address test2=tester->decrypt(test1,0x8765432187654321);
	printf("test1=%llx\ntest2=%llx\n",test1,test2);
} 
