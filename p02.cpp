#include "Set.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int main()
{
    Set A, B;
    A.readFromFile("input1.dat");
    B.readFromFile("input2.dat");

    Set AB = A.cartesianProduct(B);

    Set element = Aelements;

    std::ofstream out1("output1.dat");
    out1 << "A=";
    A.printSet(out1);
    out1 << std::endl
         << "B=";
    B.printSet(out1);
    out1 << std::endl
         << "AxB=";
    AB.printSet(out1);
    out1 << std::endl
         << "There are " << AB.getElements().size() << " elements in the Cartesian Product." << std::endl;
    out1.close();

    std::vector<Set> subsets = A.allSubsets();
    std::ofstream out2("output2.dat");
    out2 << "A=";
    A.printSet(out2);
    out2 << std::endl
         << "Subsets of A:" << std::endl;
    for (const auto &subset : subsets)
    {
        subset.printSet(out2);
        out2 << "," << std::endl;
    }
    out2 << "There are " << subsets.size() << " subsets of A." << std::endl;
    out2.close();

    return 0;
}