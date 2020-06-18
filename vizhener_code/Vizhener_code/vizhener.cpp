#include "vizhener.h"

Vizhener::Vizhener()
{

}


QString Vizhener::encrypt(QString text, QString key){
	QString encrypted = "";
	for(int i = 0; i < text.length();){
		for(int j = 0; j < key.length() && i < text.length(); ++j, ++i){
			encrypted += (text[i].toLatin1() - 97 + key[j].toLatin1() - 97) % 26 + 97;
		}
	}

	return encrypted;
}


QString Vizhener::decrypt(QString text, QString key){
	QString decrypted = "";
	for(int i = 0; i < text.length();){
		for(int j = 0; j < key.length() && i < text.length(); ++j, ++i){
			int ch = (text[i].toLatin1() - 97) - (key[j].toLatin1() - 97);
			if(ch < 0){
				decrypted += 26 + ch + 97;
			}
			else{
				decrypted += ch + 97;
			}
		}
	}
	return decrypted;
}
