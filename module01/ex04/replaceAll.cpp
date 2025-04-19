/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceAll.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:02:17 by tsantana          #+#    #+#             */
/*   Updated: 2025/04/19 16:23:26 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceAll.hpp"

std::string replaceAll(const std::string& text, const std::string& targetStr, const std::string& changeStr)
{
    if (targetStr.empty()) return text;

    std::string result;
    size_t i = 0;

    while (i < text.size())
    {
        bool findStr = true;
        for (size_t j = 0; j < targetStr.size(); ++j)
        {
            if (i + j >= text.size() || text[i + j] != targetStr[j])
            {
                findStr = false;
                break;
            }
        }

        if (findStr)
        {
            result += changeStr;
            i += targetStr.size();
        }
        else
        {
            result += text[i];
            ++i;
        }
    }

    return result;
}