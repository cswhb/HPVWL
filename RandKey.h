#include<cstdlib>
#include <time.h> 
#include "COMMON.h"
using namespace std; 
class RandKey{
	public:
		Address GetNewKey(){
			return newKey; 
		} 
		Address GetOldKey(){
			return oldKey;
		}
		void SetNewKey(){
			srand((unsigned)time(NULL)); 
			oldKey=newKey;
			newKey=(Address)rand();
		} 
		RandKey(Address key):newKey(key),oldKey(0);
	private:
		Address newKey;
		Address oldKey;
}

