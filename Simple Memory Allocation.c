#include <stdio.h>
#include <stdlib.h>
void memory_optimized_function() {
    int *arr = (int*)malloc(100 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }
    
    free(arr); // Preventing memory leaks
}


int main() {
    memory_optimized_function();
    return 0;
}
