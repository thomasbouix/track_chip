// Programme de test

#include <iostream>
#include "Structure_Sigfox.h"
int main() {
    std::cout << "Hello World!";
    Message m = Message();
    string res;
    res = m.float_to_hexa(3.14);
    std::cout << res;
    return 0;
}
