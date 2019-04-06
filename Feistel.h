#include<stdio>
#include<COMMON.h>
public class Feistel{
	public: 
      void setKey(Address k);
      int64_t encrypt();
      int64_t decrypt();
    private:
      int64_t key;
}
int64_t Feistel::decrypt(Address inStr) {
	Address mask=0x0000000011111111;
	
}
