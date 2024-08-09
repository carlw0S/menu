#pragma once

#include <iostream>
#include <vector>
#include <sstream>

/*
 * This function prints a simple menu and lets you select its options, 
 * or navigate through it if you use it again inside.
 *
 * @param title The title of the menu. It will be printed before the options.
 * @param options Sequence of pairs containing, on one hand, the name of the option, 
 * and on the other, the option itself, as a function that receives no parameters and returns a bool.
 * If set to false, this bool will make the menu show again after having executed the option.
 * 
 * @returns true if one of the options was executed, false if not.
*/
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

        // Get selection from user input
        size_t selection = 0;
        std::string input_str;
        std::getline(std::cin, input_str);
        std::stringstream(input_str) >> selection;

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
