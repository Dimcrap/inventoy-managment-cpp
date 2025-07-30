#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>              //stringstream
#include <limits>


/*
1-Inventory tracking (stock levels, track product movements, and receive alerts for low stock)
2-Purchsasing (Ordering the right amount of raw materials or goods.)
#3-Product categorization

4-Supplier managment (facilitates vendor performance tracking, supplier information management, and communication between suppliers
 and businesses)
↑↑↑[infromations about the supply from supplier to seller and other purpuses
accessing all the branches,sellers  inventory statment by the sells and best seller statement . . .]

5-Collaborative inventory ( minimizes excess inventory and reduces lead times.exp:fea websites that sales your products will
 reporting for your action)
↑↑↑↑→→→↑↑↑↑←←←←↑↑↑↑ [sellers branchs order managing ]
6-System integeration (track and coordinate inventory across multiple warehouse locations in real-time and synchronize 
this inventory data with their other systems.)

7-Forecasting system (method used to predict inventory levels for a future time period)[it will push an forcast statement]
*/



                               //T-mobile  company branchs inventoty

void main_screen();
void item_tracking();
void purchasing_request();
void supplier_managing();
void branchs_report();
void seller_inventories();
void forecast_station();



void searchingitem(std::string itemfield);


/*
struct products{

};


struct warehouse{
    int racknum;
};
*/
    



int main(){

    main_screen();


};






void main_screen(){

    int input;
    std::cout<<"\t\t\t\t\n\nwelcome to T-mobile inventory managment\n\n\n";
    std::cout<<"\t\t1.tracking inventry of items\n\t\t2.Purchsasing availble items\n\t\t3.Supplier managment\n\t\t.4.Collaborative inventory status\n\t\t5.System integeration\n\t\t6.Product Forecasting system \n";
    std::cin>>input;
    switch(input){
        
        case 1:
        item_tracking();
        break;

        case 2:
        purchasing_request();
        break;

        case 3:
        supplier_managing();
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




void item_tracking(){

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
    switch (settlement)
    {
    case smartphones:
        searchingitem("smartphone");
        break;
    case tablets :
        searchingitem("tablet");
        break;
    case smartwatchs :
        searchingitem("smartwatch");
        break;
    case accessories :
        searchingitem("accessorie");
        break;

        default:  
        break;
    };



};




void purchasing_request(){
    
    int selection_input;
           /*for reading↓↓↓↓*/
    std::ifstream available_product("warehouse1.txt");
    if(!available_product){
        std::cout<<"unable to open directory!";
        main_screen();
    }
    
    
    std::cout<<"\t\t\t\t<<purchasing item page>>\n\t\tselect the product:\n";
    //show the items
    std::cin>>selection_input;
    //conditional respond
    
    
}


void branchs_report(){
    /*
   - updating report with a data
    */




};   


void supplier_managing(){


};




void seller_inventories(){


};


void forecast_station(){


};


//          ******       inner functions       *****

void searchingitem(std::string itemfield){};


