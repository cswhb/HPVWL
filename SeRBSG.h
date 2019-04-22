#include"RBSG.h" 
#include"Feistel.h"
#include <list>
#include<vector>
#include"COMMON.h"
using namespace std;
class SeRBSG{
	public:
		SeRBSG(int level,Address bottom,Address top,Address gap,unsigned limit,unsigned areashift):level(level),bottom(bottom),top(top),limit(limit),gap(top-bottom),reset(0){
			
			rbsg=new RBSG(bottom,top,limit);
			for(Address i=0;i<top-bottom;i++)isOld.push_back(0);
			for(int i=0;i<level;i++)fList.push_back(new MyFeistel((unsigned)i,areashift));
			writetimes=0; 
		}
		Address access(Address inAddr,bool isWrite,Address &frAddr,Address &toAddr){//传入完整地址 
		    Address offset=inAddr&OFFSET;
			Address linnum=inAddr&LINENUM; 
			Address enAddr=(inAddr>>LINESHIFT)&MASK;
			for (list<MyFeistel*>::iterator it = fList.begin(); it != fList.end(); ++it)
				enAddr=it->encrypt(enAddr,isOld[it->num]^reset); //多级Feistel网络翻译 
			if(isWrite){
				writetimes++;
				if(writetimes>=limit){
					writetimes=0;
					if(gap==)
				}
			}
			return (enAddr&MASK)|offset;
		}
	private:
		int level;
		unsigned limit;//阈值  
		unsigned writetimes;
		unsigned areashift;//通过位数来确定区域大小，加密时只是用Key值的对应位 
		Address bottom;//页号 
		Address top;//页号 
		list<MyFeistel*>fList;
		char reset;//通过翻转reset位来重置isOld 
		vector<char>isOld;
		RBSG * rbsg;
};
