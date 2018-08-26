/*
file   : numeric_triangle.cpp
author : zyl
date   : 18-8-27
locat  : whu.edu.ionosphereLab
ref    : https://blog.csdn.net/baidu_28312631/article/details/47418773

description:
        7
       3 8
      8 1 0
     2 7 4 4
    4 5 2 6 5
    
    在上面的数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。
    路径上的每一步都只能往左下或 右下走。只需要求出这个最大和即可，不必给出具体路径。
    三角形的行数大于1小于等于100，数字为 0-99
*/

#include <iostream>
#include <algorithm>

using namespace std;

// 递归方法
int maxSum(int *arr, int size, int row, int clu)
{
    if (row== size-1)
    {
        return *(arr + size*row +clu);
    }
    else
    {
        return *(arr + size*row + clu) + max(maxSum( arr, size,row + 1,clu), maxSum(arr, size ,row + 1, clu+1));
    }
}

// 递推方法
int maxSum(int *arr, int size)
{
    int *M = new int[size*size];
    memcpy(M + size*(size - 1), arr + size*(size - 1), size*sizeof(int));

    for (int c = size-2; c >= 0; c--)
    {   
        for (int r = 0; r <= c; r++)
        {
            // M[c][r] = D[c][r] + max(M[c+1][r], M[c+1][r+1]);
            *(M + c*size + r) = *(arr + c*size + r) + max(*(M + (c + 1)*size + r), *(M + (c + 1)*size + r + 1));
        }
    }

    int result = *(int *)M;

    delete[] M;
    return result;
}


int main()
{
    int D[5][5] = {0};

    D[0][0] = 7;
    D[1][0] = 3; D[1][1] = 8;
    D[2][0] = 8; D[2][1] = 1; D[2][2] = 0;
    D[3][0] = 2; D[3][1] = 7; D[3][2] = 4; D[3][3] = 4;
    D[4][0] = 4; D[4][1] = 5; D[4][2] = 2; D[4][3] = 6; D[4][4] = 5;

    cout << maxSum((int *)D,5,0,0)<<endl;
    cout << maxSum((int *)D,5) << endl;

    system("pause");
    return 0;
}
