#include <iostream>
#include <vector>
#include <string>

using namespace std;
// هنا بحول الحرف لرقم
int charToInt(char c) {
    return toupper(c) - 'A';
}

// هنا العكس بحول رقم لحرف
char intToChar(int x) {
    return (char)(x + 'A');
}

int main() {


    
    //دا المفتاح بتاعي

    int keyMatrix[2][2] = { {2, 1},
                            {1, 1} };

    // (Inverse Matrix) دا الـــــ
    int inverseMatrix[2][2] = { {1, -1},
                                {-1, 2} };
    
    int choice;
    char q = 'y';

        cout << "Do you want start? choice (y or n)";
        cin >> q;

    while (q == 'y') {

       
           

                cout << "====================" << "\n";
                cout << "Select Operation:\n";
                cout << "1. Encrypt \n";
                cout << "2. Decrypt \n";
                cout << "Enter your choice (1 or 2): ";
                cin >> choice;

                // ==========================================
                // الخيار الأول: التشفير
                // ==========================================
                if (choice == 1) {
                    string inputWord;
                    cout << "Enter word to encrypt: ";
                    cin >> inputWord;

                    /*
                    ========================================
                    ( X )إذا كان العدد فردي أضف حرف الــ
                   عشان نتجنب ان المستخدم يضيف كلمه مكونه من خمس حروف و يبقي عندك اي كلمه يدخلها ينفع تتقسم علي ال 2
                    ========================================
                    */
                    if (inputWord.length() % 2 != 0) {
                        inputWord += 'X';
                    }
                    /*
                    =====================
                     هنا هضرب المصفوفتان الكونتهم بعد ما احولهم لارقام
                    =====================
                    */

                    int p1, c1, c2, p2;

                    cout << "The Encrypted Code is : ";
                    for (int i = 0; i < inputWord.length(); i += 2) {
                        //هنحول الحروف لارقام و نحطها في مصفوفه 
                        p1 = charToInt(inputWord[i]);
                        p2 = charToInt(inputWord[i + 1]);

                        //المصفوفه الاولي 
                        c1 = (keyMatrix[0][0] * p1) + (keyMatrix[0][1] * p2);
                        // المصفوفه التانيا
                        c2 = (keyMatrix[1][0] * p1) + (keyMatrix[1][1] * p2);

                        cout << c1 << " " << c2 << " ";
                    }
                    cout << endl;
                }
                // ==========================================
                // الخيار الثاني: فك التشفير 
                // ==========================================
                else if (choice == 2) {
                    int n;
                    cout << "How many numbers do you have? ";
                    cin >> n;

                    // التأكد أن عدد الأرقام زوجي
                    if (n % 2 != 0) {
                        cout << "Error: You must enter an even count of numbers." << endl;
                        return 0;
                    }


                    //هنفضي مكان لارقام التشفير 

                    vector<int> cipherNumbers(n);
                    cout << "Enter the numbers separated by space: ";
                    for (int i = 0; i < n; i++) {
                        cin >> cipherNumbers[i];
                    }

                    //هنفضي مكان للكلمه الهنفك تشفيرها 

                    int c1, c2, d1, d2;

                    string decryptedWord = "";
                    for (int i = 0; i < n; i += 2) {
                        c1 = cipherNumbers[i];
                        c2 = cipherNumbers[i + 1];

                        // المعادلة: المعكوس * الأرقام المشفرة
                        d1 = (inverseMatrix[0][0] * c1) + (inverseMatrix[0][1] * c2);
                        d2 = (inverseMatrix[1][0] * c1) + (inverseMatrix[1][1] * c2);


                        //هنحول الحروف بعد كدا لارقام 

                        decryptedWord += intToChar(d1);
                        decryptedWord += intToChar(d2);
                    }

                    cout << "Original Word: " << decryptedWord;
                }
                else {
                    cout << "Invalid choice!" << endl;
                }
                cout <<'\n' << "====================" << '\n' << "Do you want continue? choice (y or n)" << '\n';
                cin >> q;
    }
    
    
    return 0;
}