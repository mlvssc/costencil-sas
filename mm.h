#include <stdio.h>

#define piadd(p, i) (void*)((char*)(p) + (size_t)(i))
#define ppsub(p1, p2) (size_t)((char*)(p1) - (char*)(p2))

#define roundup(i, align) (((size_t)(i)+(size_t)(align)-1)/(size_t)(align)*(size_t)(align))

// function prototypes
int mm_init();
int mm_gfree(void *gp);
void *mm_galloc(size_t size);
void *mm_fetch(void *gp, size_t size);
int mm_flushall();
int mm_finish();


