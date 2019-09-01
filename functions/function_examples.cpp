#include <iostream>

// function syntax: return_value function_name(parameter_list...) { function_body }

// this function takes a number 'n' and returns 'n+1' without modifying
// the value passed in
int incrementByValue(int n)
{
    return n++;
}

// this function takes a number 'n' and increments it, modifying the
// variable passed in
void incrementByReference(int &n)
{
    n++;
}

// functions don't have to have return values
void sayHello(std::string name)
{
    std::cout << "Hello, " << name << "!\n";
}

// functions don't have to have return values or parameters
void printRandomNumber()
{
    std::cout << rand() << "\n";
}

// make sure that your functions are safe!
char getNthChar(std::string s, unsigned i)
{
    // what happens if 'i' is larger than s.size() - 1
    return s[i];
}

// this is a function declaration (without implementation)
int sumArray(int*, unsigned);

// main is a function too!
int main()
{
    int a = 4;

    // call a function by invoking its name, then open parenthesis, followed by the list of comma-separated
    // parameters in the order of the function declaration, followed by close parenthesis

    // a is passed in by value and therefore cannot be changed by code in the function
    int b = incrementByValue(a);
    std::cout << "b is " << b << " (a+1)\n";
    std::cout << "a is still " << a << "\n";

    // a is passed by reference and can therefore be changed by code in the function
    incrementByReference(a);
    std::cout << "a was changed to " << a << " because it was passed by reference\n";

    // sayHello does not have a return value, it just does something with parameters given to it
    sayHello("Joshua");

    // you can pass in variables and literals into function calls
    std::string name_variable = "Johanne";
    sayHello(name_variable);

    printRandomNumber();

    char nth_char = getNthChar(name_variable, a);
    std::cout << "The " << a+1 << "th character of " << name_variable << " is " << nth_char << "!\n";

    // const is necessary because static arrays like this have to have a known and unchanging
    // size at compile time (the size cannot be determined during the program execution)
    const int ARRAY_SIZE = 5;

    int arr[ARRAY_SIZE] = { 1,2,3,4,5 };

    // I can call sumArray here because I declared it above even though it is implemented below
    int sum = sumArray(arr, ARRAY_SIZE);
    std::cout << "The sum of the array is " << sum << "\n";
    return 0;
}

// this is the implementation of the function declaration above
// pass in raw arrays as pointers to the first element
int sumArray(int* array, unsigned size)
{
    int sum = 0;
    for(unsigned i = 0u; i < size; ++i)
        sum += array[i];
    return sum;
}


