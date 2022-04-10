#include <iostream>
#include <set>
#define N 3
using namespace std;

void printSquare(int matrix[N][N])
{
    // Executing the loop through by matrix row
    for (int i = 0; i < N; i++)
    {
        // Executes the loop through by matrix column
        for (int j = 0; j < N; j++)
        {
            cout << "  " << matrix[i][j];
        }
        cout << "\n";
    }
}

void isLatinSquare(int matrix[N][N])
{
    bool status = true;
    if (N > 0)
    {
        // This can collect relevant row and column
        set < int > row;
        set < int > col;
        // Executing the loop through by matrix row
        for (int i = 0; i < N && status; i++)
        {
            // Executes the loop through by matrix column
            for (int j = 0; j < N && status; j++)
            {
                if (matrix[j][i] > N || matrix[j][i] < 1
                    || matrix[i][j] > N || matrix[i][j] < 1)
                {
                    // When the matrix element is outside the matrix size
                    status = false;
                }
                else
                {
                    // Add row element
                    row.insert(matrix[j][i]);
                    // Add col element
                    col.insert(matrix[i][j]);
                }
            }
            if (status && (row.size() != N || col.size() != N))
            {
                // When result row and column are not N element
                status = false;
            }
            row.clear();
            col.clear();
        }
    }
    else
    {
        // When not square matrix
        status = false;
    }
    printSquare(matrix);
    if (status == true)
    {
        cout << "  Is Latin Square\n" << endl;
    }
    else
    {
        cout << "  Is Not Latin Square\n" << endl;
    }
}

void maxValue(int y[][8], int x) {
    int max = 0;
    max = y[0][0];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < 8; j++)
            if (max < y[i][j]) {
                max = y[i][j];
            }
    cout << " the max num is :" << " " << max << endl;
}

int RowSum(int y[][8], int x) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 8; j++) {
            sum += y[i][j];
        }
        cout << " the sum of [ " << i << " ] :" << sum << endl;
    }
    return 0;
}

int* ColSum(int y[][3], int x, int& allColSum) {
    int* sumC = new int[3];
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < x; j++) {
            sum += y[j][i];
        }
        sumC[i] = sum;
        allColSum += sum;
        sum = 0;
    }
    return sumC;
}

void sumCol(int col[], int x) {
    for (int i = 0; i < x; i++) {
        cout << " col " << i + 1 << " : " << col[i] << " " << endl;
    }

}

int* allRowSum(int arr[][3], int x, int result[], int& theSumOfAllRows) {
    for (int i = 0; i < x; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
        result[i] = sum;
        theSumOfAllRows += sum;

    }
    return result;
}

void allRows(int allRow[], int x) {
    for (int i = 0; i < x; i++) {
        cout << " the sum of [" << i << "] :" << allRow[i] << " " << endl;
    }
}

int rowMagic(int y[], int x) {
    for (int i = 0; i < x - 1; i++) {
        if (y[i] == y[i + 1]) {
            continue;
        }
        else {
            cout << endl << " No rowMagic " << endl;
            return 0;
        }
    }
    cout << endl << " it's a rowMagic  ";
    return 1;
}

int columnMagic(int y[], int x) {
    for (int i = 0; i < x - 1; i++) {
        if (y[i] == y[i + 1]) {
            continue;
        }
        else {
            cout << endl << " No colMagic " << endl;
            return 0;
        }
    }
    cout << endl << " it's a colMagic  " << endl;
    return 1;
}

void diagonalsFunc(int y[][3], int x, int& firstSum, int& secondSum) {
    firstSum = 0;
    secondSum = 0;
    for (int i = 0; i < x; i++) {
        cout << endl << y[i][i] << " " << y[i][x - 1 - i] << endl;
        firstSum += y[i][i];
        secondSum += y[i][x - 1 - i];
    }
    cout << endl << firstSum << "   " << secondSum << endl;
}

void magic_Seqar(int allRows[], int sumCol[], int size1, int size2, int firstDiagonalSum, int secondDiagonalSum) {
    if (allRows[0] == sumCol[0])
        if (firstDiagonalSum == secondDiagonalSum)
            if (secondDiagonalSum == sumCol[0]) {
                cout << " it's a magicseqar ";
                return;
            }

    cout << " not a magicseqar ";

}

int checkIfExistsWithDuplicates(int arr[][N], int elementToFind) {
    int numberOfDuplicates = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == elementToFind) {
                numberOfDuplicates++;
            }
        }
    }
    return numberOfDuplicates;
}

bool checkIfExists(int arr[][N], int elementToFind) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == elementToFind) {
                return true;
            }
        }
    }
    return false;
}

char containsDuplicats(int arr[N][N]) {
    //int numberToIncrease;
    for (int i = 1; i <= N*N; i++) {
        if (checkIfExists(arr,i)) {
            if (checkIfExistsWithDuplicates(arr, i) == 1) {
                continue;
            }
            else if (checkIfExistsWithDuplicates(arr, i) > 1) {
                return 'D';// Duplicated
            }
        }
        else {
            return 'N'; // Not Present
        }

    }
    return 'P'; // Present
}

int main()
{
    int result[3];
    int theSumOfAllRows = 0, allColSum = 0;
    //  int z[3]={50,50,50};
    //  int a[2][8]={{2,6,8,10,0}
            //      ,{60,80,12,50,11}};
    int x[N][N] = { {1,3,2},
                    {2,1,3},
                    {3,2,1} };
    //maxValue(a,2);
    cout << " the sum of the every row is :" << endl;
    //  RowSum(a,2);
    int* col = ColSum(x, 3, allColSum);
    sumCol(col, 3);
    int* allRow = allRowSum(x, 3, result, theSumOfAllRows);
    allRows(allRow, 3);
    //cout<<" have a rowMagic ? "<<endl;
     //rowMagic(result,2);
    // columnMagic(col,8);
    int firstDiagonalSum;
    int secondDiagonalSum;
    cout << theSumOfAllRows << " " << allColSum;
    diagonalsFunc(x, 3, firstDiagonalSum, secondDiagonalSum);
    int sumdiag = firstDiagonalSum + secondDiagonalSum;
    cout << sumdiag;
    magic_Seqar(allRow, col, 3, 3, firstDiagonalSum, secondDiagonalSum); // Question number 8
    isLatinSquare(x); // Question number 8
    if (sizeof(x) / sizeof(x[0]) == N && sizeof(x[0]) / sizeof(int) == N) { // Question Number 9
        if (containsDuplicats(x) == 'P') {
            cout << endl << "Contains All Digits" << endl;
        }
        else if (containsDuplicats(x) == 'D') {
            cout << endl << "Contains Duplicated Values" << endl;
        }
        else if(containsDuplicats(x) == 'N') {
            cout << endl << "A Number is Missing from the Sequence" << endl;
        }
    }

    return 0;
}
