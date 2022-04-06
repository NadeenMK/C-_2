/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

#define MAXSIZEOFPOLYCHAR 32
#define MAXPOLYCOEFF 32

// A utility function to return maximum of two integers
int max(int m, int n) { return (m > n) ? m : n; }



// int removeElement(int element, int* array[], int size) {
// 	    if (size > 0 && element < size -1) {
// 	        size--;
// 	        for (; element < size;  ++element) {
// 	            array[element][0] += array[element+1][0];
// 	        }
// 	    }
// 	    return size;
// }



// int simplifyPoly(int *polynomial[], int sizeOfPolyNomial){
//     // Initialize the product polynomial
//     // cout<< endl<< sizeOfPolyNomial << endl;
    
//     int newSizeOfTerms=0;
//     if(sizeOfPolyNomial == 1){
//         return sizeOfPolyNomial;
//     }
//     for (int i = 0; i < sizeOfPolyNomial; i++)
//     {
//         for (int j = 1; j < sizeOfPolyNomial; j++){
//             if (polynomial[i][1] == polynomial[j][1])
//             {
//                 sizeOfPolyNomial = removeElement(i, polynomial, sizeOfPolyNomial);
//             }
//         }
//     }
//     return sizeOfPolyNomial;
// }


// A utility function to print a polynomial
void printPoly(int *poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (poly[i][1] != 0){
            if(poly[i][1] ==1)
                cout << "x";
            else
                cout << "x^" << poly[i][1];
        }
        if (i != n - 1)
            cout << " + ";
    }
}

/* 
*   Addition process of the polynomial 
*/
void addPoly(int *firstArrayOfTerms[], int *secondArrayOfTerms[], int firstSize, int secondSize)
{
    if(firstSize > secondSize){ // if firstSize is bigger
        int initialSize = firstSize*2;
        int** additionOfPoly = new int*[initialSize];
        // Initialize the addition of polynomial
        for(int i=0;i<initialSize; i++){
            additionOfPoly[i] = new int[2];
        }
        int newSize = 0;
        for (int i = 0; i < firstSize; i++)
        {
            for(int j=0; j < secondSize;j++){// i =0, 1, 2 ______ newSize= 2, 3
                
                if(firstArrayOfTerms[i][1] == secondArrayOfTerms[j][1] && secondArrayOfTerms[j][1] != -1){
                    additionOfPoly[newSize][0] = firstArrayOfTerms[i][0] + secondArrayOfTerms[j][0];
                    additionOfPoly[newSize][1] = firstArrayOfTerms[i][1];
                    firstArrayOfTerms[i][1] = -1;
                    secondArrayOfTerms[j][1] = -1;
                    newSize++;
                    break;
                }else if(firstArrayOfTerms[i][1] != secondArrayOfTerms[j][1] && secondArrayOfTerms[j][1] != -1){
                    additionOfPoly[newSize][0] = firstArrayOfTerms[i][0];
                    additionOfPoly[newSize][1] = firstArrayOfTerms[i][1];
                    additionOfPoly[newSize+1][0] = secondArrayOfTerms[j][0];
                    additionOfPoly[newSize+1][1] = secondArrayOfTerms[j][1];
                    firstArrayOfTerms[i][1] = -1;
                    secondArrayOfTerms[j][1] = -1;
                    newSize+=2;
                    break;
                }
                
            }
            if(firstArrayOfTerms[i][1] != -1){
                    additionOfPoly[newSize][0] = firstArrayOfTerms[i][0];
                    additionOfPoly[newSize][1] = firstArrayOfTerms[i][1];
                    firstArrayOfTerms[i][1] = -1;
                    newSize++;
            }
        }
        printPoly(additionOfPoly, newSize);
        
    }else if(secondSize > firstSize){ // if secondSize size is bigger
        int initialSize = secondSize*2;
        int** additionOfPoly = new int*[initialSize];
        // Initialize the addition of polynomial
        for(int i=0;i<initialSize; i++){
            additionOfPoly[i] = new int[2];
        }
        int newSize = 0;
        // Initialize the product polynomial
        for (int i = 0; i < secondSize; i++)
        {    
            for(int j = 0; j < firstSize; j++){
                if(secondArrayOfTerms[i][1] == firstArrayOfTerms[j][1] && firstArrayOfTerms[j][1] != -1){
                    cout << endl <<"Equals" << endl;
                    additionOfPoly[newSize][0] = firstArrayOfTerms[i][0] + secondArrayOfTerms[j][0];
                    additionOfPoly[newSize][1] = firstArrayOfTerms[i][1];
                    firstArrayOfTerms[i][1] = -1;
                    secondArrayOfTerms[j][1] = -1;
                    newSize++;
                    break;
                }else if(secondArrayOfTerms[i][1] != firstArrayOfTerms[j][1] && firstArrayOfTerms[j][1] != -1){
                    cout << endl <<"Not Equals" << endl;
                    additionOfPoly[newSize][0] = firstArrayOfTerms[j][0];
                    additionOfPoly[newSize][1] = firstArrayOfTerms[j][1];
                    additionOfPoly[newSize+1][0] = secondArrayOfTerms[i][0];
                    additionOfPoly[newSize+1][1] = secondArrayOfTerms[i][1];
                    firstArrayOfTerms[j][1] = -1;
                    secondArrayOfTerms[i][1] = -1;
                    newSize+=2;
                    break;
                }
                
            }
            if(secondArrayOfTerms[i][1] != -1){
                additionOfPoly[newSize][0] = secondArrayOfTerms[i][0];
                additionOfPoly[newSize][1] = secondArrayOfTerms[i][1];
                secondArrayOfTerms[i][1] = -1;
                newSize++;
            }
        }
        printPoly(additionOfPoly, newSize);
        
        // =============
        
    }else{ // if the same size
        /* 
        * add cases to cover
        * first Poly: 3x^2+4x
        * second Poly: 2x^4+5x^4
        */
        int size = firstSize*2;
        int newSize = 0;
        int** additionOfPoly = new int*[size];
        for(int i=0;i<size; i++){
            additionOfPoly[i] = new int[2];
        }
        
        for (int i = 0; i < firstSize; i++)
        {
            if(newSize > size) break;
            if(firstArrayOfTerms[i][1] == secondArrayOfTerms[i][1]){
                additionOfPoly[i][0] = firstArrayOfTerms[i][0] + secondArrayOfTerms[i][0];
                additionOfPoly[i][1] = firstArrayOfTerms[i][1];
                newSize+=1;
            }else{
                additionOfPoly[newSize][0] = firstArrayOfTerms[i][0];
                additionOfPoly[newSize][1] = firstArrayOfTerms[i][1];
                additionOfPoly[newSize+1][0] = secondArrayOfTerms[i][0];
                additionOfPoly[newSize+1][1] = secondArrayOfTerms[i][1];
                newSize+=2;
                cout << endl <<newSize<< endl;
                
            }
        }
        
        printPoly(additionOfPoly, newSize);
    }

    
}

/* 
*    Multiplication process of the polynomial
*/
void productPoly(int *firstArrayOfTerms[], int *secondArrayOfTerms[], int firstSize, int secondSize)
{
    
    cout << "from add Poly" << endl;
    if(firstSize > secondSize){ // if firstSize is bigger
        int initialSize = firstSize*2;
        int** additionOfPoly = new int*[initialSize];
        cout << "first If" << endl;
        for(int i=0;i<initialSize; i++){
            additionOfPoly[i] = new int[2];
        }
        int newSize = 0;
        for (int i = 0; i < firstSize; i++)
        {
            for(int j=0; j < secondSize;j++){// i =0, 1, 2 ______ newSize= 2, 3
                cout << "I: "<<i << "\t"<< "J: "<< j<< endl;
                additionOfPoly[newSize][0] = firstArrayOfTerms[i][0] * secondArrayOfTerms[j][0];
                additionOfPoly[newSize][1] = firstArrayOfTerms[i][1] + secondArrayOfTerms[j][1];
                newSize++;
            }
            cout << "["<< additionOfPoly[i][0] <<", "<<additionOfPoly[i][1] << "]"<< endl;
        }
        printPoly(additionOfPoly, newSize);

    }
}

/* 
*    Derivative process of the polynomial
*/
void firstDerivativePoly(int *firstArrayOfTerms[], int firstSize)
{
        
        int** derivativeOfPoly = new int*[firstSize];
        for(int i=0;i<firstSize; i++){
            derivativeOfPoly[i] = new int[2];
        }
        int** secondDerivativeOfPoly = new int*[firstSize];
        for(int i=0;i<firstSize; i++){
            secondDerivativeOfPoly[i] = new int[2];
        }
        // [[0,],[],[]]
        // Initialize the product polynomial
        
        for (int i = 0; i < firstSize; i++)
        {
            if(firstArrayOfTerms[i][1] == 0){
                firstArrayOfTerms[i][0] = 0;
                continue;
            }
            derivativeOfPoly[i][0] = firstArrayOfTerms[i][0] * firstArrayOfTerms[i][1];
            derivativeOfPoly[i][1] = firstArrayOfTerms[i][1] - 1;
            
        }
        cout << endl <<"first derivative" << endl;
        printPoly(derivativeOfPoly, firstSize);
        
        for (int j = 0; j < firstSize; j++)
        {
            if(derivativeOfPoly[j][1] == 0){
                derivativeOfPoly[j][0] = 0;
                continue;
            }
            secondDerivativeOfPoly[j][0] = derivativeOfPoly[j][0] * derivativeOfPoly[j][1];
            secondDerivativeOfPoly[j][1] = derivativeOfPoly[j][1] - 1;
            
        }
        cout << endl <<"second derivative" << endl;
        printPoly(secondDerivativeOfPoly, firstSize);
}




// takes array of char and character to look for then returns the index of it, else returns null
int indexOfChar(char token[], char character) {
    for (int i = 0; i < strlen(token); i++) {
        if (token[i] == character) {
            return i;
        }
    }
    return 0;
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
    
    if (!strchr(token, 'x')){
        for (int i = 0; i < strlen(token); i++) {
            toBeConverted[i] += token[i];
        }
        coefficient = atoi(toBeConverted);
        return coefficient;
    }
    
    if (strchr(token, 'x')) {
        if (strlen(token) > 1) {
            
            for (int i = 0; i < indexOfChar(token, 'x'); i++) {
                toBeConverted[i] += token[i];
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

void extractAllTermsIntoArray(int *polyExtractedArray[], char polynomial[], int size) {
    int i = 1;
    char* newWord;
    newWord = strtok(polynomial, "+");
    polyExtractedArray[0][0] = getCoefficient(newWord);
    polyExtractedArray[0][1] = getExponent(newWord);
    
    while ((newWord = strtok(NULL, "+"))) {
        polyExtractedArray[i][0] = getCoefficient(newWord);
        polyExtractedArray[i][1] = getExponent(newWord);
        
    i++;
    }

   
}

void displayExtractedArray(int *firstExtractedTerms[], int *secondExtractedTerms[], int firstSize, int secondSize = 0)
{
    cout << endl << "[ ";
    if(!secondExtractedTerms){
        
        for(int i=0; i < firstSize; i++){
            cout << "[" << firstExtractedTerms[i][0] << ", " << firstExtractedTerms[i][1] << "]" << ", ";
        }
        
        return;
    }
    
    for(int i=0; i < firstSize; i++){
        cout << "[" << firstExtractedTerms[i][0] << ", " << firstExtractedTerms[i][1] << "]" << ", ";
    }
    for(int j=0; j < secondSize; j++){
        cout << "[" << secondExtractedTerms[j][0] << ", " << secondExtractedTerms[j][1] << "]" << ", ";
    }
    
    cout << " ]" << endl;
}


void initializationProcess(){
    
}


void extractTrigonometricTerm(char capturedTrigoArr[]) {
    
    char* newWord;
    newWord = strtok(capturedTrigoArr, "'");
    cout << newWord;
    if(strlen(newWord) > 1){
        if (strcmp(newWord, "sin") == 0) {
            cout << endl << "cos(x)" << endl ;
            return;
        }else if (strcmp(newWord, "cos") == 0){
            cout << endl << "-sin(x)" << endl ;
            return;
        }
        else if(strcmp(newWord, "tan") == 0){
            cout << endl << "sec^2(x)" << endl ;
            return;
        }else{
            cout << endl << "Please enter a valid Trigonometric format string" << endl ;
            return;
        }
    }
    
    newWord = strtok(capturedTrigoArr, "(");
    if(strlen(newWord) > 1){
        if (strcmp(newWord, "sin") == 0) {
            cout << endl << "cos(x)" << endl ;
            return;
        }else if(strcmp(newWord, "cos") == 0){
            cout << endl << "-sin(x)" << endl ;
            return;
        }
        else if(strcmp(newWord, "tan") == 0){
            cout << endl << "sec^2(x)" << endl ;
            return;
        }else{
            cout << endl << "Please enter a valid Trigonometric format string" << endl ;
            return;
        }
    }
    newWord = strtok(capturedTrigoArr, " "); 
    if(strlen(newWord) > 1){
        if (strcmp(newWord, "sin") == 0) {
            cout << endl << "cos(x)" << endl ;
            return;
        }else if(strcmp(newWord, "cos") == 0){
            cout << endl << "-sin(x)" << endl ;
            return;
        }
        else if(strcmp(newWord, "tan") == 0){
            cout << endl << "sec^2(x)" << endl ;
            return;
        }else{
            cout << endl << "Please enter a valid Trigonometric format string" << endl ;
            return;
        }
    }

}
int main()
{
    char firstPoly[MAXPOLYCOEFF] = "";
    char secondPoly[MAXPOLYCOEFF] = "";
    int* sum;
    int userInput = 0;

    int numberOfFirstTerms;
    int numberOfSecondTerms;
    int** polyOneExtractedArray;
    int** polyTwoExtractedArray;
    cout << "Please Pick an Option from the list:- \n \n";
    cout << "1. The Sum of 2 Polynomials:- \n";
    cout << "2. The Product of 2 Polynomials:- \n";
    cout << "3. The First Derivative of a Polynomial with the second Derivative:- \n";
    cout << "4. The Derivative of a Trigonometric:- \n";
    cin >> userInput;
    int* firstExtractedTerms;
    int* secondExtractedTerms;
    
    if (userInput == 1) {
        cout << "\n \t \t -== You Picked 'Sum' Polynomial Option ==- \n \n";
        cout << "Please Enter the First Polynomial:- \n \n";
        cin >> firstPoly;
        char copyFirst[MAXPOLYCOEFF]; 
        strcpy(copyFirst, firstPoly); // we needed to copy the the first poly since strtok() function can't be reseted after used on the same word twice :(
        numberOfFirstTerms = getNumberOfTerms(firstPoly);
        firstExtractedTerms = new int[numberOfFirstTerms];
        polyOneExtractedArray = new int*[numberOfFirstTerms];
        for(int i=0;i<numberOfFirstTerms; i++){
            polyOneExtractedArray[i] = new int[2];
        }
        extractAllTermsIntoArray(polyOneExtractedArray, copyFirst, numberOfFirstTerms);
        
        // the Second PolyNomial not very convient but for the sake of time we can repeat some code 
        cout << "Please Enter the Second Polynomial:- \n \n";
        cin >> secondPoly;
        char copySecond[MAXPOLYCOEFF];
        strcpy(copySecond, secondPoly);
        numberOfSecondTerms = getNumberOfTerms(secondPoly);
        secondExtractedTerms = new int[numberOfSecondTerms];
        polyTwoExtractedArray = new int*[numberOfSecondTerms];
        for(int i=0;i<numberOfSecondTerms; i++){
            polyTwoExtractedArray[i] = new int[2];
        }
        
        
        
        extractAllTermsIntoArray(polyTwoExtractedArray, copySecond, numberOfSecondTerms);
        displayExtractedArray(polyOneExtractedArray, polyTwoExtractedArray, numberOfFirstTerms, numberOfSecondTerms);
        // simplifyPoly(polyOneExtractedArray, numberOfFirstTerms);
        
        addPoly(polyOneExtractedArray, polyTwoExtractedArray, numberOfFirstTerms, numberOfSecondTerms);
        // printPoly(sum, size);
    }
    else if (userInput == 2) {
        cout << "\n \t \t -== You Picked 'Product' Polynomial Option ==- \n \n";
        
        cout << "Please Enter the First Polynomial:- \n \n";
        cin >> firstPoly;
        char copyFirst[MAXPOLYCOEFF]; 
        strcpy(copyFirst, firstPoly); // we needed to copy the the first poly since strtok() function can't be reseted after used on the same word twice :(
        numberOfFirstTerms = getNumberOfTerms(firstPoly);
        firstExtractedTerms = new int[numberOfFirstTerms];
        polyOneExtractedArray = new int*[numberOfFirstTerms];
        for(int i=0;i<numberOfFirstTerms; i++){
            polyOneExtractedArray[i] = new int[2];
        }
        extractAllTermsIntoArray(polyOneExtractedArray, copyFirst, numberOfFirstTerms);
        
        // the Second PolyNomial not very convient but for the sake of time we can repeat some code 
        cout << "Please Enter the Second Polynomial:- \n \n";
        cin >> secondPoly;
        char copySecond[MAXPOLYCOEFF];
        strcpy(copySecond, secondPoly);
        numberOfSecondTerms = getNumberOfTerms(secondPoly);
        secondExtractedTerms = new int[numberOfSecondTerms];
        polyTwoExtractedArray = new int*[numberOfSecondTerms];
        for(int i=0;i<numberOfSecondTerms; i++){
            polyTwoExtractedArray[i] = new int[2];
        }
        
        cout << endl <<"Extracting Polynomoial... " << endl;
        
        extractAllTermsIntoArray(polyTwoExtractedArray, copySecond, numberOfSecondTerms);
        
        cout << endl <<"Displaying Extracted Array from Polynomoial... " << endl;
        
        displayExtractedArray(polyOneExtractedArray, polyTwoExtractedArray,numberOfFirstTerms, numberOfSecondTerms);
        
        cout << endl <<"Result of Producting the  Polynomoial... " << endl;
        
        productPoly(polyOneExtractedArray, polyTwoExtractedArray, numberOfFirstTerms, numberOfSecondTerms);
        
    }
    else if (userInput == 3) {
        
        char derivativePoly[MAXPOLYCOEFF] = "";
        cout << "\n \t \t -== You Picked 'Product' Polynomial Option ==- \n \n";
        cout << "Please Enter the First Polynomial:- \n \n";
        cin >> derivativePoly;
        char copyDerivativePoly[MAXPOLYCOEFF]; 
        strcpy(copyDerivativePoly, derivativePoly); // we needed to copy the the first poly since strtok() function can't be reseted after used on the same word twice :(
        numberOfFirstTerms = getNumberOfTerms(derivativePoly);
        firstExtractedTerms = new int[numberOfFirstTerms];
        polyOneExtractedArray = new int*[numberOfFirstTerms];
        for(int i=0;i<numberOfFirstTerms; i++){ // initilizing the inner arrays pointers inside the main array
            polyOneExtractedArray[i] = new int[2];
        }
        
        extractAllTermsIntoArray(polyOneExtractedArray, copyDerivativePoly, numberOfFirstTerms);
        
        cout << endl <<"Displaying Extracted Array from Polynimoial... " << endl;
        
        displayExtractedArray(polyOneExtractedArray, nullptr, numberOfFirstTerms, numberOfSecondTerms);

        cout << endl <<"Result of first Derivitave the  Polynimoial... " << endl;
        firstDerivativePoly(polyOneExtractedArray, numberOfFirstTerms);
        cout << endl <<"Result of Second Derivitave the  Polynimoial... " << endl;
        firstDerivativePoly(polyOneExtractedArray, sizeof(polyOneExtractedArray));
        
    } else if (userInput == 4) {
        char trigo[MAXPOLYCOEFF] = "";
        cout << "\n \t \t -== You Picked 'Trigo' Option ==- \n \n";
        cout << "Please Enter the Trigo Equation:- \n \n";
        cin >> trigo;
        extractTrigonometricTerm(trigo);
    }
    else {
        cout << "Please Pick a Valid Option from the list:- \n \n";
    }
    return 0;
}