#include "RandKey.h" 
using namespace std;
class MyFeistel{
	public: 
      //void Feistel(Address key):newkey(key),oldkey(0){}
      MyFeistel(){
      	this->randkey=new RanKey(0);
	  }
	 ~MyFeistel(){delete(randkey);}
      Address encrypt(Address inStr,bool isOld);
      Address decrypt(Address inStr,bool isOld);
      RandKey* randkey;
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
