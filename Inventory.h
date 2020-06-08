#include <string>
using namespace std;
class Inventory
{ 
    // Private Access Specifier
    private:
        string * items;
        float * prices;
        int * amounts;
        int total_items,sale_number;
        string inventry_file;
    // Public Access specifier 
    public: 
        Inventory(); //Constructor
        void read_inventory_data(string file_name);
        void print_inventory_info();
        void print_inventory_info(int index);
        void sell_item(int index, int quantiy);
        int find_index(string item_name);
        void order_item(int index, int quantity);
        void store_inventory_data();
        ~Inventory(); // Destructor
}; 