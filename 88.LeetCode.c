void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int res[m+n];
    int max = m+n;
    int i = m, j = n, p1 = 0, p2 = 0, top = 0;
    

    while (i > 0 || j > 0){
        if (i > 0 && j > 0){
            if (nums1[p1] <= nums2[p2]) {
                res[top] = nums1[p1];
                top++;
                p1++;
                i--;
            } else {
                res[top] = nums2[p2];
                top++;
                p2++;
                j--;
            }
        } else {
            if (i > 0) {
                res[top] = nums1[p1];
                top++;
                p1++;
                i--;
            } else {
                if (j > 0) {
                    res[top] = nums2[p2];
                    top++;
                    p2++;
                    j--;
                }
            }
        }
    }
    for (i = 0; i < max; i++) {
        nums1[i] = res[i];
    }
}
