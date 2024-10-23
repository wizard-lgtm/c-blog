#include <mongoc/mongoc.h>
#include "db_operations.h"
int main(void) {
    // Get mongodb uri connection string from .env file
    char* dburi = get_db_uri();
    // Create mongodb client 
    mongoc_client_t* client = connect_db(dburi);

    // Get a handle on the "admin" database.
    mongoc_database_t *database = mongoc_client_get_database(client, "admin");
    if (!database) {
        fprintf(stderr, "Failed to get a MongoDB database handle.\n");
        return NULL;
    }
    mongoc_collection_t *collection = mongoc_database_get_collection(database, "post"); 

    


    mongoc_database_destroy(database);
    mongoc_collection_destroy(collection);
    // Cleanup server 
    cleanup_db(client);
}