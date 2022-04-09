#ifndef TEXTENCRYPTOR_H
#define TEXTENCRYPTOR_H

#include <QString>
#include <QVector>

class TextEncryptorImpl
{
public:
    TextEncryptorImpl() = default;
    QString encrypt(const QString text);
    QString decrypt(const QString text);
private:
    QString text;
    QString encrypted_text;
};

class TextEncryptor
{
public:
    TextEncryptor()
    {
        m_implementation = new TextEncryptorImpl;
    };
    QString encrypt(const QString text)
    {
        return m_implementation->encrypt(text);
    };
    QString decrypt(const QString text)
    {
        return m_implementation->decrypt(text);
    }
    ~TextEncryptor()
    {
        delete m_implementation;
    }
private:
    TextEncryptorImpl *m_implementation;
};

#endif // TEXTENCRYPTOR_H
