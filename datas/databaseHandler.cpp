#include "databaseHandler.h"
#include <iostream>
//#include <sstream>

DatabaseHandler::DatabaseHandler(const std::string & dbPath):DBPath(dbPath),db(nullptr){
    int rc =sqlite3_open(dbPath.c_str(),&db);
    if(rc!=SQLITE_OK){
        std::string errMsg="Can't open database:"+std::string(sqlite3_errmsg(db));
        sqlite3_close(db);
        throw std::runtime_error(errMsg);
    }

}

DatabaseHandler::~DatabaseHandler(){
    if(db){
        sqlite3_close(db);
    }
}

bool DatabaseHandler::backupDatabse(const std::string & backupPath){

    sqlite3 *backupDb;
    if(sqlite3_open(backupPath.c_str(),& backupDb)){
        return false;
    };

    sqlite3_backup * backup=sqlite3_backup_init(backupDb,"main",db,"main");
    if(!backup){
         sqlite3_close(backupDb);
         return  false;
    }
    
      int rc=  sqlite3_backup_step(backup,-1);

      int finish_rc=sqlite3_backup_finish(backup);

      sqlite3_close(backupDb);

      return (rc ==SQLITE_DONE)&&(finish_rc==SQLITE_OK);

   
}

void DatabaseHandler::executeSQL(const std::string & sql){
    char * errMsg=nullptr;
    if(sqlite3_exec(db,sql.c_str(),nullptr,nullptr,&errMsg)!=SQLITE_OK){
        std::string error=errMsg;
        sqlite3_free(errMsg);
        throw std::runtime_error("SQL error:"+error);

    }
};