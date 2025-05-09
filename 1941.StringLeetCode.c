bool areOccurrencesEqual(char* s) {
    char sc[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    int num[27];
    int i,j;
    int v=1;
    int a = 0;
    for (i=0;i < 26;i++){
        num[i] = 0;
    }
    num[26] = '\0';
    for (i=0;i < 26;i++){
        for (j=0;j <= strlen(s);j++){
            if (s[j] == sc[i]){
                num[i]++;
            }
        }
    }

    if (v){
        for (i=0;i < 26 && v == 1;i++){
            if (num[i] > 0){
                if (a == 0){
                    a = num[i];
                }else{
                    if (a == num[i]){
                           v=1;
                    }else{
                        v=0;
                    }
                }
            }
        }
    }
    if (v == 1){
        return true;
    }else{
        return false;
    }
}
