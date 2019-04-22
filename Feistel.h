#include "RandKey.h" 
using namespace std;
class MyFeistel{
	public: 
      //void Feistel(Address key):newkey(key),oldkey(0){}
      MyFeistel(unsigned num,unsigned areashift){
      	this->randkey=new RanKey(0);
      	this->num=num;
      	mask=~(0xffffffffffffffff)<<(areashift);//在SeRBAG的access方法中已经考虑了地址映射的粒度(LINESHIFT) 
	  }
	 ~MyFeistel(){delete(randkey);}
      Address encrypt(Address inStr,bool isOld);
      Address decrypt(Address inStr,bool isOld);
      RandKey* randkey;
      unsigned num;
      Address mask;
};
Address MyFeistel::encrypt(Address inStr,bool isOld) {
	Address key= isOld?randkey->GetOldKey():randkey->GetNewKey();
	Address rhalf=inStr>>HALF;
	Address lhalf=(F1(rhalf,key)^inStr)<<HALF;
	return (rhalf&RMASK)|(lhalf&LMASK);
}
Address MyFeistel::decrypt(Address inStr,bool isOld) {
	Address key= isOld?randkey->GetOldKey():randkey->GetNewKey();
	Address lhalf=inStr<<HALF;
	Address rhalf=(F1(inStr,key)^(inStr>>HALF));
	return (rhalf&RMASK)|(lhalf&LMASK);
}
