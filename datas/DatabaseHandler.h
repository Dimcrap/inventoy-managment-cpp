#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <sqlite3.h>
#include <string>


class DatabaseHandler{
public:
    DatabaseHandler(const std::string &dbPath);
    ~DatabaseHandler();   


    DatabaseHandler(const DatabaseHandler &)=delete;
    DatabaseHandler& operator=(const DatabaseHandler&)=delete;


    bool backupDatabse(const std::string & backupPath);
    
    private:
    sqlite3* db;
    std::string DBPath;
    
    void executeSQL(const std::string & sql);
    static int callback(void *data ,int argc,char ** argv);
    bool createTables();
};


#endif //DATABASEHANDLER_H