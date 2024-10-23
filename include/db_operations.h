#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H
#include <mongoc/mongoc.h>

mongoc_client_t* connect_db();
void cleanup_db(mongoc_client_t *client);
#endif
