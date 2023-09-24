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

void first_test(){
    // Create matrix on the heap
    int **matrix = new int*[30];
    for(int i = 0; i < 70; i++){
        matrix[i] = new int[30];
        for(int j = 0; j < 30; j++){
            matrix[i][j] = i+j;
        }
    }
    
    
    // Update each element row by row
    
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            auto start = std::chrono::high_resolution_clock::now();
            matrix[i][j] *= 1;
            auto time = std::chrono::high_resolution_clock::now() - start;
            std::cout << time.count() << std::endl;

        }
    }
    
}

void third_test(){
    int **matrix = new int*[30];
    for(int i = 0; i < 30; i++){
        matrix[i] = new int[30];
        for(int j = 0; j < 30; j++){
            matrix[i][j] = i+j;
        }
    }
    
    for(int i = 0; i < 150; i++){
        auto start = std::chrono::high_resolution_clock::now();
        matrix[10][10] *= 1;
        auto time = std::chrono::high_resolution_clock::now() - start;
        std::cout << time.count() << std::endl;
    }
}


void second_test(){
    // Create matrix on the heap and initialize them
    int **matrix = new int*[30];
    for(int i = 0; i < 30; i++){
        matrix[i] = new int[30];
        for(int j = 0; j < 30; j++){
            matrix[i][j] = i+j;
        }
    }
    
    srand((unsigned) time(NULL)); // use current time as seed for random generator

    int ii[900];
    int jj[900];
    
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            int i_index = std::rand() % 30;
            int j_index = std::rand() % 30;
            ii[i+j] = i_index;
            jj[i+j] = j_index;
            
            auto start = std::chrono::high_resolution_clock::now();
            matrix[i_index][j_index] *= 1;
            auto time = std::chrono::high_resolution_clock::now() - start;
            std::cout << (int) time.count() << std::endl;

        }
    }
    std::cout << std::endl;
    for(int i = 0; i < 100; i++){
        std::cout << ii[i] << " " << jj[i] << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    // Make a matrix

    
    first_test();
    second_test();
    third_test();
    
    
    return 0;
}
