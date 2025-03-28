#include "working.h"
#include "items.h"

extern int customer_number;
extern long double Company_Money;
extern int total_orders;

void working(vector<Customer> &customers, vector<Type> &types){
    cout << "\n\n              Welcome to TSH shopping center!!!\n" << endl
         << "                   What is your Login Type?" << endl
         << "                     1. Customer" << endl
         << "                     2. Head Office" << endl
         << "                     3. Admin" << endl
         << "                     4. Vendor" << endl
         << "                     5. Exit" << endl;

    int welcome_choice;
    cout << "\n              Please enter your choice: ";
    cin >> welcome_choice;

    while (cin.fail() || welcome_choice < 1 || welcome_choice > 5)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"                          ~~~ ERROR ~~~"<<endl;
        cout << "                  Invalid input. Please enter a number between 1 and 5 : ";
        cin >> welcome_choice;
    }

    switch (welcome_choice)
    {
    case 1:
        clear();
        customer_working(customers, types);
        break;
    case 2:
        head_office_working(customers, types);
        break;
    case 3:
        admin_working(customers, types);
        break;
    case 4:
        clear();
        vendor_working(types, customers);
        break;
    case 5:
        clear();
        cout << "~~~~~~~~ Thank you for visiting TSH shopping center! ~~~~~~~~" << endl;
        break;
    }
}
void admin_working(vector<Customer> &customers , vector<Type> &types){
    /*will add filing after working*/
    clear();
    again:
    cout<<"\n                        <- ADMIN ->"<<endl<<endl;
    int choice = admin_options_writing();
    switch(choice){
        case 1:
            clear();
            display_types(types);
            cout<<"These are current items avalible "<<endl;
            system("pause");
            clear();
            goto again;
           break;
        case 2:
            clear();
            showing_customers(customers);
            system("pause");
            clear();
            goto again;
           break;
        case 3:
            clear();
            formatVendors();
            clear();
            goto again;
           break;
        case 4:
            clear();
            cout<<"Current Money Company Have : "<<Company_Money<<endl;
            system("pause");
            clear();
            goto again;
           break;
        case 5:
            clear();
            cout<<"Total Order Company Placed : "<<total_orders<<endl;
            system("pause");
            clear();
            goto again;
           break;
        default:
            clear();
            return working(customers,types);
    }
    
}
void formatVendors() {
    ifstream file("vendors.txt");
    if (!file.is_open()) {
        cerr << "Unable to open file: VENDORS " << endl;
        return;
    }

    string line;
    cout<<"\n\n                  <- VENDORS WORKED HERE ->"<<endl;
    cout<<"                  NAME | PHONE NUMBER | EMAIL | CREDIT CARD "<<endl;
    while (getline(file, line)) {
        for (char& ch : line) {
            if (ch == ',') {
                ch = '|';
            }
        }
        cout <<"                   "<< line << endl;
    }

    file.close();
}

void showing_customers(const vector<Customer>&customers){
    cout<<"        NAME | ADDRESS | EMAIL | PASSWORD | TOTAL PRICE"<<endl;
    for(int i = 0; i <customers.size();i++){
        cout<<i+1<<". "<<customers[i].getName()<<" | "<<customers[i].getAddress()<<" | "<<customers[i].getEmail()<<" | "<<customers[i].getPassword()<<" | "<<customers[i].getTotalPrice()<<endl;
    }
}
int admin_options_writing(){
    cout<<"                  1.Show me current Inventory  "<<endl;
    cout<<"                  2.Show me details of customers "<<endl;
    cout<<"                  3.Show me details of Vendor who worked "<<endl;
    cout<<"                  4.Show me Current Company Money"<<endl;
    cout<<"                  5.Show me how many orders are placed"<<endl;
    cout<<"                  6.Log-Out"<<endl<<endl;
    cout<<"              Enter the option between 1 and 6 : ";
    int choice ;cin>>choice;
    while (cin.fail() || choice < 1 || choice > 6){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"                          ~~~ ERROR ~~~"<<endl;
        cout << "                  Invalid input. Please enter a number between 1 and 6 : ";
        cin >> choice;
    }
    return choice;
}
void head_office_working(vector<Customer> &customers , vector<Type> &types){
    clear();
    cout<<"            <- Head Office is Controlled by TALHA SAMI (only) -> "<<endl;
    cout<<"       Enter Password to Enter Office : ";
    string pass = "whereareugoing";
    string ask ;
    cin.ignore();
    getline(cin,ask);
    if(pass!=ask){
        return working(customers,types);
    }
    clear();
    cout<<"            <- Head Office is Controlled by TALHA SAMI (only) -> "<<endl;
    cout<<"                   - Current Progress of the Shopping portal -"<<endl;
    cout<<"                       ~ Total Company Money Present : "<<Company_Money<<" pkr ."<<endl;
    cout<<"                       ~ Total Order placed Till today : "<<total_orders<<" orders .\n\n";
    cout<<"          Do want to discuss something with Admin :  "<<endl;
    cout<<"             1. YES"<<endl;
    cout<<"             2. NO"<<endl;
    cout<<"             3. Do u want to leave?"<<endl;
    cout<<"         Enter Choice 1 or 2 or 3:";
    int what ;cin>>what;
    while(cin.fail() || (what!=2 and what!=1 and what!=3)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<"                          ~~~ ERROR ~~~"<<endl;
        cout << "                  Invalid input. Please enter a number between 1 and 3 : ";
        cin >> what;    
    }
    if(what==1){
        // This is what u'll ask from Manager
        again:
        cout<<"               <- What do u want to ask ->"<<endl;
        cout<<"                  1.Show me current Inventory  "<<endl;
        cout<<"                  2.Show me details of customers "<<endl;
        cout<<"                  3.Show me details of Vendor who worked "<<endl;
        cout<<"                  4.Can leave "<<endl<<endl;
        cout<<"              Enter the option between 1 and 4 : ";
        int choice ;cin>>choice;
        while (cin.fail() || choice < 1 || choice > 4){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"                          ~~~ ERROR ~~~"<<endl;
            cout << "                  Invalid input. Please enter a number between 1 and 4 : ";
            cin >> choice;
        }
        switch(choice){
            case 1:
                clear();
                display_types(types);
                cout<<"These are current items avalible "<<endl;
                system("pause");
                clear();
                goto again;
               break;
            case 2:
                clear();
                showing_customers(customers);
                system("pause");
                clear();
                goto again;
               break;
            case 3:
                clear();
                formatVendors();
                clear();
                goto again;
               break;
            case 4:
                system("pause");
                clear ();
                return head_office_working(customers,types);
        }    
        
    }else if (what==2){
        cout<<"                  ~~~Leaving the HEAD OFFICE~~~"<<endl;
    }
    system("pause");
    clear();
    return working(customers,types);
}

void vendor_working(vector<Type> &types, vector<Customer> &customers){
    cout<<"           <- Vendor Here ->"<<endl;
    cout<<"                     <- Enter your details for record -> "<<endl;
    cout<<"                     Enter your name: ";
    string name;    
    cin>>name;
    cout<<"                     Enter your phone number: ";
    string phone_number;   
    cin>>phone_number;
    cout<<"                     Enter your email: ";
    string email;
    cin>>email;
    while (!isValidEmail(email)) {
        cout <<"                          ~~~ ERROR ~~~"<<endl;
        cout << "            Invalid email. Please enter a valid email address: ";
        cin >> email;
    }
    cout<<"                     Enter your credit card number: ";
    string credit_card_number;
    cin>>credit_card_number;
    Vendor newVendor(name, phone_number, email, credit_card_number);
    cout<<"              Vendor record added successfully."<<endl;
    // Save new vendor to file
    ofstream outFile("vendors.txt", ios::app);
    if (outFile) {
        outFile << name << "," << phone_number << "," << email << "," << credit_card_number << endl;
        outFile.close();
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
    //--------------------------------------------------------------------------------
    int choice = vendor_work_selection();
    if(0){
        again:
        choice = vendor_work_selection();
    }
    while(choice != 3){
        switch(choice){
            case 1:{
                clear();
                adding_new_item_in_file(types);
                break;
            }
            case 2:{
                clear();
                cout<<"             Enter the category you want to update item in: "<<endl;
                types_catigories(types);
                int category_choice;
                cout<<"           Enter your choice: ";
                cin>>category_choice;
                while(cin.fail() || category_choice < 1 || category_choice > 10){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"           Invalid input. Please enter a number between 1 and 10."<<endl;
                    cin>>category_choice;
                }
                clear();
                cout<<"           Enter the item number you want to update: ";
                int item_choice;
                cin>>item_choice;
                while(cin.fail() || item_choice < 1 || item_choice > types[category_choice-1].item_list.size()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"           Invalid input. Please enter a number between 1 and "<<types[category_choice-1].item_list.size()<<"."<<endl;
                    cin>>item_choice;
                }
                clear();
                
                cout<<"          What would you like to update?"<<endl;
                cout<<"           1. Name"<<endl;
                cout<<"           2. Price"<<endl;
                cout<<"           3. Quantity"<<endl;
                cout<<"           4. Go Back"<<endl;
                cout<<"           -> Enter your choice: ";
                int update_choice;
                cin>>update_choice;
                while(cin.fail() || update_choice < 1 || update_choice > 4){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"           Invalid input. Please enter a number between 1 and 4."<<endl;
                    cin>>update_choice;
                }
                switch(update_choice){
                    case 1:{
                        cout<<"           Enter the new name: ";
                        string item_name;
                        getline(cin>>ws, item_name);
                        types[category_choice-1].item_list[item_choice-1].set_item_name(item_name);
                        cout<<"           Item name updated successfully."<<endl;
                        adding_to_file(types);
                        break;
                    }
                    case 2:{
                        cout<<"           Enter the new price: ";
                        int item_price;
                        cin>>item_price;
                        types[category_choice-1].item_list[item_choice-1].set_item_price(item_price);
                        cout<<"           Item price updated successfully."<<endl;
                        adding_to_file(types);
                        break;
                    }
                    case 3:{
                        cout<<"           Enter the new quantity: ";
                        int item_quantity;
                        cin>>item_quantity;
                        types[category_choice-1].item_list[item_choice-1].set_item_quantity(item_quantity);
                        cout<<"           Item quantity updated successfully."<<endl;
                        adding_to_file(types);
                        break;
                    }
                    case 4:{
                        
                        break;
                    }
                }
                cout<<"           Item updated successfully."<<endl;
                adding_to_file(types);
                break;
            }
        }
        choice = vendor_work_selection();
    }
    system("pause");
    clear();
    return working(customers,types);
}

void adding_new_item_in_file(vector<Type> &types){
    cout<<"           Enter the category you want to add item in: "<<endl;
    types_catigories(types);
    int category_choice;
    cout<<"           Enter your choice: ";
    cin>>category_choice;
    while(cin.fail() || category_choice < 1 || category_choice > 10){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"           Invalid input. Please enter a number between 1 and 10."<<endl;
        cin>>category_choice;
    }
    
    cout<<"           Enter the name of the item: ";
    string item_name;
    getline(cin>>ws, item_name);
    cout<<"           Enter the price of the item: ";
    int item_price;
    cin>>item_price;
    cout<<"           Enter the quantity of the item: ";
    int item_quantity;
    cin>>item_quantity;
    Item temp(item_name, item_price, item_quantity);
    types[category_choice-1].item_list.push_back(temp);
    cout<<"           Item added successfully."<<endl;
    adding_to_file(types);
}
void adding_to_file(vector<Type>&types){
    ofstream outFile("categories.txt");
    if (!outFile) {
        cerr << "Error: Could not open categories.txt for writing.\n";
        return;
    }
    for (const Type &type : types) {
        outFile << "$" << type.get_type_name() << endl;
        for (const Item &item : type.item_list) {
            outFile << item.get_item_name() << "," << item.get_item_price() << "," << item.get_item_quantity() << endl;
        }
    }
    outFile.close();

}
int vendor_work_selection(){
    cout<<"           <- What would you like to do? ->"<<endl;
    cout<<"           1. Add new item"<<endl;
    cout<<"           2. Update item"<<endl;
    cout<<"           3. Exit"<<endl;
    int vendor_choice;
    cout<<"           Enter your choice: ";
    cin>>vendor_choice;
    while(cin.fail() || vendor_choice < 1 || vendor_choice > 4){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"           Invalid input. Please enter a number between 1 and 4."<<endl;
        cin>>vendor_choice;
    }
    return vendor_choice;
}
Vendor::Vendor(string name, string phone, string email, string card)
    : name(name), phone_number(phone), email(email), credit_card_number(card) {}
string Vendor::getName() const { return name; }
string Vendor::getEmail() const { return email; }
string Vendor::getPhoneNumber() const { return phone_number; }
string Vendor::getCreditCardNumber() const { return credit_card_number; }
void Vendor::setName(string name) { this->name = name; }
void Vendor::setPhoneNumber(string phone) { this->phone_number = phone; }
void Vendor::setEmail(string email) { this->email = email; }
void Vendor::setCreditCardNumber(string card) { this->credit_card_number = card; }
    // Function to handle customer login/registration
void customer_working(vector<Customer> &customers , vector<Type> &types) {
    cout << "Are you a registered customer?" << endl
    << "1. Yes" << endl
    << "2. No" << endl
    << "3. Exit" << endl;
    
    int customer_choice;
    cout << "Enter your choice: ";
    cin >> customer_choice;
    
    while (cin.fail() || customer_choice < 1 || customer_choice > 3) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number between 1 and 3.: " ;
        cin >> customer_choice;
    }
    if (customer_choice == 3) return working(customers,types);
    clear();
    if (!registering(customers, customer_choice)) {
        return customer_working(customers,types);
    }
    customer_options(customers,types);

}
void customer_options(vector<Customer> &customers , vector<Type> &types) {
    customer_view();
    int operation;
    cout<<"Enter your choice: ";
    cin>>operation;
    while(cin.fail() || operation < 1 || operation > 5){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid input. Please enter a number between 1 and 5."<<endl;
        cin>>operation;
    }
    switch(operation){
        case 1:{
            placing_order(types,customers);
            break;
        }
        case 2:{
            clear();
            customers[customer_number].displayCart();
            cout<<"Total Bill : "<<customers[customer_number].getTotalPrice()<<endl;
            system("pause");
            clear();
            return customer_options(customers,types);
            break;
        }
        case 3:{
            clear();
            customers[customer_number].removeFromCart(types);
            system("pause");
            clear();
            return customer_options(customers,types);
            break;
        }
            break;
        case 4:{
            clear();
            payment_options(customers);
            system("pause");
            clear();
            return customer_options(customers,types);
        }
        break;
        case 5:{
            clear();
            cout<<"Thank you for visiting TSH shopping center!"<<endl;
            system("pause");
            clear();
            return working(customers,types);
        }
    }
}
void Customer:: displayCart(){
    if(cart.size() == 0){
        cout<<"Your cart is empty."<<endl;
        return;
    }
    cout<<"Your cart contains: "<<endl;
    for(int i = 0; i < cart.size(); i++){
        cout<<i+1<<" ~ "<<cart[i].get_item_name()<<" - "<<cart[i].get_item_price()<<" pkr - "<<cart[i].get_item_quantity()<<endl;
    }
}
long int Customer::getTotalPrice() const {
    return total_price;
}
void Customer::set_total_price(long int price){
    total_price += price;
}
void placing_order(vector<Type> &types,vector<Customer>&customers){
    clear();
    cout<<"Press 0 to go back to main menu."<<endl;
    types_catigories(types);
    int choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    while(cin.fail() || choice < 0 || choice > 10){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid input. Please enter a number between 1 and 10."<<endl;
        cin>>choice;
    }
    
    clear();

    if(choice == 0){
        return customer_options(customers,types);
    }
    
    cout<<"Category -> "<<types[choice-1].get_type_name();
    types[choice-1].display_items();
    int item_choice;
    cout<<"Press 0 to go back to main menu."<<endl;
    cout<<"Enter the item number you want to add to cart: ";
    cin>>item_choice;
    if(item_choice == 0){
        return placing_order(types,customers);
    }
    while(cin.fail() || item_choice < 1 || item_choice > types[choice-1].item_list.size()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid input. Please enter a number between 1 and "<<types[choice-1].item_list.size()<<"."<<endl;
        cin>>item_choice;
    }
    int quantity;
    cout<<"Enter the quantity you want to add: ";
    cin>>quantity;
    if(!quantity_check(types,item_choice, choice, quantity)){
        return placing_order(types,customers);
    };
    price_of_item(types, item_choice, choice, quantity);
    add_to_cart_confirmation(types,customers,item_choice, choice, quantity);
    
}
// Function to ask for confirmation to add to cart
void add_to_cart_confirmation(vector<Type> &types,vector<Customer>&customers,int item_choice, int choice, int quantity) {
    cout << "Would you like to add " << quantity << " " << types[choice-1].item_list[item_choice-1].get_item_name() << " to your cart?" << endl
    << "1. Yes" << endl
    << "2. No" << endl;
    int confirm;
    cout << "Enter your choice: ";
    cin >> confirm;
    while (cin.fail() || confirm < 1 || confirm > 2) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number between 1 and 2." << endl;
        cin >> confirm;
    }
    if (confirm == 1) {
        cout << "Item added to cart." << endl;
        types[choice-1].item_list[item_choice-1].reduce_quantity(quantity);
        customers[customer_number].addToCart( quantity, types, choice, item_choice);
        customers[customer_number].set_total_price(types[choice-1].item_list[item_choice-1].get_item_price()*quantity);
        system("pause");
        return placing_order(types,customers);
    } else {
        cout << "Item not added to cart." << endl;
        
        return placing_order(types,customers);

    }
}
void price_of_item(vector<Type> &types, int item_choice, int choice, int quantity){
    int price = types[choice-1].item_list[item_choice-1].get_item_price();
    clear();
    cout<<"Total price of "<<quantity<<" "<<types[choice-1].item_list[item_choice-1].get_item_name()<<" is "<<price*quantity<<endl;
}
bool quantity_check(vector<Type>&types, int item_choice ,int choice,int quantity){
    
    while(cin.fail() || quantity < 1){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid input. Please enter a number greater than 0."<<endl;
        cin>>quantity;
    }
    if(!isQuantityAvailable(types[choice-1], item_choice-1, quantity)){
        cout<<"Sorry, the requested quantity is not available."<<endl;
        system("pause");
        return false;
    }
    return true;
}
// Function to check if the requested quantity is available
bool isQuantityAvailable(const Type &type, int item_index, int requested_quantity) {
    if (item_index < 0 || item_index >= type.item_list.size()) {
        return false;
    }
    return type.item_list[item_index].get_item_quantity() >= requested_quantity;
}
// Function to display customer options
void customer_view() {
    cout << "         What would you like to do?" << endl
    << "              1. Place an order" << endl
    << "              2. Display cart items" << endl
    << "              3. Remove an item from cart" << endl
    << "              4. Confirm payment" << endl
    << "              5. Checkout " << endl;
}
void Customer::removeFromCart(vector<Type> &types) {
    if (cart.empty()) {
        cout << "Your cart is empty." << endl;
        return;
    }
    
    displayCart();
    int item_index;
    cout << "Enter the item number you want to remove: ";
    cin >> item_index;
    
    while (cin.fail() || item_index < 1 || item_index > cart.size()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number between 1 and " << cart.size() << "." << endl;
        cin >> item_index;
    }

    item_index--; // Adjust for zero-based index
    int quantity;
    cout << "Enter the quantity you want to remove: ";
    cin >> quantity;

    while (cin.fail() || quantity < 1 || quantity > cart[item_index].get_item_quantity()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number between 1 and " << cart[item_index].get_item_quantity() << "." << endl;
        cin >> quantity;
    }

    cart[item_index].reduce_quantity(quantity);
    if (cart[item_index].get_item_quantity() == 0) {
        cart.erase(cart.begin() + item_index);
    }

    types[customer_number].item_list[item_index].reduce_quantity(-quantity);
    set_total_price(-cart[item_index].get_item_price() * quantity);
    cout << "Item removed from cart." << endl;
}

// Constructor Implementation
Customer::Customer(string name, string address, string phone, string email, string password, string card)
    : name(name), address(address), phone_number(phone), email(email), password(password), credit_card_number(card) {}
// Getter functions
string Customer::getName() const { return name; }
string Customer::getEmail() const { return email; }
string Customer::getPassword() const { return password; }
string Customer::getAddress() const { return address; }
string Customer::getPhoneNumber() const { return phone_number; }

// Setter functions
void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }
void Customer::setPhoneNumber(string phone) { this->phone_number = phone; }
void Customer::setEmail(string email) { this->email = email; }
void Customer:: addToCart(int quantity, vector<Type> &types,int choice , int item_choice){
    Item temp(types[choice-1].item_list[item_choice-1].get_item_name(), types[choice-1].item_list[item_choice-1].get_item_price()*quantity, quantity);
    cart.push_back(temp);
}

// Save customer data to file
void Customer::saveToFile(ofstream &outFile) const {
    outFile << name << "," << address << "," << phone_number << "," << email << "," << password << "," << credit_card_number << endl;
}

// Load customers from file
vector<Customer> Customer::loadFromFile() {
    vector<Customer> customers;
    ifstream inFile("customers.txt");

    if (!inFile) {
        cout << "No existing customer data found." << endl;
        return customers;
    }

    string name, address, phone, email, password, credit_card_number;
    while (getline(inFile, name, ',') &&
           getline(inFile, address, ',') &&
           getline(inFile, phone, ',') &&
           getline(inFile, email, ',') &&
           getline(inFile, password, ',') &&
           getline(inFile, credit_card_number)) {
        customers.emplace_back(name, address, phone, email, password, credit_card_number);
    }
    inFile.close();
    return customers;
}
// Function to register a new customer or log in
bool registering(vector<Customer> &customers, int &customer_choice) {
    if (customer_choice == 1) {
        cout << "Please enter your email: ";
        string email;
        cin >> email;
        cout << "Please enter your password: ";
        string password;
        cin >> password;

        customers = Customer::loadFromFile(); // Load customers from file

        auto it = find_if(customers.begin(), customers.end(), [email, password](const Customer &c) {
            return c.getEmail() == email && c.getPassword() == password;
        });

        if (it == customers.end()) {
            cout << "Invalid email or password. Please try again." << endl;
            return false;
        }
        customer_number = distance(customers.begin(), it);
        clear();
        cout << "Welcome back, " << it->getName() << "!" << endl;
        return true;
    } else if (customer_choice == 2) {
        cout << "Please enter your name: ";
        string name;
        cin >> name;
        cout << "Please enter your address: ";
        string address;
        cin >> address;
        cout << "Please enter your phone number: ";
        string phone_number;
        cin >> phone_number;
        cout << "Please enter your email: ";
        string email;
        cin >> email;

        while (!isValidEmail(email)) {
            cout << "Invalid email. Please enter a valid email address: ";
            cin >> email;
        }

        string password;
        cout << "Please enter your password (8 characters): ";
        cin >> password;

        while (!isValidPassword(password)) {
            cout << "Invalid password length. Please enter an 8-character password: ";
            cin >> password;
        }

        cout << "Please enter your credit card number: ";
        string credit_card_number;
        cin >> credit_card_number;

        Customer newCustomer(name, address, phone_number, email, password, credit_card_number);
        customers.push_back(newCustomer);

        // Save new customer to file
        ofstream outFile("customers.txt", ios::app);
        if (outFile) {
            newCustomer.saveToFile(outFile);
            outFile.close();
        }
        cout << "Welcome, " << newCustomer.getName() << "!" << endl;
        return true;
    }
    return false;
}
void payment_options(vector<Customer>&customers){
    cout<<"Payment options: "<<endl
        <<"1. Credit Card"<<endl
        <<"2. Cash on Delivery"<<endl;
    int payment_choice;
    cout<<"Enter your choice: ";
    cin>>payment_choice;
    while(cin.fail() || payment_choice < 1 || payment_choice > 2){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid input. Please enter a number between 1 and 2."<<endl;
        cin>>payment_choice;
    }
    if(payment_choice == 1){
        customers[customer_number].online_checking();
    }
    else{
        cout<<"Total Bill : "<<customers[customer_number].getTotalPrice()<<endl;
        Company_Money += customers[customer_number].getTotalPrice();
        cout<<"Payment successful. Please pay the delivery person."<<endl;
        total_orders++;
        customers[customer_number].set_total_price(0);
        customers[customer_number].clear_cart();
    }
}
void Customer:: online_checking(){
    cout<<"Total Bill : "<<total_price<<endl;
    cout<<"Enter Credit Card Number: ";
    string card_number;
    cin>>card_number;
    cout<<"Enter password: ";
    string password;
    cin>>password;
    cout<<"Enter Address where you want to recieve : ";
    string address;
    cin>>address;
    cout<<"Enter Phone Number which would be working at delivery time: ";
    string phone_number;
    cin>>phone_number;
    if(card_number == credit_card_number && password == this->password){
        cout<<"Payment successful. Your order will be delivered to "<<address<<" within 3 days."<<endl;
        Company_Money += total_price;
        total_price = 0;
        total_orders++;
        clear_cart();
    }
    else{
        cout<<"Invalid credit card number or password."<<endl;
        cout<<"Payment failed. Please try again."<<endl;
    }
}
void Customer::clear_cart(){
    cart.clear();
}
// Function to clear the screen
void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
// Function to validate email format
bool isValidEmail(const string &email) {
    int at_pos = email.find('@');
    int dot_pos = email.find('.', at_pos);
    return (at_pos != string::npos && dot_pos != string::npos && at_pos > 0 && dot_pos < email.length() - 1);
}
// Function to validate password format
bool isValidPassword(const string &password) {
    return password.length() == 8;
}
void startup() {
    cout<<"\n\n\n\n\n\n";
    setTextColor(9);
    cout<<setw(30) << " " <<"__________________   ____________                 "<< endl;
    cout<<setw(30) << " " <<"         |          |               |            |"<< endl;
    cout<<setw(30) << " " <<"         |          |               |            |"<< endl;
    cout<<setw(30) << " " <<"         |          |___________    |____________|"<< endl;
    cout<<setw(30) << " " <<"         |                      |   |            |"<< endl;
    cout<<setw(30) << " " <<"         |                      |   |            |"<< endl;
    cout<<setw(30) << " " <<"         |          ____________|   |            |"<< endl;
    cout<<"\n\n\n";
    setTextColor(4);
    cout<<setw(30) << " " <<"               Online Shopping Portal             "<< endl;
    cout<<"\n\n\n\n\n\n";
    setTextColor(7);
    system("pause");
    system("cls");
}

void setTextColor(int textColor){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Preserve the existing background color
    int currentBgColor = (csbi.wAttributes & 0xF0);

    SetConsoleTextAttribute(hConsole, currentBgColor | textColor);
}
