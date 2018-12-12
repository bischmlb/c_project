#include <vector.h>
#include <stdio.h>

int main()
{
    printf("hello world \n");
    
    Vector v = {
        10,
        10,
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,6,7,8,9}
    };
    
    int i;
    for(i=0; i<10; i++){
     printf("%p, \t %d \n", &v.arr[i], v.arr[i]);   
    }
    return 0;
}

// Initialize a vector to be empty.
// Pre: v != NULL
void Vector_ctor(Vector *v){
    int i = 0;
    for(i=0;i<sizeof((*v).arr);i++){
        { (*v).arr[i] = 0; };
    }
};
// Deallocate internal structures of the vector.
// Note: the user is responsible for deleting all values.
// Note: the user is responsible for deleting the actual vector if it was dynamically allocated.
void Vector_dtor(Vector *v);

// Insert a new element at the end of the vector.
// Pre: v != NULL
void Vector_push_back(Vector *v, void *value);

// Remove the last element in the vector.
// Pre: v != NULL && Vector_size(v) > 0
void Vector_pop_back(Vector *v);

// Return the number of elements in the vector.
// Pre: v != NULL
size_t Vector_size(const Vector *v);

// Return the current capacity of the vector.
// Pre: v != NULL
size_t Vector_capacity(const Vector *v);

// Return the value at the given index.
// Pre: v != NULL && index < Vector_size(v)
void *Vector_get(const Vector *v, size_t index);

// Return a pointer to the underlying array.
void **Vector_data(Vector *v);
