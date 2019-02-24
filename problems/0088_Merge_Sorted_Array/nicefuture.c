void insert(int* arr, int len, int index, int tar) {  //assume that the space is enough
    int i;
    for (i = len; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[i] = tar;
}

void merge(int* nums1, int m, int* nums2, int n) {
    int i = 0, j = 0;
    while(i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            insert(nums1, m, i, nums2[j]);
            m++;
            i++;
            j++;
        }
        else {
            insert(nums1, m, i+1, nums2[j]);
            m++;
            i++;
            j++;
        }
    }
    while(j < n) {
        nums1[i] = nums2[j];
        i++;
        j++;
    }
}
