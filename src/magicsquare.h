#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H

int ** generateMagicSquare(int n)
{
    int **magic_square = new int* [n];
    for (auto i = 0; i < n; i++) {
        magic_square[i] = new int[n];
    }
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < n; j++) {
            magic_square[i][j] = 0;
        }
    }

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        }
        else {
            if (j == n) {
                j = 0;
            }
            if (i < 0) {
                i = n - 1;
            }
        }
        if (magic_square[i][j]) {
            j -= 2;
            i++;
            continue;
        }
        else {
            magic_square[i][j] = num++;
        }
        j++;
        i--;
    }
    return magic_square;
}

#endif // MAGICSQUARE_H
