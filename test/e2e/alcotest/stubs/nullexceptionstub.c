#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/config.h>
#include <caml/custom.h>
#include <caml/fail.h>
#include <caml/intext.h>
#include <caml/memory.h>
#include <caml/misc.h>
#include <caml/mlvalues.h>

value caml_segfault_call()
{
    CAMLparam0();
    int* someVal = NULL;
    int a = *someVal;
    CAMLreturn(Int_val(a));
}