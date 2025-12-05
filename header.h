#ifndef HEADER.H
#define HEADER.H

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string data;
    Node *next;
};
class playlist
{
public:
    Node *head;
    string is_curr = "";
    playlist()
    {
        head = NULL;
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
        cout << "6. Exit\n";
        cout << "------------------\n";
        cout << "Enter your choice: ";
    }

    void search_Song(string song)
    {
        Node *temp = head;
        if (isEmpty())
        {
            cout << "playlist is Empty!!\n";
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
                cout << "song is available---> " << song << " , playing it now\n";
                is_curr = temp->data;
            }
        }
    }
    void play_next(){
        if (isEmpty())
        {
            cout << "playlist is Empty!!\n";
        }
        else
        {
            Node *temp = head;
            while (temp != NULL && temp->data != is_curr)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "no song was selected , playing first song: " << head->data;
                is_curr = head->data;
            }
            else
            {
                if ( ( temp->next ) != NULL ){
                    cout << "now playing : " << (temp->next)->data << "\n";
                }
                else{
                    cout << "end of playlist , current song is : " << is_curr << " , now playing first song: " << head->data << "\n";
                    is_curr = head->data;
                }
            }
        }
    }
    void play_prev(){
        if ( isEmpty() ){
            cout << "playlist empty\n";
        }
        else{
            Node *temp = head; Node *prev = NULL;
            while ( temp != NULL && temp->data != is_curr ){
                prev = temp;
                temp = temp->next;
            }
            if ( temp == NULL ){
                cout << "playing last song -> " << prev->data << "\n";
                is_curr = prev->data;
            }
            else if ( temp->data == is_curr ){
                cout << "playing the previous of : " << temp->data << " , which is : " << prev->data << "\n";
                is_curr = prev->data;
            }
        }
    }
};
#endif
