#include <unistd.h>
#include <stdio.h>
int main () {
  //char hostbuffer[256];
  int hostname;
  char hn[257];
  hostname = gethostname(hn,257);
  printf("Hostname: %s\n", hn);

  return hostname;
}
