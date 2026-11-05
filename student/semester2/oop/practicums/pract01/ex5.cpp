#include <iostream>

using VoidFunction = void(*)(void);

void loop(VoidFunction f, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        f();
    }
}

void say() {
    std::cout << "Hello, FMI!\n";
}

int main() {
    loop(say, 6);
}