#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#define MAXSIZEOFPOLYCHAR 32
#define MAXPOLYCOEFF 32

// A utility function to return maximum of two integers
int max(int m, int n) { return (m > n) ? m : n; }

// A[] represents coefficients of first polynomial
// B[] represents coefficients of second polynomial
// m and n are sizes of A[] and B[] respectively

int* addPoly(int A[], int B[], int m, int n)
{
    int size = max(m, n);
    int* sum = new int[size];

    // Initialize the product polynomial
    for (int i = 0; i < m; i++)
        sum[i] = A[i];

    // Take ever term of first polynomial
    for (int i = 0; i < n; i++)
        sum[i] += B[i];

    return sum;
}


// A utility function to print a polynomial
void printPoly(int poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << poly[i];
        if (i != 0)
            cout << "x^" << i;
        if (i != n - 1)
            cout << " + ";
    }
}

// takes array of char and character to look for then returns the index of it, else returns null
int indexOfChar(char token[], char character) {
    for (int i = 0; i < strlen(token); i++) {
        if (token[i] == character) {
            return i;
        }
    }
    return NULL;
}


int getExponent(char token[]) {
    int expNumber = 0;
    char* strNumber= new char[20]; // represents the size of the exponent
    int expIndex = indexOfChar(token, '^');
    if (strchr(token, 'x')) {
        if (strchr(token, '^')) {
            for (int i = expIndex+1, j=0; i < strlen(token); i++,j++) {
                strNumber[j] = token[i];
            }
            expNumber = atoi(strNumber);
            return expNumber;
        }
        return 1;
    }
    return 0;
}

int getCoefficient(char token[]) {
    int coefficient = 0;
    char *toBeConverted= new char[20]; // represents the size of coefficient

    if (strchr(token, 'x')) {
        if (strlen(token) > 1) {
            
            for (int i = 0; i < indexOfChar(token, 'x'); i++) {
                toBeConverted[i] = token[i];
            }
            coefficient = atoi(toBeConverted);
            return coefficient;
        }
        return 1;
    }
    return 0;
}

int extractTerms(char token[]) {
    // int finalExtractedArray[numberOfTerms];
    
    int coefficient = getCoefficient(token);
    int exponent = getExponent(token);
    //cout << "[" << coefficient <<", " << exponent << "]";
    return 0;
}

int getNumberOfTerms(char polynomial[]) {
    char* word;
    word = strtok(polynomial, "+");
    //extractTerms(word);
    
    int numberOfTerms = 1;
    while (word) {
        word = strtok(NULL, "+");
        if (!word) {
            break;
        }
        numberOfTerms++;
  
    }


    return numberOfTerms;
}

void extractAllTermsIntoArray(int polyExtractedArray[], char polynomial[]) {
    int i = 0;
    char* word;
    word = strtok(polynomial, "+");
    int* pairArr = new int[2];
    pairArr[0] = getCoefficient(word);
    pairArr[1] = getExponent(word);
    polyExtractedArray[i] = *pairArr;
    cout << "[" << pairArr[0] << ", " << pairArr[1] << "]" << pairArr << endl;
    while (word) {
        i++;
        word = strtok(NULL, "+");
        pairArr = new int[2];
        pairArr[0] = getCoefficient(word);
        pairArr[1] = getExponent(word);
        polyExtractedArray[i] = *pairArr;
        cout << "[" << pairArr[0] << ", " << pairArr[1] << "]" << pairArr << endl;
        if (!word) {
            break;
        }

    }

   
}

int main()
{
    // The following array represents polynomial 5 + 10x^2 + 6x^3
    // int A[] = {5, 0, 10, 6};
    char firstPoly[MAXPOLYCOEFF] = "";
    char secondPoly[MAXPOLYCOEFF] = "";
    // The following array represents polynomial 1 + 2x + 4x^2
    // int B[] = {1, 2, 4};
    // int m = sizeof(A)/sizeof(A[0]);
    // int n = sizeof(B)/sizeof(B[0]);

    // cout << "First polynomial is \n";
    // printPoly(A, m);
    // cout << "\nSecond polynomial is \n";
    // printPoly(B, n);

    int* sum;
    // int size = max(m, n);

    // cout << "\nsum polynomial is \n";
    // printPoly(sum, size);

    int userInput = 0;

    int numberOfTerms;
    int* polyOneExtractedArray;
    cout << "Please Pick an Option from the list:- \n \n";
    cout << "1. The Sume of 2 Polynomials:- \n";
    cout << "2. The Product of 2 Polynomials:- \n";
    cout << "3. The Derivative of a Polynomial with the second Derivative:- \n";
    cin >> userInput;
    int* extractedTerms;
    if (userInput == 1) {
        cout << "Please Etner the First Polynomial:- \n \n";
        cin >> firstPoly;
        numberOfTerms = getNumberOfTerms(firstPoly);
        extractedTerms = new int[numberOfTerms];
        polyOneExtractedArray = new int[numberOfTerms];
        extractAllTermsIntoArray(polyOneExtractedArray, firstPoly);

        cout << polyOneExtractedArray[0];
        // sum = addPoly(firstPCoef, secondPCoef, MAXSIZEOFPOLYCHAR, MAXSIZEOFPOLYCHAR);
        // printPoly(sum, size);
    }
    else if (userInput == 2) {
        // sum = addPoly(A, B, m, n);
        // printPoly(sum, size);
    }
    else if (userInput == 3) {
        // sum = addPoly(A, B, m, n);
        // printPoly(sum, size);
    }
    else {
        cout << "Please Pick a Valid Option from the list:- \n \n";
    }



    return 0;
}