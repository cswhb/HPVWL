class RBSG{
	public:
		RBSG(Address bottom,Address top,unsigned limit):start(bottom),gap(top-1),
	    bottom(bottom),top(top),limit(limit){}
	    void SetLimit(unsigned limit){
	    	this->limit=limit;
		}
		Address Translate(Address inAddr){
			
		}
			
	private:
		Address start;
		Address gap;
		Address bottom;
		Address top;
		unsigned limit;
};
