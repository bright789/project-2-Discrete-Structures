#include "Set.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
     Set A, B;
     A.readFromFile("input1.dat");
     B.readFromFile("input2.dat");

     Set AB = A.cartesianProduct(B);

     ofstream out1("output1.dat");
     out1 << "A=";
     A.printSet(out1);
     out1 << endl
          << "B=";
     B.printSet(out1);
     out1 << endl
          << "AxB=";
     AB.printSet(out1);
     out1 << endl
          << "There are " << AB.getElements().size() << " elements in the Cartesian Product." << endl;
     out1.close();

     vector<Set> subsets = A.allSubsets();
     ofstream out2("output2.dat");
     out2 << "A=";
     A.printSet(out2);
     out2 << endl
          << "Subsets of A:" << endl;
     for (const auto &subset : subsets)
     {
          subset.printSet(out2);
          out2 << "," << endl;
     }
     out2 << "There are " << subsets.size() << " subsets of A." << endl;
     out2.close();

     return 0;
}