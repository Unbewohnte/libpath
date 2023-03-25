# libpath

### A minimal (file)path library

### Features

- Joining multiple path parts
- Cleaning path of duplicate separators
- Retrieval of path's parent


### Example
```c
// Compiling for *nix system (therefore the separator is '/')
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libpath.h"

int main() {
    char* path = path_join(4, "//here", "there", "/over/there_as_well", "file.txt");
    printf("Joined path: %s\n", path);
    
    char* parent = path_parent(path);
    printf("Parent: %s\n", parent);

    path_free(&path);

    char* parent_of_parent = path_parent(parent);
    printf("Parent of parent: %s\n", parent_of_parent);
    
    path_free(&parent);
    path_free(&parent_of_parent);
    
    return EXIT_SUCCESS;
}
```

### License

MIT