#include <bits/stdc++.h>
using namespace std;
//operator overloading for matrix

class Matrix {
    public: 
        int rows, cols;
        int mat[50][50];

        Matrix(int r, int c) {
            rows = r;
            cols = c;
            for (int i=0;i<r;i++) {
                for (int j=0;j<c;j++) {
                    mat[i][j] = 0;
                }
            }
        }

        Matrix operator*(const Matrix& opr) {
            //multiple this opr with this matrix and save result in result matrix . then return result
            int r= rows, c = opr.cols;
            Matrix result(this->cols,c);

            for (int i=0;i<r;i++) {
                for (int j=0;j<c;j++) {
                    //find result[i][j] = 
                    
                    for (int k=0;k<opr.rows;k++) {
                        result.mat[i][j]+= this->mat[i][k] * opr.mat[k][j];

                    }
                    
                }
            }
            return result;
        }
        void display() {
            for (int i=0;i<this->rows;i++) {
                for (int j=0;j<this->cols;j++) {
                    cout << this->mat[i][j] << " " ;
                }
                cout << endl;
            }
        }

};

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 ;
    Matrix mat1(r1, c1);
    for (int i=0;i<r1;i++) {
        for (int j=0;j<c1;j++) {
            cin >> mat1.mat[i][j] ;
        }
    }
    cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    for (int i=0;i<r1;i++) {
        for (int j=0;j<c1;j++) {
            cin >> mat2.mat[i][j] ;
        }
    }
    // Matrix sum = mat1 + mat2;
    // sum.display();

    Matrix product = mat1 * mat2;
    product.display();
    return 0;

}