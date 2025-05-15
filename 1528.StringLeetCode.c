char* restoreString(char* s, int* indices, int indicesSize) {
    char s2[indicesSize+1];
    int i;
    strcpy(s2,s);
    for (i=0;i < indicesSize; i++) {
        s[indices[i]] = s2[i];
    }

    return s;
}
