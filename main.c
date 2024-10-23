#include <stdlib.h>
#include <stdio.h>
#include "markdown_operations.h"
int main() {
    char* filename = "./file.md";
    char* html = convert_md_file_to_html(filename);
    if (html) {
        printf("Converted HTML:\n%s\n", html);
        free(html);
    } else {
        return 1;
    }


    return 0;
}
