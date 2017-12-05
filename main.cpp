/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: agendron
 *
 * Created on November 17, 2017, 1:07 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Matrix {
    
public:
    
    Matrix(int n1, int n2, int n3, int n4) {
        v[0][0] = n1;
        v[0][1] = n2;
        v[1][0] = n3;
        v[1][1] = n4;
    }
    
    void print(ostream &os) const {
        os << v[0][0] << " " << v[0][1] << endl;
        os << v[1][0] << " " << v[1][1] << endl;
        //os << "---------" << endl;
    }
    
    void add(const int& rhs) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                v[i][j] += rhs;
            }
        }
    }
    
    void multiply(const int& rhs) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                v[i][j] *= rhs;
            }
        }
    }
    
    void subtract(const int& rhs) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                v[i][j] -= rhs;
            }
        }
    }
    
    void set(const int& rhs) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                v[i][j] = rhs;
            }
        }
    }
    
    void operator+(const int& rhs) {
        add(rhs);
    }
    
    void operator*(const int& rhs) {
        multiply(rhs);
    }    
    
    void operator-(const int& rhs) {
        subtract(rhs);
    }
    
    void operator=(const int& rhs) {
        set(rhs);
    }
    
    void add(Matrix& m) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                v[i][j] += m.v[i][j];
            }
        }
    }
    
    void multiply(Matrix& m) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                v[i][j] *= m.v[i][j];
            }
        }
    }
    
    void subtract(Matrix& m) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                v[i][j] -= m.v[i][j];
            }
        }
    }
    
    void set(Matrix& m) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                v[i][j] = m.v[i][j];
            }
        }
    }
    
    void operator+(Matrix& m) {
        add(m);
    }
    
    void operator*(Matrix& m) {
        multiply(m);
    }    
    
    void operator-(Matrix& m) {
        subtract(m);
    }
    
    void operator=(Matrix& m) {
        set(m);
    }
    
private:
    
  int v[2][2];  
};

int main(int argc, char** argv) {
    
    cout << "Matrix A:" << endl;
    Matrix A(1,1,1,1);    
    A.print(cout);
    
    cout << "Matrix B:" << endl;
    Matrix B(3,3,3,3);
    B.print(cout);
    
    cout << endl << "Matrix A + 1:" << endl;
    A+1;
    A.print(cout);
    
    cout << endl << "Matrix A * 2:" << endl;
    A*2;
    A.print(cout);
    
    cout << endl << "Matrix A - 1:" << endl;
    A-1;
    A.print(cout);
    
    cout << endl << "Matrix A + Matrix B:" << endl;
    A+B;
    A.print(cout);
    
    A-B; //required to print correct "Example output"
    
    cout << endl << "Matrix A - Matrix B:" << endl;
    A-B;
    A.print(cout);
    
    A+B; //required to print correct "Example output"
    A+B; //required to print correct "Example output"
    
    cout << endl << "Matrix A * Matrix B:" << endl;
    A*B;
    A.print(cout);
    
    return 0;
}