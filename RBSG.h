#include "COMMON.h"
using namespace std; 
class RBSG{
	public:
		RBSG(Address bottom,Address top,unsigned limit):start(0),gap(top-bottom),
	    bottom(bottom),top(top),area(top-bottom),limit(limit),writetimes(0){}//����=top-bottom ���������� 
	    void SetLimit(unsigned limit){
	    	this->limit=limit;
		}
		Address Translate(Address inAddr){
			Address pa=(inAddr+start)%(top-bottom);
			return pa>=gap?pa+1:pa;
		}
		bool ChangeWrite(Address &fromAddr ,Address &toAddr){
	    //���д����������ֵ������һ��gap��Ǩ�� 
			writetimes=writetimes+1==limit?0:writetimes+1;
			toAddr=gap;
		    if(writetimes==0){
		    	if(gap==0){
		    		gap=area;
		    		start=(start+1)%(area);
		    		gap=area;
				}
				else gap=gap-1;
			}
			fromAddr=gap;
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
