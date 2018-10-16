//
//  main.c
//  prime count
//
//  Created by Alvis Yang on 2018/10/16.
//  Copyright © 2018 Alvis Yang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int prime_count(int count);

int prime_count(int count) {
    //    1 isn't prime
    int number    = 2;
    int prime_idx = 0;
    int all_prime[count];
    bool found = false;
    
    memset(all_prime, 0, sizeof(int)*count);
    
    for (number; number <= count; number++)
    {
        found = false;
        for(int cur_prime = 0; cur_prime <= prime_idx; cur_prime++)
        {
            if (all_prime[cur_prime] == 0)
            {
                continue;
            }
            
            if (number%all_prime[cur_prime] == 0)
            {
//                printf("%d can be divide to zero by %d\n", number, all_prime[cur_prime]);
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            printf("new prime %d\n", number);
            prime_idx++;
            all_prime[prime_idx] = number;
        }
    }
    
    printf("total number is %d\n", prime_idx);
    return prime_idx++;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("sum is %lld\n", prime_count(10));
    return 0;
}

