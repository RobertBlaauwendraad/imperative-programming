#include <iostream>
#include <fstream>          // for file I/O
#include <cassert>          // for assertion checking

using namespace std;

enum Action { Encrypt, Decrypt };

int seed = 0;

void initialise_pseudo_random (int r)
{
//  pre-condition:
    assert (r > 0 && r <= 65536) ;
/*  post-condition:
    seed has value r.
*/
    seed = r ;
}

int next_pseudo_random_number ()
{
//  pre-condition:
    assert (seed > 0 && seed <= 65536) ;
/*  post-condition:
    result value > 0 and result value <= 65536 and result value != seed at entry of function
*/
    const int SEED75 = seed * 75 ;
    int next = (SEED75 & 65535) - (SEED75 >> 16) ;
    if (next < 0)
        next += 65537 ;
    seed = next ;
    return next ;
}

char rotate_char (char a, int r, Action action)
{
//  Pre-condition:
    assert ( r >= 0 );
/*  Post-condition:
    result is the encryption/decryption of a single character
*/
    if (a >= 32)
    {
        if(action == Action::Encrypt) {
            a = (a - 32 + (r % (128 - 32)) + (128 - 32)) % (128 - 32) + 32;
        } else if (action == Action::Decrypt) {
            a = (a - 32 - (r % (128 - 32)) + (128 - 32)) % (128 - 32) + 32;
        }
    }
    return a;
}

bool open_input_and_output_file (ifstream& infile, ofstream& outfile)
{
//  Pre-condition:
    assert ( true );
/*  Post-condition:
    if result is true input and output files are opened
*/

    string infile_name;
    string outfile_name;
    cout << "Please enter the input file name (without symbols): " << endl;
    cin >> infile_name;
    cout << "Please enter the output file name (without symbols): " << endl;
    cin >> outfile_name;

    if(infile_name == outfile_name) {
        cout << "Input and output file name must be different.\n" << endl;
        return false;
    }

    infile.open(infile_name);
    if (infile.fail()) {
        cout << infile_name << " could not be opened\n" << endl;
        return false;
    }

    outfile.open(outfile_name);
    if (outfile.fail()) {
        cout << outfile_name << " could not be openend\n" << endl;
        return false;
    }

    cout << "Files opened successfully\n" << endl;
    return true;
}

Action get_user_action ()
{// Pre-condition:
    assert ( true ) ;
/*  Post-condition:
    result is the Action that the user has indicated that the program should encrypt / decrypt
*/
    cout << "Do you want to encrypt the file? (y/n): " ;
    string answer ;
    cin  >> answer ;
    if (answer == "y")
        return Encrypt;
    else
        return Decrypt;
}

int initial_encryption_value ()
{// Pre-conditie:
    assert (true) ;
/*  Post-condition:
    result is a value between 0 and 65355 (both inclusive)
*/
    int initial_value = -1 ;
    while (initial_value < 0 || initial_value > 65535)
    {
        cout << "Please enter the initial coding value (greater or equal to 0 and less than 65536)" << endl ;
        cin  >> initial_value ;
    }
    return initial_value ;
}

void use_OTP (ifstream& infile, ofstream& outfile, Action action, int initial_value)
{
//  Pre-condition:
    assert( infile.is_open() && outfile.is_open() );
/*  Post-condition:
    Encrypts/decrypts input file to output file
*/
    char a;
    char b;
    infile.get(a);
    int r = initial_value;
    initialise_pseudo_random(r);
    while (!infile.fail())
    {
        b = rotate_char(a, r, action);
        outfile.put(b);
        infile.get(a);
        r = next_pseudo_random_number();
    }
}

#ifndef TESTING
int main()
{
    const Action ACTION = get_user_action() ;
    ifstream input_file  ;
    ofstream output_file ;
    if (!open_input_and_output_file (input_file,output_file))
    {
        cout << "Program aborted." << endl ;
        return -1 ;
    }
    const int INITIAL_VALUE = initial_encryption_value () ;
    use_OTP (input_file,output_file,ACTION,INITIAL_VALUE);
    input_file.clear () ;
    output_file.clear () ;
    input_file.close () ;
    output_file.close () ;

    if (!input_file || !output_file)
    {
        cout << "Not all files were closed succesfully. The output might be incorrect." << endl ;
        return -1 ;
    }
    return 0 ;
}
#endif