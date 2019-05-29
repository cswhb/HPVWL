#include "COMMON.h"
using namespace std; 
class RBSG{
	public:
		RBSG(Address bottom,Address top,unsigned limit):start(0),gap(top-bottom+1),
	    bottom(bottom),top(top),area(top-bottom+1),limit(limit),writetimes(0){}//����=top-bottom+1 ���������� 
	    void SetLimit(unsigned limit){
	    	this->limit=limit;
		}
		Address Translate(Address inAddr,bool iswrite,bool &ischange,Address &fromAddr ,Address &toAddr){
			Address pa=(inAddr-bottom+start)%(top-bottom);
			pa= pa>=gap?pa+1:pa;
			if(iswrite){
				if(ischange=ChangeWrite(fromAddr ,toAddr)){
					if(pa==fromAddr){
						ischange=false;
						return toAddr+bottom;
					}
				}
			}
			return PA+bottom;
		}
		bool ChangeWrite(Address &fromAddr ,Address &toAddr){
	    //���д����������ֵ������һ��gap��Ǩ�� 
			writetimes=writetimes+1==limit?0:writetimes+1;
			toAddr=gap+bottom;
		    if(writetimes==0){
		    	if(gap==0){
		    		gap=area;
		    		start=(start+1)%(area);
		    		gap=area;
				}
				else gap=gap-1;
			}
			fromAddr=gap+bottom;
			return writetimes==0?1:0;
		} 
	private:
		Address start;
		Address gap;
		Address bottom;//�����ַ�½� 
		Address top;//�����ַ�Ͻ� 
		Address area;
		unsigned limit;//��ֵ 
		unsigned writetimes;
};
