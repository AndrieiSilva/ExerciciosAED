int scoreOfString(char* s) {
    int i,res = 0;
    for (i=0;i < strlen(s)-1;i++) {
        res += abs(s[i] - s[i + 1]);

    }
    return res;
}
