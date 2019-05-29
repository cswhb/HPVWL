#include"RBSG.h" 
#include"Feistel.h"
#include <list>
#include<vector>
#include"COMMON.h"
using namespace std;
class SeRBSG{
	public://�����кţ�bottom��top�� 
		SeRBSG(int level,Address bottom,Address top,unsigned limit):level(level),limit(limit),reset(0){
			this->bottom=bottom 
			this->top=top;
			gap=top-bottom;
			for(Address i=0;i<top-bottom;i++)isOld.push_back(0);
			for(Address i=0;i<(top-bottom)/(1<<AREASHIFT)+1;i++)RBSG.push_back(new RBSG(bottom+i*(1<<AREASHIFT),bottom+(i+1)*(1<<AREASHIFT)-1,limit););
			for(int i=0;i<level;i++)fList.push_back(new MyFeistel((unsigned)i,areashift));
			writetimes=0; 
		}
		Address access(Address inAddr,bool isWrite,Address &frAddr,Address &toAddr){//����������ַ 
		    Address offset=inAddr&OFFSET;
			Address enAddr=((inAddr>>LINESHIFT)&MASK)-bottom;//ת��Ϊ�ڲ���ַ��bottom��Ϊ0�� 
			for (list<MyFeistel*>::iterator it = fList.begin(); it != fList.end(); ++it)
				enAddr=it->encrypt(enAddr,isOld[it->num]^reset); //�༶Feistel���緭�� 
			if(isWrite){
				writetimes++;
				if(writetimes>=limit){
					writetimes=0;
					if(gap==)    
				}
			}
			return ((enAddr+bottom)<<LINESHIFT)|offset;
		}
	private:
		int level;
		unsigned limit;//��ֵ  
		unsigned writetimes;
		Address bottom;//ҳ�� 
		Address top;//ҳ�� 
		list<MyFeistel*>fList;
		char reset;//ͨ����תresetλ������isOld 
		vector<char>isOld;
		vector<RBSG*>rbsg;
};
