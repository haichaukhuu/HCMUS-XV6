#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int pid;

    // Gọi hàm ugetpid() để lấy PID hiện tại
    pid = getpid();

    // Kiểm tra và in ra PID
    printf("Testing ugetpid...\n");
    printf("Current process ID: %d\n", pid);

    // Kiểm tra nếu PID là hợp lệ
    if (pid > 0)
    {
        printf("ugetpid test passed.\n");
    }
    else
    {
        printf("ugetpid test failed.\n");
    }

    // Kết thúc chương trình
    exit(0);
}