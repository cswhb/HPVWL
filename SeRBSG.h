#include"RBSG.h" 
#include"Feistel.h"
#include <list>
#include<vector>
using namespace std;
class SeRBSG{
	public:
		SeRBSG(int level,Address bottom,Address top,unsigned limit):level(level),limit(limit){
			rbsg=new RBSG(bottom,top,limit);
			for(int i=0;i<top-bottom;i++)isOld.push_back(0);
		}
		Address access(Address inAddr){
			
		}
	private:
		int level;
		unsigned limit;//ãÐÖµ 
		unsigned writetimes;
		list<Feistel>fList;
		vector<char>isOld;
		RBSG * rbsg;
};
