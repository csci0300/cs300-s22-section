void foo(int a, int b) {
    int i = 0;
    while (i <= 10) {
        if (i < a) {
            i += 2;
        } else if (i < b) {
            i += 5;
        } else {
            i++;
        }
    }
}

int main() {
    int a = 3;
    int b = 7;
    
    foo(a, b);

    return 0;
}