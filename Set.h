#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

class Set
{
public:
    void readFromFile(const std::string filename);
    void printSet(std::ostream &out) const;
    Set cartesianProduct(const Set &other) const;
    std::vector<Set> allSubsets() const;
    std::set<std::string> getElements() const
    {
        return elements;
    }
    void setElements(const std::set<std::string> &elements)
    {
        this->elements = elements;
    }

private:
    std::set<std::string> elements;
    static void generateSubsets(const std::set<std::string> &input, std::vector<Set> &output, Set &current, std::set<std::string>::iterator pos);
};