#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void isValidOption(char& option) {
   while (option != 'a' && option != 'd' &&
          option != 'c' && option != 's' &&
          option != 't' && option != 'o') {
      cout << "Choose an option:" << endl;
      cin >> option;
   }
}

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   char currOption = option;
   int i = 1;
   string id;
   string song;
   string artist;
   int length;
   PlaylistNode* currNode = headNode;
   PlaylistNode* leadingNode = nullptr;
   PlaylistNode* followingNode = nullptr;

   if (currOption == 'o') {
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      if (headNode->GetNext() == nullptr) {
         cout << "Playlist is empty" << endl;
      } else {
         currNode = headNode->GetNext();
         while (currNode != nullptr) {
            cout << i++ << "." << endl;
            currNode->PrintPlaylistNode();
            cout << endl;
            currNode = currNode->GetNext();
         }
      }
   } else if (currOption == 'a') {
      cin.ignore();
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      getline(cin, id);
      cout << "Enter song's name:" << endl;
      getline(cin, song);
      cout << "Enter artist's name:" << endl;
      getline(cin, artist);
      cout << "Enter song's length (in seconds):" << endl;
      cin >> length;
      PlaylistNode* nextNode = new PlaylistNode(id, song, artist, length);
      while (currNode->GetNext() != nullptr) {
         currNode = currNode->GetNext();
      }
      currNode->InsertAfter(nextNode);
      cout << endl;
   } else if (currOption == 'd') {
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> id;
      while (currNode->GetID() != id) {
         leadingNode = currNode;
         currNode = currNode->GetNext();
      }
      if (currNode->GetID() == id) {
         followingNode = currNode->GetNext();
         leadingNode->SetNext(followingNode);
         cout << "\"" << currNode->GetSongName() << "\" removed." << endl;
      }
      cout << endl;
   } else if (currOption == 'c') {
      int maxNodes = 0;
      int currentPosition = 1;
      int targetNode;
      int targetPosition;
      PlaylistNode* temp = nullptr;
      PlaylistNode* tempNext = nullptr;

      while (currNode->GetNext() != nullptr) {
         currNode = currNode->GetNext();
         maxNodes++;
      }

      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      cin >> targetNode;
      cout << "Enter new position for song:" << endl;
      cin >> targetPosition;

      currNode = headNode;
      while (currentPosition <= targetNode) {
         leadingNode = currNode;
         currNode = currNode->GetNext();
         followingNode = currNode->GetNext();
         currentPosition++;
      }

      temp = headNode;
      currentPosition = 0;
      while (currentPosition < targetPosition) {
         temp = temp;
         tempNext = temp->GetNext();
         currentPosition++;
         if (currentPosition != targetPosition) {
            temp = temp->GetNext();
         }
      }

      leadingNode->SetNext(followingNode);
      temp->SetNext(currNode);
      currNode->SetNext(tempNext);

      cout << "\"" << currNode->GetSongName() << "\" moved to position " << targetPosition << endl;
      cout << endl;
   } else if (currOption == 's') {
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:" << endl;
      cin.ignore();
      getline(cin, artist);
      currNode = headNode->GetNext();
      for (int i = 1; currNode != nullptr; i++) {
         if (currNode->GetArtistName() == artist) {
            cout << i << "." << endl;
            currNode->PrintPlaylistNode();
            cout << endl;
         }
         currNode = currNode->GetNext();
      }
   } else if (currOption == 't') {
      int totalTime = 0;
      currNode = headNode->GetNext();
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      while (currNode != nullptr) {
         totalTime += currNode->GetSongLength();
         currNode = currNode->GetNext();
      }
      cout << "Total time: " << totalTime << " seconds" << endl;
      cout << endl;
   }

   return headNode;
}

int main() {
   string userTitle;
   char userOption;
   PlaylistNode* headNode = new PlaylistNode;

   cout << "Enter playlist's title:" << endl;
   getline(cin, userTitle);
   cout << endl;

   PrintMenu(userTitle);
   cout << "Choose an option:" << endl;
   cin >> userOption;

   if (userOption == 'q') {
      return 0;
   }

   while (userOption != 'q') {
      isValidOption(userOption);
      ExecuteMenu(userOption, userTitle, headNode);
      PrintMenu(userTitle);
      cout << "Choose an option:" << endl;
      cin >> userOption;
   }

   return 0;
}
