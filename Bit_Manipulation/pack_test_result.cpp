#include<iostream>
#include<cstdint>
#include<bitset>

/*
We have 8 bits to store the result of a test. We need to pack the following information into these 8 bits:
1. Error Category (3 bits): This can represent up to 8 different error categories (0-7).
2. Test ID (4 bits): This can represent up to 16 different test IDs (0-15).
3. Pass/Fail Status (1 bit): This can represent whether the test passed (1) or failed (0).  
*/
uint8_t packTestResult(uint8_t errorCat, uint8_t testId, bool isPass)
{
    uint8_t result = 0;
    result |= (errorCat & 0x07);                      // Pack error category (Bits 0-3). 0x07 implies we only take the last 3 bits of errorCat
    result |= (testId & 0x0F) << 3;                   // Pack test ID (Bits 4-7). 0x0F implies last 4 bits of testId, shift it left by 3 to place in bits 4-7
    result |= (static_cast<uint8_t>(isPass) << 7);    // Pack pass/fail status (Bit 7). Shift by 7 to place it in bit 7
    return result;
}

int main() {
    // Test case 1
    uint8_t errorCategory = 5; 
    uint8_t testId = 10;       
    bool isPass = true;     
    
    uint8_t packedResult = packTestResult(errorCategory, testId, isPass);
    std::cout << "Test 1 - Error: 5, TestID: 10, Pass: true" << std::endl;
    std::cout << "Packed Result: " << static_cast<int>(packedResult) << std::endl; //static_cast required as c++ treats uint8 as a character and prints ASCII
    std::cout << "Binary: " << std::bitset<8>(packedResult) << std::endl << std::endl;

    // Test case 2
    errorCategory = 7; 
    testId = 15;        
    isPass = false;
    
    packedResult = packTestResult(errorCategory, testId, isPass);
    std::cout << "Test 2 - Error: 7, TestID: 15, Pass: false" << std::endl;
    std::cout << "Packed Result: " << static_cast<int>(packedResult) << std::endl;
    std::cout << "Binary: " << std::bitset<8>(packedResult) << std::endl;

    return 0;
}