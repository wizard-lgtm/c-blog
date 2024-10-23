#include <stdio.h>
#include <mongoc/mongoc.h>
#include <dotenv.h>

char* get_db_uri(){
    env_load(".", false);
    char* uri_string = getenv("MONGODBURI");
    if(uri_string == NULL){
        fprintf(stderr, "Err: Please provide MONGODBURI in .env file\n");
        return NULL;
    }
    return uri_string;
}

void cleanup_db(mongoc_client_t *client){
    mongoc_client_destroy(client);
    mongoc_cleanup();
}
mongoc_client_t* connect_db(char* dburi) {
    mongoc_client_t *client = NULL;
    bson_error_t error = {0};
    mongoc_database_t *database = NULL;
    bson_t *command = NULL;
    bson_t reply = BSON_INITIALIZER;
    bool ok = true;

    // Initialize the MongoDB C Driver.
    mongoc_init();

    client = mongoc_client_new(dburi);
    if (!client) {
        fprintf(stderr, "Failed to create a MongoDB client.\n");
        return NULL;
    }

    // Get a handle on the "admin" database.
    database = mongoc_client_get_database(client, "admin");
    if (!database) {
        fprintf(stderr, "Failed to get a MongoDB database handle.\n");
        return NULL;
    }

    // Ping the database.
    command = BCON_NEW("ping", BCON_INT32(1));
    ok = mongoc_database_command_simple(
        database, command, NULL, &reply, &error
    );
    if (!ok) {
        fprintf(stderr, "error: %s\n", error.message);
        return NULL;
    }
    bson_destroy(&reply);

    printf("Successfully connected to MongoDB!\n");


    // Cleanup
    bson_destroy(command);
    mongoc_database_destroy(database);
    cleanup_db(client);
}
