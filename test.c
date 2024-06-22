#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // 创建子进程
    pid = fork();

    if (pid < 0) {
        // fork 失败
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // 子进程
        printf("This is the child process.\n");
        printf("Child PID: %d\n", getpid());
        
        // 在子进程中执行新的可执行程序 (例如 ls)
        execl("/bin/ls", "ls", NULL);

        // 如果 exec 执行失败
        perror("exec failed");
        exit(EXIT_FAILURE);
    } else {
        // 父进程
        printf("This is the parent process.\n");
        printf("Parent PID: %d\n", getpid());

        // 等待子进程结束
        wait(NULL);
        printf("Child process finished.\n");
    }

    return 0;
}
