#include <stdlib.h>
#include <errno.h>

int dummy_var = 0;

void *aligned_alloc(size_t alignment, size_t size);

// Embedded Swift currently requires posix_memalign, but the C libraries in the
// Zephyr SDK do not provide it. Let's implement it and forward the calls to
// aligned_alloc(3).
int
posix_memalign(void **memptr, size_t alignment, size_t size)
{
  //void *p = aligned_alloc(alignment, size);
  void *p = malloc(size);
  if (p) {
    *memptr = p;
    return 0;
  }

  return errno;
}