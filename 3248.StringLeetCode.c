int finalPositionOfSnake(int n, char** commands, int commandsSize) {
    short int i,j;
    short int snake = 0;

    for (i=0;i < commandsSize;i++) {
        if (commands[i][0] == 'D') {
            snake = snake + n;
        }else{
            if (commands[i][0] == 'U') {
                snake = snake - n;
            }else{
                if (commands[i][0] == 'R') {
                    snake++;
                }else{
                    if (commands[i][0] == 'L') {
                        snake--;
                    }
                }
            }
        }
    }
    return snake;
}
