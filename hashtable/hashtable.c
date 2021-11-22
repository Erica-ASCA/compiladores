#include<stdio.h>
#define MAX 7

int array[MAX];

void array_create(){
    int i;
    for(i = 0; i < MAX; i++){
        array[i] = -1;
    }    
}

void array_insert(int value){
    int key = value % MAX;

    if (array[key] == -1){
        array[key] = value;
    } else {
        printf("Error: Key collision\n");
    }
}

void array_delete(int value){
    int key = value % MAX;
    if (array[key] == value){
        array[key] = -1;
    }
}

int array_search(int value){
    int key = value % MAX;
    int result;
    if (array[key] == value){
        result = key;
    } else {
        result = -1;
    }
    
}

void array_print(){
    int i;
    printf("Hash table:\n");
    for(i = 0; i < MAX; i++){
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("--------------------------------\n");
}

void array_alter_value(int old_value, int new_value){
    int key = array_search(old_value);
    if (key != -1){
        array_delete(old_value);
        array_insert(new_value);
    } else {
        printf("Error: Value does not exist\n");
    }
}

int main(void){
    array_create();
    array_insert(85);
    array_insert(73);
    array_insert(1050);
    array_print();
    array_delete(85);
    array_print();
    array_search(73);
    array_alter_value(1050, 50);
    array_insert(54);
    array_print();
}