// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
#include "ds.h"
using namespace std;

#define fixedp(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define Mod 1000000007
#define EPS 1e-9
#define updmax(a, b) a = max(a, b)
#define updmin(a, b) a = min(a, b)
#define nl '\n'
#define pi acos(-1.0)

int main()
{
    playlist obj;
    string again;
    do
    {
        obj.show_Menu();
        int choice;

        cin >> choice;
        // ------------------------------------------------------
        // handle invalid (non-integer) input
        if (cin.fail())
        {
            cin.clear();            // reset error state
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Error: Please enter a number from 1 to 8\n";
            continue; // restart loop
        }

        // clear rest of the line so getline works afterwards
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // ------------------------------------------------------
        string song;
        string newName;

        switch (choice)
        {
        case 1:
            cout << "Enter a Song: ";
            getline(cin, song);
            if (song.empty())
            {
                cout << "No song entered. Operation cancelled.\n";
            }
            else
            {
                obj.insert_Song(song);
            }
            break;
        case 2:
            cout << "Enter a song to delete: ";
            getline(cin, song);
            if (song.empty())
            {
                cout << "No song entered. Operation cancelled.\n";
            }
            else
            {
                obj.delete_Song(song);
            }
            break;
        case 3:
            cout << "Enter a song to search about: ";
            getline(cin, song);
            if (song.empty())
            {
                cout << "No song entered. Operation cancelled.\n";
            }
            else
            {
                obj.search_Song(song);
            }
            break;

        case 4:
            cout << "Enter a song to update: ";
            getline(cin, song);
            if (song.empty())
            {
                cout << "No song entered. Operation cancelled.\n";
                break;
            }
            cout << "Enter the new song name: ";
            getline(cin, newName);
            if (newName.empty())
            {
                cout << "No new name entered. Operation cancelled.\n";
            }
            else
            {
                obj.update_songName(song, newName);
            }
            break;
        case 5:
            obj.display_All_Songs();
            break;
        case 6:
            obj.play_next();
            break;
        case 7:
            obj.play_prev();
            break;
        case 8:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "invalid choice! \n";
            cout << "Error: Enter a number from 1 to 6.\n";
        }

        cout << "\nDo you want to return to the Main Menu? (y/n): ";
        getline(cin, again);

    } while (!again.empty() && (again == "y" || again == "Y"));

    return 0;
}
