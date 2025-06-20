#pragma once
#include "DEFS.h"

class CellPosition
{
	int vCell; // the vertical cell number: starts from 0 to NumVerticalCells - 1
	int hCell; // the horizontal cell number: starts from 0 to NumHorizontalCells - 1

public:
	CellPosition(); // Initializes the cell to (-1,-1) indicating not initialized with valid values
	CellPosition(int v, int h); // Sets vCell and hCell if valid
	CellPosition(int cellNum);  // Sets vCell and hCell from the passed cellNum if valid

	// Note: this class does NOT deal with real coordinates, it deals with the "vCell", "hCell" and "cellNum" instead

	// assuming NumVerticalCells = 5 and NumHorizontalCells = 11 
	// Cell Numbers (CellNum) should be from 1 to 55
	// Numbered from [left-to-right] [bottom-up], as follows:

	// hCell (right):   0    1   ...   10
	// vCell (below):
	//   0             C45  C46  ...  C55
	//   1             C34  C35  ...  C44
	//  ...            ...  ...  ...  ...
	//   3             C12  C13  ...  C22
	//   4             C1   C2   ...  C11

	// In the Grid above, C13 has vCell = 3 and hCell = 1


	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	bool SetVCell(int v); //done

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	bool SetHCell(int h); //done

	int VCell() const; // The getter of vCell 
	int HCell() const; // The getter of hCell 

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	bool IsValidCell() const;//done
	bool IsValidHcell(int h)const; //done
	bool IsValidVcell(int v)const; //done
	int GetCellNum() const;   // Gets the cellNum from the vCell and hCell of the cell position

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	static int GetCellNumFromPosition(const CellPosition& cellPosition);  // Calculates the cellNum of the passed "cellPosition"
	// It is a static function (no need for a calling obj)

///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	static CellPosition GetCellPositionFromNum(int cellNum); // Returns the corresponding CellPosition (vCell, hCell) of the passed cellNum
	// It is a static function (no need for a calling obj)

///TODO: IMPLEMENT THE FOLLOWING FUNCTION
/* Adds the passed "addedNum" to the "cellNum" of the current cell position based on the passed direction
	and updates the data members (vCell and hCell) accordingly
	for example, if cellNum = 11 (vCell = 4, hCell = 10) and the passed num = 2 and direction is up,
	this will make cellNum = 33 which corresponds to vCell = 2 and hCell = 10
	(assuming NumVerticalCells = 5 and NumHorizontalCells = 11 )
	Note: Make sure to make any necessary validations
*/
	void AddCellNum(int addedNum, Direction direction);//donee

};

