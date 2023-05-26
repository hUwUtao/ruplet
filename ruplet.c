#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  unsigned char buf[1], // write buffer to
      lbuf = 0;              // iter chain
  char *key = "this is encryption key";
  int enc = 1 > 0;
  unsigned int kl = strlen(key), ol = 1;
  while (read(0, buf, 1) > 0) {
    char o = key[ol % kl] ^ lbuf ^ buf[0];
    lbuf = enc ? buf[0] : o;
    putchar(o);
    ol++;
  }
  return 0;
}
