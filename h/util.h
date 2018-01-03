

#ifndef _util_h_
#define _util_h_

#include <stdio.h>

#define lock() { asm pushf; asm cli; }
#define unlock() { asm popf; }

typedef void interrupt(*InterPtr)(...);

#endif // !_util_h_
