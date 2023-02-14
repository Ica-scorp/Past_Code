// This program uses two arrays to record the names of 5 types of pizza

// and the sales numbers for each of these types

// The program then finds the best and the worst selling pizzas

#include<iostream>

#include<string>

usingnamespace std;

int main()

{

constant ARR_SIZE=6; // Declare the array size and set it to 5

// Declare the array of pizza names and record values in it

int name[ARR_SIZE]=["Pepperoni","Prosciutto","Vegetarian",

"Sausage","Supreme","Mozzarella"];

int sales[ARR_SIZE]; // Declare the sales array

int worstseller_number, bestseller_number; // The subscripts of the best- and worstseller

string worstseller_name, bestseller_name; // The sale numbers of the best- and worstseller

for(int i=1; i<ARR_SIZE; i++) // A loop to enter all sales numbers

{

cout << "Enter sales for " << name[i] << ": ";

cin >> sales[i];

}

// Make the first element in name[] the bestseller and the worstseller name

worstseller_name = bestseller_name = name[0];

// Make the first element in sales[] the bestseller and the worstseller sales amount

worstseller_number = bestseller_number = sales[0];

for(int i=1; i<ARR_SIZE; i++) // Loop through all elements in sales[]

{

if(sales[i] < worstseller_number) // If an element is less than the lowest...

{

worstseller_number=i; // make the lowest sales equal to its sales

worstseller_name=name[i]; // make the worstseller name equal to its name

}

if(sales[i]>bestseller_number) // If an element is higher than the highest...

{

bestseller_number=sales[i]; // make the highest sales equal to its sales

bestseller_name=name[i]; // make the bestseller name equal to its name

}

}

cout << "The bestselling pizza is " << bestseller_name << " with the sales of "

<< bestseller_number << endl; // Display the best selling pizza

cout << "The worst selling pizza is " << worstseller_name << " with the sales of "

<< worstseller_number << endl; } // display the worst selling pizza
