#include <stdlib.h>
#include <stdio.h>
#include "markdown_operations.h"
#include "dotenv.h"
#include "db_operations.h"
#include <mongoc/mongoc.h>

int main() {
    env_load(".", false);
    mongoc_client_t* client = connect_db();
    if(client == NULL){
        perror("Some error happened while connecting to db");
        return 1;
    }

    char* filename = "./file.md";
    char* html = convert_md_file_to_html(filename);
    if (!html) {
        return 1;
    }
    printf("Converted HTML:\n%s\n", html);

    free(html);
    cleanup_db(client);
    return 0;
}
