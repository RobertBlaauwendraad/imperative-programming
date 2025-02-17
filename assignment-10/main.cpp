#define NDEBUG
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

const int NO_TEST_CASES = 13;
const string FILENAME = "Tracks.txt";
int g_count = 0;
int countArray[NO_TEST_CASES] = {};

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

struct TrackDisplay
{
    bool showArtist;  // if true, show name of artist
    bool showAlbum;   // if true, show cd title
    bool showYear;    // if true, show year of appearance
    bool showTrack;   // if true, show track number
    bool showTitle;   // if true, show track title
    bool showTags;    // if true, show tags
    bool showLength;  // if true, show playing time
    bool showCountry; // if true, show countr(y/ies) of artist
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
    g_count++;
    if (a.artist == b.artist &&
        a.cd == b.cd &&
        a.year == b.year &&
        a.track == b.track){
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
    g_count++;
    if (a.artist == b.artist)
    {
        if (a.year < b.year)
            return true;
        if (a.cd < b.cd)
            return true;
        if (a.cd == b.cd)
            if (a.track < b.track)
                return true;
    }
    
    if (a.artist < b.artist)
        return true;

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
    while ((left_child(i) <= unsorted && data[i] < data[left_child(i)]) || (right_child(i) <= unsorted && data[i] < data[right_child(i)]))
    {
        int j;
            if (data[left_child(i)] >= data[right_child(i)])
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

ostream &operator<<(ostream &out, const Length length)
{ // Precondition:
    assert(true);
    /*  Postcondition:
    the value of length is shown via out in the format: minutes, ':', seconds (two digits)
*/

    if (length.seconds < 10)
    {
        out << length.minutes << ":0" << length.seconds;
    }
    else
    {
        out << length.minutes << ":" << length.seconds;
    }

    return out;
}

istream &operator>>(istream &in, Track &track)
{ // Precondition:
    assert(true);
    /*  Postcondition:
        the content of the first 8 lines from in have been read and are stored in the corresponding members of track.
        The following (empty) line from in has also been read.
    */
    in >> track;
    return in;
}

void show_track(Track track, TrackDisplay lt)
{ // Precondition:
    assert(true);
    /*  Postcondition:
    only the members of track are shown for which the corresponding member in lt is true.
*/

    if (lt.showArtist)
        cout << track.artist << endl;
    if (lt.showAlbum)
        cout << track.cd << endl;
    if (lt.showYear)
        cout << track.year << endl;
    if (lt.showTrack)
        cout << track.track << endl;
    if (lt.showTitle)
        cout << track.title << endl;
    if (lt.showTags)
        cout << track.tags << endl;
    if (lt.showLength)
        cout << track.time << endl;
    if (lt.showCountry)
        cout << track.country << endl;
}

istream &operator>>(istream &in, Length &length)
{ // Precondition:
    assert(true);
    /*  Postcondition:
    the value of length has been read from in: first minutes, then ':', then seconds
*/
    char ignore;
    in >> length.minutes >> ignore >> length.seconds;
    return in;
}

int read_tracks(string filename, vector<Track> &tracks, bool show_content, int elements)
{
    // Precondition:
    assert(true);
    /*  Postcondition:
        tracks is a copy of the tracks that are found in the file with file name filename, and result
        is the number of tracks that have been read.
        The read tracks are shown on screen only if show_content is true.
    */
    ifstream in_file(filename);
    if (in_file.fail())
        return 0;

    int i = 0;
    while (!in_file.fail() && i < elements)
    {
        Track track;
        TrackDisplay td = {true, true, true, true, true, true, true, true};
        string emptyline;
        string firstLine;
        getline(in_file, firstLine);
        if (firstLine.length() == 0)
            break;
        track.artist = firstLine;
        getline(in_file, track.cd);
        in_file >> track.year;
        in_file >> track.track;
        getline(in_file, track.title);
        getline(in_file, track.title);
        getline(in_file, track.tags);
        in_file >> track.time;
        getline(in_file, track.country);
        getline(in_file, track.country);
        getline(in_file, emptyline);

        if (show_content)
            show_track(track, td);
        tracks.push_back(track);
        i++;
    }
    return tracks.size();
}

void print_algorithm_counts(string algorithm_name, vector<int>& countVector) {
    cout << algorithm_name << ',';
    for (int i = 0; i < NO_TEST_CASES; i++)
    {
        cout << countVector[i] << ',';
    }
    cout << endl;
}

void measureSorting(string algorithm_name, vector<int>& countVector)
{
    // int countArray[NO_TEST_CASES];
    vector<Track> tracks;
    for (int i = 0; i < NO_TEST_CASES; i++)
    {
        read_tracks(FILENAME, tracks, false, (i+1)*500);
 
        if(algorithm_name == "insertion")
            insertion_sort(tracks);
        else if (algorithm_name == "selection")
            selection_sort(tracks);
        else if (algorithm_name == "bubble")
            bubble_sort(tracks);
        else if (algorithm_name == "heap")
            heap_sort(tracks);

        countVector.push_back(g_count);
        // countArray[i] = g_count;
        g_count = 0;
    };

}

#ifndef TESTING
int main()
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the music database "Tracks.txt" has been read (if present and correctly formatted).
    The assignment queries have beezn executed and their result has been shown on screen.
    In case of the bonus assignment, the user has been able to query the database and has
    seen the results of these queries.
*/ 

    cout << "sorting_algorithm,";
    for (int i = 500; i <= NO_TEST_CASES*500; i=i+500)
    {
        cout << i;
        cout << ',';
    }
    cout << endl;

    // vector<int> insertionCounts;
    // measureSorting("insertion", insertionCounts);
    // print_algorithm_counts("insertion_sort", insertionCounts);

    // vector<int> selectionCounts;
    // measureSorting("selection", selectionCounts);
    // print_algorithm_counts("selection_sort", selectionCounts);

    // vector<int> bubbleCounts;
    // measureSorting("bubble", bubbleCounts);
    // print_algorithm_counts("bubble_sort", bubbleCounts);

    vector<int> heapCounts;
    measureSorting("heap", heapCounts);
    print_algorithm_counts("heap_sort", heapCounts);
    return 0;
}
#endif

/*
    a.
        The 3 nested for loops give that this function is O(n^3)
  
    b.
        3 nested for loops so O(n^3)
  
    c.
        1 while loop so O(n)
  
    d.
        This calls strlen(text) every iteration which has complexity O(n) (as it is looping through the whole string) this makes the complete function O(n*n) = O(n^2)
 
    e.
        This loops sqrt(n) times so this function does not have linear complexity, nor constant time. Therefore it is O(log n)
 
    f.
        This function has complexity O(n) because the statement push_back() inside the for loop only takes O(1) complexity and the loop itself O(n)
 
    g.
        Complexity is O(n) because the while loop ends when the vector is empty or when the vector has doubled in size.
        You could also say that all the operations done inside the loop are O(1)
 
     h.
        The while loop loops n times, the for loop inside of the while loop loops N times. So this function is O(n^2) times
 
    i.
        O(1), no loops or O(n) functions are called.
*/
