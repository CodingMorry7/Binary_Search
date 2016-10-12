#include <vector>
#include <iostream>
/*
//===============================
HW#: HW2P2 combine sorting
Your Name: Chris Morikawa
Complier: g++
File Type: combine implementation file
//===============================
Purpose: The program will ask the user to input three integers into two vectors, then
take the two vectors and use combine sort and place the numbers into a final vector that is sorted out.
*/
using namespace std;
const int SIZE_3 = 3;
const int SIZE_4 = 4;

/*
//============================
// Purpose: Sort the two vectors by combining them into the result vector.
// Algorithm: First initialize three integer variables. Then go through the while
// loop to insert the integers from smallest to largest numbers into the final vector
// if there is still variables in either of the vectors (A and B) then push the rest of
// the integers into the final vector.
// PARAMETERS: vector <int> A, vector <int> B, vector <int> R
// LOCAL VARIABLES: int ia, int ib, int ir, int i, int j
//============================
*/
void Combine(vector <int> A, vector <int> B, vector <int>& R)  // combine sorted lists A and B
  {     
       int ia = 0; // index for A
       int ib = 0; // index for B
       int ir = 0; // index for R
     //Until you run out of elements in A or run out of elements in B:
       while(ia < A.size() && ib < B.size())
	{ 
	  //cout << "In thr while loop" << endl;
	  if (A[ia] < B[ib])
	   {
	     // cout << "In the if A is less than B" << endl;
	     R.push_back(A[ia]); 
	     ia = ia + 1; // get the A element
       	   }
	  else
	   {
	     //cout << "In the else B is small" << endl;
	     R.push_back(B[ib]);
	     ib = ib + 1; // get the B element
       	   }
	ir = ir + 1;
	cout << "comparison" << endl;
	}//end of while loop
       //cout << " end of while" << endl;
     //After the loop:
     //if you still have A elements left, copy them into R
       if(ia != A.size())
	{
	  for (int i = ia; i < A.size(); i++)
	   {
	    R.push_back(A[i]);
	   }
	}
	//else copy the remaining B elements into R.
	else
	{
	  for(int j = ib; j < B.size(); j++)
	   {
	     R.push_back(B[j]);
	   }
        }
   }
//=======================================
/*
Purpose: The program will ask the user to input three integers into two vectors, then
take the two vectors and combine them into a final vector that sorts the list out.
Algorithm: The main will intialize three vectors, asking the user to input three numbers into the first
vector by increasing order, and do the same for the second vector. After that it will call the combine
function and give you the sorted vector.
LOCAL VARIABLE: int answer, vector <int> L1, vector <int> L2, vector <int> L3, int input, int i, int j, int k 
*/
//======================================
int main()
{
 vector <int> L1, L2, L3;
 int input =0;
 int answer;
 cout << "Are you entering 3 or 4 numbers? (Type 3 for 3 numbers or type 4 for 4 numbers): ";
 cin >> answer;
 if (answer == 3)
   {
     cout << "Input 3 integers in increasing order into L1" << endl;
     for (int i =0; i < SIZE_3;i++)
       {
	 cout << "Element " << i << ": ";
	 cin >> input;
	 L1.push_back(input);
       }
     cout<< "Same thing again for L2" << endl;
     for (int j=0; j < SIZE_3; j++)
       {
	 cout << "Element " << j << ": ";
	 cin >> input;
	 L2.push_back(input);
       }

     Combine(L1, L2, L3);

     cout << "L3: ";
     for( int k = 0; k < L3.size(); k++)
       cout << L3[k] << " ";
     cout << "DONE!" << endl;
   }
 if (answer == 4)
   {
     cout << "Input 4 integers in increasing order into L1" << endl;
     for (int i =0; i < SIZE_4;i++)
       {
         cout << "Element " << i << ": ";
         cin >> input;
         L1.push_back(input);
       }
     cout<< "Same thing again for L2" << endl;
     for (int j=0; j < SIZE_4; j++)
       {
         cout << "Element " << j << ": ";
         cin >> input;
         L2.push_back(input);
       }

     Combine(L1, L2, L3);

     cout << "L3: ";
     for( int k = 0; k < L3.size(); k++)
       cout << L3[k] << " ";
     cout << "DONE!" << endl;
   }
return 0;
}

