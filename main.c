#include "twice.h"
// in honor of Twice's song Signal

static void sighandler(int signal) {
  if (signal == SIGINT) {
    int file = open("exit.data", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (file == -1) {
        printf("An error has occured. %s\n", strerror(errno));
    }
    char *message = "Program exited --> SIGINT caught\n";
    write(file, message, strlen(message));
    exit(0);
  }
  else if (signal == SIGUSR1) {
    printf("PPID: %d\n", getppid());
  }
}

int main() {

    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while(1) {
        printf("PID: %d\n", getpid());
        sleep(1);
    }

}
