#include <stdlib.h>

int main() {
  int* ptr = malloc(sizeof(int));
  *ptr = 42;

  // Uncomment this line to simulate a memory leak
  // ptr = NULL;

  free(ptr);
  return 0;
}
/*
In this example, we're allocating a block of memory using the malloc function, storing a value in the allocated memory, and then freeing the memory using the free function. If there are no memory leaks in the code, valgrind should report that there were no leaks detected.

To run this code with valgrind, you would first need to compile the code with debugging symbols enabled using the -g flag, and then run the code with valgrind using the following command:

bash
Copy code
gcc -g -o myprogram myprogram.c
valgrind --leak-check=full ./myprogram

When you run valgrind with the --leak-check=full option, it will detect any memory leaks in your code and report them in the output.

Note that this is just a basic example, and there are many other techniques and tools available for detecting memory leaks in C code, depending on the specifics of your application.


*/
