#include<stdint.h>
#define F1(a,b) ((a)^(b))
#define RMASK 0x000000000FFFFFFF
#define LMASK 0x000000000FFFFFFF 
#define MASK 0x00FFFFFFFFFFFFFF
#define OFFSET 0x00000000000000FF
#define LINENUM 0xFFFFFFFFFFFFFF00
#define HALF 28
#define LINESHIFT 8 
#define PAGESHIFT 12
#define AREASHIFT 12
//AREASHIFT :RBSG¥Û–° 
typedef uint64_t Address;
