#define NUM_REGS 4
#define byte unsigned char 
#define i32 int
#define i64 unsigned long long
#define DEFAULT 255
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
	i32 src;

	// flags
	i32 zero;
	i32 ltz;
	i32 gtz;
} vcpu;