#include "RandKey.h" 
#include"cstdio"
using namespace std;
class MyFeistel{
	public: 
      MyFeistel(unsigned num){
      	this->randkey=new RandKey(0);
      	this->num=num;
      	mask=~((0xffffffffffffffff)<<(AREASHIFT));//在SeRBAG的access方法中已经考虑了地址映射的粒度(LINESHIFT) 
      	rmask=~((0xffffffffffffffff)<<(AREASHIFT/2));
      	lmask=(~((0xffffffffffffffff)<<(AREASHIFT/2)))<<(AREASHIFT/2);
	  }
	 ~MyFeistel(){delete(randkey);}
      Address encrypt(Address inStr,bool isOld);
      Address decrypt(Address inStr,bool isOld);
      RandKey* randkey;
      unsigned num;
      Address mask;
      Address lmask;
      Address rmask;
};
Address MyFeistel::encrypt(Address inStr,bool isOld) {
	Address key= (isOld?randkey->GetOldKey():randkey->GetNewKey())&mask;
	Address rhalf=inStr>>HALF;
	Address lhalf=(F1(rhalf,key)^inStr)<<HALF;
	return (rhalf&rmask)|(lhalf&lmask);
}
Address MyFeistel::decrypt(Address inStr,bool isOld) {
	Address key= (isOld?randkey->GetOldKey():randkey->GetNewKey())&mask;
	Address lhalf=inStr<<HALF;
	Address rhalf=(F1(inStr,key)^(inStr>>HALF));
	return (rhalf&rmask)|(lhalf&lmask);
}
