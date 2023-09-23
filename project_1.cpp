#include <time.h>
#include <iostream>

int return_element(const int *arr, int index){
    return arr[index];
}
void part_1(){
    // Create one array in the stack (cache) and another in the heap (main memory)
    int stack[10];
    int *heap = new int[10];


    // Test writes
    for(int i = 0; i < 10; i++){                // Cache
        stack[i] = i;
    }
    
    for(int i = 0; i < 10; i++){                // Main memory                    
        heap[i] = i;
    }

    // Test read
    for(int i = 0; i < 10; i++){                // Stack
        return_element(stack, i);
    }

    for(int i = 0; i < 10; i++){
        return_element(heap, i);
    }
}

void part_5(){
    // Create 3 high valued arrays of cache memory
    int stack1[100], stack2[200], stack3[300];
    for(int i = 0; i < 100; i++){
        stack1[i] = i;
    }
    for(int i = 0; i < 200; i++){
        stack2[i] = i;
    }
    for(int i = 0; i < 300; i++){
        stack3[i] = i;
    }
}

int main(){
    // Part 1
    part_1();

    return 0;
}
