// C++ is basically just C, so I can easily change C to C++ by changing a few headers :)

#include <iostream>
#include <string>

#include "uci.h"
#include "evaluate.h"

//#include other things

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios::unitbuf);
    lookups::init();
    eval::init();

    std::string word;
    while (true) {
        std::cin >> word;
        if (word == "uci")
        {
            uci::init();
            break;
        }
        else
        {
            std::cout << "Unknown command" << std::endl;
        }
    }
    return 0;
}
