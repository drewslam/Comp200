#include <iostream>
#include <string>
#include "PlaylistNode.h"
using namespace std;

PlaylistNode::PlaylistNode() {
   this->uniqueID = "none";
   this->songName = "none";
   this->artistName = "none";
   this->songLength = 0;
   this->nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string id, string song, string artist, int length) {
   this->uniqueID = id;
   this->songName = song;
   this->artistName = artist;
   this->songLength = length;
   this->nextNodePtr = nullptr;
}

string PlaylistNode::GetID() const {
   return this->uniqueID;
} // Accessor

string PlaylistNode::GetSongName() const {
   return this->songName;
} // Accessor

string PlaylistNode::GetArtistName() const {
   return this->artistName;
} // Accessor

int PlaylistNode::GetSongLength() const {
   return this->songLength;
} // Accessor

PlaylistNode* PlaylistNode::GetNext() const {
   return this->nextNodePtr;
} // Accessor

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
   PlaylistNode* tmp = this->nextNodePtr;
   this->nextNodePtr = nodePtr;
   nodePtr = tmp;
} // Mutator

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
   this->nextNodePtr = nodePtr;
} // Mutator

void PlaylistNode::PrintPlaylistNode() const {
   cout << "Unique ID: " << this->uniqueID << endl;
   cout << "Song Name: " << this->songName << endl;
   cout << "Artist Name: " << this->artistName << endl;
   cout << "Song Length (in seconds): " << this->songLength << endl;
} // Outputs uniqueID, songname, artistName,
  // and songLength based on the format example below.
