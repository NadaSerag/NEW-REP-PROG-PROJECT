#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation):::done
	if (v <= 4 && v >= 0) {
		vCell = v;
		return true;
	}

		return false;

}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation) ::: done
	if (h <= 10 && h >= 0)
	{
		hCell = h;
		return true;
	}

		return false;

}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file:::done

	return IsValidHcell(hCell) && IsValidVcell(vCell);
}

bool CellPosition::IsValidHcell(int h) const
{
	return h <= 10 && h >= 0;
}

bool CellPosition::IsValidVcell(int v) const
{
	return v <= 4 && v >= 0;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it
	

	///TODO: Implement this function as described in the .h file 
	if (cellPosition.IsValidCell())
	{
		int cellNUM = 0;
		int index_h = 0;
		int index_v = 0;
		index_v = cellPosition.VCell();
		index_h = cellPosition.HCell();
		cellNUM = 11 * (4 - index_v) + (1 + index_h);
		return cellNUM;
	}
	return -1;
	
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file:::done
	
	if ( cellNum >=1 &&cellNum <= 55) {
		int index_h;
		int index_v;
		if (cellNum >= 1 && cellNum <= 11) {
			index_h = cellNum - 1;
			index_v = 4;
		}
		else if (cellNum >= 12 && cellNum <= 22) {
			index_h = cellNum - 12;
			index_v = 3;

		}
		else if (cellNum >= 23 && cellNum <= 33) {
			index_h = cellNum - 23;
			index_v = 2;

		}
		else if (cellNum >= 34 && cellNum <= 44) {
			index_h = cellNum - 34;
			index_v = 1;

		}
		else if (cellNum >= 45 && cellNum <= 55) {
			index_h = cellNum - 45;
			index_v = 0;

		}

		
		position.SetHCell(index_h);
		position.SetVCell(index_v);
		return position;
	}
	
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it

	
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{

	/// TODO: Implement this function as described in the .h file:::done
	if (direction == UP)
	{
		if ((vCell + addedNum * 11)>=0 && (vCell + addedNum * 11) <= 4) {
			vCell = vCell + addedNum * 11;
		}
	}
	if (direction == DOWN)
	{
		if ((vCell - addedNum * 11)>=0 && (vCell - addedNum * 11) <= 4) {
			vCell = vCell - addedNum * 11;
		}
	}
	if (direction == RIGHT)
	{
		if ((hCell + addedNum)>=0 && (hCell + addedNum) <= 10) {
			hCell = hCell + addedNum;
		}
	}
	if (direction == LEFT)
	{
		if ((hCell - addedNum)>=0 && (hCell - addedNum) <= 10) {
			hCell = hCell - addedNum;
		}
	}
	// Note: this function updates the data members (vCell and hCell) of the calling object

}