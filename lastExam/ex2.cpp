
// #include <iostream>
// #include <algorithm>
// #include <vector>

// int main()
// {
//     std::vector<int> arr = {5, 2, 8, 10, 3};

//     // Find the maximum element in the array
//     auto maxElement = std::max_element(arr.begin(), arr.end());

//     // Remove the maximum element from the array
//     arr.erase(maxElement);
//     arr.push_back(2);

//     // Print the updated array
//     for (const auto &element : arr)
//     {
//         std::cout << element << " ";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <sstream>
int main()
{
    std::vector<int> arr;
    std::string input;
    std::cout << "Enter 'insert <number>' to insert a number into the array: " << std::endl;
    while (getline(std::cin, input))
    {
        std::istringstream iss(input);
        std::string command;
        int number;
        if (iss >> command >> number && command == "insert")
        {
            arr.push_back(number);
        }
        else
        {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        std::cout << "Array: ";
        for (const auto &element : arr)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
