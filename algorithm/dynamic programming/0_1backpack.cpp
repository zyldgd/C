/*
file   : 0_1backpack.cpp
author : zyl
date   : 18-8-26
locat  : whu.edu.home
ref    : https://baike.baidu.com/item/01%E8%83%8C%E5%8C%85 

description:
        One of the problems solved by the greedy algorithm.
        the problem is to take away the most valuable things. but the capacity of your backpack is limited(1-100), 
    and those valuable things have different values and weights. now, you should find a way to chose them and 
    make total value highest.
    

*/

#include <iostream>
#include <algorithm>

#define NUM 100

using namespace std; 

void show(int *arr,int h,int w)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%5d", (int)*(arr+i*w+j));
        }
        printf("\n");
    }
}

int main()
{
    // start with 1, align with index
    int W[NUM] = {0, 1, 3, 2, 4, 5 }; // weight
    int V[NUM] = {0, 3, 5, 6, 2, 5 }; // value
    int C = 10;                       // capacity
    int M[7][11] = { 0 };             // SUM(values)

    /*
    M[j][i] --- M[5][10]

    +---+---+---+---+---+---+---+---+---+---+---+---+
    |   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|  i
    +---+---+---+---+---+---+---+---+---+---+---+---+
    | 1 |   |   |   |   |   |   |   |   |   |   |MAX|
    +---+---+---+---+---+---+---+---+---+---+---+---+
    | 2 |   |   |   |   |   |   |   |   |   |   |   |
    +---+---+---+---+---+---+---+---+---+---+---+---+
    | 3 |   |   |   |   |   |   |   |   |   |   |   |
    +---+---+---+---+---+---+---+---+---+---+---+---+
    | 4 |   |   |   |   |   |   |   |   |   |   |   |
    +---+---+---+---+---+---+---+---+---+---+---+---+
    | 5 |   |   |   |   |   |   |   |   |   |   |   |
    +---+---+---+---+---+---+---+---+---+---+---+---+
      j
    */
        
    for (int j = 5; j > 0; j--)// j [5-1]
    {
        for (int i = 1; i <= C; i++)// i [0-10]
        {
            if (i>=W[j])
            {
                 M[j][i] = max(M[j + 1][i], M[j + 1][i - W[j]] + V[j]);
            }
        }
    }

    show(&M[0][0], 7, 11);
    printf("MAX VALUE = %d \n", M[1][10]);
    system("pause");
    return 0;
}

