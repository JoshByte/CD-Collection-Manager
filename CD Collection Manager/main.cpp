/*********************************************************************/
/* This program diplays a main menu of options to manage a small CD  */
/* collection with the following options:                            */
/*       1. Read Collection                                          */
/*       2. Display Collection                                       */
/*       3. Sort Collection                                          */
/*       4. Find a CD                                                */
/*       5. Edit a CD                                                */
/*       6. Math Break                                               */
/*       7. Quit                                                     */
/*                                                                   */
/* It will be implemented in stages.                                 */
/* This stage has the following optiions implemented:                */
/*       1. Read Collection                                          */
/*       2. Display Collection                                       */
/*       3. Sort Collection                                          */
/*       4. Find a CD                                                */
/*       5. Edit a CD  (stub)                                        */
/*       6. Math Break                                               */
/*       7. Quit                                                     */
/*                                                                   */
/* Math Break has its own menu:                                      */
/*       1. Even or Odd                                              */
/*       2. Prime Number                                             */
/*       3. Quit                                                     */
/*********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

/**************************************************/
/* CD Class Decclaration                          */
/* Private member variables:                      */
/*      artist			CD artist                 */
/*      title			CD title                  */
/*      yearReleased	Year CD was released      */
/* Public member functions:                       */
/*     Mutators:                                  */
/*      setArtist                                 */
/*      setTitle                                  */
/*      setYearReleased                           */
/*    Accessors:                                  */
/*		getArtist                                 */
/*		getTitle                                  */
/*		getYearReleased                           */
/**************************************************/
class CD
{
private:
    string artist,    // CD artist
        title;        // CD title
    int yearReleased, // Year CD was released
        numTracks;
    string *tracks;

public:
    CD();
    ~CD();
    // Mutators
    void setArtist(string);
    void setTitle(string);
    void setYearReleased(int);
    void setNumTracks(int);
    void setTrackName(int, string);

    // Accessors
    string getArtist();
    string getTitle();
    int getYearReleased();
    int getNumTracks();
    string getTrackName(int);

    void deleteTracks();
};
CD::CD()
{
    artist = "";
    title = "";
    yearReleased = 0;
    numTracks = 0;
    tracks = nullptr;
}

void CD::setArtist(string a)
{
    artist = a;
}

void CD::setTitle(string t)
{
    title = t;
}

void CD::setYearReleased(int y)
{
    yearReleased = y;
}

void CD::setNumTracks(int n)
{
    numTracks = n;
    tracks = new string[numTracks];
}

void CD::setTrackName(int index, string name)
{
    tracks[index] = name;
}

string CD::getArtist()
{
    return artist;
}

string CD::getTitle()
{
    return title;
}

int CD::getYearReleased()
{
    return yearReleased;
}

int CD::getNumTracks()
{
    return numTracks;
}

string CD::getTrackName(int index)
{
    return tracks[index];
}

void CD::deleteTracks()
{
    if (tracks)
    {
        delete[] tracks;
        tracks = nullptr;
        numTracks = 0;
    }
}
CD::~CD()
{
    deleteTracks();
}

// Function prototypes
int getMainMenuOption();
bool readCollection(CD[]);
void displayCollection(CD[]);
void sortCollection(CD[]);
void findCD(CD[]);
int searchForCD(CD[], string, string);
void editCD(CD[]);
void editOneCD(CD *);
void addTracks(CD[]);
void deleteTracks(CD[]);
void mathBreak();
int getMathBreakOption();
void evenOdd();
void primeNumber();
int getPositiveInt();
int isEven(int);
int isPrime(int);

// Global constants
const int NUM_CDS = 17; // Number of CDs in collection
const int READ = 1,     // Menu option for Read Collection
    DISPLAY = 2,        // Menu option for Display Collection
    SORT = 3,           // Menu option for Sort Collection
    FIND = 4,           // Menu option for Find a CD
    EDIT = 5,           // Menu option for Edit a CD
    MATH = 8,           // Menu option for Math Break
    QUIT = 9;           // Menu option for Quit

int main()
{
    // Variable Declarations
    CD albums[NUM_CDS];    // array to hold the CD objects
    int option;            // option returned by function
    bool beenRead = false; // the collection has been read or not

    // Get the first option
    option = getMainMenuOption();

    // Continue to display the main menu
    // until user chooses to quit
    while (option != QUIT)
    {
        switch (option)
        {
        case READ:
            // Read the collection option
            beenRead = readCollection(albums);
            break;
        case DISPLAY:
            // Display the collection option
            if (beenRead)
                displayCollection(albums);
            else
                cout << "\n*** Must read collection first ***\n";
            break;
        case SORT:
            // Display the collection option
            if (beenRead)
                sortCollection(albums);
            else
                cout << "\n*** Must read collection first ***\n";
            break;
        case FIND:
            // Display the collection option
            if (beenRead)
                findCD(albums);
            else
                cout << "\n*** Must read collection first ***\n";
            break;
        case EDIT:
            // Display the collection option
            if (beenRead)
                editCD(albums);
            else
                cout << "\n*** Must read collection first ***\n";
            break;
        case 6:
            // Add tracks
            if (beenRead)
                addTracks(albums);
            else
                cout << "\n*** Must read collection first ***\n";
            break;
        case 7:
            // Delete tracks
            if (beenRead)
                deleteTracks(albums);
            else
                cout << "\n*** Must read collection first ***\n";
            break;
        case MATH:
            // Math Break option
            mathBreak();
            break;
        }

        // Get the next option
        option = getMainMenuOption();

    } // end while option is not quit

} // end main

/*****************************************************/
/* Function:   getMainMenuOption                     */
/* Inputs:     none                                  */
/* Outputs:    a valid user option                   */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option, validates          */
/*             and returns it.                       */
/*             Menu options:                         */
/*             1. Display Test CD                    */
/*             1. Math Break                         */
/*             2. Quit                               */
/*****************************************************/
int getMainMenuOption()
{
    // Variable Declarations
    int option; // option entered by user

    do
    {
        // Display main menu
        cout << "\n*************\n";
        cout << "Main Menu\n";
        cout << "-----------\n";
        cout << "1. Read Collection\n";
        cout << "2. Display Collection\n";
        cout << "3. Sort Collection\n";
        cout << "4. Find a CD\n";
        cout << "5. Edit a CD\n";
        cout << "6. Add Tracks for a CD\n";
        cout << "7. Delete All Tracks for a CD\n";
        cout << "8. Math Break\n";
        cout << "9. Quit\n";

        // Read the first option
        cout << "Option: ";
        cin >> option;

        // Display error message for invalid options
        if ((option < 1) || (option > QUIT))
            cout << "Invalid option\n\n";

    } while ((option < 1) || (option > QUIT));

    return option;

} // end getMainMenuOption()

/**************************************************************/
/* Function:	readCollection                                */
/* Inputs:		Array of 10 CD objects                        */
/* Outputs:		none                                          */
/* Description:	This function reads 10 records out of a file  */
/*           	and stores them in an array of CD objects.    */
/**************************************************************/
bool readCollection(CD cds[])
{
    ifstream inputFile;   // Input file
    string artist,        // CD artist
        title;            // CD title
    int year;             // Year CD was released
    bool success = false; // Collection was read successfully
                          // or not

    // Open the file
    inputFile.open("cd.txt");

    // If file opened
    if (inputFile)
    {
        // Read 10 records
        for (int i = 0; i < NUM_CDS; i++)
        {
            // Read the artist, title and year released
            getline(inputFile, artist);
            getline(inputFile, title);
            inputFile >> year;
            // Move past the newline that was not
            // processed when year was read
            inputFile.ignore(100, '\n');

            // cout << "\n    ***** " << artist << "\n" << title << "\n" << year << endl << endl;

            // Set the member variables
            cds[i].setArtist(artist);
            cds[i].setTitle(title);
            cds[i].setYearReleased(year);

        } // end for

        // Close the input file
        inputFile.close();
        cout << "\nCD collection has been read\n\n";
        // Set flag to indicate collection was successfully read
        success = true;
    } // end if input file opened
    else
        cout << "Error: Could not open input file\n";

    return success;

} // end readCollection()

/*************************************************************/
/* Function:	displayCollection                            */
/* Inputs:		Array of 10 CD objects                       */
/* Outputs:		none                                         */
/* Description:	This function displays the collection of 10  */
/*           	CDs stored in an array of CD objects.        */
/*************************************************************/
void displayCollection(CD cds[])
{
    // Display title
    cout << "\n\nCD COLLECTION\n";
    cout << "-------------\n";

    // Display column headings
    cout << left << setw(30) << "Artist" << setw(30) << "Title"
         << setw(10) << "Year Released\n";
    cout << left << setw(30) << "------" << setw(30) << "-----"
         << setw(10) << "-------------\n";

    // Display the 10 CDs
    for (int i = 0; i < NUM_CDS; i++)
    {
        cout << left << setw(30) << cds[i].getArtist()
             << left << setw(30) << cds[i].getTitle()
             << left << setw(10) << cds[i].getYearReleased() << endl;

        if (cds[i].getNumTracks())
            for (int j = 0; j < cds[i].getNumTracks(); j++)
                cout << "\t" << j + 1 << "." << cds[i].getTrackName(j) << endl;
    }

} // end displayCollection()

/*************************************************************/
/* Function:	sortCollection                               */
/* Inputs:		Array of 10 CD objects                       */
/* Outputs:		none                                         */
/* Description:	This function uses the bubble sort to sort   */
/*              the collection by artist - ascending order   */
/*************************************************************/
void sortCollection(CD cds[])
{
    CD temp;   // CD object used for swapping
    bool swap; // Flag to indicate swap occurred

    do
    {
        swap = false;
        for (int i = 0; i < NUM_CDS - 1; i++)
        {
            if (cds[i].getArtist() > cds[i + 1].getArtist())
            {
                temp = cds[i];
                cds[i] = cds[i + 1];
                cds[i + 1] = temp;
                swap = true;
            }

        } // end for each CD

    } while (swap);

} // end sortCD()

/*************************************************************/
/* Function:	findCD                                       */
/* Inputs:		Array of 10 CD objects                       */
/* Outputs:		The postion in the array - used by other     */
/*              functions.                                   */
/* Description:	This function will let the user search for   */
/*              a CD by Artist and Title. A message is       */
/*              displayed stating the CD is or is not in     */
/*              the collection.                              */
/*************************************************************/
void findCD(CD tunes[])
{
    string artist,    // CD artist
        title;        // CD title
    int position = 0; // position in the CD array

    // Clear the input buffer - option was just read
    cin.ignore();

    // Read artist and title for CD
    // You must search on both fields since an
    // artist may have more than 1 CD in the collection
    cout << "\nCD Search\n";
    cout << "    Enter artist: ";
    getline(cin, artist);
    cout << "    Enter title: ";
    getline(cin, title);

    // Display the CD artist and title
    cout << "CD: " << artist << " - " << title;

    // Display an appropriate message based on whether
    // or not the CD was found
    if (searchForCD(tunes, artist, title) >= 0)
        cout << " is in collection\n\n";
    else
        cout << " is not in collection\n\n";

} // end findCD()

/*************************************************************/
/* Function:	searchForCD                                  */
/* Inputs:		Array of 10 CD objects                       */
/*              CD artist to search for                      */
/*              CD title to search for                       */
/* Outputs:		The position in the array or -1 if not found */
/*               - used by other functions.                  */
/* Description:	This function searches for a CD by Artist    */
/*              and Title. The position is returned.         */
/*************************************************************/
int searchForCD(CD tunes[], string artist, string title)
{
    int position = -1; // position of CD in array
                       // or -1 if not found

    // Look through array for matching CD
    for (int i = 0; i < NUM_CDS; i++)
        // Check artist
        if (tunes[i].getArtist() == artist)
            // Check title
            if (tunes[i].getTitle() == title)
                // Found the CD - save the position in the array
                position = i;

    return position;

} // end searchForCD()

/*************************************************************/
/* Function:	editCD                                       */
/* Inputs:		Array of 10 CD objects                       */
/* Outputs:		none                                         */
/* Description:	This function asks the user for a CD artist  */
/*              and title. If the CD is in the collection    */
/*              a menu of choices of fields to edit is       */
/*              displayed, new value(s) are entered and the  */
/*              CD object is updated.                        */
/*************************************************************/
void editCD(CD music[])
{
    string artist, // CD artist
        title;     // CD title
    int position,  // position in the CD array
        option,    // Field to edit
        year;      // CD year released

    // Clear the input buffer - option was just read
    cin.ignore();

    cout << "CD Search\n";
    cout << "    Enter artist: ";
    getline(cin, artist);
    cout << "    Enter title: ";
    getline(cin, title);

    // First determine if the CD is in the collection
    position = searchForCD(music, artist, title);
    if (position >= 0)
        editOneCD(&music[position]);
    else
        cout << "CD: " << artist << " - " << title << "is not in the collection\n";
}

void editOneCD(CD *oneCD)
{
    int option, year;
    string artist, title;

    // Display the edit menu
    do
    {
        cout << "\nEdit Menu\n";
        cout << "   1. Artist\n";
        cout << "   2. Title\n";
        cout << "   3. Year Released\n";
        cout << "   4. Exit Edit Menu\n";
        cout << "Enter field to edit: ";

        // Read the option
        cin >> option;
        cin.ignore();

        // Branch based on option
        switch (option)
        {
        case 1: // Edit the artist
            cout << "Enter new artist info: ";
            getline(cin, artist);
            oneCD->setArtist(artist);
            break;
        case 2: // Edit the title
            cout << "Enter new title info: ";
            getline(cin, title);
            oneCD->setTitle(title);
            break;
        case 3: // Edit the year released
            cout << "Enter new year released: ";
            cin >> year;
            cin.ignore();
            oneCD->setYearReleased(year);
            break;
        case 4:
            break; // Don't want to display error
                   // message if option is to quit
        default:
            cout << "Invalid option\n";
        }

    } while (option != 4);
    cout << endl;

} // end editOneCD()

void addTracks(CD cds[])
{
    int numTracks, index;
    string track, artist, title;

    cin.ignore();

    cout << "CD for adding tracks:\n";
    cout << "  Artist: ";
    getline(cin, artist);
    cout << "  Title: ";
    getline(cin, title);

    index = searchForCD(cds, artist, title);

    if (index >= 0)
    {
        cout << "How many tracks? ";
        cin >> numTracks;

        cds[index].setNumTracks(numTracks);
        cin.ignore();

        for (int i = 0; i < numTracks; i++)
        {
            cout << "Enter track #" << i + 1 << " name: ";
            getline(cin, track);

            cds[index].setTrackName(i, track);
        }
    }
}

void deleteTracks(CD cds[])
{
    int index;
    string artist, title;

    cin.ignore();

    cout << "CD for deleting tracks:\n";
    cout << "  Artist: ";
    getline(cin, artist);
    cout << "  Title: ";
    getline(cin, title);

    index = searchForCD(cds, artist, title);

    if (index >= 0)
    {
        if (cds[index].getNumTracks())
        {
            cds[index].deleteTracks();
            cout << "Tracks have been deleted\n";
        }
        else
            cout << "This CD had no tracks\n";
    }
}

/*****************************************************/
/* Function:   mathBreak                             */
/* Inputs:     none                                  */
/* Outputs:    none                                  */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option and plays the game. */
/*             Menu options:                         */
/*             1. Even or Odd                        */
/*             2. Prime Number                       */
/*             3. Quit                               */
/*****************************************************/
void mathBreak()
{
    // Variable Declarations
    int option; // option entered by user

    // Get the first option
    option = getMathBreakOption();

    // Check for option to quit
    while (option != 3)
    {
        switch (option)
        {
        case 1: // Even or Odd
            evenOdd();
            break;
        case 2: // Prime Number
            primeNumber();
            break;

        } // end switch

        // Get the next option
        option = getMathBreakOption();

    } // end while option is not quit

} // end mathBreak()

/*****************************************************/
/* Function:   getMathBreakOption                    */
/* Inputs:     none                                  */
/* Outputs:    a valid user option                   */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option, validates          */
/*             and returns it.                       */
/*             Menu options:                         */
/*             1. Math Break                         */
/*             2. Quit                               */
/*****************************************************/
int getMathBreakOption()
{
    // Variable Declarations
    int option; // option entered by user

    do
    {
        // Display main menu
        cout << "\n***************\n";
        cout << "Math Break Menu\n";
        cout << "---------------\n";
        cout << "1. Even or Oddk\n";
        cout << "2. Prime Number\n";
        cout << "3. Quit\n";

        // Read the option
        cout << "Option: ";
        cin >> option;

        // Display error message for invalid options
        if ((option < 1) || (option > 3))
            cout << "Invalid option\n\n";

    } while ((option < 1) || (option > 3));

    return option;

} // end getMathBreakOption()

/*****************************************************/
/* Function:   evenOdd                               */
/* Inputs:     none                                  */
/* Outputs:    none                                  */
/* Purpose:    This function prompts the user for a  */
/*             positive integer and displays a       */
/*             message identifying whether the int   */
/*             is even or odd.                       */
/*****************************************************/
void evenOdd()
{
    // Variable Declarations
    int num; // User input

    // Display heading for the game
    cout << "\n     Even or Odd\n";
    cout << "********************\n";

    // Read first integer
    num = getPositiveInt();

    // Continue to ask for numbers
    // until the user enters zero
    while (num > 0)
    {
        // Identify whether the number
        // is even or odd
        if (isEven(num))
            cout << num << " is even\n";
        else
            cout << num << " is odd\n";

        // Read next integer
        num = getPositiveInt();

    } // end while number is > 0

} // end evenOdd()

/*****************************************************/
/* Function:   isEven                                */
/* Inputs:     integer to be tested                  */
/* Outputs:    1 if even, 0 if odd                   */
/* Purpose:    This function takes one integer input */
/*             and determines if it is even or odd . */
/*****************************************************/
int isEven(int number)
{
    // return 1(true) if number is even
    // or 0(false) if the number is odd
    return !(number % 2);
}

/*****************************************************/
/* Function:   primeNumber                           */
/* Inputs:     none                                  */
/* Outputs:    none                                  */
/* Purpose:    This function prompts the user for a  */
/*             positive integer and displays a       */
/*             message identifying whether the int   */
/*             is prime or not.                      */
/*****************************************************/
void primeNumber()
{
    // Variable Declarations
    int num; // User input

    cout << "\n     Prime Number\n";
    cout << "********************\n";

    // Read first integer
    num = getPositiveInt();

    while (num > 0)
    {
        // Prime numbers start at 2
        if (num == 1)
            cout << "Prime numbers start at 2\n";
        else if (isPrime(num))
            cout << num << " is prime\n";
        else
            cout << num << " is not prime\n";

        // Read next integer
        num = getPositiveInt();

    } // end while num > 0

} // end primeNumber()

/*****************************************************/
/* Function:   isPrime                               */
/* Inputs:     integer to test                       */
/* Outputs:    1 if prime, 0 if not prime            */
/* Purpose:    This function takes one integer input */
/*             and determines if it is prime or not. */
/*****************************************************/
int isPrime(int number)
{
    // Variable declarations
    int limit, // Upper limit for loop
        i;     // Loop control variable

    // Set the limit for the loop -
    // No need to interate through all the numbers
    // between 2 and the number.
    // This makes the loop more efficient.
    limit = sqrt(number) + 1;

    // See if any nmber between 2 and
    // the square root of the number
    // evenly divides into the number
    for (i = 2; (i < limit) && (number % i); i++)
        ;

    // If 'i' reaches the value of number,
    // it is prime; any value of 'i'
    // less than that means it is not prime.
    return !(i < limit);
} // end isPrime()

/*****************************************************/
/* Function:   getPositiveInt                        */
/* Inputs:     none                                  */
/* Outputs:    a positive integer                    */
/* Purpose:    This function returns a positive      */
/*             integer > 0                           */
/*****************************************************/
int getPositiveInt()
{
    // Variable declarations
    int num; // user input

    // Read integer
    cout << "Enter a positive integer or 0 to quit: ";
    cin >> num;

    // Validate the input
    // numbers must be 0 or larger
    while (num < 0)
    {
        cout << "Invalid input; must be 0 or larger\n";
        cout << "Enter a positive integer or 0 to quit: ";
        cin >> num;
    } // end while input is invalid

    // Return valid input
    return num;

} // end getPositiveInt()