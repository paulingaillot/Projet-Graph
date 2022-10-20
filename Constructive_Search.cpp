//
// Created by Pauli on 04/05/2022.
//

#include "Constructive_Search.h"

int constructive_algorithm(int **table, int N) {

    // Algo

    char* tab = new char[N];
    for(int i=0; i<N; i++) {
        tab[i] = 'b';
    }
    int first = 1;
    tab[(first-1)] = 'n';
    int poids = 0;
    string result = to_string(1) +" ";

    int min = -1;
    int next = 1;
    for(int i=0; i<N; i++) {
        if((first-1) != i) {
            int value = table[(first - 1)][i];
            if (value < min || min < 0) {
                min = value;
                next = (i+1);
            }
        }
    }
    if(min != -1) poids += min;

    bool tab_noir = false;
    while(tab_noir != true) {

        tab[(next-1)] = 'n';
        int new1;
        min = -1;
        for(int i=0; i<N; i++) {
            if((next-1) != i) {
                int value = table[(next - 1)][i];
                if ((value < min || min < 0) && tab[i] == 'b') {
                    min = value;
                    new1 = (i+1);
                }
            }
        }
        if(min != -1) poids += min;
        result += to_string(next) + " ";
        next = new1;

        tab_noir=true;
        for(int i=0; i<N; i++) {

            if(tab[i] == 'b')  tab_noir = false;

        }


    }

    result += "1";
    poids += table[(next-1)][0];

    cout << "result path : " << result << endl;
    cout << "weight path : " << poids << endl;

    ofstream outfile (to_string(N)+"_constr.out");
    outfile <<  result+"\n";
    outfile <<  to_string(poids)+"\n";
    outfile.close();

    return poids;


}
