//
// Created by Justin on 01/05/2022.
//

#ifndef CODE_EXACT_H
#define CODE_EXACT_H
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int exactAlgo(int** table, int size);
void visit(int from, string path, int dist, int n);

#endif //CODE_EXACT_H
