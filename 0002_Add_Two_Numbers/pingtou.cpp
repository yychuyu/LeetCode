//
// Created by pingtou on 18-11-8.
//
#include <iostream>
#include <cstdlib>
int HammingDistance(int x,int y)
{
    int num = 0;
    x = x ^ y;
    while(x)
    {
      if(x & 1)
      {
        num++;
      }
      x = x>>1;
    }
    return num;
}

int main(int argc,char *argv[]){
  int x=atoi(argv[1]),y=atoi(argv[2]);
  std::cout << HammingDistance(x,y) << std::endl;
  return 0;
}
