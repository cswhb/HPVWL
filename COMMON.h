#include<stdint.h>
#define F1(a,b) ((a)^(b))
#define OFFSET 0x00000000000000FF
#define LINENUM 0xFFFFFFFFFFFFFF00
#define HALF 7
#define LINESHIFT 8 //256B –– 
#define PAGESHIFT 12 //4KB“≥ 
#define AREASHIFT 14 //area size 4MB  shift=22-8=14 
//AREASHIFT :RBSG¥Û–° 
typedef uint64_t Address;
