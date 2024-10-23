#include <stdio.h>
#include <mongoc/mongoc.h>

mongoc_client_t* connect_db() {
    char* uri_string = getenv("MONGODBURI");
    if(uri_string == NULL){
        fprintf(stderr, "Err: Please provide MONGODBURI in .env file\n");
        return NULL;
    }
    
    mongoc_client_t *client;
    mongoc_init();

    // Create a new client instance
    client = mongoc_client_new(uri_string);
    if (!client) {
        fprintf(stderr, "Failed to parse URI: %s\n", uri_string);
        return NULL;
    }

    // Test the connection
    bson_error_t error;
    if (!mongoc_client_get_database(client, "admin")) {
        fprintf(stderr, "Failed to connect to the database: %s\n", uri_string);
        mongoc_client_destroy(client);
        return NULL;
    }

    printf("Connected to MongoDB at: %s\n", uri_string);

    return client;

}
void cleanup_db(mongoc_client_t *client){
    mongoc_client_destroy(client);
    mongoc_cleanup();
}