#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H
#include <string>
using namespace std;

// Build the PlaylistNode class per the following specifications.
// Note: Some functions can initially be function stubs (empty functions),
// to be completed in later steps.
class PlaylistNode {
   private:
      string uniqueID;           // Initialized to "none" in default constructor
      string songName;           // Initialized to "none" in default constructor
      string artistName;         // Initialized to "none" in default constructor
      int songLength;            // Initialized to 0 in default constructor
      PlaylistNode* nextNodePtr; // Initialized to 0 in default constructor
   public:
      PlaylistNode();
      PlaylistNode(string id, string song, string artist, int length);
      string GetID() const;                    // Accessor
      string GetSongName() const;              // Accessor
      string GetArtistName() const;            // Accessor
      int GetSongLength() const;               // Accessor
      PlaylistNode* GetNext() const;           // Accessor
      void InsertAfter(PlaylistNode* nodePtr); // Mutator
      void SetNext(PlaylistNode* nodePtr);     // Mutator
      void PrintPlaylistNode() const;          // Outputs uniqueID, songname, artistName,
                                               // and songLength based on the format example below.
};

#endif
