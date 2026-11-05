#include <iostream>

int repeat(int(*f)(int), int x0, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        x0 = f(x0);
    }

    return x0;
}

int increment(int n) {
    return ++n;
}

int main() {
    std::cout << repeat(increment, 1, 6);
}