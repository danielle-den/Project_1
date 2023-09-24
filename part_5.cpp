//
//  main.cpp
//  part_5
//
//

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <unistd.h> // For sysconf
#include <cmath>    // For ceil


const size_t PAGE_SIZE = sysconf(_SC_PAGE_SIZE); // Get the system's page size
const int ARRAY_SIZE = 4096 * 100; // 4MB array

void no_miss(){
    char* largeArray = new char[ARRAY_SIZE];
    
    for(int i = 0; i < 100; i++){
        auto start = std::chrono::high_resolution_clock::now();
        largeArray[i] = 0;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = end - start;
        std::cout << duration.count() << std::endl;
    }
}


void tlb_miss2(){
    // Allocate a large array that spans multiple pages
    char* largeArray = new char[ARRAY_SIZE];

    // Access elements in the array in a way that causes TLB misses
    for (int i = 0; i < ARRAY_SIZE; i += PAGE_SIZE) {
        auto start = std::chrono::high_resolution_clock::now();
        largeArray[i] = 0;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = end - start;
        std::cout << duration.count() << std::endl;
    }

    // Clean up and release memory
    delete[] largeArray;
}

int main() {
    std::cout << "no Miss" << std::endl;
    no_miss();
    std::cout << "\nTLB Miss" << std::endl;
    tlb_miss2();
    
    return 0;
}
