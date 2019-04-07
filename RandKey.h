#include<cstdlib> 
class RandKey{
	public:
		Address GetNewKey();
		Address GetOldKey();
		void SetNewKey(Address key);
		RandKey(Address key):newKey(key),oldKey(0);
	private:
		Address newKey;
		Address oldKey;
}

