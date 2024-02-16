#define NUM_REGS 4
#define byte unsigned char 
#define i32 int
#define i64 unsigned long long
int regs [NUM_REGS] ;
int aregs [NUM_REGS];

typedef struct {
	i64 *mem;
	i64 max_mem;

	// registers
	i32 pc;
	i32 sp;
	i32 r[4];
	i32 ar[4];

	// instruction parts
	byte inst;
	byte dest;
	byte src;

	// flags
	i32 zero;
	i32 ltz;
	i32 gtz;
} vcpu;