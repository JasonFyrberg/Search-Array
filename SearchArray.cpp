#include <iostream>
#include <limits> 

// declare function to search through the array
int searchArray(int array[], int size, int target);

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    while (std::cin.fail() || size <= 0) { // input validation loop
        std::cout << "Invalid input. Please enter a positive integer for the size: ";
        std::cin.clear(); // clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input buffer
        std::cin >> size; // retry input
    }

    int numbers[size]; // declare an array of user-defined size
    std::cout << "Enter " << size << " numbers to form the array:" << std::endl;
    
    // input numbers into the array
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter number " << i+1 << ": ";
        while (!(std::cin >> numbers[i])) { // input validation loop
            std::cout << "Invalid input. Please enter a valid number: ";
            std::cin.clear(); // clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }

    int myNumber;
    std::cout << "Enter the number you want to search for: ";
    while (!(std::cin >> myNumber)) { // input validation loop
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear(); // clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    int index = searchArray(numbers, size, myNumber);
    if (index != -1) {
        std::cout << myNumber << " is at index " << index << std::endl;
    } else {
        std::cout << myNumber << " is not in the array." << std::endl;
    }
}

// iterate through array, return if found, -1 if not
int searchArray(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}
