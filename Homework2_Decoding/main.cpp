#include <iostream>
#include <string>

#include "stringdecoding.h"

int main() {
    // Define the input strings from the assignment
    std::string exp = "czitqommta_ehmumt_nio_szozir_eulopupoa_yeht_";
    std::string code = "_acefhilnpst";

    // Call your decode function
    std::string decoded_string = decode(exp, code);

    // Print the output to the console
    std::cout << "Original String: " << exp << std::endl;
    std::cout << "Code String: " << code << std::endl;
    std::cout << "Decoded String: " << decoded_string << std::endl;

    // Check if the output matches the expected output
    std::string expected_output = "zqommmumozozruouoy_the_apple_is_in_the_attic";
    if (decoded_string == expected_output) {
        std::cout << "Test passed! ✅" << std::endl;
    } else {
        std::cout << "Test failed. ❌" << std::endl;
        std::cout << "Expected: " << expected_output << std::endl;
    }

    return 0;
}