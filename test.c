/*
The MIT License (MIT)

Copyright © 2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

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