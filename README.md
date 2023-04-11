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
    
    char* parent = path_parent_copy(path);
    printf("Parent: %s\n", parent);

    path_free(&path);

    // becomes parent of parent
    path_parent(parent);
    printf("Parent of parent: %s\n", parent);
    
    path_free(&parent);
    
    char* windows_path = path_join(2, "C:\\Documents\\", "file.txt");
    printf("Windows path: %s\n", windows_path);
    path_to_native_separators(windows_path);
    printf("Windows path with native separators: %s\n", windows_path);

    path_free(&windows_path);

    return EXIT_SUCCESS;
}
```

### License

MIT