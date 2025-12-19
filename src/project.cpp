#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to repeat the keyword to match message length
string generateKey(const string &text, const string &key)
{
    string newKey;
    int keyIndex = 0;

    for (char c : text)
    {
        if (isalpha(c))
        {
            newKey += key[keyIndex % key.length()];
            keyIndex++;
        }
        else
        {
            newKey += c; // keep non-letters unchanged
        }
    }
    return newKey;
}

// Encrypt function
string encrypt(const string &plaintext, const string &key)
{
    string ciphertext;
    string fullKey = generateKey(plaintext, key);

    for (int i = 0; i < plaintext.length(); i++)
    {
        if (isalpha(plaintext[i]))
        {
            int P = plaintext[i] - 'A';
            int K = fullKey[i] - 'A';
            int E = (P + K) % 26;
            ciphertext += char(E + 'A');
        }
        else
        {
            ciphertext += plaintext[i];
        }
    }
    return ciphertext;
}

// Decrypt function
string decrypt(const string &ciphertext, const string &key)
{
    string plaintext;
    string fullKey = generateKey(ciphertext, key);

    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (isalpha(ciphertext[i]))
        {
            int C = ciphertext[i] - 'A';
            int K = fullKey[i] - 'A';
            int D = (C - K + 26) % 26;
            plaintext += char(D + 'A');
        }
        else
        {
            plaintext += ciphertext[i];
        }
    }
    return plaintext;
}

int main()
{
    int choice;
    string message, key;

    do
    {
        cout << "\nVigenere Cipher Menu\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter plaintext: ";
            getline(cin, message);
            cout << "Enter keyword: ";
            getline(cin, key);

            // Convert to uppercase
            for (char &c : message)
                c = toupper(c);
            for (char &c : key)
                c = toupper(c);

            cout << "Encrypted text: " << encrypt(message, key) << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter ciphertext: ";
            getline(cin, message);
            cout << "Enter keyword: ";
            getline(cin, key);

            // Convert to uppercase
            for (char &c : message)
                c = toupper(c);
            for (char &c : key)
                c = toupper(c);

            cout << "Decrypted text: " << decrypt(message, key) << endl;
        }
        else if (choice == 3)
        {
            cout << "Exiting program...\n";
        }
        else
        {
            cout << "Invalid selection\n";
        }

    } while (choice != 3);

    return 0;
}
