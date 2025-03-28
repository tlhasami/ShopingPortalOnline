#include <iostream>
#include <vector>
#include "working.h"
#include "items.h"

using namespace std;

int customer_number = -1;
long double Company_Money = 100000;
int total_orders = 0 ;

int main()
{
    startup();
    vector<Type> types;
    category_load_from_file(types);                        // Load categories at start
    vector<Customer> customers = Customer::loadFromFile(); // Load customers at start
    working(customers, types);
}
