// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#ifndef DS_H
#define DS_H

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'




class Node
{
public:
    string data;
    Node *next;
    Node(string song) : data(song), next(nullptr) {}
};
class playlist
{
    Node *head;
    string curSong;

public:
    playlist()
    {
        head = NULL;
        curSong = "";
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    void show_Menu()
    {
        cout << "Main Menu \n";
        cout << "------------------\n";
        cout << "1. Insert \n";
        cout << "2. Delete \n";
        cout << "3. Search \n";
        cout << "4. Update \n";
        cout << "5. Display \n";
        cout << "6. Play the next song\n";
        cout << "7. Play the previous song\n";
        cout << "8. Exit\n";
        cout << "------------------\n";
        cout << "Enter your choice: ";
    }

    // ############################# Omar karam ################################

    void insert_Song(string song)
    {
        Node *newnode = new Node(song);
        newnode->next = NULL;
        if (isEmpty())
        {

            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cout << "song is inserted successfully\n";
    }

    // ############################# Ali soliman ################################

    void delete_Song(string song)
    {
        Node *temp = head;
        Node *prev = NULL;
        if (isEmpty())
        {
            cout << "playlist is Empty!!";
            return;
        }
        else
        {
            if (head->data == song)
            {
                head = head->next;
                delete temp;
            }
            else
            {
                while (temp != NULL && temp->data != song)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if (temp == NULL)
                {
                    cout << "song is not availble in your playlist!!\n";
                    return;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
            }
            cout << "song is deleted successfully\n";
        }
    }

    // ############################# omar elghamry ################################

    void search_Song(string song)
    {
        Node *temp = head;
        if (isEmpty())
        {
            cout << "playlist is Empty!!\n";
            return;
        }
        else
        {
            while (temp != NULL && temp->data != song)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "song is not availble in your playlist!!\n";
            }
            else
            {
                cout << "song is available---> " << song << "\n";
            }
        }
    }

    void update_songName(string song, string newName)
    {
        Node *temp = head;
        if (isEmpty())
        {
            cout << "playlist is Empty!!\n";
            return;
        }
        else
        {
            while (temp != NULL && temp->data != song)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "song is not availble in your playlist!!\n";
                return;
            }
            else
            {
                temp->data = newName;
            }
        }
        cout << "song is updated sucessfully\n";
    }

    // ############################# Ali yousry ################################

    void display_All_Songs()
    {
        Node *temp = head;
        int index = 1;
        if (isEmpty())
        {
            cout << "the playlist is Empty \n";
        }
        else
        {
            cout << "============Playlist============\n";
            while (temp != NULL)
            {
                if (temp->data == curSong)
                {
                    cout << index << "-" << curSong << "   <--(CURRENT)" << '\n';
                }
                else
                {

                    cout << index << "-" << temp->data << "\n";
                }

                temp = temp->next;
                index++;
            }
            cout << "================================\n";
        }
    }

    // ############################ Omar Tamer ################################

    // -- currrent, prv , next song section -- //

    void setCurrent(string song)
    {
        Node *temp = head;
        if (temp != nullptr)
        {
            if (temp->data == song)
            {
                curSong = song;
                cout << "Now Playing " << song << nl;
                return;
            }
            temp = temp->next;
        }

        cout << "Song not found !" << nl;
    }

    void play_prev()
    {
        if (isEmpty())
        {
            cout << "playlist empty\n";
        }
        else
        {
            Node *temp = head;
            Node *prev = NULL;
            while (temp != NULL && temp->data != curSong)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "playing last song -> " << prev->data << "\n";
                curSong = prev->data;
            }
            else if (temp->data == curSong)
            {
                cout << "playing the previous of : " << temp->data << " , which is : " << prev->data << "\n";
                curSong = prev->data;
            }
        }
    }

    void play_next()
    {
        if (isEmpty())
        {
            cout << "playlist is Empty!!\n";
        }
        else
        {
            Node *temp = head;
            while (temp != NULL && temp->data != curSong)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "no song was selected , playing first song: " << head->data;
                curSong = head->data;
            }
            else
            {
                // FIXED : current song wasn't updated accurately
                // cout << "stopped at : " << temp->data << " which in comparison with " << curSong << "\n";
                if ((temp->next) != NULL)
                {
                    cout << "now playing : " << (temp->next)->data << "\n";
                    curSong = (temp->next)->data;
                }
                else{
                    cout << "end of playlist , current song is : " << curSong << " , now playing first song: " << head->data << "\n";
                    curSong = head->data;
                }
            }
        }
    }
};

#endif
