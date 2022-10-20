//
// Created by Pauli on 04/05/2022.
//

#include "local_Search.h"

int getpos(int value, int* S, int n) {
    for(int i=0; i<n; i++) {
        if(S[i] == value) return i;
    }
}

int dist(int* S, int n, int** table) {
    int dist =0;
    for(int i=0; i<n; i++) {
        dist += table[S[i]][S[(i+1)%n]];
    }
    return dist;
}

int local_SearchAlgo(int **table, int N){

    int* S = new int[N];
    for(int i=0; i<N; i++) {
        S[i] = i;
    }

    int* S1=new int[N];
    for(int i=0; i<N; i++) {
        S1[i] = S[i];
    }
    for(int v=0; v<N; v++) {
        for(int w= 0; w<N; w++) {

            if(v == w || w == S[(v-1)%N] || w == S[(v+1)%N]) {

            }else {
                for(int i=0; i<N; i++) {
                    S1[i] = S[i];
                }

                int posv =getpos(v, S, N);
                int posw = getpos(w, S,N);

                int min = 0;
                if(posv <posw) min = posv;
                else min = posw;
                int max =0;
                if(posv <posw) max = posw;
                else max = posv;

                int k =0;
                for(int i=0; i< min; i++) {
                    S1[i] = S[i];
                    k++;
                }
                S1[min] = v;
                S1[min+1] = w;
                k+=2;

                for(int i=min+1; i<max; i++) {
                    S1[k] = S[i];
                    k++;
                }

                for(int i=(max+1); i<N; i++) {
                    S1[k] = S[i];
                    k++;
                }

                if(dist(S1, N, table) < dist(S, N, table)) {

                    for(int i=0; i<N; i++) {

                        S[i] = S1[i];
                    }
                }
            }

        }
    }
    cout << "Final path : ";
    string result ="";
    int first = getpos(0, S, N);
    for(int i=0; i<N; i++) {
        result += to_string(S[(i+first)%N]+1)+" ";
        cout << to_string(S[(i+first)%N]+1)+" ";
    }

    cout<<endl << "Distance : " <<dist(S, N , table)<<endl;

    ofstream outfile (to_string(N)+"_local.out");
    outfile <<  result+"\n";
    outfile <<  to_string(dist(S, N , table))+"\n";
    outfile.close();

    return dist(S, N , table);

}