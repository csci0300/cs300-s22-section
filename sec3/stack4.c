void foo(int a, int b) {
    int i = 0;
    // DRAW THE STACK HERE
    while (i <= 10) {
        if (i < a) {
            i += 2;
        } else if (i < b) {
            i += 5;
        } else {
            i++;
        }
    }
    // DRAW THE STACK HERE
}

int main() {
    int a = 3;
    int b = 7;
    // DRAW THE STACK HERE
    
    foo(a, b);
    // DRAW THE STACK HERE

    return 0;
}