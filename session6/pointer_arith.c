#include <stdio.h>
#include <stdint.h>

#define dump_addr(VAR) \
  printf("\nAddr = %p", VAR)

#define dump_diff(IDENT, VAR) \
  printf("\n%s :: diff = %ld byte%s.\n", IDENT, VAR, VAR > 1 ? "s" : "")

int main(void) {

  long diff;

  // Char: offset 1 byte
  char c;
  char *pc = &c;
  diff = (long) pc;

  dump_addr(pc);
  pc++;
  dump_addr(pc);

  diff = ((long) pc) - diff;
  dump_diff("char", diff);

  //////////////////////

  int i;
  int *pi = &i;
  diff = (long) pi;

  dump_addr(pi);
  pi++;
  dump_addr(pi);
  
  diff = ((long) pi) - diff;
  dump_diff("int", diff);
  
  //////////////////////

  long l;
  long *pl = &l;
  diff = (long) pl;

  dump_addr(pl);
  pl++;
  dump_addr(pl);

  diff = ((long) pl) - diff;
  dump_diff("long", diff);
  
  //////////////////////

  long long ll;
  long long *pll = &ll;
  diff = (long) pll;

  dump_addr(pll);
  pll++;
  dump_addr(pll);

  diff = ((long) pll) - diff;
  dump_diff("long long", diff);

  return 0;
}
