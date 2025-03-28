#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

extern long double Company_Money;
extern int customer_number;
extern int total_orders;

class Item; // Forward declaration

class Type {
private:
    string type_name;
public:
    vector<Item> item_list;
    Type(string name);
    string get_type_name() const;  // Correct
    void add_item(const Item& item);
    void display_items() const;

};

class Item {
private:
    string item_name;
    int item_price;
    int item_quantity;

public:
    Item(string name, int price, int quantity);
    string get_item_name() const;
    int get_item_price() const;
    int get_item_quantity() const;
    void reduce_quantity(int quantity);
    void increase_quantity(int quantity);
    void set_item_name(string name);
    void set_item_price(int price);
    void set_item_quantity(int quantity);
};

void category_load_from_file(vector<Type> &types);
void display_types(const vector<Type>& types);
void types_catigories(const vector<Type>& types);


#endif // ITEMS_H
