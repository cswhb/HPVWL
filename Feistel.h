#include "COMMON.h"
class MyFeistel{
	public: 
      //void Feistel(Address key):newkey(key),oldkey(0){}
      Address encrypt(Address inStr,Address key);
      Address decrypt(Address inStr,Address key);
};
Address MyFeistel::encrypt(Address inStr,Address key) {
	Address rhalf=inStr>>HALF;
	Address lhalf=(F1(rhalf,key)^inStr)<<HALF;
	return (rhalf&RMASK)|(lhalf&LMASK);
}
Address MyFeistel::decrypt(Address inStr,Address key) {
	Address lhalf=inStr<<HALF;
	Address rhalf=(F1(inStr,key)^(inStr>>HALF));
	return (rhalf&RMASK)|(lhalf&LMASK);
}
