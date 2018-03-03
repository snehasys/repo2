/*
	PROBLEM STATEMENT:
		<DeDuplication problem>
		1. Compress a file. 		a.k.a. dedup()
		2. And Uncompress the File. a.k.a. redup()
	
	DETAILED PROBLEM STATEMENT:		
	1.	dedup():
		The given source file is in the size of multiples of 1024byte blocks.
		Now read the file, and find the duplicate blocks.
		Now spit out a smaller file, which has only the unique blocks from the original file.
		Store the mapping metadata as you wish.	
		
	2.	redup(): 
		Reconstruct the same source file from the compressed file.
		Consult only the dumped compressed data (and/or metaData)
	
	3. Extra Credit
		If possible, run a checksum to check if the constructed file is identical to the original source file.
		return false in redup() if checksum fails.
*/

/** --- High Level Design Document ---
  * My intention was to calculate MessageDigest(SHA1) for each block 
  * and use that as a key for storing the value part and their respective position.
  *   * Remember: Only, the unique values will be stored in the output file,
  *   *           and the HashMap will contain the following info:
      *           < hashKey , < inFileChunkPosition, outFileChunkPosition> >  
  *
  * This above hashMap info will be used as a dictionary to reconstruct the original file later in redup().
  *
  **************************************************************************************************
  * NOTE: For some reason, I am facing linkTime error for using <openssl/sha.h> in Hackerrank editor
  * In absence of openssl, I have to use the std::hash, whose hash conflict probability is 1/INT_MAX
  **************************************************************************************************
*/


#include <unordered_map>
#include <map>
#include <iostream>
#include <fstream>
#include <functional> // std::hash
#include <string>
#include <openssl/sha.h>

#define hashKey     size_t
#define outLocation size_t
#define inLocation  size_t

using namespace std;
const size_t CHUNK = 1024;
unordered_map<hashKey, pair<outLocation, set<inLocation>>> dictionary;


void printSet(set<size_t> &bunch){
    for(auto &each: bunch)
        cout<< endl << to_string(each);
}

void dedup(string input_file_path, string deduped_file_path) 
{
    dictionary.clear();
    ifstream in (input_file_path,   ifstream::binary);
    ofstream out(deduped_file_path, ofstream::binary);
    if(!in && !out) 
    {
        return; // file open failed
    }
    // ***filesize calculator *****
    in.seekg(0,in.end);
    size_t fileSize = in.tellg();
    in.seekg(0,in.beg);
    // ********
    
    size_t outPos = 0;
    for ( size_t pos = 0; pos<fileSize; pos+= CHUNK)
    {
        in.seekg(pos /*, in.end*/);
        char buffer[CHUNK];
        in.read(buffer, CHUNK);
        /*
        unsigned char* uBuff = (unsigned char*)buffer;
        cout << SHA_DIGEST_LENGTH;
        unsigned char hash [SHA_DIGEST_LENGTH];
        SHA1(uBuff, CHUNK, hash );
        */
        std::hash<string> digest;
        string buffStr (buffer, CHUNK);
        size_t hashVal = digest(buffStr);
        
        auto it = dictionary.find(hashVal);
        if (it == dictionary.end())
        {   // new hash, insert
            set<size_t> inPoses = {pos};
            dictionary[hashVal] = make_pair(outPos, inPoses ); //insert new entry
            // write new buffer in outputfile at outpos location
            out.write (buffer, CHUNK);
            outPos += CHUNK;
        }
        else
        { // duplicate found, only update the set<>
            it->second.second.insert(pos); // <hashkey, pair<outLocation, set<inLocation>>>
            //printSet(it->second.second);
        }
       // cout<< " hashkey::"<< hashVal<< endl;

    }
    in.close();
    out.close();
}



bool redup(string deduped_file_path, string output_file_path) 
{
    ifstream in (deduped_file_path, ifstream::binary);
    ofstream out(output_file_path,  ofstream::binary);
    if(!in && !out) 
    {
        return false; // file open failed
    } 
     // actual, deduped
    map<size_t, size_t> flatMap;

    for(auto &item: dictionary){
        for(auto actualLoc : item.second.second)
        {
            flatMap[actualLoc] = item.second.first; //duped location            
        }
        
    } // flatmap constructed
    
    for(auto i: flatMap){
        auto actual = i.first;
        auto deduped= i.second;
        
        in.seekg(deduped);     
        char buffer[CHUNK];
        in.read(buffer, CHUNK);
        in.seekg(0,in.beg); // run to front for nxt fresh iteration

        out.write (buffer, CHUNK);
    }
    in.close();
    out.close();
    
    return false; // redup failed
}