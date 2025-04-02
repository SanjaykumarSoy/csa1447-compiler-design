#include <stdio.h>
#include <stdbool.h>
#define HEAP_SIZE 10

typedef struct Object {
    bool marked;
    struct Object* references[2];
    int ref_count;
} Object;

Object heap[HEAP_SIZE];
Object* free_list = NULL;

void print_heap(const char* phase) {
    printf("\nHeap state (%s):\n", phase);
    for (int i = 0; i < HEAP_SIZE; i++) {
        printf("Object %d: marked=%d, ref_count=%d, refs=[%p, %p]\n",
               i, heap[i].marked, heap[i].ref_count,
               heap[i].references[0], heap[i].references[1]);
    }
    printf("Free list: %p\n", (void*)free_list);
}

void mark(Object* obj) {
    if (!obj || obj->marked) return;
    obj->marked = true;
    for (int i = 0; i < obj->ref_count; i++) {
        mark(obj->references[i]);
    }
}

void sweep() {
    for (int i = 0; i < HEAP_SIZE; i++) {
        if (heap[i].marked) {
            heap[i].marked = false;
        } else {
           
            heap[i].references[0] = free_list;
            free_list = &heap[i];
        }
    }
}

void gc(Object* roots[], int root_count) {
    printf("\nStarting garbage collection...\n");
    print_heap("pre-GC");
  
    for (int i = 0; i < root_count; i++) {
        mark(roots[i]);
    }
    
 
    sweep();
    
    print_heap("post-GC");
}

int main() {

    for (int i = 0; i < HEAP_SIZE; i++) {
        heap[i].marked = false;
        heap[i].ref_count = 0;
        heap[i].references[0] = NULL;
        heap[i].references[1] = NULL;
    }

    Object* root = &heap[0];
    root->ref_count = 1;
    root->references[0] = &heap[1];
    heap[1].ref_count = 1;
    

    Object* roots[] = {root};
    gc(roots, 1);

    printf("\nGarbage collection completed.\n");
    return 0;
}
