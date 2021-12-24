#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int **initial(int *n,int *m);
void input (int **arr_1,int *m,int *n);
void output(int **arr_1,int *m,int *n,string massage);
void average (int **arr_1,double *arr_2,int *m,int *n);
void output_vec(double *arr_2,int *n,string massage);
double sigma (double *arr_2,double *arr_3,int *n);
void delete_array(int **arr_1,int *m);

int main() {
    srand(time(NULL));
    int n,m,**A,**M;
    double *B = new double [n];
    double *T = new double [n];
    cout << "Enter the amount of rows in Arrays :\n ";
    cin >> m;
    cout << "Enter the amount of columns in Arrays :\n ";
    cin >> n;
    A = initial(&n,&m);
    M = initial(&n,&m);
    input(A,&m,&n);
    input(M,&m,&n);
    output(A,&m,&n,"A array:");
    output(M,&m,&n,"M array:");
    average(A,B,&n,&m);
    average(M,T,&n,&m);
    output_vec(B,&n,"Array B:");
    output_vec(T,&n,"Array T:");
    cout << "Y= " << sigma(B,T,&n) << endl;
    delete[] B;
    delete[] T;
    delete_array(A,&m);
    delete_array(M,&m);
    system("pause");
    return 0;
}
int **initial(int *n,int *m){
    int **arr_1 = new int*[*m];
    for(int i = 0;i < *m;i++){
        arr_1[i] = new int[*n];
    }
    return arr_1;
}
void input (int **arr_1,int *m,int *n){
    for (int i = 0;i < *m;i++) {
        for (int j = 0; j < *n; j++) {
            arr_1[i][j] = rand()% 21 - 10;
        }
    }
}
void output(int **arr_1,int *m,int *n,string massage){
    cout << massage << endl;
    for (int i = 0;i < *m;i++) {
        for (int j = 0; j < *n; j++) {
            printf("%3d",arr_1[i][j]) ;
        }
        cout << endl;
    }
}
void average (int **arr_1,double *arr_2,int *n,int *m){
    for (int j = 0;j < *n;j++) {
        double sum = 0;
        for (int i = 0; i < *m; i++) {
            sum += arr_1[i][j];
        }
        sum /= *m;
        *arr_2 = sum;
        arr_2++;
    }
}
void output_vec(double *arr_2,int *n,string massage){
    cout << massage << endl;
    for (int i = 0;i < *n;i++) {
        printf("%2.1f\n",arr_2[i]) ;
    }
}
double sigma(double* arr_b, double* arr_t, int *n)
{
    double sum = 0;
    for (int i = 1; i < *n; i++)
    {
        sum += abs(arr_b[i] - arr_t[i]);
    }
    return sum;
}
void delete_array(int **arr_1,int *m){
    for(int i = 0;i < *m ;i++){
        delete[] arr_1[i];
    }
    delete[] arr_1;
}