#pragma once
#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <iostream>
#include <string>

class ENCRYPTION //// An abstract class for encryption, implementing Caesar Cipher Algorithm ////
{
	public:
		virtual void ENCRYPT(const string& FILE_NAME) = 0;
};

class DECRYPTION //// An abstract class for encryption, implementing Caesar Cipher Algorithm ////
{
public:
	virtual void DECRYPT(const string& FILE_NAME) = 0;
};
#endif /* CAESAR_CIPHER_H */