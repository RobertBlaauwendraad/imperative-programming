#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

struct Length
{
	int minutes;							// #minutes (0..)
	int seconds;							// #seconds (0..59)
};

struct Track
{
	string artist;                          // name of artist
	string cd;                              // cd title
	int    year;                            // year of appearance (if known)
	int    track;							// track number
	string title;                           // track title
	string tags;                            // tags
	Length time;							// playing time
	string country;                         // main countr(y/ies) of artist
};

typedef Track El;                           // as explained in lecture, define algorithms on El

int size (const vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    result is the size of data, converted to int
*/
    return static_cast<int>(data.size()) ;
}

void swap (El& a, El& b)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    value of a has been assigned to b and vice versa
*/
    const El TEMP = a ;
    a = b ;
    b = TEMP ;
}

struct Slice
{  int from;     // from >= 0
   int length;   // length >= 0
};

Slice mkSlice (int from, int length)
{// Precondition:
    assert (from >= 0 && length >= 0);
/*  post-condition:
    return slice with given from and length
*/
    Slice s = { from, length};
    return s;
}

Slice mkSlice (const vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns the slice for the entire vector data.
*/
    Slice s = { 0, size (data) };
    return s;
}

bool valid_slice (Slice s)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if all selector values of s are not negative.
*/
    return 0 <= s.from && 0 <= s.length;
}
bool valid_slice (const vector<El>& data, Slice s)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if s is a valid slice for data
*/
    return valid_slice (s) && s.from + s.length <= size (data);
}

int first (Slice s)
{// Precondition:
    valid_slice (s);
/*  Postcondition:
    result is index of first element in s (s.from)
*/
    return s.from;
}

int last (Slice s)
{// Precondition:
    valid_slice (s);
/*  Postcondition:
    result is index of last element in s (s.from + s.length - 1)
*/
    return s.from + s.length - 1;
}



bool operator== (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if all selector values of a are equal to their counterparts of b
*/

    if (a.artist == b.artist &&
        a.cd == b.cd &&
        a.year == b.year &&
        a.track == b.track &&
        a.title == b.title &&
        a.tags == b.tags &&
        a.time.minutes == b.time.minutes &&
        a.time.seconds == b.time.seconds &&
        a.country == b.country){
        return true;
    }

    return false;

}

bool operator< (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    check the assignment for the proper definition of < on Tracks
*/

    if(a == b){
        return false;
    }

    if(a.artist < b.artist){
        return true;
    } 

    if(a.artist > b.artist){
        return false;
    }

    if(a.artist == b.artist){
        if(a.cd < b.cd){
            return true;
        } 

        if(a.cd > b.cd){
            return false;
        }

        if(a.cd == b.cd){
                if(a.track < b.track){
                    return true;
                }
                if(a.track > b.track){
                    return false;
                }
        }
    }
    return false;

}

bool operator>(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a does not precede b according to the ordering < on Tracks (don't forget to implement operator<)
*/
	return b < a;
}

bool operator<=(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a < b or a == b according to their definitions on Tracks (don't forget to implement operator< and operator==)
*/
	return a < b || a == b;
}

bool operator>=(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a > b or a == b according to their definitions on Tracks (don't forget to implement operator< and operator==)
*/
	return a > b || a == b;
}


int max_value_at (const vector<El>& data, Slice s)
{// Precondition:
    assert (valid_slice (data, s));
/*  Postcondition:
    data[result] is the maximum of every element in data[first (s)] ... data[last (s)]
*/
    int maximum = first(s);
    for (int i = first(s)+1; i < last(s)+1; i++) {
        if (data[i] > data[maximum])
        {
            maximum = i;
        }
    }
    return maximum;
}

bool is_sorted (const vector<El>& data, Slice s)
{// pre-condition:
    assert (valid_slice (data, s));
/*  post-condition:
    result is true if data[first (s)] <= data[first (s) + 1] ... data[last(s)-1] <= data[last(s)]
*/
    if (size(data) < 2) return true;

    for (int i = first(s); i < last(s); i++)
    {
        if(data[i] > data[i + 1])
            return false;
    }
    return true;
}

void insert (vector<El>& data, Slice s)
{// Precondition:
    assert (valid_slice (data,s) && s.length > 0 && is_sorted (data, mkSlice(s.from, s.length - 1)));
/*  Postcondition:
    data[last(s)] is moved in data[first(s)]...data[last(s)] and is_sorted (data, s)
*/
    int i = last(s) - 1;
    while (i >= first(s) && data[i] > data[i+1])
    {
        swap(data[i], data[i+1]);
        i--;
    }
}


/**********************************************************************************************************
 *
 * insertion sort algorithm:
 * 
 *********************************************************************************************************/
void insertion_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    int sorted = 1;
    while(sorted < size(data)) {
        sorted++;
        insert(data, mkSlice(0, sorted));
    }
}

/**********************************************************************************************************
 *
 * selection sort algorithm:
 * 
 *********************************************************************************************************/
void selection_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    for (int i = size(data); i > 1; i--)
    {
        int max = max_value_at(data, mkSlice(0, i));
        swap(data[max], data[i-1]);
    };
}

/**********************************************************************************************************
 *
 * bubble sort algorithm:
 * 
 *********************************************************************************************************/
bool bubble (vector<El>& data, Slice unsorted)
{// Precondition:
    valid_slice (data, unsorted);
/*  Postcondition:
    immediate pairs in data with slice unsorted are swapped if left element is larger than right element, and result is 
    true only if this is done at least once (don't forget to implement operator< and operator==)
*/
    bool swapped = false;

    for (int i = 0; i < last(unsorted); i++)
    {
        if(data[i] > data[i+1]) {
            swap(data[i], data[i+1]);
            swapped = true;
        }
    }
    return swapped;
}

void bubble_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    int unsorted = size(data);
    bool swapped = true;
    while (swapped)
    {
        swapped = bubble(data, mkSlice(0, unsorted));
        unsorted--;
    }
}

/**********************************************************************************************************
 *
 * heap sort algorithm:
 * 
 *********************************************************************************************************/
int left_sibling (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the left sibling of an element at index i in a heap structured array/vector
*/
    return i-1;
}

int right_sibling (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the right sibling of an element at index i in a heap structured array/vector
*/
    return i+1;
}

int parent (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the parent of an element at index i in a heap structured array/vector
*/
    return (i-1) / 2;
}

int left_child (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the left child of an element at index i in a heap structured array/vector
*/
    return 2*(i+1)-1;
}

int right_child (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the right child of an element at index i in a heap structured array/vector
*/
    return 2*(i+1);
}

bool is_a_heap (const vector<El>& data, Slice s)
{// Precondition:
    valid_slice (data,s);
/*  Postcondition:
    result is true only if all existing children in slice s of data have a value that is not greater than their parent
*/
    for (int i = first(s); i < parent(last(s)) + 1; i++)
    {
        if (left_child(i) <= last(s) && data[i] < data[left_child(i)]) 
            return false;
        if (right_child(i) <= last(s) && data[i] < data[right_child(i)])
            return false;
    }
    return true;
}

void push_up ( vector<El>& data, int elem )
{// Precondition:
    assert (0 <= elem && elem < size (data) && is_a_heap (data, mkSlice (0,elem)));
/*  Postcondition:
    data[0] ... data[elem] is a heap
*/
    while (elem > 0 && data[parent(elem)] < data[elem])
    {
        swap(data[parent(elem)], data[elem]);
        elem = parent(elem);
    }
    
}

void build_heap ( vector<El>& data )
{// Precondition:
    assert (true );
/*  Postcondition:
    data is a heap structure
*/
    for (int i = 1; i < size(data); i++)
    {
        push_up(data, i);
    }
}

void push_down (vector<El>& data, int unsorted)
{// Precondition:
    assert (is_a_heap (data, mkSlice (1,unsorted)));
/*  Postcondition:
    data[0] ... data[unsorted] is a heap
*/
    int i = 0;
    while (data[i] < data[left_child(i)] || data[i] < data[right_child(i)])
    {
        int j;
        if (data[left_child(i)] > data[right_child(i)])
            j = left_child(i);
        else 
            j = right_child(i);
        swap(data[i], data[j]);
        i = j;
    }
}

void pick_heap (vector<El>& data)
{// Precondition:
    assert(is_a_heap (data, mkSlice (data)));
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement < and ==)
*/
    int unsorted = size(data)-1;
    while (unsorted > 0)
    {
        swap(data[0], data[unsorted]);
        unsorted--;
        push_down(data, unsorted);
    }
}

void heap_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement < and ==)
*/
    build_heap(data);
    pick_heap(data);
}



#ifndef TESTING
int main()
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the music database "Tracks.txt" has been read (if present and correctly formatted).
    The assignment queries have been executed and their result has been shown on screen.
    In case of the bonus assignment, the user has been able to query the database and has
    seen the results of these queries.
*/
	return 0;
}
#endif
