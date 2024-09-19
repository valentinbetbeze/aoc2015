#include <string>
#include <vector>

#ifndef _HELPER_H_
#define _HELPER_H_

/**
 * @brief Parse a file into a list of strings
 *
 * @param file_name Name of the file to parse
 * @param lines List holding the parsed output
 */
void parse_file(const std::string &file_name, std::vector<std::string> &lines);


#endif    // _HELPER_H_
