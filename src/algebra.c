#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.rows==b.rows && a.cols==b.cols)
    {
        Matrix c= create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++)
        {
                for(int j=0;j<a.cols;j++)
                {
                    c.data[i][j]=a.data[i][j]+b.data[i][j];
                }
        }
        print_matrix(c);
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.");
    }
    

    return create_matrix(0, 0);
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.rows==b.rows && a.cols==b.cols)
    {
        Matrix c= create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++)
        {
                for(int j=0;j<a.cols;j++)
                {
                    c.data[i][j]=a.data[i][j]-b.data[i][j];
                }
        }
        print_matrix(c);
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.");
    }
    
    return create_matrix(0, 0);
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.cols==b.rows)
    {
        Matrix c= create_matrix(a.rows,b.cols);
        for(int i=0;i<a.rows;i++)
        {
                for(int j=0;j<b.rows;j++)
                {
                    for(int k=0;k<a.cols;k++)
                    {
                        c.data[i][j]+=a.data[i][k]*b.data[k][j];
                    }
                }
        }
        print_matrix(c);
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.");
    }
    return create_matrix(0, 0);
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    
        Matrix b= create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++)
        {
                for(int j=0;j<a.cols;j++)
                {
                    b.data[i][j]=a.data[i][j]*k;
                }
        }
        print_matrix(b);
    
    return create_matrix(0, 0);
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    Matrix b= create_matrix(a.rows,a.cols);
        for(int i=0;i<a.rows;i++)
        {
                for(int j=0;j<a.cols;j++)
                {
                    b.data[i][j]=a.data[j][i];
                }
        }
        print_matrix(b);
    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    // ToDo
    double sum=0;
    if (a.rows==a.cols&&a.rows>2)
    {
        Matrix b= create_matrix(a.rows-1,a.cols-1); /*取第一行*/
        
      
        for(int i=0;i<a.rows;i++)
        {
            for(int j=0;j<a.rows-1;j++)
            {
                for(int k=0;k<a.rows-1;k++){
                    if (j<i)
                    {
                        b.data[i][j]=a.data[i+1][j];
                    }
                   else
                   {
                        b.data[i][j]=a.data[i+1][j+1];
                   }
                }
            }
            sum=a.data[0][i]*pow(-1,i)*det_matrix(b);
                
        }
        
        
    }
    else if (a.rows=2)
    {
        sum=a.data[0][0]*a.data[1][1]-a.data[1][0]*a.data[0][1];
    }
    else if (a.rows=1)
    {
        sum=a.data[0][0];
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.");
    }
    return sum;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}