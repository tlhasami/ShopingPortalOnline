#include "items.h"
#include "working.h"

extern int customer_number;
extern long double Company_Money;
extern int total_orders;

// Item class definitions
Item::Item(string name, int price, int quantity) {
    item_name = name;
    item_price = price;
    item_quantity = quantity;
}

void Item::set_item_name(string name) {
    item_name = name;
}

void Item::set_item_price(int price) {
    item_price = price;
}

void Item::set_item_quantity(int quantity) {
    item_quantity = quantity;
}

string Item::get_item_name() const {
    return item_name;
}

int Item::get_item_price() const{
    return item_price;
}

int Item::get_item_quantity() const{
    return item_quantity;
}

Type::Type(string name) {
    type_name = name;
}

string Type::get_type_name() const {  
    return type_name;
}

void Item::reduce_quantity(int quantity) {
    ifstream inFile("categories.txt");
    if (!inFile) {
        cerr << "Error: Could not open categories.txt\n";
        return;
    }

    vector<string> lines;
    string line;
    
    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();

    for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i].empty() || lines[i][0] == '$') {
            continue; // Skip empty lines and category headers
        }

        stringstream ss(lines[i]);
        string name;
        int price, qty;

        getline(ss, name, ',');
        if (ss >> price && ss.ignore() && ss >> qty) { // Check if it's an item line
            if (name == item_name) {

                qty = max(0, qty - quantity);  // Ensure non-negative quantity
                lines[i] = name + "," + to_string(price) + "," + to_string(qty);
                cout<<"line -> name "<< name + "," + to_string(price) + "," + to_string(qty);
                system("pause");
            }
        }
    }

    ofstream outFile("categories.txt");
    if (!outFile) {
        cerr << "Error: Could not open categories.txt for writing.\n";
        return;
    }

    for (const string& updatedLine : lines) {
        outFile << updatedLine << "\n";
        cout<<updatedLine<<"\n";
        system("pause");
    }
    outFile.close();

    item_quantity = max(0, item_quantity - quantity);
}
void Item::increase_quantity(int quantity) {
    ifstream inFile("categories.txt");
    if (!inFile) {
        cerr << "Error: Could not open categories.txt\n";
        return;
    }

    vector<string> lines;
    string line;
    
    while (getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();

    for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i].empty() || lines[i][0] == '$') {
            continue; // Skip empty lines and category headers
        }

        stringstream ss(lines[i]);
        string name;
        int price, qty;

        getline(ss, name, ',');
        if (ss >> price && ss.ignore() && ss >> qty) { // Check if it's an item line
            if (name == item_name) {
                qty = qty + quantity;  // Ensure non-negative quantity
                lines[i] = name + "," + to_string(price) + "," + to_string(qty);
                cout<<lines[i]<<endl;
            }
        }
    }

    ofstream outFile("categories.txt");
    if (!outFile) {
        cerr << "Error: Could not open categories.txt for writing.\n";
        return;
    }

    for (const string& updatedLine : lines) {
        outFile << updatedLine << "\n";
    }
    outFile.close();

    item_quantity = item_quantity + quantity;   
}

void Type::add_item(const Item& item) {
    item_list.push_back(item);
}

void Type::display_items() const {
    if (item_list.empty()) {
        cout << "  No items available in this category.\n";
        return;
    }
    
    cout<<"\n             Item Name | Price | Quantity\n";
    for (size_t i = 0; i < item_list.size(); i++) {
        cout <<"     "<< i+1 << " - " << item_list[i].get_item_name() 
             << " | Price: " << item_list[i].get_item_price() 
             << " | Quantity: " << item_list[i].get_item_quantity() 
             << endl;
    }
}


void category_load_from_file(vector<Type> &types) {
    ifstream inFile("categories.txt");
    if (!inFile) {
        cerr << "Error: Could not open categories.txt\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            if (line[0] == '$') {
                // New category found
                Type newType(line.substr(1)); // Remove '$' from category name
                types.push_back(newType);
            } else {
                // Process items under the current category
                stringstream ss(line);
                string name;
                int price, quantity;
                
                getline(ss, name, ',');  // Extract item name
                ss >> price;
                ss.ignore(); // Ignore comma
                ss >> quantity;
    
                if (!types.empty()) { // Ensure there's an active category
                    Item newItem(name, price, quantity);
                    types.back().add_item(newItem);
                }
            }
        }
    }
    inFile.close();
    //display_types(types);
}

void display_types(const vector<Type>& types) {
    if (types.empty()) {
        cout << "No categories available.\n";
        return;
    }

    cout << "Available Categories and Items:\n";
    for (size_t i = 0; i < types.size(); i++) {
        cout << "\n" << i + 1 << ". " << types[i].get_type_name() << ":\n";
        types[i].display_items(); // Call display_items to show the items
    }
}

void types_catigories(const vector<Type>& types) {
    if (types.empty()) {
        cout << "No categories available.\n";
        return;
    }
    cout << "Available Categories and Items:\n";
    for (size_t i = 0; i < types.size(); i++) {
        cout <<setw(2)<< i + 1 ;
        cout<< " -> " << types[i].get_type_name() << "\n";
    }
    
}

