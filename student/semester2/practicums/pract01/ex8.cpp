#include <iostream>

template<typename T>
using TFunction = T(*)(T);

template <typename T>
T applyInOrder(TFunction<T>* funcs, size_t* order, size_t orderSize, T t) {
    for (unsigned i = 0; i < orderSize; i++) {
        t = funcs[order[i]](t);
    }

    return t;
}

int inc(int x) { return x + 1; }
int mul2(int x) { return x * 2; }
int dec(int x) { return x - 1; }

int main() {
    int (*funcs[])(int) = {inc, mul2, dec};
    size_t order1[] = {2, 0, 1};
    size_t order2[] = {0, 1, 2};
    std::cout << applyInOrder<int>(funcs, order1, 3, 3) << std::endl; // ((3 - 1) + 1) * 2 = 6
    std::cout << applyInOrder<int>(funcs, order2, 3, 3) << std::endl; // ((3 + 1) * 2) - 1 = 7
}