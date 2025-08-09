#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <sqlite3.h>
#include <string>


class DatabaseHandler{
public:
    DatabaseHandler(const std::string &dbPath);
    ~DatabaseHandler();   


    DatabaseHandler(const DatabaseHandler &)=delete;
    

    bool createTables();
};


#endif //DATABASEHANDLER_H