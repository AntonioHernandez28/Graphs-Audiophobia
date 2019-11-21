//
//  main.cpp
//  AUDIOPHOBIA
//
//  Created by Antonio Hernández Ruiz on 9/30/19.
//  Copyright © 2019 Antonio Hernández Ruiz. All rights reserved.
//

#include <iostream>
#include <climits>
#include <unordered_map> 
using namespace std;


void leeArcos(int mat[100][100], int p[100][100], int m) {
    int a,b,c;
    
    for(int i = 0; i < 100; i++) {
        p[i][i] = mat[i][i] = 0;
        for(int j = i+1; j < 100; j++) {
            mat[i][j] = mat[j][i] = INT_MAX; // asignacion multiple se van llenando los dos triangulos
            p[i][j] = p[j][i] = 0;
        }
    }
    
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        mat[a-1][b-1] = mat[b-1][a-1] = c;
        
    }
    
}


void checaTrayectoria(int p[100][100], int a, int b) {
    
    if(p[a][b] != 0){
        
        checaTrayectoria(p, a, p[a][b]);
        checaTrayectoria(p, p[a][b], b);
    }
}

void consulta(int mat[100][100], int p[100][100], int q) {
    int a, b;
    for(int i = 1; i <= q; i++) {
        cin >> a >> b;
        if(mat[a-1][b-1] == INT_MAX) {
            cout << "No path" << endl;
        }
        else {
            cout << "Costo: " << mat[a-1][b-1] << endl;
            checaTrayectoria(p, a-1, b-1);
        }
    }
}

void Floyd(int mat[100][100], int p[100][100], int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][j] > max(mat[i][k], mat[k][j]) ) {
                    mat[i][j] = max(mat[i][k], mat[k][j]);
                    p[i][j] = k;
                }
                
            }
        }
    }
}

int main()
{
    int mat[100][100];
    int p[100][100];
    int n = 1, m = 1,  q = 1;
    int cont = 1;
    
    
    while(true) {
    
        cin >> n >> m >> q;  // n - Cantidad Nodos, M cantidad arcos, Q - cantidad consultas
        if(n == 0 && m == 0 && q == 0) break;
        cout << "Test Case # " << cont << endl;
        leeArcos(mat, p, m);
        Floyd(mat, p, n);
        consulta(mat, p, q);
        cont++;
        cout << endl;
    }
    
}

