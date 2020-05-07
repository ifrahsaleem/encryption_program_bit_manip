#include <iostream>
#include <string>
using namespace std;

void Permute(unsigned char & n, int p, int b) //Given a number n, a position p and a binary value b, 
	                            //we need to change the bit at position p in n to value b.
{ 
    int mask = 1 << p; 
    n = (n & ~mask) | ((b << p) ); 
} 

int getBit(unsigned char byte, int position) // position in range 0-7 // get bit at position of char 
{
    return (byte >> position) & 0x1;
}

string Encrypt(string enc_key, string plaintext) //function that encrypts code 
{ 
	int j = 0;
	string ciphertext = "";
	string temp = plaintext;
	for(unsigned int i=0; i<plaintext.length();i++) //iterating over plaintext
	{
		unsigned char ch = plaintext[i];
		unsigned char t = temp[i];
		for (unsigned int k = 0; k < 8; k++)// iterating over bits of plaintext char 
		{
			switch(k) //where k is the bit position
			{
			case 0:
				{
					Permute(ch,2,getBit(t,0));
					plaintext[i] = ch;
					break;
				}
			case 1:
				{
					Permute(ch,0,getBit(t,1));
					plaintext[i] = ch;
					break;
				}
			case 2:
				{
					Permute(ch,3,getBit(t,2));
					plaintext[i] = ch;
					break;
				}
			case 3:
				{
					Permute(ch,1,getBit(t,3));
					break;
				}
			case 4:
				{
					Permute(ch,6,getBit(t,4));
					plaintext[i] = ch;
					break;
				}
			case 5:
				{
					Permute(ch,4,getBit(t,5));
					plaintext[i] = ch;
					break;
				}
			case 6:
				{
					Permute(ch,7,getBit(t,6));
					plaintext[i] = ch;
					break;
				}
			default:
				{
					Permute(ch,5,getBit(t,7));
					plaintext[i] = ch;
				}
			}
		}
		ciphertext += (plaintext[i] ^ enc_key[j]);	
		if (j == enc_key.length() - 1)
				j = 0;
		else
			j++;
	}
	return ciphertext;
}

int main()
{
	string enc_key, plaintext; 
	string ciphertext;
	cout << "*** Welcome to the Simple Data Encryption Application ***" << endl;
	cout << "Please enter the encryption key: " ;
	getline(cin, enc_key);

	cout << "Please enter the plaintext to be encrypted: " ;
	while(getline(cin, plaintext))
	{
		ciphertext = Encrypt(enc_key,plaintext);

		cout << "Ciphertext: ";
		for (unsigned int i = 0; i < ciphertext.size();i++)
		{
				cout << hex << (int)(unsigned char)ciphertext[i];
		}
		cout << endl << endl;
		ciphertext= "";
		cout << "Please enter the plaintext to be encrypted: " ;
	}

	cin.clear();
	return 0;
}