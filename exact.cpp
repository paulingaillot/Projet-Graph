//
// Created by Justin on 01/05/2022.
//
#include <iostream>
#include "exact.h"
#include <bits/stdc++.h>

int minD = 999999;
string res = "";
int N=0;
int** table;


int exactAlgo(int** table1, int N1){
    table = table1;
    N= N1;
    minD=99999;
    for(int i = 0; i < N; i++){
        visit(i,"",0,0);
    }
    cout << res << endl << minD << endl;

    ofstream outfile (to_string(N)+"_exact.out");
    outfile <<  res+"\n";
    outfile <<  to_string(minD)+"\n";
    outfile.close();

    return minD;
}

void visit(int from, string path, int dist, int n){
    if(n < N) {
        for (int i = 0; i < N; i++) {
            if (table[from][i] != 0 && !strstr(path.c_str(),to_string(i+1).c_str())) {
                visit(i, path + " "+to_string(i + 1), dist + table[from][i], n + 1);
            }
        }
    }else{
        if(dist <= minD){
            minD = dist;
            res = path;
        }
    }
}