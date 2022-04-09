#include "textencryptor.h"
#include "magicsquare.h"

#include <QtMath>


QString TextEncryptorImpl::encrypt(const QString text)
{
    auto size = text.length();
    auto n = qCeil(qSqrt(size));

    n += (n % 2) ? 0 : 1;
    int **magic_square = generateMagicSquare(n);

    for (qsizetype i = 0; i < n; i++) {
        for (qsizetype j = 0; j < n; j++) {
            auto index = magic_square[i][j];

            if (index <= size) {
                encrypted_text += text[index-1];
            }
        }
    }
    for (qsizetype i = 0; i < n; i++) {
        delete[] magic_square[i];
    }
    delete[] magic_square;

    return encrypted_text;
}

QString TextEncryptorImpl::decrypt(const QString text)
{
    auto size = text.length();
    auto n = qCeil(qSqrt(size));

    n += (n % 2) ? 0 : 1;
    int **magic_square = generateMagicSquare(n);

    encrypted_text.resize(size);
    int cnt = 0;
    for (qsizetype i = 0; i < n; i++) {
        for (qsizetype j = 0; j < n; j++) {
            auto index = magic_square[i][j];

            if (index <= size) {
                encrypted_text[index-1] = text[cnt++];
            }
        }
    }

    for (qsizetype i = 0; i < n; i++) {
        delete[] magic_square[i];
    }
    delete[] magic_square;

    return encrypted_text;

}
