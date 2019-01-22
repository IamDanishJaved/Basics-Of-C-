/************************* *******************************
Basics of Variables and Pointers
Author: Agha Ali Raza
Date: Oct 11, 2015
*********************************************************/

#include <conio.h>
#include <iostream>
using namespace std;

void passByVal(int, int);
void passByRef(int &, int *);

void passArrayINTstyle1(int *);
void passArrayINTstyle2(int []);
void passArrayCHARstyle1(char *);
void passArrayCHARstyle2(char []);
void passArrayGENERIC(void *, int);

void passMArray(int [][3][2]);
void passMArray2(int *[10]);
void passMArray3(int **);
void passMArray4(int ***);

void createMemLeak();

int main(){
	cout << "Welcome of DataStructures and Algorithms!" << endl;

	// Declaring variables of built-in types
	bool a = 1;
	char b = 'a';
	int c = 201;
	float d = 21.2;
	double e = 2001.2;
	wchar_t f = 'a';

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "f = " << f << endl << endl;
	/************************* OUTPUT *******************************
	Welcome of DataStructures and Algorithms!
	a = 1
	b = a
	c = 201
	d = 21.2
	e = 2001.2
	f = 97
	*****************************************************************/
	
	// Checking sizes in the compiler
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of short int : " << sizeof(short int) << endl;
	cout << "Size of long int : " << sizeof(long int) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << endl << endl;

	/************************* OUTPUT *******************************
	Size of char : 1
	Size of int : 4
	Size of short int : 2
	Size of long int : 4
	Size of float : 4
	Size of double : 8
	Size of wchar_t : 2
	*****************************************************************/

	// Passing variables by value
	int var1=10, var2=20;

	passByVal(var1, var2);
	cout << "var1 = " << var1 << ", var2 = " << var2 << endl;
	
	/************************* OUTPUT *******************************
	var1 = 10, var2 = 20
	*****************************************************************/
	
	// Passing variables by reference. Param 1: as a ref, Param 2: as a pointer
	passByRef(var1, &var2);
	cout << "var1 = " << var1 << ", var2 = " << var2 << endl << endl;

	/************************* OUTPUT *******************************
	var1 = 11, var2 = 21
	*****************************************************************/
	
	// Pointers
	int var3 = 35;
	int * ptr1 = &var3;
	char var4 = 'A';
	char * ptr2 = &var4;

	// Pointer values with and without dereferencing
	cout << "ptr1 = " << ptr1 << ", ptr2 = " << ptr2 << ", (char*)ptr2 = " << (char*)ptr2 << ", (void*)ptr2 = " << (void*)ptr2 << endl; // char* is interpreted as char array.
	cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl << endl;
	
	/************************* OUTPUT *******************************
	ptr1 = 0052FB50, ptr2 = A╠╠╠╠╠╠╠╠P√R, (char*)ptr2 = A╠╠╠╠╠╠╠╠P√R, (void*)ptr2 = 0052FB3B
	*ptr1 = 35, *ptr2 = A
	*****************************************************************/
	
	// Incrementing
	cout << "ptr1 = " << ptr1 << ", (void*)ptr2 = " << (void*)ptr2 << endl; // char* is interpreted as char array.
	++ptr2;
	cout << "++ptr1 = " << ++ptr1 << ", (void*)++ptr2 = " << (void*)ptr2 << endl << endl; // char* is interpreted as char array.
	--ptr1;
	--ptr2;

	cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
	cout << "++(*ptr1) = " << ++(*ptr1) << ", ++(*ptr2) = " << ++(*ptr2) << endl << endl; 
	
	/************************* OUTPUT *******************************
	ptr1 = 0052FB50, (void*)ptr2 = 0052FB3B
	++ptr1 = 0052FB54, (void*)++ptr2 = 0052FB3C

	*ptr1 = 35, *ptr2 = A
	++(*ptr1) = 36, ++(*ptr2) = B
	*****************************************************************/
	
	// Assignment after dereferencing
	int *ptr3 = new int;
	int *ptr4 = new int;

	*ptr3 = 15;
	*ptr4 = 20;

	*ptr3 = *ptr4;
	cout << "*ptr3 = *ptr4 \n ptr3 = " << ptr3 << ", ptr4 = " << ptr4 << endl; 
	cout << "*ptr3 = " << *ptr3 << ", *ptr4 = " << *ptr4 << endl; 
	
	char *ptr5 = new char;
	char *ptr6 = new char;

	*ptr5 = 'A';
	*ptr6 = 'B';

	*ptr5 = *ptr6;
	cout << "*ptr5 = *ptr6 \n ptr5 = " << (void *)ptr5 << ", ptr6 = " << (void*)ptr6 << endl; 
	cout << "*ptr5 = " << *ptr5 << ", *ptr6 = " << *ptr6 << endl << endl; 
	
	/************************* OUTPUT *******************************
	*ptr3 = *ptr4
	 ptr3 = 00154BE0, ptr4 = 00154C20
	*ptr3 = 20, *ptr4 = 20
	
	*ptr5 = *ptr6
	 ptr5 = 00154C60, ptr6 = 00154CA0
	*ptr5 = B, *ptr6 = B
	*****************************************************************/
	
	// Pointer Assignment and Memory Leak
	ptr3 = new int;
	ptr4 = new int;

	*ptr3 = 15;
	*ptr4 = 20;

	ptr3 = ptr4;
	cout << "ptr3 = ptr4 \n ptr3 = " << ptr3 << ", ptr4 = " << ptr4 << endl; 
	cout << "*ptr3 = " << *ptr3 << ", *ptr4 = " << *ptr4 << endl; 
	
	ptr5 = new char;
	ptr6 = new char;

	*ptr5 = 'A';
	*ptr6 = 'B';

	ptr5 = ptr6;
	cout << "ptr5 = ptr6 \n ptr5 = " << (void *)ptr5 << ", ptr6 = " << (void*)ptr6 << endl; 
	cout << "*ptr5 = " << *ptr5 << ", *ptr6 = " << *ptr6 << endl << endl; 

	// Another example of mem leak
	createMemLeak();
	
	/************************* OUTPUT *******************************
	ptr3 = ptr4
	 ptr3 = 00154F20, ptr4 = 00154F20
	*ptr3 = 20, *ptr4 = 20
	
	ptr5 = ptr6
	 ptr5 = 00154FA0, ptr6 = 00154FA0
	*ptr5 = B, *ptr6 = B
	*****************************************************************/
	
	// Dangling Pointers
	ptr3 = new int;
	*ptr3 = 55;
	
	cout << "ptr3 = " << ptr3 << endl; 
	cout << "*ptr3 = " << *ptr3 << endl; 
	
	ptr4 = ptr3;
	delete ptr4;

	cout << "ptr3 = " << ptr3 << ", ptr4 = " << ptr4 << endl; 
	cout << "*ptr3 = " << *ptr3 << ", *ptr4 = " << *ptr4 << endl << endl; 
	
	/************************* OUTPUT *******************************
	ptr3 = 00154FE0
	*ptr3 = 55
	ptr3 = 00154FE0, ptr4 = 00154FE0
	*ptr3 = -17891602, *ptr4 = -17891602
	*****************************************************************/
	
	// Const and const Pointers
	const int const1 = 10;
	// All of the following produce compile time errors
		// const1 = 20;
		// const1 = const1 + 1;
		// int *ptr7 = &const1;
	const int *ptr7 = &const1;
		// *ptr7 = 20;
	int nonConst1 = 10;
	int nonConst2 = 100;
	const int *ptr8 = &nonConst1;
	nonConst1 = 20;
	// Following is an error
		//*ptr8 = 30;
	int * const ptr9 = &nonConst1;
	*ptr9 = 30;
	// Following is an error
		//ptr9 = &nonConst2;

	// Arrays
	int A[5] = {1, 2, 3, 4, 5};
	char B[5] = {'a', 'b', 'c', 'd', '\0'};

	cout << "A = " << A << ", B = " << B << endl;
	cout << "A[0] = " << A[0] << ", B[0] = " << B[0] << endl;
	cout << "*A = " << *A << ", *B = " << *B << endl;
	cout << "A[1] = " << A[1] << ", B[1] = " << B[1] << endl;
	cout << "*(A+1) = " << *(A+1) << ", *(B+1) = " << *(B+1) << endl;

	/************************* OUTPUT *******************************
	A = 0052FA98, B = abcd
	A[0] = 1, B[0] = a
	*A = 1, *B = a
	A[1] = 2, B[1] = b
	*(A+1) = 2, *(B+1) = b
	*****************************************************************/
	
	// Arrays are always passed by ref
	cout << "A[1] = " << A[1] << ", B[1] = " << B[1] << endl;
	passArrayINTstyle1(A);
	cout << "A[1] = " << A[1] << endl;
	passArrayINTstyle2(A);
	cout << "A[1] = " << A[1] << endl;
	passArrayCHARstyle1(B);
	cout << "B[1] = " << B[1] << endl;
	passArrayCHARstyle2(B);
	cout << "B[1] = " << B[1] << endl;
	passArrayGENERIC(A, sizeof(A[0]));
	cout << "A[1] = " << A[1] << endl;
	passArrayGENERIC(B, sizeof(B[0]));
	cout << "B[1] = " << B[1] << endl;
	
	/************************* OUTPUT *******************************
	A[1] = 2, B[1] = b
	A[1] = 2000
	A[1] = 3000
	B[1] = X
	B[1] = Y
	A[1] = 5005
	B[1] = W
	*****************************************************************/
	
	// Automatic Arrays could not be deleted. The following produce run-time errors
		// delete [] A;
		// delete [] B;
	
	// Automatic arrays need constant size (defined at compile time). The following is an error
		// int size = 10;
		// int C1[size];
	// But the following is okay
	const int size1 = 10;
	int D1[size1];

	// Dynamic memory allocation
	int size2 = 10;
	int * dyArray = new int[size2];

	// But after its use, it needs to be deleted as follows
	delete [] dyArray;
	
	// Pointer to pointer (double pointers)
	int val = 555;
	int *ptr;
	int **ptr2ptr;
	int ***ptr2ptr2ptr;
	int ****ptr2ptr2ptr2ptr;
	
	ptr = &val;
	ptr2ptr = &ptr;
	ptr2ptr2ptr = &ptr2ptr;
	ptr2ptr2ptr2ptr = &ptr2ptr2ptr;

	cout << endl;
	cout << "val = " << val << endl;
	cout << "ptr = " << ptr << ", *ptr = " << *ptr << endl;
	cout << "ptr2ptr = " << ptr2ptr << ", *ptr2ptr = " << *ptr2ptr << ", **ptr2ptr = " << **ptr2ptr << endl;
	cout << "ptr2ptr2ptr = " << ptr2ptr2ptr << ", *ptr2ptr2ptr = " << *ptr2ptr2ptr << ", **ptr2ptr2ptr = " << **ptr2ptr2ptr << ", ***ptr2ptr2ptr = " << ***ptr2ptr2ptr << endl;
	cout << "ptr2ptr2ptr2ptr = " << ptr2ptr2ptr2ptr << ", *ptr2ptr2ptr2ptr = " << *ptr2ptr2ptr2ptr << ", **ptr2ptr2ptr2ptr = " << **ptr2ptr2ptr2ptr << ", ***ptr2ptr2ptr2ptr = " << ***ptr2ptr2ptr2ptr << ", ****ptr2ptr2ptr2ptr = " << ****ptr2ptr2ptr2ptr << endl;

	/************************* OUTPUT *******************************
	val = 555
	ptr = 0052F9F8, *ptr = 555
	ptr2ptr = 0052FA04, *ptr2ptr = 0052F9F8, **ptr2ptr = 555
	ptr2ptr2ptr = 0052FA10, *ptr2ptr2ptr = 0052FA04, **ptr2ptr2ptr = 0052F9F8, ***pt
	r2ptr2ptr = 555
	ptr2ptr2ptr2ptr = 0052FA1C, *ptr2ptr2ptr2ptr = 0052FA10, **ptr2ptr2ptr2ptr = 005
	2FA04, ***ptr2ptr2ptr2ptr = 0052F9F8, ****ptr2ptr2ptr2ptr = 555
	*****************************************************************/
	
	// Multidimensional Arrays
	// Type 1
	int mArray[4][3][2] = {{{1, 2}, {3, 4}, {5, 6}}, {{7, 8}, {9, 10}, {11, 12}}, {{13, 14}, {15, 16}, {17, 18}}, {{19, 20}, {21, 22}, {23, 24}}};
	cout << endl;
	cout << "mArray[2][2][1] = " << mArray[2][2][1];

	passMArray(mArray);
	cout << endl;
	cout << "mArray[2][2][1] = " << mArray[2][2][1];

	// Type 2
	int *mArray2[10];
	for(int i = 0; i < 10; i++){
		mArray2[i] = new int[10];
	}
	passMArray2(mArray2);
	cout << endl;
	cout << "mArray2[2][13] = " << mArray2[2][3];

	// Type 3
	int **mArray3;
	mArray3 = new int*[10];
	for(int i = 0; i < 10; i++){
		mArray3[i] = new int[10];
	}
	passMArray3(mArray3);
	cout << endl;
	cout << "mArray3[2][3] = " << mArray3[2][3];

	// Type 4
	int ***mArray4;
	mArray4 = new int**[10];
	for(int i = 0; i < 10; i++){
		mArray4[i] = new int*[10];
		for(int j = 0; j < 10; j++){
			mArray4[i][j] = new int[10];
		}
	}
	passMArray4(mArray4);
	cout << endl;
	cout << "mArray4[2][2][1] = " << mArray4[2][2][1];

	/************************* OUTPUT *******************************
	mArray[2][2][1] = 18
	mArray[2][2][1] = 222
	mArray2[2][3] = 223
	mArray3[2][3] = 224
	mArray4[2][2][1] = 225
	*****************************************************************/
	
	/************************* DELETION *****************************
	Multidimensional, dynamically allocated arrays need to be deleted
	in a loop (just like their creation). There is no 
	delete [][] mArray4, as there is no int **mArray4 = new int[10][10];
	*****************************************************************/
	
	// void variables could not be declared
	// void voidVar;

	// Void pointers could not be incremented, decremented as size of the steps is not defined
	// void * voidPtr;
	// voidPtr++;

	// Complete
	getch();

	return 0;
}

void passByVal(int a, int b){
	a++;
	b++;
}

void passByRef(int &a, int *b){
	a++;
	(*b)++;
}


void passArrayINTstyle1(int * a){
	a[1] = 2000;
}

void passArrayINTstyle2(int a[]){
	a[1] = 3000;
}

void passArrayCHARstyle1(char *b){
	b[1] = 'X';
}

void passArrayCHARstyle2(char b[]){
	b[1] = 'Y';
}

void passArrayGENERIC(void *c, int size){
	if(size == sizeof(char)){
		char *pchar = (char*)c;
		*(pchar+1) = 'W';
	}
	else if(size == sizeof(int)){
		int *pint = (int*)c;
		*(pint+1) = 5005;
	}
}

void passMArray(int A[][3][2]){
	A[2][2][1] = 222;
}

void passMArray2(int **A){
	A[2][3] = 223;
}

void passMArray3(int **A){
	A[2][3] = 224;
}

void passMArray4(int ***A){
	A[2][2][1] = 225;
}

void createMemLeak(){
	int *a  = new int;
	// as soon as this function returns *a will be destroyed and with it the address of the allocated memory
}
