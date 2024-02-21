#ifndef FLAGS_H 
#define FLAGS_H

void clear_flags(vcpu *c) {
	c->zero = 0;
	c->ltz = 0;
	c->gtz = 0;
}

void set_flags(vcpu *c, i32 a, i32 b) {
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	i32 res = a - b;
	c->zero = (res == 0);
	c->ltz = (res < 0);
	c->gtz = (res > 0);
}

#endif // FLAGS_H