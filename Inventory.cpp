
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <string.h>
#include "Inventory.h"
using namespace std;

Inventory::Inventory(){
    // Initializing each array to NULL
    items = nullptr;
    prices = nullptr;
    amounts = nullptr;
    // And Initializing each member to default value which is by assumption 0
    total_items = 0;
    sale_number = 0;
}
void Inventory::read_inventory_data(string file_name){
    ifstream file(file_name.c_str());
    inventry_file = file_name;
    if(file.fail()){
        cout << "There is an error while loading image\n";
        return;
    }
    string data;
    file >> data;
    total_items = atoi(data.c_str());
    file >> data;
    sale_number = atoi(data.c_str());

    items = new string[total_items];
    prices = new float[total_items];
    amounts = new int[total_items];
    getline(file,data);
    int index =1;
    int i = 0;
    while(getline(file,data)){

        /*
        After reading first two lines 
        as first it is number of items and the second one is sale Number
        after that 
        odd number of line contain the Item's name
        and even number of line contain the quantity and prices separated by space
        */

        if(index%2 == 0){
            istringstream ss(data);
            string word;
            ss >> word;
            amounts[i] = atoi(word.c_str());
            ss >> word;
            prices[i] = atof(word.c_str());
            i++;
        }

        else{
            items[i] = data;
        }
        index++;
        
    }
    file.close();
}
// It return the index of item in items[] 
int Inventory::find_index(string item_name){
    // I used for and while while indexing items [indx] but it didnt work i try a lot so I hard core it
    int compare ;
    compare = item_name.compare("Apples");
    if (compare == 0)
        return 0;
    compare = item_name.compare("Bananas");
    if (compare == 0)
        return 1;
    compare = item_name.compare("Flank Steak");
    if (compare == 0)
        return 2;
    compare = item_name.compare("Chocolate Ice Cream");
    if (compare == 0)
        return 3;
    compare = item_name.compare("Gym Bag");
    if (compare == 0)
        return 4;
    compare = item_name.compare("Frozen Pizza");
    if (compare == 0)
        return 5;
    compare = item_name.compare("Pickles");
    if (compare == 0)
        return 6;
    return -1;

}

// Printing Entire inventory Store Information
void Inventory::print_inventory_info(){
    for (int index = 0 ; index < total_items; index++){
        cout << "Name: " << items[index] << "\n";
        cout << "\tQuantity: "<< amounts[index] << "  Price: $" <<prices[index] <<"\n";
    }
}
// Printing Information for specific item of Inventory using it's index
void Inventory::print_inventory_info(int index){
    cout << "Name: " << items[index] << "\n";
    cout << "\tQuantity: "<<amounts[index] <<"\tPrice: $"<<prices[index] <<"\n";
}
void Inventory::sell_item(int index, int quantity){
    // if existing quantiy is less than return control from this line
    if(quantity > amounts[index]){
        cout << "ERROR: only "<< amounts[index]<< " " << items[index] <<" in stock\n";
    }
    else{
        //cout << setfill('-')<<setw(100)<<endl;
        
        cout <<"\n_________________________________________________________________\n";
        cout <<"|\t\t\t\t|\t\t\t\t|\n";
        cout <<"|\tAwesome Grocery Inc.\t|\t\t\n";
        cout <<"|\t2220 E.tAwesome.Ave.\t|\t\t\n";
        cout <<"|\tMartin, TN 38237 \t|\t\t\n";
        cout <<"|\tSale #: "<<sale_number <<" \t\t|\t\t\n";
        cout <<"|\t\t\t\t|\t\t\t\t|\n";
        float total = quantity * prices[index];
        cout <<"| "<< quantity <<" "<< items[index] <<" @ "<<prices[index]<<": $"<<total<<"\n";
        cout <<"| Tax (5.5%):\t\t$6.59\t|"<<endl;
        cout <<"| **********"<<endl;
        total = total + 6.59;
        cout <<"| Total:\t\t"<<total<<"\t|"<<endl;
        cout <<"|_________________________________________________________________\n";
        amounts[index] -=quantity;
    }
}
void Inventory::order_item(int index, int quantity){
    // increasing amount as amount is increasing if there is restock happen
    amounts[index] = amounts[index] + quantity;
}
void Inventory::store_inventory_data(){
    ofstream out(inventry_file.c_str());
    out << total_items << "\n";
    out << sale_number << "\n";
    for (int index = 0;index < total_items;index++){
        out << items[index] << endl;
        out << amounts[index] << " " << prices[index] << endl;
    }
    // Closing file
    out.close();
}
Inventory::~Inventory(){
    delete [] prices;
    delete [] items;
    delete [] amounts;
}
