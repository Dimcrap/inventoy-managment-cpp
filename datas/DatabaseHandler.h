#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <exception>
#include <cstring>

class DatabaseHandler{
public:
    DatabaseHandler(const std::string &dbPath);
    ~DatabaseHandler();   


    DatabaseHandler(const DatabaseHandler &)=delete;
    DatabaseHandler& operator=(const DatabaseHandler&)=delete;


    bool addrequest(const std::string Rfield, int quantity);
    std::vector <std::string> getitembyfield(std::string field);
    bool backupDatabse(const std::string& backupPath);
    std::string getinfo(std::string infopart, std::string vendorid);
    std::string DatabaseHandler::getwarehousinfo(std::string section);
    std::vector<std::string>getwarehouseinbranch(int brancnum);
    
private:
    sqlite3* db;
    std::string DBPath;
    
    void executeSQL(const std::string & sql);
    static int callback(void *data ,int argc,char ** argv,char ** azColName);
    

};


#endif //DATABASEHANDLER_H