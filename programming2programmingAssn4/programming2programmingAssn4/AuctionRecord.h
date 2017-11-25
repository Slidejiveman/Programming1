// Specification file for the AuctionRecord class
#ifndef AUCTION_RECORD_H
#define AUCTION_RECORD_H

class AuctionRecord
{
private:

	// Structure that serves as the record for the list
	struct AuctionNodeType
	{
		char itemNumber[6];				// Holds two chars and three nums
		char buyerName[12];				// Holds name of the buyer
		char sellerName[12];			// Holds name of the seller
		double finalBid;				 // Money value of transaction
		struct AuctionNodeType *next;	// To point to the next node
	};

	AuctionNodeType *head;				// List head pointer

public:

	// default constructor defined in-line
	AuctionRecord()
	{
		//creates the head pointer necessary for all of the operations
		head = nullptr;
	}

	// Destructor defined in implementation file
	~AuctionRecord();

	// Linked list operations
	bool findNode(char[6]);
	void insertNode(char[6], char[12], char[12], double);
	void deleteNode(char[6]);
	void displayList() const;
};
#endif