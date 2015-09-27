Kewen Gu & Zhaochen Ding
--
Project 2
--
CS 3013
--
Sep 18, 2015
--

==========================================
Part 1:
------
In part 1, we intercepted the new added syscall cs3013_syscall1, then we wrote two programs sys_open.c and sys_close.c to intercept the original open and close syscalls. To test our program, enter "make" to generate the kernel modules, then "sudo insmod <module_name>" to insert the module into the kernel. We have a program called "part1test" which is used to test the intercepted cs3013_syscall1. you can enter "./part1test" to test cs3013_syscall1, and observe the logfile by entering "tail -n 3 /var/log/syslog". After the testing, remove all the modules from the kernel using "sudo rmmod <module_name>".
------------------------------------------

Part 2:
------
In part 2, we intercepted the syscall cs3013_syscall2. After the interception, we are able to print the statistics of the parent and child processes using cs3013_syscall2. In order to do this, first, "make" the kernel modul. Next, "sudo insmod part2.ko" to insert the part2 module into the kernel, then using our test program "./part2test" to test the module. In the end, remove the module from the kernel by "sudo rmmod part2.ko".
------------------------------------------
