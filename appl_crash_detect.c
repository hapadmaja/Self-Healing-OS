#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signum) {
  printf("Application crashed with signal %d\n", signum);
  exit(1);
}

int main() {
  signal(SIGSEGV, signal_handler);
  signal(SIGILL, signal_handler);
  signal(SIGFPE, signal_handler);
  signal(SIGABRT, signal_handler);
#ifdef SIGBUS
  signal(SIGBUS, signal_handler);
#endif

  // Start your application code here
  while (1) {
    // Your application code goes here
    sleep(1);
  }

  return 0;
}
