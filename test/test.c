char mapearParaLetra(char *bloco) {
         if (strcmp(bloco, "AAA") == 0) return 'A';
    else if (strcmp(bloco, "AAC") == 0) return 'B';
    else if (strcmp(bloco, "AAG") == 0) return 'C';
    else if (strcmp(bloco, "AAT") == 0) return 'D';
    else if (strcmp(bloco, "ACA") == 0) return 'E';
    else if (strcmp(bloco, "ACC") == 0) return 'F';
    else if (strcmp(bloco, "ACG") == 0) return 'G';
    else if (strcmp(bloco, "ACT") == 0) return 'H';
    else if (strcmp(bloco, "AGA") == 0) return 'I';
    else if (strcmp(bloco, "AGC") == 0) return 'J';
    else if (strcmp(bloco, "AGG") == 0) return 'K';
    else if (strcmp(bloco, "AGT") == 0) return 'L';
    else if (strcmp(bloco, "ATA") == 0) return 'M';
    else if (strcmp(bloco, "ATC") == 0) return 'N';
    else if (strcmp(bloco, "ATG") == 0) return 'O';
    else if (strcmp(bloco, "ATT") == 0) return 'P';
    else if (strcmp(bloco, "CAA") == 0) return 'Q';
    else if (strcmp(bloco, "CAC") == 0) return 'R';
    else if (strcmp(bloco, "CAG") == 0) return 'S';
    else if (strcmp(bloco, "CAT") == 0) return 'T';
    else if (strcmp(bloco, "CCA") == 0) return 'U';
    else if (strcmp(bloco, "CCC") == 0) return 'V';
    else if (strcmp(bloco, "CCG") == 0) return 'W';
    else if (strcmp(bloco, "CCT") == 0) return 'X';
    else if (strcmp(bloco, "CGA") == 0) return 'Y';
    else if (strcmp(bloco, "CGC") == 0) return 'Z';
    else if (strcmp(bloco, "CGG") == 0) return '0';
    else if (strcmp(bloco, "CGT") == 0) return '1';
    else if (strcmp(bloco, "CTA") == 0) return '_';
    // ...
    else return ' '; // Retorna espaço se o bloco não mapear para uma letra
}