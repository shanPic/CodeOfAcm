    void readstring( *c){
        for(;*buf=='\n'||*buf=='\t'||*buf==' ';buf++);
        while(((*buf!='\n')&&(*buf!='\t')&&(*buf!=' '))){*(c++)=*(buf++);}
        *c=0;
    }
