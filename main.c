#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmark.h>
#include "file_operations.h"
int main() {
    char* filename = "./file.md";

    char* file_contents = read_file(filename);




    // Convert Markdown to HTML
    char *html = cmark_markdown_to_html(file_contents, strlen(file_contents), CMARK_OPT_DEFAULT);

    // Check for conversion success
    if (html) {
        // Print the generated HTML
        printf("Generated HTML:\n%s\n", html);

        // Free the memory allocated for the HTML string
        free(html);
    } else {
        fprintf(stderr, "Failed to convert Markdown to HTML.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
