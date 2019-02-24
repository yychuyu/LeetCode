int findComplement(int num) {
    int temp = num;
    int mask = 1;
    
    while (temp > 0) {
        temp = temp >> 1;
        mask = mask << 1;
    }
    mask--;

    return ~num & mask;
}
