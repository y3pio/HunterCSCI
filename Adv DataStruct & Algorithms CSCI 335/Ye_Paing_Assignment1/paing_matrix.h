/**********************************************************************
 Title:         : paing_matrix.h
 Author         : Ye Paing
 Created on     : 9/4/2012
 Description    : Assignment 1 for CSCI335 Spring'13
 Purpose        : Header file for our own Matrix STL.
 Usage          : ./assignment1.exe OR with makefile: "make all"
 Build with     : g++ paing_* -o paing.exe
 Modification   : -
 Comments	: -
 **********************************************************************/
//Defining matrix 
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <class T>
class matrix
{
    public:
        //Default cTor
        matrix()
        {
            rows=0;
            cols=0;
        }
        //ccTor
        matrix(const matrix& other)
        {
            rows=other.rows;
            cols=other.cols;
            arry = new T*[rows];

            for(int i=0; i<rows; i++)
                arry[i]=new T[cols];

            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                {
                    arry[i][j]=other.arry[i][j];
                }
        }

	//cTor for user defined (x,y) dimensons;
        matrix(int x, int y)
        {
            rows=x;
            cols=y;
            arry = new T*[rows];

            for(int i=0; i<rows; i++)
                arry[i]=new T[cols];
        }

        //dTor
        ~matrix()
        {
            for(int i=0; i<rows; i++)
            {
                delete arry[i];
            }
            delete arry;
        }

        // = Overload
        const matrix& operator=(const matrix& other) //a=a+c assume a is *this
        {
            if(rows==0 && cols==0)//if the left hand side is 0x0 matrix.
            {
                rows=other.rows; //Set new matrix dimensions and create dynamic matrix.
                cols=other.cols;
                arry = new T*[rows];
                for(int i=0; i<rows; i++)
                    arry[i]=new T[cols];
            }

	    //If matrix dimensions are not the same.
            else if(rows!=other.rows || cols!=other.cols)
            {
                cout << "matrixDimensionErrorException" << endl; //Print error message.
                return *this; //Return *this matrix object unchanged.
            }

	    //If program gets to here it means both matrices have equal dimensions.
            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                {
                    arry[i][j]=other.arry[i][j]; //Double nested for loop to copy elements.
                }
            return *this; //Return the modified LHS matrix object after.
        }

        // + Overload
        const matrix operator+(const matrix& other)
        {
            if(rows!=other.rows || cols!=other.cols)
            {
                cout << "matrixDimensionErrorException" << endl;
                return *this;
            }

            matrix<int> temp(other.rows, other.cols);

            T **tempArry; //temp arry to store product. AxB * CxD = AxD result
            tempArry=new T*[rows+other.rows];
            for(int i=0; i<rows; i++)
                tempArry[i]=new T[cols+other.cols];

	    //These output statements below are for testing purpose.
            //cout << "\n\nRows:" << rows << "   Cols:" << cols << endl;
            //cout << "otherRows:" << other.rows << "    otherCols:" << other.cols << endl;

            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                {
                    tempArry[i][j]= arry[i][j] + other.arry[i][j];
                }

            for(int i=0; i<rows; i++)
                for(int j=0; j<other.cols; j++)
                    temp.arry[i][j]=tempArry[i][j];

            return temp;
        }

        // * Overload
        const matrix operator*(const matrix& other)//Check matrix multiplication
        {
            if(cols!=other.rows) // (A x B) * (C x D), B must equal to C, result is A x D matrix
            {
                cout << "matrixMultiplicationDimensionException" << endl;
                //cout << rows << "x" << cols << " - " << other.rows << "x" << other.cols << endl;
                return *this;
            }

            //cout << "ECHO SEG FAULT!!" << endl;
            matrix<int> temp(rows,other.cols);

            T **tempArry; //temp arry to store product. AxB * CxD = AxD result
            tempArry=new T*[rows+other.rows];
            for(int i=0; i<rows; i++)
                tempArry[i]=new T[cols+other.cols]; //Building temp matrix.

	    //Setting all elements in temp to 0 (not really needed?)
            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                    tempArry[i][j]=0;

	    //Multiplication for loops.
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    for(int k=0; k<other.rows; k++)
                    {
                        //Output for testing purpose
                        //cout << arry[i][k] << " x " << other.arry[k][j] << " = " << arry[i][k]*other.arry[k][j] << endl;
                        tempArry[i][j]+=arry[i][k]*other.arry[k][j];
                    }
                    //cout << "Total sum:" << tempArry[i][j] << endl;
                }
            }

            for(int i=0; i<rows; i++)
                for(int j=0; j<other.cols; j++)
                    temp.arry[i][j]=tempArry[i][j];

            return temp; //Return the new resulting matrix. Both previous 2 matrices remain unchanged.
        }

        //Overload * for scalar multiplication.
        friend const matrix& operator*(int x, const matrix& other)
        {
           
            for(int i=0; i<other.rows; i++)
                for(int j=0; j<other.cols; j++)
                {
		    //Output for testing purpose only.
                    //cout << other.arry[i][j] << " x " << x << " =" << other.arry[i][j]*x << endl;
                    other.arry[i][j]=other.arry[i][j]*x;
                }

            return other;
        }

        // += Overload
        const matrix& operator+=(const matrix& other)
        {
            if(rows!=other.rows || cols!=other.cols)
                {
                    cout << "matrixDimensionErrorException" << endl;
                    return *this;
                }

		//Output for testing purpose only.
                //cout << "\n\nRows:" << rows << "   Cols:" << cols << endl;
                //cout << "otherRows:" << other.rows << "    otherCols:" << other.cols << endl;

                for(int i=0; i<rows; i++)
                    for(int j=0; j<cols; j++)
                    {
                        arry[i][j] = arry[i][j] + other.arry[i][j];
                    }
                return *this;
        }

        const T* operator[](int num)const
        {
            return arry[num];
        }

        T* operator[](int num)
        {
            return arry[num];
        }

        // I/O Overloading

        friend ostream& operator<< (ostream &output,const matrix& obj)
        {
		output << "["; //Output first brackets.
                for(int i=0; i<obj.rows; i++)
                {
		    if(i!=0)
			output << " "; //Leave spaces for other rows.
                    for(int j=0; j<obj.cols; j++)
                    {
			if(i==obj.rows-1 && j==obj.cols-1)
			{
			    output << obj.arry[i][j] << "]"; //Bracket output statement for last element.
			}
			else
                            output << obj.arry[i][j] << " "; //All other element output.
                    }
                    output << endl;
                }
		output << endl;
                return output;
        };

        friend const istream& operator>> (istream &input, matrix<T> &obj)
        {
	    //Set buffer to first input for first bracket: [x x x x ...
	    string buffer="";
            input >> buffer;
	    buffer=buffer.substr(1);
	    obj.rows=atoi(buffer.c_str());
            
	    input >> obj.cols;
            obj.arry = new T*[obj.rows];
            for(int i=0; i<obj.rows; i++)
                obj.arry[i] = new T[obj.cols];

            for(int i=0; i<obj.rows; i++)
                for(int j=0; j<obj.cols; j++)
                {
		    if(i==obj.rows-1 && j==obj.cols-1)//if it's the last element
		    {
			//Use buffer to clean up last bracket: ...x x x]
                        input >> buffer;
			buffer=buffer.substr(0,buffer.length()-1);
                        obj.arry[i][j]=atoi(buffer.c_str());
		    }
		    else
                        input >> obj.arry[i][j]; //Regular input for other elements.
                }
            return input;
        };

        // Accessor functions for rows/columns dimension.
        int numrows()
        {
            return rows;
        }
        int numcols()
        {
            return cols;
        }

    private:
        int rows, cols; //rows and cols store matrix dimension.
        T **arry;	//Dynamic array to store elements of 2D matrix.
};

#endif // MATRIX_H
//End matrix def.
