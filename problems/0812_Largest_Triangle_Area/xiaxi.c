#include <stdio.h>
#include <math.h>

double largestTriangleArea(int** points, int pointsRowSize, int pointsColSize) {
    double S = 0.0;
    int i,j,k;
    int x1,x2,x3,y1,y2,y3;
    double max = 0;
    for(i=0;i<pointsRowSize;i++)
    {
        x1 = *((int *)points +i*pointsColSize);
        y1 = *((int *)points +i*pointsColSize + 1);
        for(j=i+1;j<pointsRowSize;j++)
        {
            x2 = *((int *)points +j*pointsColSize);
            y2 = *((int *)points +j*pointsColSize + 1);
            for(k=j+1;k<pointsRowSize;k++)
            {
                x3 = *((int *)points +k*pointsColSize);
                y3 = *((int *)points +k*pointsColSize + 1);
                S = ((x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y1-x1*y3)) / 2;
                S = fabs(S);
                if(S > max)
                    max = S;
            }
        }
    }
    return max;
}

int main(){
    double max;
    int points[5][2] = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    max = largestTriangleArea((int **)points,5,2);
    printf("%.2f\n",max);
}

