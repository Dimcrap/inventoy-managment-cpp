#include "databaseHandler.h"
#include <iostream>
#include <sstream>


DatabaseHandler::DatabaseHandler(const std::string & dbPath):DBPath(dbPath),db(nullptr){
    int rc =sqlite3_open(dbPath.c_str(),&db);
    if(rc!=SQLITE_OK){
        std::string errMsg="Can't open database:"+std::string(sqlite3_errmsg(db));
        sqlite3_close(db);
        throw std::runtime_error(errMsg);
    }

    rc = sqlite3_exec(db, "PRAGMA foreign_keys = ON;", NULL, NULL, NULL);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        throw std::runtime_error("Failed to enable foreign key support: " 
            + std::string(sqlite3_errmsg(m_db)));
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

    };

};

std::vector <std::string> DatabaseHandler::getitembyfield(std::string field) {
    std::vector<std::vector<std::string>> result;
    std::string sql = "SELECT Id,count,sellmotion,alert FROM products WHERE field = " + field+";";
   
    char* errmsg = nullptr;
    if (sqlite3_exec(db, c_str(), callback, &result , errmsg)!=SQLITE_OK) {
        std::string error = errmsg;
        sqlite3_free(errmsg);
        throw std::runtime_error("SQL error:" + error);
    }

    if (!result.empty()) {
        return result[0];
    }

    return {};

};

std::string DatabaseHandler::getinfo(std::string infopart,std::string vendorid) {
    std::vector<std::string> result;
    std::string sql="SELECT "+infopart+" FROM vendcare WHERE vendorid = "+vendorid+";";

    char* errmsg = nullptr;
    if (sqlite3_exec(db, c_str(), callback, &result, errmsg) != SQLITE_OK) {
        std::string error = errmsg;
        sqlite3_free(errmsg);
        throw std::runtime_error("SQL error:" + error);
    }
    if (!result.empty()) {
        return result[0];
    }


    return {};


};

std::string DatabaseHandler::getwarehousinfo(std::string section) {
    std::vector<std::string> result;
    std::string sql = "SELECT "+section+" FROM warehouse WHERE warehoustype = collaborative";
    char* errmsg;
    if (SQLITE_OK!=sqlite3_exec(db, sql.c_str(), callback, &result, errmsg)) {
        std::string error = errmsg;
        sqlite3_free(errmsg);
        throw std::runtime_error("SQL error:" + error);
    }

    if (!result.empty()) {
        return result[0];
    }

    return {};

};

bool DatabaseHandler::addrequest(const std::string Rfield, int quantity) {

    std::stringstream ss;
    ss << "INSERT INTO requests(requestfield,requestscontent)VALUES(" << Rfield << ";" << quantity << ");";
try {
    executeSQL(ss.str());
    return true;
}
catch(const std::exception & e){
    std::cerr << "Error adding request" << e.what() << std::endl;
    return false;
}

};

std::vector<std::string> DatabaseHandler::getwarehouseinbranch(int brancnum) {
    std::vector <std::vector<std::string >>warehouses;
    std::string sql = "SELECT warehouse.Id FROM warehouse"
        "JOIN branch ON warehouse.branch = branch.branchnum"
        "WHERE branch.branchnum = "+std::to_string(brancnum)+";";

    char* errmsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), callback, &warehouses, &errmsg) != SQLITE_OK) {
        std::string err = errmsg;
        sqlite3_free(errmsg);
        throw std::runtime_error("SQL error" + err);
    };

    if (!warehouses.empty()) {
        return warehouses[0];
    }
   
    return {};
};

std::string DatabaseHandler::getbranchinfo(int branchnum) {
    std::vector <std::string> result;
    std::string sql = "SELECT branchinform FROM branch"
        "WHERE branch.brnachnum="+std::to_string(branchnum)+";";

    
    char* errmsg;
    if (sqlite3_exec(db, sql.c_str(), callback, &result, &errmsg) != SQLITE_OK) {

        std::string err=errmsg;
        sqlite3_free(errmsg);
        throw std::runtime_error("SQL error:" + err);
        return {};
    };
    if (!result.empty()) {
        return result[0];
    };
    
    return {};
};

std::vector<std::string> alertgetter(branchnum)
std::vector <std::string> DatabaseHandler::sellmotiongetter(int branch) {
    std::vector<std::vector<std::string>> result;
    
    std::string sql = "SELECT sellmotion FROM products"
        "JOIN warehouse ON products.warehouseID=warehouse.Id"
        "JOIN branch ON warehouse.branch=branch.branchnum"
        "WHERE branch.branchnum = "+std::to_string(branch)+"; ";
    char* errmsg=nullptr;
    if (sqlite3_exec(db, sql.c_str(), callback, &result, errmsg) != SQLITE_OK) {
        std::string err = errmsg;
        sqlite3_free(errmsg);
        throw std::runtime_error("SQl error" + err);
    };

    if (!result.empty()) {
        return result[0];
    }
    
    return {};

};



int DatabaseHandler::callback(void *data ,int argc,char ** argv,char** azColName){
    auto* result = static_cast<std::vector<std::vector<std::string>>*>(data);
    std::vector<std::string> row;
    for (int i = 0; i < argc; i++) {
        row.emplace_back(argv[i] ? std::string(argv[i]) : "NULL");
    };

     result->push_back(row);
     return 0;
};

