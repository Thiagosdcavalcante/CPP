/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:43:35 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/19 16:35:32 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceAll.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "To use: " << argv[0] << " <File> <Target> <NewWord>" << std::endl;
        return 1;
    }

    std::string myFile = argv[1];
    std::string targetStr = argv[2];
    std::string changeStr = argv[3];

    if (targetStr.empty() || changeStr.empty())
    {
        std::cerr << "Error: strings cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream enterFile(myFile.c_str());
    if (!enterFile)
    {
        std::cerr << "Error trying to open file: " << myFile << std::endl;
        return 1;
    }

    std::string contentStr((std::istreambuf_iterator<char>(enterFile)),
                           std::istreambuf_iterator<char>());
    enterFile.close();

    std::string result = replaceAll(contentStr, targetStr, changeStr);

    std::string outputFile = myFile + ".replace";
    std::ofstream outputResult(outputFile.c_str());
    if (!outputResult)
    {
        std::cerr << "Error creating output file: " << outputFile << std::endl;
        return 1;
    }

    outputResult << result;
    outputResult.close();

    return 0;
}
