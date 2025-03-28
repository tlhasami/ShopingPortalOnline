#ifndef WORKING_H
#define WORKING_H

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
#include <string>
#include <windows.h>
#include <conio.h>
#include "items.h"

using namespace std;

extern int customer_number;
extern long double Company_Money;
extern int total_orders;

class Vendor {
private:
    string name;
    string phone_number;
    string email;
    string credit_card_number;
    public:
    Vendor() = default; // Default constructor
    Vendor(string name, string phone, string email, string card);

    string getName() const;
    string getEmail() const;
    string getPhoneNumber() const;
    string getCreditCardNumber() const;

    void setName(string name);
    void setPhoneNumber(string phone);
    void setEmail(string email);
    void setCreditCardNumber(string card);
};

class Customer {
protected:
    string name;
    string address;
    string phone_number;
    string email;
    string password;
    string credit_card_number;
    long int total_price = 0;
    vector<Item>cart;
    public:
    Customer() = default; // Default constructor
    Customer(string name, string address, string phone, string email, string password, string card);

    long int getTotalPrice() const;
    string getName() const;
    string getEmail() const;
    string getPassword() const;
    string getAddress() const;
    string getPhoneNumber() const;

    void set_total_price(long int price);
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(string phone);
    void setEmail(string email);
    void addToCart( int quantity, vector<Type> &types,int choice , int item_choice);
    void displayCart();
    void removeFromCart(vector<Type> &types);
    void clear_cart();
    void online_checking();

    // File handling functions
    void saveToFile(ofstream &outFile) const;
    static vector<Customer> loadFromFile();
};

void formatVendors();
void showing_customers(const vector<Customer>&customers);
int admin_options_writing();
void admin_working(vector<Customer> &customers , vector<Type> &types);
int vendor_work_selection();
void head_office_working(vector<Customer> &customers , vector<Type> &types);
void vendor_working(vector<Type> &types,vector<Customer> &customers);
void customer_working(vector<Customer> &customers , vector<Type> &types);
bool registering(vector<Customer> &customers, int &customer_choice);
void clear();
bool isValidPassword(const string &password);
bool isValidEmail(const string &email);
void customer_view();
void placing_order(vector<Type> &types,vector<Customer>&customers);
bool isQuantityAvailable(const Type &type, int item_index, int requested_quantity);
bool quantity_check(vector<Type>&types, int item_choice ,int choice,int quantity);
void price_of_item(vector<Type> &types, int item_choice, int choice, int quantity);
void add_to_cart_confirmation(vector<Type> &types,vector<Customer>&customers,int item_choice, int choice, int quantity) ;
void working(vector<Customer> &customers, vector<Type> &types);
void placing_order(vector<Type> &types,vector<Customer>&customers);
void customer_options(vector<Customer> &customers , vector<Type> &types);
void startup();
void setTextColor(int textColor);
void payment_options(vector<Customer>&customers);
void adding_new_item_in_file(vector<Type> &types);
void adding_to_file(vector<Type>&types);

#endif
