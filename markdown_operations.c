#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmark.h>
#include "file_operations.h"

char* convert_md_file_to_html(char* filename){
    char* file_contents = read_file(filename);
    if (file_contents == NULL) {
        fprintf(stderr, "IO Error: File %s not found.\n", filename);
        return NULL; // Return NULL on error
    }
    char *html = cmark_markdown_to_html(file_contents, strlen(file_contents), CMARK_OPT_DEFAULT);

    // Free contents
    free(file_contents);

    // Check for conversion success
    if (html) {
        return html;
    } else {
        fprintf(stderr, "Failed to convert Markdown to HTML.\n");
        return NULL;
    }

}