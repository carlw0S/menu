#include "menu.h"

#include <sstream>

size_t getSelection();

bool menu(const std::string &title,
          const std::vector< std::pair< std::string, bool (*)() > > &options)
{
    bool end = false;
    while (!end) {
        // Print title and option names
        std::cout << title << std::endl;
        size_t i = 1;
        for (const auto &option : options) {
            std::cout << "    " << i << ") " << option.first << std::endl;
            ++i;
        }
        std::cout << "    Enter anything else to cancel." << std::endl;

        size_t selection = getSelection();

        if (selection != 0 && selection <= options.size()) {
            // Option selected -- the menu will be shown again depending on its return value
            end = options[selection - 1].second();
        } else {
            // Go back
            return false;
        }
    }

    return true;
}

size_t getSelection()
{
    std::string input_str;
    std::getline(std::cin, input_str);
    size_t selection = 0;
    std::stringstream(input_str) >> selection;
    return selection;
}
