/* Kewen Gu & Zhaochen Ding */
/* Sep 18, 2015 */

#include "processinfo.h"

// These values MUST match the unistd_32.h modifications:

// #define __NR_cs3013_syscall1 355
#define __NR_cs3013_syscall2 356
// #define __NR_cs3013_syscall3 357

long getprocessinfo (struct processinfo* info) {
    return (long) syscall(__NR_cs3013_syscall2, info);
}
