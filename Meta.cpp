//
// Created by Pauli on 04/05/2022.
//

#include "Meta.h"

int getpos2(int value, int* S, int n) {
    for(int i=0; i<n; i++) {
        if(S[i] == value) return i;
    }
}

int dist2(int* S, int n, int** table) {
    int dist =0;
    for(int i=0; i<n; i++) {
        dist += table[S[i]][S[(i+1)%n]];
    }
    return dist;
}

int* local_SearchAlgo2(int **table, int size, int*path){

    int N = size;

    int* S1=new int[N];
    for(int i=0; i<N; i++) {
        S1[i] = path[i];
    }
    for(int v=0; v<N; v++) {
        for(int w= 0; w<N; w++) {

            if(v == w || w == path[(v-1)%N] || w == path[(v+1)%N]) {

            }else {
                for(int i=0; i<N; i++) {
                    S1[i] = path[i];
                }

                int posv =getpos2(v, path, N);
                int posw = getpos2(w, path,N);

                int min = 0;
                if(posv <posw) min = posv;
                else min = posw;
                int max =0;
                if(posv <posw) max = posw;
                else max = posv;

                int k =0;
                for(int i=0; i< min; i++) {
                    S1[i] = path[i];
                    k++;
                }
                S1[min] = v;
                S1[min+1] = w;
                k+=2;

                for(int i=min+1; i<max; i++) {
                    S1[k] = path[i];
                    k++;
                }

                for(int i=(max+1); i<N; i++) {
                    S1[k] = path[i];
                    k++;
                }

                if(dist2(S1, N, table) < dist2(path, N, table)) {
                    for(int i=0; i<N; i++) {
                        path[i] = S1[i];
                    }
                }
            }
        }
    }
    return path;
}

int metaheuristic(int** table, int size){



    int *path = new int[size];
    for(int i=0; i<size; i++) {
        path[i] = i;
    }
    int T = 8;
    while(T > 0){
        int* tempPath = new int[size];
        for(int i=0; i<size; i++) {
            tempPath[i] = path[i];
        }
        int a = experimental::randint(0, size-1);
        int b = experimental::randint(0, size-1);
        tempPath[a] = path[b];
        tempPath[b] = path[a];
        int* lastLocal = local_SearchAlgo2(table, size, tempPath);
        if(dist2(lastLocal, size, table) < dist2(path, size, table)) {
            path = lastLocal;
            T = 8;
        }else{
            T--;
        }
    }
    cout << "Final path Meta Heuristic : ";
    string res="";
    int first = getpos2(0, path, size);
    for(int i=0; i<size; i++) {
        res += to_string(path[(i+first)%size]+1)+" ";
        cout << to_string(path[(i+first)%size]+1)+" ";
    }
    cout<<endl << "Distance : " <<dist2(path, size , table)<<endl;

    ofstream outfile (to_string(size)+"_meta.out");
    outfile <<  res+"\n";
    outfile <<  to_string(dist2(path, size , table))+"\n";
    outfile.close();

    return dist2(path, size , table);
}