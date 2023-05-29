/*
 Ahmad Usayd 1926573
 Muhammad Aniq Haris 1920041
 Muhammad Harraz Bin Abd Rahim 1922475
 Muhammad Ismail 1922235
 
 CSCI 1300 Section 3
 
 Progress of program
 Title: Matrix Calculator
 Objectives:
 - Two Matrices (using 2D Arrays)                        [X]
 - Input the size of the two matrices                    [X]
 - input the values of the two matrices                  [X]
 - Ask what operation user would like to perform         [X]
 - Restrict operation based on size of two matrices      [X]
 - Find determinant                                      [X]
 - Find transposed                                       [X]
 - Find inverse                                          [x]
 - Addtion                                               [X]
 - Subtraction                                           [X]
 - Multiplication                                        [x]
 - Power                                                 [x]
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int rowa, cola, rowb, colb, oper = 0, opt = 0;
char d;
double **A = new double*[cola]; // Matrix A
double **B = new double*[colb]; // Matrix B

//for various calculation purposes
double **tempA = new double*[cola];
double **tempB = new double*[colb];
double **tempC = new double*[cola];
double **tempD = new double*[colb];

void getmatrixSize(); //Function to find the sizes of the matrices

void dispMatrix(); // Dispalys matrices

int oprNo(); //Function to find what the user would like to do

void determinant(); //Function to find out the determinant of a matrix

void transpose(); //Function to find the trasnposed matrix

void inverse(); //Function to find the inverse of a matrix

void addition(); //Function to add two matrices

void subtraction(); //Function to subtract two matrices

void multiply(); //Function to multiply two matrices

void power(); //Function to find the power of a matrix

int cont(); //Function to find whether the user would like to continue or exit;

int main() //Main function
{
   do
   {
      if (opt == 0)
      {
         getmatrixSize(); // starts off by asking user for the matrices' sizes.
         dispMatrix(); // Dispalys matrices
      }
      
      oper = oprNo(); // then asks user what they would like to do
      
      if (oper == 1) //find determinant
      {
         determinant();
      }
      else if (oper == 2) //find transposed
      {
         transpose();
      }
      else if (oper == 3) //find inverse
      {
         inverse();
      }
      else if (oper == 4) //addition
      {
         addition();
      }
      else if (oper == 5) //subtraction
      {
         subtraction();
      }
      else if (oper == 6) //multiplication
      {
         multiply();
      }
      else if (oper == 7) //power
      {
         power();
      }
      else if (oper == 8)
      {
         exit(0);
      }
      else
      {
         cout << "Invalid option! Please try again!" << endl;
      }
      
      do
      {
         opt = cont();
         if (opt == 1)
         {
            system("cls");
            cout << "Current matrices: " << endl;
            dispMatrix();
         }
         else if (opt == 2)
         {
            exit(0);
         }
         else
         {
            cout << "Invalid option! Please try again!" << endl;
         }
         
      }
      while (opt != 1 && opt != 2);
   }
   while (oper < 1 || oper > 8 || opt == 1);
   
   return 0;
}

void getmatrixSize() //function to find the sizes of the matrices
{
   //Matrix A
   cout << "Enter the number of columns for matrix A: ";
   cin >> cola;
   cout << "Enter the number of rows for matrix A: ";
   cin >> rowa;
   
   //makes matrix A user specified
   for(int i = 0; i < cola; ++i)
   {
      A[i] = new double[rowa];
   }
   
   //takes values of matrix A row by row
   cout << "Enter values for matrix per row (e.g.[a b c]): " << endl;
   for (int i = 0; i < rowa; ++i)
   {
      for (int j = 0; j < cola; ++j)
      {
         cin >> *(*(A + i) + j);
      }
   }
   
   //Matrix B
   cout << "Enter the number of columns for matrix B: ";
   cin >> colb;
   cout << "Enter the number of rows for matrix B: ";
   cin >> rowb;
   
   //makes matrix B user specified
   for(int i = 0; i < colb; ++i)
   {
      B[i] = new double[rowb];
   }
   
   //takes values of matrix row by row
   cout << "Enter values for matrix per row (e.g.[a b c]): " << endl;
   for (int i = 0; i < rowb; ++i)
   {
      for (int j = 0; j < colb; ++j)
      {
         cin >> *(*(B + i) + j);
      }
   }
}

void dispMatrix()
{
   //temporary arrays for calcuations
   for(int i = 0; i < cola; ++i)
   {
      tempA[i] = new double[rowa];
   }
   for(int i = 0; i < colb; ++i)
   {
      tempB[i] = new double[rowb];
   }
   for(int i = 0; i < cola; ++i)  // for transposing Matrix A
   {
      tempC[i] = new double[rowa];
   }
   for(int i = 0; i < colb; ++i) // for transposing Matrix B
   {
      tempD[i] = new double[rowb];
   }
   // making the temp arrays equal zero
   for(int i = 0; i < rowa; ++i)
   {
      for(int j = 0; j < cola; ++j)
      {
         tempA[i][j]=0;
      }
   }
   for(int i = 0; i < rowb; ++i)
   {
      for(int j = 0; j < colb; ++j)
      {
         tempB[i][j]=0;
      }
   }
   for(int i = 0; i < rowa; ++i)
   {
      for(int j = 0; j < cola; ++j)
      {
         tempC[i][j]=0;
      }
   }
   for(int i = 0; i < rowb; ++i)
   {
      for(int j = 0; j < colb; ++j)
      {
         tempD[i][j]=0;
      }
   }
   
   //outputs values in matrix A [dev]
   cout << "Matrix A: " << endl;
   for (int i = 0; i < rowa; ++i)
   {
      cout << "| ";
      for (int j = 0; j < cola; ++j)
      {
         cout << fixed << setprecision(2) << right << setw(6)
         << A[i][j] << " " ;
      }
      cout << "|" << endl;
   }
   
   //outputs values in matrix B [dev]
   cout << "Matrix B: " << endl;
   for (int i = 0; i < rowb; ++i)
   {
      cout << "| ";
      for (int j = 0; j < colb; ++j)
      {
         cout << fixed << setprecision(2) << right << setw(6)
         << B[i][j] << " " ;
      }
      cout << "|" << endl;
   }
}

int oprNo() //function to find what the user would like to do
{
   cout << "What would you like to do?" << endl;
   cout << "[1] Find Determinant of Matrix [only up to 3x3]" << endl;
   cout << "[2] Find Transposed matrix" << endl;
   cout << "[3] Find Inverse of matrix [only up to 3x3]" << endl;
   cout << "[4] Add both matrices" << endl;
   cout << "[5] Subtract both matrices" << endl;
   cout << "[6] Multiply both matrices" << endl;
   cout << "[7] Find power of Matrix [Power of 1 & 2 only]" << endl;
   cout << "[8] Exit\n" << endl;
   cout << "Enter the number of your option []: ";
   cin >> oper;
   
   return oper;
}

void determinant() //function to find out the determinant of a matrix
{
   cout << "Which Matrix would you like to find your determinant from: " << endl;
   cout << "A or B?" << endl;
   cin >> d;
   
   if (d == 'A')
   {
      if (rowa != cola)
      {
         cout << "The Matrix selected cannot be used to find a determinant, only square matrix are allowed" << endl;
      }
      else
      {
         if (rowa == 1)
         {
            cout << "The determinant for Matrix A is " << A[0][0] << endl;
         }
         else if (rowa == 2)
         {
            double det;
            det = (A[0][0] * A[1][1]) - (A[1][0] * A[0][1]);
            cout << "The determinant for Matrix A is " << det << endl;
         }
         else if (rowa == 3)
         {
            double det;
            det = ((A[0][0]*((A[1][1]*A[2][2]) - (A[1][2]*A[2][1]))) - (A[0][1]*((A[1][0]*A[2][2]) - (A[1][2]*A[2][0]))) + (A[0][2]*((A[1][0]*A[2][1]) - (A[1][1]*A[2][0]))));
            cout << "The determinant for Matrix A is " << det << endl;
         }
         else
         {
            cout << "Out of the scope of this program!" << endl;
         }
      }
   }
   else if (d == 'B')
   {
      if (rowb!= colb)
      {
         cout << "The Matrix selected cannot be used to find a determinant, only sqaure matrix are allowed" << endl;
      }
      else
      {
         if (rowb == 1)
         {
            cout << "The determinant for Matrix B is " << B[0][0] << endl;
         }
         else if (rowb == 2)
         {
            double det;
            det = (B[0][0] * B[1][1]) - (B[1][0] * B[0][1]);
            cout << "The determinant for Matrix B is " << det << endl;
         }
         else if (rowb == 3)
         {
            double det;
            det = ((B[0][0]*((B[1][1]*B[2][2]) - (B[1][2]*B[2][1]))) - (B[0][1]*((B[1][0]*B[2][2]) - (B[1][2]*B[2][0]))) + (B[0][2]*((B[1][0]*B[2][1]) - (B[1][1]*B[2][0]))));
            cout << "The determinant for Matrix B is " << det << endl;
         }
         else
         {
            cout << "Out of the scope of this program!" << endl;
         }
      }
   }
   else
   {
      cout << "Invaild option!" << endl;
   }
}

void transpose() // function to find the trasnposed matrix
{
   cout << "Which Matrix would you like to transpose: " << endl;
   cout << "A or B?" << endl;
   cin >> d;
   
   if (d == 'A')
   {
      for (int i = 0; i < rowa; ++i)
      {
         for (int j = 0; j < cola; ++j)
         {
            tempC[j][i] = A[i][j];
         }
      }
      for (int i = 0; i < cola; ++i)
      {
         cout << "| ";
         for (int j = 0; j < rowa; ++j)
         {
            cout << tempC[i][j] << " ";
         }
         cout << "|" << endl;
      }
   }
   else if (d == 'B')
   {
      for (int i = 0; i < rowb; ++i)
      {
         for (int j = 0; j < colb; ++j)
         {
            tempD[j][i] = B[i][j];
         }
      }
      for (int i = 0; i < colb; ++i)
      {
         cout << "| ";
         for (int j = 0; j < rowb; ++j)
         {
            cout << tempD[i][j] << " ";
         }
         cout << "|" << endl;
      }
   }
   else
   {
      cout << "Invaild option!" << endl;
   }
}

void inverse() //function to find the inverse of a matrix || incomplete
{
   cout << "Which matrix would you like to find your inverse from: " << endl;
   cout << "A or B?" << endl;
   cin >> d;
   
   if(d == 'A')
   {
      int det;
      
      if (rowa!= cola)
      {
         cout << "The Matrix must be a square matrix!" << endl;
      }
      else
      {
         if (rowa == 1)
         {
            det = A[0][0];
         }
         if (rowa == 2)
         {
            det = (A[0][0] * A[1][1]) - (A[1][0] * A[0][1]);
         }
         if (rowa == 3)
         {
            det = ((A[0][0]*((A[1][1]*A[2][2]) - (A[1][2]*A[2][1]))) - (A[0][1]*((A[1][0]*A[2][2]) - (A[1][2]*A[2][0]))) + (A[0][2]*((A[1][0]*A[2][1]) - (A[1][1]*A[2][0]))));
         }
         if (det == 0)
         {
            cout << "The determinant is 0, this matrix is not invertible." << endl;
         }
         
         if (det != 0)
         {
            cout << "Inverse of matrix is: " << endl;
            
            if (rowa == 2)
            {
               tempC[0][0] = (A[1][1]) / det;
               tempC[0][1]   = (-A[0][1]) / det;
               tempC[1][1] = (A[0][0]) / det;
               tempC[1][0]   = (-A[1][0]) / det;
               
               for(int i = 0; i < rowa; i++)
               {
                  cout << "| ";
                  
                  for(int j = 0; j < cola; j++)
                  {
                     cout << fixed << setprecision(2) << right << setw(6) << tempC[i][j] << " ";
                  }
                  
                  cout << "|" << endl;
               }
            }
            if (rowa == 3)
            {
               for(int i = 0; i < rowa; i++)
               {
                  cout << "| ";
                  
                  for(int j = 0; j < cola; j++)
                  {
                     cout << fixed << setprecision(2) << right << setw(6) << " " <<
                     ((A[(j + 1) % cola][(i + 1) % rowa] * A[(j + 2) % cola][(i + 2) % rowa]) - (A[(j + 1) % cola][(i + 2) % rowa] * A[(j + 2) % cola][(i + 1) % rowa])) / det << " ";
                  }
                  
                  cout << "|" << endl;
               }
            }
         }
      }
   }
   else if(d == 'B')
   {
      
      int det;
      if (rowb!= colb)
      {
         cout << "The Matrix must be a square matrix!" << endl;
      }
      else
      {
         if (rowb == 1)
         {
            det = B[0][0];
         }
         if (rowa == 2)
         {
            det = (B[0][0] * B[1][1]) - (B[1][0] * B[0][1]);
         }
         if (rowa == 3)
         {
            det = ((B[0][0]*((B[1][1]*B[2][2]) - (B[1][2]*B[2][1]))) - (B[0][1]*((B[1][0]*B[2][2]) - (B[1][2]*B[2][0]))) + (B[0][2]*((B[1][0]*B[2][1]) - (B[1][1]*B[2][0]))));
         }
         if (det == 0)
         {
            cout << "The determinant is 0, this matrix is not invertible." << endl;
         }
         
         if (det != 0)
         {
            cout << "Inverse of matrix is: " << endl;
            
            if (rowb == 2)
            {
               tempD[0][0] = (B[1][1]) / det;
               tempD[0][1]   = (-B[0][1]) / det;
               tempD[1][1] = (B[0][0]) / det;
               tempD[1][0]   = (-B[1][0]) / det;
               
               for(int i = 0; i < rowb; i++)
               {
                  cout << "| ";
                  
                  for(int j = 0; j < colb; j++)
                  {
                     cout << fixed << setprecision(2) << right << setw(6) << tempD[i][j] << " ";
                  }
                  
                  cout << "|" << endl;
               }
            }
            if (rowb == 3)
            {
               for(int i = 0; i < rowb; i++)
               {
                  cout << "| ";
                  
                  for(int j = 0; j < colb; j++)
                  {
                     cout << fixed << setprecision(2) << right << setw(6) << " " <<
                     ((B[(j + 1) % colb][(i + 1) % rowb] * B[(j + 2) % colb][(i + 2) % rowb]) - (B[(j + 1) % colb][(i + 2) % rowb] * B[(j + 2) % colb][(i + 1) % rowb])) / det << " ";
                  }
                  
                  cout << "|" << endl;
               }
            }
         }
      }
   }
   else
   {
      cout << "Invaild option!" << endl;
   }
}

void addition() //function to add two matrices
{
   
   if (rowa == rowb && cola == colb)
   {
      cout << "Matrix A + Matrix B is:" << endl;
      
      for (int i = 0; i < rowa; i++)
      {
         cout << "| ";
         for (int j = 0; j < cola; j++)
         {
            cout << (A[i][j] + B[i][j]) << " ";
         }
         cout << " |" << endl;
      }
      
   }
   else
   {
      cout << "Matrices must both be same sizes!" << endl;
   }
}

void subtraction() //function to subtract two matrices
{
   if (rowa == rowb && cola == colb)
   {
      cout << "Matrix A - Matrix B is:" << endl;
      
      for (int i = 0; i < rowa; i++)
      {
         cout << "| ";
         for (int j = 0; j < cola; j++)
         {
            cout << (A[i][j] - B[i][j]) << " ";
         }
         cout << " |" << endl;
      }
   }
   else
   {
      cout << "Matrices must both be same sizes!" << endl;
   }
}

void multiply() //function to multiply two matrices
{
   if (cola == rowb)
   {
      for(int i = 0; i < rowa; ++i)
      {
         for(int j = 0; j < colb; ++j)
         {
            for(int k = 0; k < cola; ++k)
            {
               tempA[i][j] += A[i][k] * B[k][j];
            }
            
         }
      }
      for (int i = 0; i < rowa; ++i)
      {
         cout << "| ";
         for (int j = 0; j < colb; ++j)
         {
            cout << tempA[i][j] << " " ;
         }
         cout << "|" << endl;
      }
      
   }
   else
   {
      cout << "Dimensions does not allow multiplication!" << endl;
   }
   
}

void power() //function to find the power of a matrix
{
   char d;
   int pwr;
   cout << "Which matrix's power would you like to find?" << endl;
   cin >> d;
   cout << "Power of?" << endl;
   cin >> pwr;
   
   if(d == 'A')
   {
      if (cola == rowa)
      {
         if (pwr == 1)
         {
            for (int i = 0; i < rowa; ++i)
            {
               cout << "| ";
               for (int j = 0; j < cola; ++j)
               {
                  cout << A[i][j] << " " ;
               }
               cout << "|" << endl;
            }
         }
         else if (pwr == 2)
         {
            for(int i = 0; i < rowa; ++i)
            {
               for(int j = 0; j < cola; ++j)
               {
                  for(int k = 0; k < cola; ++k)
                  {
                     tempA[i][j] += A[i][k] * A[k][j];
                  }
                  
               }
            }
            for (int i = 0; i < rowa; ++i)
            {
               cout << "| ";
               for (int j = 0; j < cola; ++j)
               {
                  cout << tempA[i][j] << " " ;
               }
               cout << "|" << endl;
            }
         }
      }
      else
      {
         cout << "Invalid. # of Rows must match # of columns.";
      }
    }

   else if (d == 'B')
   {
      if (colb == rowb)
      {
         if (pwr == 1)
         {
            for (int i = 0; i < rowb; ++i)
            {
               cout << "| ";
               for (int j = 0; j < colb; ++j)
               {
                  cout << B[i][j] << " " ;
               }
               cout << "|" << endl;
            }
         }
         else if (pwr == 2)
         {
            for(int i = 0; i < rowb; ++i)
            {
               for(int j = 0; j < colb; ++j)
               {
                  for(int k = 0; k < colb; ++k)
                  {
                     tempB[i][j] += B[i][k] * B[k][j];
                  }
                  
               }
            }
            for (int i = 0; i < rowb; ++i)
            {
               cout << "| ";
               for (int j = 0; j < colb; ++j)
               {
                  cout << tempB[i][j] << " " ;
               }
               cout << "|" << endl;
            }
         }
      }
      else
      {
         cout << "Invalid. # of Rows must match # of columns.";
      }
   }
}

int cont()
{
   cout << "What would you like to do?" << endl;
   cout << "[1] Continue with current matrices" << endl;
   cout << "[2] Exit\n" << endl;
   cout << "Enter the number of your option []: ";
   cin >> opt;
   
   return opt;
}
