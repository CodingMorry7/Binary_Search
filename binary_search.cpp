//=========================================================
//HW#: HW2P1 analysis
//Your name: Chris Morikawa
//Complier:  g++
//File type: binary search implementation file
//=========================================================

using namespace std;
#include <iostream>
int binarySearch (int L[], int x, int first, int last);
//Purpose of the program: The user enters in a number they want to search in the array.
//Algorithm: The main will initialize the array to have a set of ten numbers. It wil ask the
//user what number they want to search and call the function binarySearch. The user will ethier get 
//two answers: 1: The program could not find the number, or 2: The program found the number
//and report back the number and it's position in the array.
int main()
{
  const int max = 10;
  int list[max] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }; //Set up the array with a set of numbers
  
  int num_seek;
  int myfirst = 0; 
  int mylast = max - 1; //  set up initial indices
  cout << "What number do you seek?: " << endl;
  cin >> num_seek; 
  int resultloc = binarySearch(list, num_seek, myfirst, mylast); // The variable resultloc will hold the result when the 
  // function is done.
  if (resultloc == -1) // If no number exists then report back saying can't find it.
	cout << "mmm... Sorry I can't find " << num_seek << endl;
  else // else the program found the number
	cout << "The number " << num_seek << " was found in position: " << resultloc << endl;
  cout << "End of the Program! Goodbye!" << endl; 
  return 0;
}
//==============================================================================
//----------------------------------------------------------
//PURPOSE: To go through the array and find the location 
//of the number in the array.
//PARAMETER: the array L[], the number they seek int x, the minimum int first,
// the maximum number int last
//LOCAL VARIABLES: int middle
//ALGORITHM: Divides the array up into two and checks to see if the numebr is
// in the middle, left side of the array, or right side of the array, and 
// calls the function again within it (basically recurrsion).  
//----------------------------------------------------------
int binarySearch(int L[], int x, int first, int last) 
{
   if (first > last)
   {
     return -1; //return -1 if myfrist is bigger than mylast.
   }
   int middle = (first + last)/2; 
   
   if (x == L[middle])
   { 
     return middle + 1; //found x at location middle
   }
   
   else if (x < L[middle]) 
   {
     last  = middle - 1; // go to first half
   }
   
   else if (x > L[middle])
   { 
     first = middle + 1; // go to second half
   }
   
   return binarySearch(L, x, first, last); // recursive call
}
//-----------------------------------------------------
