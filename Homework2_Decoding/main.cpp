#include <iostream>
#include <string>
#include "stringdecoding.h" // Assuming you're using the header file approach

void run_test(const std::string& exp, const std::string& code, const std::string& expected_output, int test_number) {
    std::cout << "--- Test Case " << test_number << " ---" << std::endl;
    std::cout << "Input Expression: " << exp << std::endl;
    std::cout << "Input Code: " << code << std::endl;
    
    std::string decoded_string = decode(exp, code);
    
    std::cout << "Decoded String: " << decoded_string << std::endl;
    std::cout << "Expected Output: " << expected_output << std::endl;

    if (decoded_string == expected_output) {
        std::cout << "Result: Test PASSED! ✅" << std::endl;
    } else {
        std::cout << "Result: Test FAILED. ❌" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Original Assignment Test Case
    run_test("czitqommta_ehmumt_nio_szozir_eulopupoa_yeht_", "_acefhilnpst", "zqommmumozozruouoy_the_apple_is_in_the_attic", 1);

    // Basic Cases
    run_test("hello", "aeiou", "hlloe", 2);
    run_test("programming", "p", "rogrammingp", 3);

    // Edge Cases
    run_test("", "abc", "", 4); // Empty exp string
    run_test("hello", "", "hello", 5); // Empty code string
    run_test("apple", "aple", "elppa", 6); // All code characters
    run_test("xyz", "123", "xyz", 7); // No code characters

    return 0;
}