#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>              //stringstream
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

struct products{

};



struct warehouse{
    int racknum;
};
    



int main(){

    main_screen();


};





void main_screen(){

    int input;
    std::cout<<"\t\t\t\twelcome to T-mobile inventory managment\n";
    std::cout<<"\t\t1.tracking inventry of items\n\t\t2.Purchsasing availble items\n\t\t3.Supplier managment\n\t\t.4.Collaborative inventory status\n\t\t5.System integeration\n\t\t6.Product Forecasting system ";
    std::cin>>input;
    switch(input){
        case 1:
        item_tracking();
        
        case 2:
        purchasing_request();
        
        case 3:
        supplier_managing();
        
        case 4:
        seller_inventories();
        
        case 5:
        branchs_report();
        
        case 6:

        forecast_station();

    }

}

int main(){
    main_screen();
}


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
    //conditional reaction
    
    
}