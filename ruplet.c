#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  unsigned char buf[1], obuf[1024], loc;

  char *key = "this is encryption key";
  unsigned int kl = strlen(key), ol = 1;

  while (read(0, buf, sizeof(buf)) > 0) {
    char toc = buf[0], ck = key[ol % kl];
    toc = ck ^ loc ^ toc;
    putchar(toc);
    ol++;
  }
  return 0;
}