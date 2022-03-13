typedef struct my_struct {
    int* num_ptr;
    int num;
} my_struct_t;

void change_val(my_struct_t* s_ptr) {
    // DRAW THE STACK HERE
    int j = *(s_ptr->num_ptr);
    *(s_ptr->num_ptr) = j + 1;

    // DRAW THE STACK HERE
    return;
}

int main() {
    int i = 10;
    int j = 12;
    // DRAW THE STACK HERE

    my_struct_t s;
    s.num = i;
    s.num_ptr = &j;
    // DRAW THE STACK HERE

    change_val(&s);

    return 0;
}