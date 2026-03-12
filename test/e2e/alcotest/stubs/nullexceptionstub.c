#include <caml/mlvalues.h>
#include <caml/memory.h>

#include <stdio.h>

value caml_segfault_call(void) {
  CAMLparam0();
  int *someVal = NULL;
  int a = *someVal;
  printf("%i\n", a); // printf to force Apple plat evalation
  CAMLreturn(Int_val(a));
}