struct Heap {
    int array[1000];
    unsigned int max_size = 1000;
    unsigned int size = 0;
};

unsigned int father(unsigned int i) {
    return i/2;
}

void insert(struct Heap heap, int data) {
    if (heap.size < heap.maxsize) {
        heap.size+=1;
        unsigned int i = heap.size; 
        while (i > 1 and (heap.array[father(i)] < data)) {
            heap.array[i] = heap.array[father(i)];
            i = father(i);
        }
        heap.array[i] = k;
    }
}

int find_max(struct Heap heap) {
    if (heap.size > 0) {
        return heap.array[0];
    }
}
