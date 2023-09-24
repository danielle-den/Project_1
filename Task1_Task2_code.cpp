#include <time.h>
#include <iostream>
#include <chrono>

std::chrono::duration<double> dur1, dur2, dur3, dur4, dur5, dur6, dur7, dur8;

//int time1a, time2a, time3a, time1b, time2b, time3b;
const int SIZE = 1000;
const int P2_SIZE = 1000;

int return_element(const int* arr, int index) {
    return arr[index];
}
void part_1() {

    // Create one array in the stack (cache) and another in the heap (main memory)
    auto time1a = std::chrono::high_resolution_clock::now();
    int stack[SIZE];
    auto time1b = std::chrono::high_resolution_clock::now();
    int* heap = new int[SIZE];
    auto time2b = std::chrono::high_resolution_clock::now();


    // Test reads
    auto time2a = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++) {                // Stack
        return_element(stack, i);
    }
    
    auto time3a = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++) {
        return_element(heap, i);
    }
    
    auto time3b = std::chrono::high_resolution_clock::now();

    // Test writes
    for (int i = 0; i < SIZE; i++) {                // Cache
        stack[i] = i;
    }
    auto time5 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++) {                // Main memory                    
        heap[i] = i;
    }
   
    auto time6 = std::chrono::high_resolution_clock::now();

    // Test writes
    for (int i = 0; i < SIZE; i++) {                // Cache
        stack[i] = i;
    }
    auto time7 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++) {                // Main memory                    
        heap[i] = i;
    }
    auto time8 = std::chrono::high_resolution_clock::now();

    dur1 = time1b - time1a;
    dur2 = time2b - time1b;
    dur3 = time3a - time2a;
    dur4 = time3b - time3a;
    dur5 = time5 - time3b;
    dur6 = time6 - time5;
    dur7 = time7 - time6;
    dur8 = time8 - time7;

    std::cout <<  "Read_Cache:" << dur3.count() << "\nRead_Main:" << dur4.count() << "\nWrite1_Cache:" << dur5.count() << "\nWrite1_Main:" << dur6.count() << "\nWrite2_Cache:" << dur7.count() << "\nWrite2_Cache:" << dur8.count() << std::endl;
}

void part_2() {
    int* rows = new int[P2_SIZE];
    int* cols = new int[P2_SIZE];
    int* results = new int[P2_SIZE];

    for (int m = 0; m < P2_SIZE; m++) {
        rows[m] = m/20;
    }
    for (int n = 0; n < P2_SIZE; n++) {
        cols[n] = n/40;
    }

    for (int t = 0; t < P2_SIZE; t++) {
        results[t] = 0;
    }

    for (int i = 0; i < P2_SIZE; i++) {
        for (int j = 0; j < P2_SIZE; j++) {
            results[i] += rows[i] * cols[j];
        }
    }

    for (int z = 0; z < P2_SIZE; z++) {
        std::cout << results[z] << "  ";

        if (z % 100 == 0) {
            std::cout << std::endl;
        }
    }
}

void part_3() {


}

void part_4() {

}

void part_5() {
    // Create 3 high valued arrays of cache memory
    int stack1[100], stack2[200], stack3[300];
    for (int i = 0; i < 100; i++) {
        stack1[i] = i;
    }
    for (int i = 0; i < 200; i++) {
        stack2[i] = i;
    }
    for (int i = 0; i < 300; i++) {
        stack3[i] = i;
    }
}

int main() {
    // Part 1
    while (1) {
         part_2(); 
    }
        

    return 0;
}