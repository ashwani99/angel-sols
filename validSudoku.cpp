int validateSubBox(const vector<string> &A, int i, int j) {
    int hashTable[10] = {0};
    
    for (int x = 0; x < 9; x++) {
        if (A[i][x] == '.')
            continue;
        if (hashTable[A[i][x]-'0'])
            return 0;
        hashTable[A[i][x]-'0'] = 1;
    }
    
    memset(hashTable, 0, sizeof(hashTable[0])*10);
    for (int x = 0; x < 9; x++) {
        if (A[x][j] == '.')
            continue;
        if (hashTable[A[x][j]-'0'])
            return 0;
        hashTable[A[x][j]-'0'] = 1;
    }
    
    memset(hashTable, 0, sizeof(hashTable[0])*10);
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            int p = i/3*3+x;
            int q = j/3*3+y;
            if (A[p][q] == '.')
                continue;
            if (hashTable[A[p][q]-'0'])
                return 0;
            hashTable[A[p][q]-'0'] = 1;
        }
    }
    return 1;
}

int Solution::isValidSudoku(const vector<string> &A) {
    if (A.size() != 9) 
        return 0;
    for (int i = 0; i < 9; i++) {
        if (A[i].length() != 9) 
            return 0;
        for (int j = 0; j < 9; j++) {
            if (validateSubBox(A, i, j) == 0)
                return 0;
        }
    }
    return 1;
}

