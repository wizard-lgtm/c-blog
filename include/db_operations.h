#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H
#include <mongoc/mongoc.h>

char* get_db_uri();
mongoc_client_t* connect_db(char* dburi);
void cleanup_db(mongoc_client_t *client);
#endif
