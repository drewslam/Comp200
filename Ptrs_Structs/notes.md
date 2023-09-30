# Pointers

Pointers let you work with data whose locations change or whose size is variable.

With a variable, you can access a value at a fixed location. With a pointer, the location can vary.

`double harrys_account = 0;
 double* acct_pointer = &harrys_account;`

* == operator to read or update the location of a value to which a pointer points.

Pointer and memory address pointed to MUST be same type. eg. Int pointer cannot point to Double address.

Pointers must be initialized to a value or to nullptr.

To define multiple pointers inline apply the * operator to each individual variable and not the type.

# Dynamic Memory Allocation

new & delete operators


