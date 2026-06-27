#include <iostream>
#include "Array.h"

int main() {
    Array<int> arr;

    std::cout << "=== pushBack ===\n";
    for (int i = 1; i <= 5; ++i)
        arr.pushBack(i * 10);
    arr.print();  // [ 10 20 30 40 50 ]

    std::cout << "\n=== insert(2, 99) ===\n";
    arr.insert(2, 99);
    arr.print();  // [ 10 20 99 30 40 50 ]

    std::cout << "\n=== remove(2) ===\n";
    arr.remove(2);
    arr.print();  // [ 10 20 30 40 50 ]

    std::cout << "\n=== popBack ===\n";
    arr.popBack();
    arr.print();  // [ 10 20 30 40 ]

    std::cout << "\n=== operator[] ===\n";
    std::cout << "arr[0]=" << arr[0] << "  arr[2]=" << arr[2] << "\n";

    std::cout << "\n=== capacity 자동 증가 확인 ===\n";
    Array<int> small(2);
    for (int i = 1; i <= 6; ++i) {
        small.pushBack(i);
        small.print();
    }

    return 0;
}
