#include <bits/stdc++.h> 
#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/resource.h>
#include "Inventory.cpp"
using namespace std; 

int main()
{
    string filename; // for file to be read and write
    string input; // string to be input by user
    int num; // number 
    int option; // option for menu
    // Doing a bouns point
    cout <<"Please enter the data file name: ";
    cin >> filename;
    Inventory inventory;
    inventory.read_inventory_data(filename);
    
    while(true){
        cout << "\nWelcome to our Awesome Inventory Program (TM)\n";
        cout << "What would you like to do:\n";
        cout << "1. Check a single item.\n2. Print entire inventory.\n3. Restock an item.\n4. Sell an item.\n0. Save and Exit."<<endl;
        cout <<"Please enter your choice: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int index;
        if(option == 0){
            inventory.store_inventory_data();
            break;
        }
        else if (option == 1){
            /* code */
            cout << "Enter item to check information:";
            getline(cin,input);
            // checking for details
            index = inventory.find_index(input);    
            inventory.print_inventory_info(index);

        }
        else if (option == 2){
            /* code */
            // checking for entire inventory
            cout << "\n";
            inventory.print_inventory_info();
            cout << "\n";
         
        }
        else if (option == 3){
            // Restocking an item => increasing quantity of some item
            cout << "Enter item to restock:";
            getline(cin,input);
            cout <<"Enter quantity: ";
            cin >> num;
            index = inventory.find_index(input);
            inventory.order_item(index,num);
            cout << "Order successfully placed:"<< endl;
            inventory.print_inventory_info(index);
        }
        else if (option == 4){
                        // Selling an item
            cout << "Enter item to sell:";
            getline(cin,input);
            cout <<"Enter quantity: ";
            cin >> num;
            index = inventory.find_index(input);
            inventory.sell_item(index,num);

        }
        else{
            cout << "Enter a valid Input..\n";
        }
        
    }
}
