#include <iostream>
#include <chrono>
#include <fstream>
#include "Constructive_Search.h"
#include "local_Search.h"
#include "exact.h"
#include "meta.h"

using namespace std;

int** openTable(string data, int *size) {
    // Lecture

    ifstream infile("./"+data);
    string line;
    getline(infile, line);
    *size = 0;
    *size = stoi(line);
    int**  table = new int*[*size];
    for(int i=0;i<*size;i++) {
        table[i] = new int[*size];
    }
    for(int i = 0; i < *size; i++) {
        getline(infile, line);
        istringstream ss(line);
        string elem;
        for (int j = 0; j < *size; j++) {
            getline(ss, elem, ' ');
            table[i][j] = stoi(elem);
        }
    }
    return table;
}

int main() {
    srand(time(NULL));
    clock_t start;
    clock_t end;
    string values="";





    fstream outfile ("result_local.txt");
    ofstream outfile2 ("result_constr.txt");
    ofstream outfile3 ("result_exact.txt");
    ofstream outfile4 ("result_meta.txt");
    for(int i=3; i<11; i++) {

        // Test file creation

        /*values="";
        ofstream file ("temp.in");
        values+=to_string(i)+"\n";
        for(int j=0; j<i; j++) {
            for(int k=0; k<i; k++) {
                if(j==k) values += "0 ";
                else values += to_string(rand()%100)+" ";
            }
            values+="\n";
        }
        file << values;
        file.close();*/

        // Algorithms Executions

        int size =0;
        int** table = openTable(to_string(i)+"_check.in", &size);
        double delay;

        start = clock();
        int wei = local_SearchAlgo(table, size);
        end = clock();

        delay = ((double)end - (double)start)/CLOCKS_PER_SEC;
        std::cout << "Duration : " << delay << std::endl;

        outfile <<  to_string(i)+";"+to_string(delay)+"\n";

        start = clock();
        int wei2 = constructive_algorithm(table, size);
        end = clock();

        delay = ((double)end - (double)start)/CLOCKS_PER_SEC;
        std::cout << "Duration : " << delay << std::endl;

        outfile2 <<  to_string(i)+";"+to_string(delay)+"\n";

        start = clock();
        int wei3 =exactAlgo(table, size);
        end = clock();

        delay = ((double)end - (double)start)/CLOCKS_PER_SEC;
        std::cout << "Duration : " << delay << std::endl;

        outfile3 <<  to_string(i)+";"+to_string(delay)+"\n";

        start = clock();
        int wei4 = metaheuristic(table, size);
        end = clock();

        delay = ((double)end - (double)start)/CLOCKS_PER_SEC;
        std::cout << "Duration : " << delay << std::endl;

        outfile4 << to_string(i)+";"+ to_string(delay)+"\n";

    }
    outfile.close();
    outfile2.close();
    outfile3.close();
    outfile4.close();

    return 0;
}
