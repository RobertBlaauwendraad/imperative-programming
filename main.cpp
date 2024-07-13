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

struct TrackDisplay
{
	bool showArtist;						// if true, show name of artist
	bool showAlbum;							// if true, show cd title
	bool showYear;							// if true, show year of appearance
	bool showTrack;							// if true, show track number
	bool showTitle;							// if true, show track title
	bool showTags;                          // if true, show tags
	bool showLength;						// if true, show playing time
	bool showCountry;                       // if true, show countr(y/ies) of artist
};

bool match (string sub, string source)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    Result is true only if sub is a literal (case sensitive) sub string of source.
*/
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length is shown via out in the format: minutes, ':', seconds (two digits)
*/

    if(length.seconds < 10){
        out << length.minutes << ":0" << length.seconds;
    } else {
        out << length.minutes << ":" << length.seconds;
    }

    return out;

}

istream& operator>> (istream& in, Length& length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length has been read from in: first minutes, then ':', then seconds
*/
    char ignore;
    in >> length.minutes >> ignore >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{// Precondition:
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*  Postcondition:
    Result is the sum of a and b.
*/

    int mins = a.minutes + b.minutes;
    int secs = 0;
    if(a.seconds + b.seconds >= 60){
        mins++;
        secs = (a.seconds+ b.seconds) % 60;
    } else {
        secs = a.seconds+ b.seconds; 
    }

    Length result = { mins, secs };
    return result;

}

void show_track (Track track, TrackDisplay lt)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    only the members of track are shown for which the corresponding member in lt is true.
*/

   if(lt.showArtist) cout << track.artist << endl; 
   if(lt.showAlbum) cout << track.cd << endl; 
   if(lt.showYear) cout << track.year << endl; 
   if(lt.showTrack) cout << track.track << endl; 
   if(lt.showTitle) cout << track.title << endl; 
   if(lt.showTags) cout << track.tags << endl; 
   if(lt.showLength) cout << track.time << endl; 
   if(lt.showCountry) cout << track.country << endl; 

}

int match_tracks (const vector<Track>& tracks, string track, bool display)
{
    // Precondition
    assert(true);
    // Postcondition
    // Returns amount of matched tracks found and displays info about them if display is true

    int matches = 0;
    for (int i = 0; i < static_cast<int>(tracks.size()); i++)
    {
        if(match(track, tracks[i].title)) {
            if(display) {
                TrackDisplay td = {
                    true, true, true, true, true, true, true, true
                };
                show_track(tracks[i], td);
            }
            matches++;
        }
    }
    return matches;
}

int match_artists (const vector<Track>& tracks, string artist, bool display)
{
    // Precondition
    assert(true);
    // Postcondition
    // Returns the amount of matched tracks based on artist, each artists counted
    // max once. Displays artists if display set to true.

    vector<string> matchedArtists;
    for(int i = 0; i < static_cast<int>(tracks.size()); i++) {
        const string CURRENT_ARTIST = tracks[i].artist;
        if (match(artist, CURRENT_ARTIST))
        {
            bool alreadyMatched = false;
            for (int j = 0; j < static_cast<int>(matchedArtists.size()); j++)
            {
                if(CURRENT_ARTIST == matchedArtists[j])
                    alreadyMatched = true;
            }
            if(!alreadyMatched) {
                if(display) {
                    TrackDisplay td = {
                        true,
                        false,
                        false,
                        false,
                        false,
                        false,
                        false,
                        false
                    };
                    show_track(tracks[i], td);
                }
                matchedArtists.push_back(CURRENT_ARTIST);
            }
        }
    }
    return matchedArtists.size();
}

int match_cds (const vector<Track>& tracks, string artist, bool display)
{
    // Precondition
    assert(true);
    // Postcondition
    // Returns the amount of matched cds based on artist, each album counted
    // max once. Displays information about album if display set to true.

    vector<string> matchedAlbums;
    for (int i = 0; i < static_cast<int>(tracks.size()); i++)
    {
        if(match(artist, tracks[i].artist)) {
            bool alreadyMatched = false;
            for (int j = 0; j < static_cast<int>(matchedAlbums.size()); j++)
            {
                if (tracks[i].cd == matchedAlbums[j])
                    alreadyMatched = true;
            }
            if (!alreadyMatched)
            {
                if (display)
                {
                    TrackDisplay td = {
                        true, true, true, false, false, false, false, false};
                    show_track(tracks[i], td);
                }
                matchedAlbums.push_back(tracks[i].cd);
            }
        }
    }    
    return matchedAlbums.size();
}

int number_of_cds (const vector<Track>& tracks)
{
    // Precondition
    assert(true);
    // Postcondition
    //

    vector<string> albums;
    for(int i = 0; i < static_cast<int>(tracks.size()); i++) {
        bool alreadyCounted = false;
        for(int j = 0; j < static_cast<int>(albums.size()); j++)
            if (tracks[i].cd == albums[j]) 
                alreadyCounted = true;
        if(!alreadyCounted)
            albums.push_back(tracks[i].cd);
    }
    return albums.size();
}

istream& operator>> (istream& in, Track& track)
{// Precondition:
    assert (true) ;
    /*  Postcondition:
        the content of the first 8 lines from in have been read and are stored in the corresponding members of track.
        The following (empty) line from in has also been read.
    */ 
    in>>track;
    return in;
}

int read_tracks (string filename, vector<Track>& tracks, bool show_content)
{
    // Precondition:
    assert (true);
    /*  Postcondition:
        tracks is a copy of the tracks that are found in the file with file name filename, and result
        is the number of tracks that have been read.
        The read tracks are shown on screen only if show_content is true.
    */
   ifstream in_file(filename);
   if(in_file.fail())
       return 0;

    while(!in_file.fail()) {
        Track track;
        TrackDisplay td = {true, true, true, true, true, true, true, true};
        string emptyline;
        string firstLine;
        getline(in_file, firstLine);
        if(firstLine.length() == 0)
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
    }
    return tracks.size();
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
        Length l1 = {42, 55};

        Length l2 {24, 6};
        
        Length res = l1 + l2;

        cout << res << endl;


	return 0;
}
#endif
