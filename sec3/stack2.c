int foo(int a, int b) {
    if (a + b < 20) {
        int c = 2 * (a + b);
        return c;
    } else {
        return 20;
    }
}

int main () {
    int i = foo(3, 4);

    return i;
}