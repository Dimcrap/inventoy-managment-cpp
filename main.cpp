#include "datas\DatabaseHandler.h"
#include <memory>



                               //T-mobile  company branchs inventoty

void main_screen(DatabaseHandler& dbhandlerobj);
void item_tracking(DatabaseHandler& dbhandlerobj);
void purchasing_request(DatabaseHandler& dbhandlerobj);
void supplier_managing(DatabaseHandler& dbhandlerobj);
void seller_inventories(DatabaseHandler& dbhandlerobj);
void branchs_report(DatabaseHandler& dbhandlerobj);
void forecast_station(DatabaseHandler& dbhandlerobj);
int movementevaluator(std::vector <std::string> motions);







int main(){
 
 
 
 //std::unique_ptr<DatabaseHandler> db;
 
 try {
   auto db =std::make_unique<DatabaseHandler>("datas/alldatas.db");
   
   std::cout<<"|";
   main_screen(*db);
}
catch (std::exception& e) {
    
std::cout << "Database Error:" << e.what() << std::endl;
return 0;
};


    

    


};




/////////////////////////////////////////////////////



void main_screen(DatabaseHandler &dbhandlerobject){

    int input;
    std::cout<<"\n\n\t\t\t\twelcome to T-mobile inventory managment\n\n\n";
    std::cout<<"\t\t\t\t1.tracking inventry of items\n\t\t\t\t2.Purchsasing availble items"
    "\n\t\t\t\t3.Supplier managment\n\t\t\t\t4.Collaborative inventory status\n\t\t\t\t5.Branch managment"
    "\n\t\t\t\t6.Product Forecastion \n\n\n\t\t";
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
        seller_inventories(dbhandlerobject);
        break;

        case 5:
        branchs_report(dbhandlerobject);
        break;

        case 6:
        forecast_station(dbhandlerobject);
        break;


    };

}


void item_tracking(DatabaseHandler& dbhandlerobj) {

    std::vector<std::vector<std::string>> data;
    enum fields {
        smartphones=1,
        tablets,
        smartwatchs,
        accessories
    };

    int settlement;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"\n\t\t\t-item tracking-\nchoose fields:\n1-SmartPhones\n2-Tablets\n3-Smartwatchs\n4-Accessories\n";
    std::cin>>settlement;
   
    try{
        switch (settlement)
        {
        case smartphones:
            data = dbhandlerobj.getitembyfield("smartphones");
            break;
        case tablets:
            data = dbhandlerobj.getitembyfield("tablets");
            break;
        case smartwatchs:
            data = dbhandlerobj.getitembyfield("smartwatchs");
            break;
        case accessories:
            data = dbhandlerobj.getitembyfield("accessorie");
            break;

        };
    }
    catch (std::exception & e) {
        std::cerr << "error accurred!" << e.what();
        main_screen(dbhandlerobj);
    }
    //[ID ,count ,sellmotion ,alert]
    std::cout<<"========================================================================\n";

    for(int col=0;col<data.size();col++){

        for (int i = 0; i < 4; i++) {
            switch (i)
            {
                case 0:
                std::cout << "\nitems warehouse ID: " << data[col][i];
                break;
                case 1:
                std::cout << "\nitems units: " << data[col][i];
                break;
                case 2:
                std::cout << "\nitems selling movment: " <<
                data[col][i] ;
                break;
                case 3:
                (data[col][i] == "NULL") ? std::cout << "\nitem has no alert notification" : std::cout << "\nalert:" << data[col][i];
                break;
            };
        };
        std::cout<<"\n";
    }
    std::cout<<"\n========================================================================";

    main_screen(dbhandlerobj);


};


void purchasing_request(DatabaseHandler & dbhandlerobj){
   
    int field;
    std::string request;
    std::cout << "\n\n\t\t\tordering product\n\n"<<"1-smartphones    2-tablets\n3-smartwatchs   4- accessoriesenter \n requestfield:";
    std::cin >> field;
    while (!std::cin||field<1||field>4) {
        std::cerr << "\nunvalid input\n";
        std::cin.clear(), std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "1-smartphones    2-tablets\n3-smartwatchs    4- accessories  \nenter requestfield:";
        std::cin >> field;
    };
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "write down the request quantity with warehous id:";
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
        main_screen(dbhandlerobj);

    }

    if (result) {
        std::cout << "request added successfully\n";
        main_screen(dbhandlerobj);
    }
    else {
        std::cerr << "\ngoing to mainscreen\n";
        main_screen(dbhandlerobj);

    };


    
    
    
}


void branchs_report(DatabaseHandler& dbhandlerobj){
    int select;
    int branchnum;
    std::cout << "\n1-track branch warehouses\n2-check branch form\n3-main screen\n";
    std::cin >> select;
    while (!std::cin || select < 1 || select>3) {
        std::cout << "unvalid input !try again";
        std::cout << "\n1-track branch warehouses\n2-check branch form\n3-main screen\n";
        std::cin >> select;
    };
    
     if (select == 3) {
         main_screen(dbhandlerobj);
     };

    std::cout << "\nenter branch number:";
    std::cin >> branchnum;

    if (select == 1) {
        std::vector <std::string> warehouses;
        try {
            warehouses = dbhandlerobj.getwarehouseinbranch(branchnum);
        }
        catch (std::exception& e) {
            std::cerr << "error accurred " << e.what();
            main_screen(dbhandlerobj);
        }
        if(warehouses.empty()){
            std::cout<<"No branch detected!";
        };
        for (std::string warehouse : warehouses) {
            std::cout << warehouse << " ";
        }
        main_screen(dbhandlerobj);

    }
    else if (select == 2) {
        std::string inform;
        try {
            inform = dbhandlerobj.getbranchinfo(branchnum);
        }
        catch (std::exception& e) {
            std::cerr << "Error accurred!\n" << e.what();
        };
        if (inform.empty()) {
            std::cout << "\nno inform registred\n";
            main_screen(dbhandlerobj);
        }
        std::cout << std::endl << inform << std::endl;
        main_screen(dbhandlerobj);

    }



};   


void supplier_managing(DatabaseHandler &dbclassobj){
  
    std::vector<std::string>menu = {};
    int selection;
    std::string result,vendorid;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "please enter the vendor id:\n";
    getline(std::cin, vendorid);

while(selection!=4){
    std::cout <<"\n1 - check vendor statement\n2 -"
    " check vendor informs\n3 - check selling movment \n"
    "4 - Exit\n";
    std::cin >> selection;
    while (!std::cin || selection < 1 || selection>4) {
        std::cout << "unvalid nput\n1-check vendor statement"
        "\n2-check vendor informs\n3-check selling movment \n"
        "4 - Exit";
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
            result = dbclassobj.getinfo("sellmotion", vendorid);
        };
        if(selection==4){
            main_screen(dbclassobj);
        };
        if (!result.empty()){
            std::cout << "\n=====================\n" << result <<
             "\n=====================";
             }else if(result.empty()){
             std::cout<<"Error finding input";
             };
    }catch(std::exception & e ){
        std::cerr << "\n\t\t\terror getting info!\n"<<e.what();
        main_screen(dbclassobj);
    };

}
    main_screen(dbclassobj);

};

void seller_inventories(DatabaseHandler& dbhandlerobj) {
    int request;
    std::string info;
    std::cout << "1-get essential status\n2-get filled space amount\n";
    std::cin >> request;
    while (!std::cin || request > 2 || request < 1) {
        std::cout << "unvalid input try again1-get essential status"
        "\n2-get filled space amount\n";
            std::cin >> request;
    };
    
    try {

    if (request == 1) {
        std::vector <std::vector<std::string>> 
        result=dbhandlerobj.getwarehousinfo("warhouseinforms");
        for(int i=0;i<result.size();i++){

            if(result[i][1]=="NULL"){
                std::cout<<"\n no inform registred!";
                main_screen(dbhandlerobj);
            };
                std::cout << "\nID:\n" << result[i][0]<<
                "\ninforms:"<<result[i][1];
        };
        main_screen(dbhandlerobj);
    };
    if (request == 2) {
        std::vector <std::vector<std::string>>  
         result = dbhandlerobj.getwarehousinfo("filledspace");
        for(int i=0;i<result.size();i++){
         if (result[i][1] == "NULL") {
             std::cout << "demanded warehous is empty.";
             main_screen(dbhandlerobj);
        };
        std::cout <<"\n\nwarehouse ID"<<result[i][0]<<
         "\nwarehous stock level is %" << result[i][1] <<
          " filled";
        }
    }
    }
    catch (std::exception& e) {
        std::cout << "error accured!\n" << e.what();
        main_screen(dbhandlerobj);
    }
    
    //could apply some delay 
        std::cout << "\n\ngoing to the m5ain screen . . .\n";
        main_screen(dbhandlerobj);

};





void forecast_station(DatabaseHandler& dbhandlerobj){
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.clear();
    std::cout << "\n===forcastion\n"
        "press Enter to continue . . .";
    std::cin.get();
    int branch;
    std::cout << "\nenter branch number for its forcastion:\n";
    std::cin>>branch;
    std::string forcastinform;
    std::vector<std::string> sellmotions;


    try {
        sellmotions = dbhandlerobj.sellmotiongetter(branch);
    }catch (std::exception& e) {
        std::cerr << "error accurred!\n" << e.what();
        main_screen(dbhandlerobj)\
            ;
    };
    int process = movementevaluator(sellmotions);
    std::cout<<"\n====================================================";
    if (process < 0) {
        std::cout << "\nsell process is negetive \npossibilty of decreasing is high";
    }
    else if (process > 0) {
        std::cout << "\nsell movment is positive\npossibility of increasing is high";
    }
    else {
        std::cout << "\nits possible selling process to be stagnant ";
    };
    std::cout<<"\n====================================================";
    main_screen(dbhandlerobj);
};
int movementevaluator(std::vector <std::string> motions) {
    int result=0;

    for (std::string motion : motions) {
        result = (motion.find("+") != std::string::npos) ? result + 1
            : (motion.find("-") != std::string::npos) ? result - 2
            : result;
    }
    return result;

};



