void reverseString(char* s, int sSize) {
    char string[sSize], b;
    int i;
    for (i=0;i < sSize;i++){
        string[(sSize -1) - i] = s[i];
    }
    for (i=0; i < sSize;i++){
    s[i] = string[i];
    }
}
