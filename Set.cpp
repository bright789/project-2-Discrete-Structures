#include "Set.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void Set::readFromFile(const std::string filename)
{
    std::ifstream in(filename);
    std::string str;

    while (in >> str)
    {
        elements.insert(str);
    }
}

void Set::printSet(std::ostream &out) const
{
    out << "{";
    for (auto it = elements.begin(); it != elements.end(); ++it)
    {
        if (it != elements.begin())
        {
            out << ",";
        }
        out << *it;
    }
    out << "}";
}

Set Set::cartesianProduct(const Set &other) const
{
    Set result;
    for (const auto &e1 : elements)
    {
        for (const auto &e2 : other.elements)
        {
            result.elements.insert("(" + e1 + "," + e2 + ")");
        }
    }
    return result;
}

std::vector<Set> Set::allSubsets() const
{
    std::vector<Set> subsets;
    Set current;
    generateSubsets(elements, subsets, current, elements.begin());
    return subsets;
}

void Set::generateSubsets(const std::set<std::string> &input, std::vector<Set> &output, Set &current, std::set<std::string>::iterator pos)
{
    if (pos == input.end())
    {
        output.push_back(current);
    }
    else
    {
        generateSubsets(input, output, current, std::next(pos));
        current.elements.insert(*pos);
        generateSubsets(input, output, current, std::next(pos));
        current.elements.erase(*pos);
    }
}
