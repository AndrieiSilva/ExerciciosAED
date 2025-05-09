int percentageLetter(char* s, char letter) {
    int num_letter;
    int i;
    float qt_letter = 0,result;
    for (i=0;i <= strlen(s);i++) {
        if (s[i] == letter) {
            qt_letter++;
        }
    }

    return qt_letter*100/strlen(s);

}
