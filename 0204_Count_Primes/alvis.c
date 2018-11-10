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
int sieve_of_Eratosthenes(int count);

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

int sieve_of_Eratosthenes(int count)
{
    int  max_number = count;
    int  times_of_number;
    int  prime_count = 0;
    bool all_number[count+1];
    
    if(count < 2)
    {
        return prime_count;
    }
    
    memset(all_number, true, count*sizeof(bool));
    
    for(int number = 2; number*number <= max_number; number++)
    {
        if(all_number[number])
        {
            for(times_of_number = 2; times_of_number*number <= max_number; times_of_number++)
            {
                all_number[number*times_of_number] = false;
            }
            
            if(max_number == times_of_number*number)
            {
                for(int backward = max_number; backward == 0; backward--)
                {
                    if(all_number[backward])
                    {
                        max_number = backward;
                        break;
                    }
                }
            }
        }
    }
//    number 0 and 1 aren't prime
    for(int number = 2; number < count; number++)
    {
        if(all_number[number])
        {
            prime_count++;
        }
    }
    
    return prime_count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("sum is %d\n", prime_count(10));
    printf("sieve is %d\n", sieve_of_Eratosthenes(10));

    return 0;
}

