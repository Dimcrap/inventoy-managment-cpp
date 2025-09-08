#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <sqlite3.h>
#include <string>
#include <vector>

class DatabaseHandler{
public:
    DatabaseHandler(const std::string &dbPath);
    ~DatabaseHandler();   


    DatabaseHandler(const DatabaseHandler &)=delete;
    DatabaseHandler& operator=(const DatabaseHandler&)=delete;

    bool addrequest(const std::string Rfield, int quantity);
    std::vector <std::string> getitembyfield(std::string field);
    bool backupDatabse(const std::string& backupPath);
    
    private:
    sqlite3* db;
    std::string DBPath;
    
    void executeSQL(const std::string & sql);
    static int callback(void *data ,int argc,char ** argv,char ** azColName);
    

};


#endif //DATABASEHANDLER_H