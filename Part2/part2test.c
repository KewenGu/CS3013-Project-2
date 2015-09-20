/* Kewen Gu & Zhaochen Ding */
/* Sep 18, 2015 */

#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "processinfo.h"
#include "getprocessinfo.h"

#define LARGE_NUM 500000000L // Used for giving program run time in for loops

/* Function to print info of a created 'processinfo' struct */
void print_stats()
{
    struct processinfo* info = (struct processinfo*)malloc(sizeof(struct processinfo));
    getprocessinfo(info);
    printf("╔════════════════════════════════╗\n");
    printf("║State           : %14ld║\n", info->state);
    printf("║Pid             : %14d║\n", info->pid);
    printf("║Parent Pid      : %14d║\n", info->parent_pid);
    printf("║Youngest Child  : %14d║\n", info->youngestChild);
    printf("║Younger Sibling : %14d║\n", info->youngerSibling);
    printf("║Older Sibling   : %14d║\n", info->olderSibling);
    printf("║Uid             : %14d║\n", info->uid);
    printf("║Start time      : %14lld║\n", info->start_time);
    printf("║User time       : %14lld║\n", info->user_time);
    printf("║System time     : %14lld║\n", info->sys_time);
    printf("║CU Time         : %14lld║\n", info->cutime);
    printf("║CS Time         : %14lld║\n", info->cstime);
    printf("╚════════════════════════════════╝\n\n");
}

/* Main
 * Run 3 children and 1 parent process
 * Output prints parent, child 1, child 0, child 2 to demonstrate younger & older siblings, and youngest child
 */
int main () {
    int pid; // Pid for children processes
    int i; // Counter
    long l; // Run time counter
    long times[] = {LARGE_NUM * 2, LARGE_NUM * 1, LARGE_NUM * 3}; // Used to let child 1 finish before child 0, showing younger and older siblings

    for (i = 0; i < 3; i++)
    {
        if ((pid = fork()) == 0)
        {
            for (l = 0; l < times[i]; l++); // Run time
	    printf("\n");
            printf("Child %d (%d) info\n", i, getpid());
            print_stats();
            exit(0);
        }
    }
    for (l = 0; l < LARGE_NUM/2; l++); // Run time
    printf("\n");
    printf("Parent process info\n");
    print_stats();
    while(wait(0) > 0); // Wait for all children to finish
    return 0;
}
