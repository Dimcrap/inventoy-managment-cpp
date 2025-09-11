#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>              //stringstream
#include <limits>
#include <datas\DatabaseHandler.h>

/*
1-Inventory tracking (stock levels, track product movements, and receive alerts for low stock)
2-Purchsasing (Ordering the right amount of raw materials or goods.)
#3-Product categorization

4-Supplier managment (facilitates vendor performance tracking, 
supplier information management, and communication between 
suppliersand businesses)
↑↑↑[infromations about the supply 
from supplier to seller and other purpuses accessing all the 
branches,sellers  inventory statment by the sells and best
seller statement . . .]

5-Collaborative inventory ( minimizes excess inventory and
reduces lead times.exp:fea websites that sales your products 
will reporting for your action)
↑↑↑↑→→→↑↑↑↑←←←←↑↑↑↑ [sellers branchs order managing ]

6-System integeration (track and coordinate inventory across 
multiple warehouse locations in real-time and synchronize 
this inventory data with their other systems.)

7-Forecasting system (method used to predict inventory levels
for a future time period)[it will push an forcast statement]
*/



                               //T-mobile  company branchs inventoty

void main_screen();
void item_tracking(DatabaseHandler& dbhandlerobj);
void purchasing_request();
void supplier_managing();
void branchs_report();
void seller_inventories();
void forecast_station();



void searchingitem(std::string itemfield);

    



int main(){

    DatabaseHandler db("datas/alldatas.db");
    
    // 1. This creates the database file if it doesn't exist
    if (sqlite3_open("datas/mydatabase.db", &db) != SQLITE_OK) {
        std::cerr << "Can't create database: " << sqlite3_errmsg(db) << std::endl;
    };
        return 1;
    main_screen(db);


};






void main_screen(DatabaseHandler &dbhandlerobject){

    int input;
    std::cout<<"\t\t\t\t\n\nwelcome to T-mobile inventory managment\n\n\n";
    std::cout<<"\t\t1.tracking inventry of items\n\t\t2.Purchsasing availble items\n\t\t3.Supplier managment\n\t\t.4.Collaborative inventory status\n\t\t5.System integeration\n\t\t6.Product Forecasting system \n";
    std::cin>>input;
    switch(input){
        
        case 1:
        item_tracking(dbhandlerobject);
        break;

        case 2:
        purchasing_request(dbhandlerobject);
        break;

        case 3:
        supplier_managing(dbhandlerobject);
        break;

        case 4:
        seller_inventories();
        break;

        case 5:
        branchs_report();
        break;

        case 6:
        break;
        forecast_station();

    };

}




void item_tracking(DatabaseHandler& dbhandlerobj) {

    std::vector<std::string> data;
    enum fields {
        smartphones=1,
        tablets,
        smartwatchs,
        accessories
    };

    int settlement;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"\n\t\t\t-item tracking-\nchoose fields:1-SmartPhones\n2-Tablets\n3-Smartwatchs\n4-Accessories\n";
    std::cin>>settlement;
   
    try{
        switch (settlement)
        {
        case smartphones:
            data = dbhandlerobj.getitembyfield("smartphone");
            break;
        case tablets:
            data = dbhandlerobj.getitembyfield("tablet");
            break;
        case smartwatchs:
            data = dbhandlerobj.getitembyfield("smartwatch");
            break;
        case accessories:
            data = dbhandlerobj.getitembyfield("accessorie");
            break;

        };
    }
    catch (std::exception & e) {
        std::cerr << "error accurred!" << e.what();
        main_screen();
    }
    //[ID ,count ,sellmotion ,alert]
    for (int i = 0; i < 4; i++) {
        switch (i)
        {
        case 0:
            std::cout << "items warehouse ID:\n" << data[0];
        case 1:
            std::cout << "items units:\n" << data[1];
        case 2:
            std::cout << "items selling movment:\n" << data[2] << std::endl;
        case 3:
            (data[3] == "NULL") ? std::cout << "item has no alert notification" : std::cout << "alert:" << data[3];

        }
    };
    main_screen();


};




void purchasing_request(DatabaseHandler & dbhandlerobj){
   
    int field;
    int request;
    std::cout << "\n\n\t\t\tordering product\n\n"<<
    "1-smartphones    2-tablets\n3-smartwatchs\   4- accessoriesenter \n requestfield:";
    std::cin >> field;
    while (!std::cin||field<1||field>4) {
        std::cerr << "\nunvalid input\n";
        std::cin.clear(), std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "1-smartphones    2-tablets\n3-smartwatchs    4- accessories  \nenter requestfield:";
        std::cin >> field;
    };
    std::cout << "write down the request quantity:";
    std::cin>> request;
    //need input validatioin
    bool result;
    switch (field)
    {
    case 1:
     result= dbhandlerobj.addrequest("smartphones",request);
     break;
    case 2:
        result = dbhandlerobj.addrequest("tablets", request);
        break;
    case 3:
        result = dbhandlerobj.addrequest("smartwatchs", request);
        break;
    case 4:
        result = dbhandlerobj.addrequest("accessories", request);
        break;
    default:
        std::cerr << "Error accurred!";
        main_screen();

    }

    if (result) {
        std::cout << "request added successfully\n";
        main_screen();
    }
    else {
        std::cerr << "\ngoing to mainscreen\n";
        main_screen();

    };


    
    
    
}


void branchs_report(){
    /*
   - updating report with a data
    */




};   


void supplier_managing(DatabaseHandler &dbclassobj){
    //mention that the smaertphones inventory must be recharged after 30%

    /*4 - Supplier managment(
       -facilitates vendor performance tracking,
       -supplier information management,
       -and communication between suppliers and businesses)
        ↑↑↑[infromations about the supply
        from supplier to seller and other purpuses accessing all the
        branches, sellers  inventory statment by the sells and
        *best seller statement . . .]*/
    std::vector<std::string>menu = {};
    int selection;
    std::string result,vendorid;

    std::cout << "please enter the vendor id:\n";
    getline(std::cin, vendorid);


    std::cout <<"\n1 - check vendor statement\n2 - check vendor informs\n3 - check selling movment \n";
    std::cin >> selection;
    while (!std::cin || selection < 1 || selection>4) {
        std::cout << "unvalid nput\n1-check vendor statement\n2-check vendor informs\n3-check selling movment \n ";
        std::cin >> selection;
    };
    try {
        if (selection == 1) {
            result = dbclassobj.getinfo("vendorstatement", vendorid);
        }
        if (selection == 2) {
            result = dbclassobj.getinfo("vendorsinforms", vendorid);
        };
        if (selection == 3) {
            result = dbclassobj.getinfo("sellmotioin", vendorid);
        };
        if (!result.empty())
            std::cout << "\ninfo:\n" << result << std::endl;
        main_screen();
    }
    catch(std::exception & e ){
        std::cerr << "\n\t\t\terror getting info!\n";
        main_screen();
    };




};




void seller_inventories(){


};


void forecast_station(){


};


//          ******       inner functions       *****

void searchingitem(std::string itemfield){



};


