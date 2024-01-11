#include <iostream>
#include "user/User.h"
#include "pointers/unique_ptr.h"

int main() {
    std::cout << "Demo Unique Pointer\n";
    unique_ptr<int> singlePtr(new int(42));
    std::cout << "singlePtr points to: " << *singlePtr << std::endl;

    singlePtr.reset(new int(55));
    std::cout << "singlePtr now points to: " << *singlePtr << std::endl;

    {
        unique_ptr<int[]> arrayPtr(new int[3]{1, 2, 3});
        std::cout << "arrayPtr points to an array: ";
        for (int i = 0; i < 3; ++i) {
            std::cout << arrayPtr[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
