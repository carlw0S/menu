#pragma once

#include <iostream>
#include <vector>

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
          const std::vector< std::pair< std::string, bool (*)() > > &options);
