//
//  main.cpp
//  part_4
//
//  Created by Dennis Kwarteng on 9/23/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

int first_test(int matrix[60][60]){
    // Update each element row by row
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            matrix[i][j] *= 1;
        }
    }
    
    auto time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "first: " << (int) time.count() << std::endl;
    return (int) time.count();
}


int second_test(int matrix[60][60]){
    // Update each element randomly
    srand((unsigned) time(NULL)); // use current time as seed for random generator
    
    
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            matrix[std::rand() % 60][std::rand() % 60] /= 1;
        }
    }
    
    auto time = std::chrono::high_resolution_clock::now() - start;
    
    std::cout << "second: " << (int) time.count() << std::endl;
    return (int) time.count();
}

int main(int argc, const char * argv[]) {
    // Make a matrix
    int matrix[60][60];
    int first_array[10];
    int second_array[10];
    
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            matrix[i][j] = i+j;
        }
    }
    
    for(int i = 0; i < 10; i++){
        first_array[i] = first_test(matrix);
        second_array[i] = second_test(matrix);
    }
    
    return 0;
}
