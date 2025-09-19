#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#pragma once
#include <string>
#include <vector>
#include <exception>    
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>             
#include <limits>


struct sqlite3;

class DatabaseHandler{
    private:
        sqlite3* db;
        std::string DBPath;
        
        void executeSQL(const std::string & sql);
        static int callback(void *data ,int argc,char ** argv,char ** azColName);
        
public:
    DatabaseHandler(const std::string &dbPath);
    ~DatabaseHandler();   


    DatabaseHandler(const DatabaseHandler &)=delete;
    DatabaseHandler& operator=(const DatabaseHandler&)=delete;


    bool addrequest(const std::string Rfield, std::string quantity);
    std::vector<std::vector <std::string>> getitembyfield(std::string field);
    bool backupDatabse(const std::string& backupPath);
    std::string getinfo(std::string infopart, std::string vendorid);
    std::vector <std::vector<std::string>> getwarehousinfo(std::string section);
    std::vector<std::string>getwarehouseinbranch(int brancnum);
    std::string getbranchinfo(int branchnum);
    std::vector <std::string> sellmotiongetter(int branch);
    


    //PRAGMA foreign_keys = ON;

};


#endif //DATABASEHANDLER_H