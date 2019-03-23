//
//  main.c
//  00263_ugly_number
//
//  Created by Alvis Yang on 2018/10/16.
//  Copyright © 2018 Alvis Yang. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#define array_count(array) sizeof(array)/sizeof(array[0])

bool is_ugly_number(int input);

bool is_ugly_number(int input)
{
    int res = input;
    int ugly_idx = 0;
    int ugly_element[3] = {5, 3, 2};
    
    if(input <= 0)
        return false;
    
    while(res != 1 && ugly_idx < array_count(ugly_element))
    {
        if(res%ugly_element[ugly_idx] == 0)
        {
            res = res/ugly_element[ugly_idx];
        }
        else
        {
            ugly_idx++;
        }
    }
    
    return res==1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    bool result = is_ugly_number(21);
    
    if (result)
        printf("Hello, Ugly number!\n");
    else
        printf("Don't worry, you are so pretty\n");
        
    return 0;
}
