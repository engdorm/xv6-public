//#include "processInfo.h"
#include "types.h"
#include "stat.h"

#include "user.h"
//#include "proc.h"

enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

int main(int argc, char *argv[]) {
  int max_pid = 0;
  struct processInfo pi;
  max_pid = getMaxPid();

  printf(1, "Total number of active processes: %d\n", getNumProc());
  printf(1, "Maximum PID: %d\n", max_pid);
  for (int pid = 0; pid < max_pid; pid++) {
    if (getProcInfo(pid, &pi) == 0) {
      char *state_str;

      switch (pi.state) {
      case UNUSED:
        state_str = "UNUSED";
        break;
      case EMBRYO:
        state_str = "EMBRYO";
        break;
      case SLEEPING:
        state_str = "SLEEPING";
        break;
      case RUNNABLE:
        state_str = "RUNNABLE";
        break;
      case RUNNING:
        state_str = "RUNNING";
        break;
      case ZOMBIE:
        state_str = "ZOMBIE";
        break;
      default:
        state_str = "???";
        break;
      }

      printf(1, "%d %s %d %d %d %d\n", pid, state_str, pi.ppid, pi.sz, pi.nfd,
             pi.nrswitch);
    }
  }

  exit();
}
