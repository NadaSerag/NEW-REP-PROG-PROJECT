#include "Input.h"
#include "Output.h"
#include <iostream>
using namespace std;

//NADA'S TESTCODE
// Nada testcode 2
// jana testcode
// Passant!!
// Salma testcode
// NEW CODE
// //janaaa
//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output * pOut = new Output();
	Input * pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test classes of phase 1, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			- Create The FULL Tool bar of Design Mode, the grid area, the status bar
	//				and an empty command bar
	//			- This has already been done through the constructor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar, Grid, Status bar and Empty Command bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	// 1.1- Drawing the Command bar in the Game mode
	// =============================================
	pOut->PrintMessage("1.1- Drawing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	Command savedCommands[5];
	for (int i = 0; i < 5; i++)
		savedCommands[i] = NO_COMMAND;
	Command availableCommands[10];
	for (int i = 0; i < 10; i++)
		availableCommands[i] = MOVE_FORWARD_ONE_STEP;
	pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 10);
	pOut->PrintMessage("1.1.1- Finished Drawing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.2- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///TODO: Draw the command bar with only 4 available commands and 4 empty slots for saved commands
	// done for now ~s
	for (int i = 0; i < 4; i++)
		savedCommands[i] = NO_COMMAND;

	for (int i = 0; i < 4; i++)
		availableCommands[i] = MOVE_BACKWARD_ONE_STEP;
	pOut->CreateCommandsBar(savedCommands, 4, availableCommands, 4);


	pOut->PrintMessage("1.1.2- Finished Testing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.3- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Draw the command bar with 5 saved commands and 7 available commands, 
	/// 	but the first saved command will be MOVE_FORWARD_ONE_STEP
	///		and the first available command will be NO_COMMAND
	// done for now ~s
	
	for (int i = 1; i < 5; i++) {
		savedCommands[0] = MOVE_FORWARD_ONE_STEP;
		savedCommands[i] = NO_COMMAND;
	}


	for (int i = 0; i < 7; i++) {
		availableCommands[i] = Command(i);
	}
	pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 7);


	
	pOut->PrintMessage("1.1.3- Finished Testing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.4- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Draw the command bar with 5 saved commands and 6 available commands,
	/// 	but the first saved command will be MOVE_FORWARD_TWO_STEPS
	///		and the first available command will be NO_COMMAND as previous test
	// done for now ~s
	
	for (int i = 1; i < 5; i++){
		savedCommands[0] = MOVE_FORWARD_TWO_STEPS;
		savedCommands[i] = NO_COMMAND;
	}

	for (int i = 0; i < 6; i++)
		availableCommands[i] = Command(i);

	pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 6);
	

	pOut->PrintMessage("1.1.4- Finished Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->CreateDesignModeToolBar();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	DONEE
	//			Testing the Output Class
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Testing the [ Output ] class, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	// 2.1- Drawing Water Pits Cells //::donee
	// =============================

	pOut->PrintMessage("2.1- Drawing (Water Pits Cells) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_10(10);	// cell num 10
	CellPosition cell_53(53);	// cell num 53
	CellPosition cell_1(1);		// cell num 1

	// TODO: Draw Water Pits in cell_10 and cell_53 and cell_1 (Invalid)
	pOut->DrawWaterPit(cell_10);
	pOut->DrawWaterPit(cell_53);
	pOut->DrawWaterPit(cell_1);
	pOut->PrintMessage("FINISHED - Drawing (Water Pits) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	// 2.2- Drawing DangerZone Cells //::donee
	// =============================
	pOut->PrintMessage("2.2- Drawing (DangerZone Cells) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_20(20);	// cell num 20
	CellPosition cell_60(60);	// cell num 60

	// TODO: Draw DangerZone in cell_20, [cell_60 and cell_1] (Invalid)
	pOut->DrawDangerZone(cell_20);
	pOut->DrawDangerZone(cell_60);
	pOut->DrawDangerZone(cell_1); 

	pOut->PrintMessage("FINISHED - Drawing (DangerZone) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	
	// 2.3- Drawing Players Test //::donee
	// =========================
	pOut->PrintMessage("2.3- Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition player_1(1);//cell 1
	CellPosition player_2(2);//cell 2
	CellPosition player_15(2,18); //invalid cell testcase
	CellPosition player_99(2,5); //cell 28



	///TODO: Call Function DrawPlayer of Class Ouput Multiple Times :: DONE:WORKS (players drawn in the right cells)
	///       to draw the following players:
	///       playerNum (0) with color (PlayerColors[0] defined in UI object) 
	///			in cell position (player_1 declared above) pointing to right direction 
	/// 
	///       playerNum (1) with color (PlayerColors[1] defined in UI object) 
	///			in cell position (player_1 declared above) pointing to the up direction
	/// 
	///       playerNum (2) with color (PlayerColors[2] defined in UI object) 
	///			in cell position (player_1 declared above) pointing to the down direction --> Invalid
	/// 
	///       playerNum (3) with color (PlayerColors[3] defined in UI object) 
	///			in cell position (player_1 declared above) pointing to the left direction --> Invalid
	/// 
	///       playerNum (0) with color (PlayerColors[0] defined in UI object) 
	///			in cell position (player_15 declared above) pointing to the left direction --> Invalid
	/// 
	///       playerNum (1) with color (PlayerColors[1] defined in UI object) 
	///			in cell position (player_99 declared above) pointing up
	/// 
	///       playerNum (5) with color (PlayerColors[1] defined in UI object) 
	///			in cell position (player_99 declared above) pointing down--> Invalid
	/// 
	///       playerNum (-1) with color (PlayerColors[1] defined in UI object) 
	///			in cell position (player_99 declared above) pointing left--> Invalid

	pOut->DrawPlayer(player_1, 0, UI.PlayerColors[0], RIGHT);
	pOut->DrawPlayer(player_1, 1, UI.PlayerColors[1], UP);
	pOut->DrawPlayer(player_1, 2, UI.PlayerColors[2], DOWN);
	pOut->DrawPlayer(player_1, 3, UI.PlayerColors[3], LEFT);
	pOut->DrawPlayer(player_15, 0, UI.PlayerColors[0], LEFT);
	pOut->DrawPlayer(player_99, 1, UI.PlayerColors[1], UP);
	pOut->DrawPlayer(player_99, 5, UI.PlayerColors[1], DOWN);
	pOut->DrawPlayer(player_99, -1, UI.PlayerColors[1], LEFT);
	pOut->PrintMessage("FINISHED - Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// 2.4- Drawing Flags::done
	/// ====================
	/// 
	pOut->PrintMessage("2.4- Drawing (Flags) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition flag_1(9);
	CellPosition flag_60(60);
	CellPosition flag_99(99);

	// TODO: Draw Flags in cell positions (flag_1, flag_60, flag_99)::done
	pOut->DrawFlag(flag_1);
	pOut->DrawFlag(flag_60);
	pOut->DrawFlag(flag_99);


	pOut->PrintMessage("FINISHED - Drawing (Flags) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// 2.5- Drawing Belts::done
	/// ====================
	/// 
	pOut->PrintMessage("2.5- Drawing (Belts) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	
	CellPosition belt_start_1(1);
	CellPosition belt_end_1(5);
	CellPosition belt_start_2(12);
	CellPosition belt_end_2(45);
	CellPosition belt_start_3(54);
	CellPosition belt_end_3(32);
	CellPosition belt_end_4(33);

	// TODO: Draw 5 belts
	//		1- from belt_start_1 to belt_end_1
	//		2- from belt_start_2 to belt_end_2 
	//		3- from belt_start_3 to belt_end_3
	//		4- from belt_start_3 to belt_end_4 --> Invalid
	//		5- from belt_end_1 to belt_end_2 --> Invalid
	// 		6- from belt_end_3 to belt_end_4 --> Invalid
	pOut->DrawBelt(belt_start_1, belt_end_1);
	pOut->DrawBelt(belt_start_2, belt_end_2);
	pOut->DrawBelt(belt_start_3, belt_end_3);
	pOut->DrawBelt(belt_start_3 ,belt_end_4);
	pOut->DrawBelt(belt_end_1, belt_end_2);
	//pOut->DrawBelt(belt_end_3, belt_end_4);


	pOut->PrintMessage("FINISHED - Drawing (Belts) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	

	// 2.6- Drawing Rotating Gears //
	// ===========================

	pOut->PrintMessage("2.6- Drawing (Rotating Gears) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_13(13);
	CellPosition cell_19(19);

	// TODO: Draw Rotating Gears in cell positions (cell_13, cell_19) :: done
	//        1. At cell_13 with rotation left (anticlockwise) 
	//        2. At cell_19 with rotation right (clockwise)
	pOut->DrawRotatingGear(cell_13, false);
	pOut->DrawRotatingGear(cell_19, true);

	pOut->PrintMessage("FINISHED - Drawing (Rotating Gears) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.7- Drawing Antenna //::donee
	// ======================
	pOut->PrintMessage("2.7- Drawing (Antenna) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_25(2,2);
	
	// TODO: Draw Antenna in cell position (cell_25)::donee
	pOut->DrawAntenna(cell_25);
	pOut->PrintMessage("FINISHED - Drawing (Antenna) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.8- Drawing Workshop //::donee
	// =======================

	pOut->PrintMessage("2.8- Drawing (Workshop) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_30(30);

	// TODO: Draw Workshop in cell position (cell_30)
	pOut->DrawWorkshop(cell_30);
	pOut->PrintMessage("FINISHED - Drawing (Workshop) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click




	/////////////////////////////////////////////////////////////////////////////////
	 //TEST 3: DONEE
				//Input Class - Part 1
	/////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST3: Now Time to test class [ Input ], Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.1- Getting Integer ///
	/// ===========================
	pOut->PrintMessage("3.1- (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to ::done
	// 1- Call GetInteger Function and receive its returned integer
	// 2- Print it in the status bar in this format:   You Entered: 116
	//    (assuming the entered number is 116)
	// 3- Call GetPointClicked() function

	//Done
	int received = pIn->GetInteger(pOut);
	pOut->PrintMessage("You Entered: " +to_string(received));
	pIn->GetPointClicked(x, y);
	///////////////////////////

	pOut->PrintMessage("FINISHED - (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.2- Getting Cell Clicked ///
	/// =========================
	pOut->PrintMessage("3.2- (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Call function GetCellClicked :: done
	// 2- Print on the status bar the vCell and hCell of the clicked cell :: done
	// 3- Repeat Step 1 and 2 five  :: done

	
	for (int i = 0; i < 6; i++)
	{
		pIn->GetCellClicked();
		pOut->PrintMessage("(GetCellClicked) Test, VCell = " + to_string((pIn->GetCellClicked()).VCell()) + ", HCell = " + to_string((pIn->GetCellClicked()).HCell()));
	}

	pOut->PrintMessage("FINISHED - (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	/// 3.3- Reading a String ///
	/// =====================
	pOut->PrintMessage("3.3- (GetString) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar :: done
	// 2- After reading the string clear the status bar :: done
	// 3- print on the status bar "You Entered" then print the string :: done
	// NOTE: GetString() is already implemented. It is just required from you to call it
	string n = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	pOut->PrintMessage("You Entered: " + n);
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("FINISHED - (GetString) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4:	
	//			Test the functions of CellPosition Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST4: Testing the [ CellPosition ] class, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.1- (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition cellpos_1(1);

	//TODO:
	// 1- Ask user to enter an integer and read it using GetInteger():::done
	 //2- Call SetVCell() of cellpos_1 with that integer:::done
	 //3- Print GetVCell() of cellpos_1 as follows: "Now the vCell = 5" (assuming the entered integer is 5):::done
	 //4- Call GetPointClicked():::done
	 //5- Repeat the above steps FIVE TIMES:::done
	 //6- Repeat all the above steps to test SetHCell() function instead with the needed modifications:::done

	int V_int = 0;
	for (int i = 0; i < 5; i++) 
	{
		
		pOut->PrintMessage("Enter an integer to set VCell: ");
		V_int = pIn->GetInteger(pOut);
		cellpos_1.SetVCell(V_int);
		pOut->PrintMessage("Now the VCell=  " + to_string(cellpos_1.VCell()));
		pIn->GetPointClicked(x, y);
		
	}
	int H_int = 0;
	for (int i = 0; i < 5; i++)
	{

		pOut->PrintMessage("Enter an integer to set HCell: ");
		 H_int = pIn->GetInteger(pOut);

		cellpos_1.SetHCell(H_int);
		pOut->PrintMessage("Now the HCell=  " + to_string(cellpos_1.HCell()));
		pIn->GetPointClicked(x, y);

	}
	pOut->PrintMessage("FINISHED - (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.2- (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// TODO:
	// 1- Read from user two integers representing vCell and hCell:::done
	// 2- Creates a CellPosition object of them:::done
	// 3- Use the function GetCellNum() to get the corresponding Cell Number (it used function : GetCellNumFromPosition() inside it):::done
	// 4- Print the Cell Number on the status bar:::done
	// 5- Repeat the above steps Five TIMES:::done
	int vcellin;
	int hcellin;
	int numprint;
	for (int i = 0; i < 5; i++) {
		pOut->PrintMessage("Enter the VCell: ");
		 vcellin = pIn->GetInteger(pOut);
		 pOut->PrintMessage("Enter the HCell: ");
		 hcellin = pIn->GetInteger(pOut);
		CellPosition cellposition(vcellin, hcellin);
		 numprint = cellposition.GetCellNum();
		
		pOut->PrintMessage("CellNum = " + to_string(numprint));
		pIn->GetPointClicked(x, y);
	}
	
	pOut->PrintMessage("FINISHED - (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.3- (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// TODO:
	// 1- Read from user one integer representing cellNum:::done
	// 2- Creates a CellPosition object of that integer using that constructor: 
	//		CellPosition (int cellNum);
	//			--> it uses the function : GetCellPositionFromNum () inside it:::done
	// 4- Print the Cell vCell and hCell on the status bar:::done
	// 5- Repeat the above steps Five TIMES:::done
	int cellNum;
	int v;
	int h;
	for (int i = 0; i < 5; i++) {
		pOut->PrintMessage("Enter the CellNum: ");
		 cellNum = pIn->GetInteger(pOut);
		CellPosition cellin(cellNum);
		 h = cellin.HCell();
		 v = cellin.VCell();
		
		pOut->PrintMessage("VCell= " + to_string(v) + " HCell= " + to_string(h));
		pIn->GetPointClicked(x, y);
	}
	
	pOut->PrintMessage("FINISHED - (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.4- (AddCellNum) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///// TODO:
	//// 1- Read from user two integers representing cellNum and addedNum:::done
	//// 2- Creates a CellPosition object of cellNum:::done
	//// 3- Use the function AddCellNum() to add the addedNum to the cellNum:::done
	//// 4- Print the vCell and hCell of the new Cell Position on the status bar:::done
	//// 5- Repeat the above steps Four TIMES with each time a different direction:::done
	pOut->PrintMessage("Enter the cellNum: ");
	int cellnum = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter the addedNum: ");
	int addednum = pIn->GetInteger(pOut);
	CellPosition cellposofup(cellnum);
	cellposofup.AddCellNum(addednum, UP);
	pOut->PrintMessage("New VCell= " + to_string(cellposofup.VCell()) + " New HCell= " + to_string(cellposofup.HCell()));
	pIn->GetPointClicked(x, y);
	CellPosition cellposofdown(cellnum);
	cellposofdown.AddCellNum(addednum, DOWN);
	pOut->PrintMessage("New VCell= " + to_string(cellposofdown.VCell()) + " New HCell= " + to_string(cellposofdown.HCell()));
	pIn->GetPointClicked(x, y);
	CellPosition cellposofr(cellnum);
	cellposofr.AddCellNum(addednum, RIGHT);
	pOut->PrintMessage("New VCell= " + to_string(cellposofr.VCell()) + " New HCell= " + to_string(cellposofr.HCell()));
	pIn->GetPointClicked(x, y);

	CellPosition cellposofl(cellnum);
	cellposofl.AddCellNum(addednum, LEFT);
	pOut->PrintMessage("New VCell= " + to_string(cellposofl.VCell()) + " New HCell= " + to_string(cellposofl.HCell()));
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("FINISHED - (AddCellNum) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 5: 
	//			Input Class - Part2: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST5: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	// You must add a case for EACH action (both Design mode and Game mode actions)
	// Add cases for the missing actions below :: DONEE 
	do
	{
		ActType = pIn->GetUserAction();

		int clickedCommandItemIndex; // if the action is SELECT_COMMAND, this will have the icon index
		switch (ActType)
		{
			case SET_FLAG_CELL:
				pOut->PrintMessage("Action: SET_FLAG_CELL , Click anywhere");
				break;
		

			case EXIT:				
				break;

			case TO_PLAY_MODE:

				pOut->PrintMessage("Action: TO_PLAY_MODE , Click anywhere");
				pOut->CreatePlayModeToolBar();

				///TODO:  Call Function (PrintPlayersInfo) of Class Output with a string similar to :: DONE
				//        the one given in the screenshot of project document 
				pOut->PrintPlayersInfo("P1(2, Right, 10), P2(2, Up, 10) | Curr = P1");

				break;

			case ADD_ANTENNA:

				pOut->PrintMessage("Action: ADD_ANTENNA , Click anywhere");
				break;

			case ADD_BELT:

				pOut->PrintMessage("Action: ADD_BELT (HORIZONTALLY) , Click anywhere");
				break;

			case ADD_VERTICAL_BELT:

				pOut->PrintMessage("Action: ADD_BELT (VERTICALLY) , Click anywhere");
				break;

			case ADD_WATERPIT:
				
				pOut->PrintMessage("Action: ADD_WATERPIT , Click anywhere");
				break;

			case ADD_DANGERZONE:

				pOut->PrintMessage("Action: ADD_DANGERZONE , Click anywhere");
				break;

			case ADD_WORKSHOP:

				pOut->PrintMessage("Action: ADD_WORKSHOP , Click anywhere");
				break;

			case ADD_ROTATING_GEAR_ANTI:

				pOut->PrintMessage("Action: ADD_ROTATING_GEAR_ANTI , Click anywhere");
				break;

			case ADD_ROTATING_GEAR:

				pOut->PrintMessage("Action: ADD_ROTATING_GEAR , Click anywhere");
				break;

			case COPY_GAME_OBJECT:

				pOut->PrintMessage("Action: COPY_GAME_OBJECT , Click anywhere");
				break;

			case CUT_GAME_OBJECT:

				pOut->PrintMessage("Action: CUT_GAME_OBJECT , Click anywhere");
				break;

			case PASTE_GAME_OBJECT:

				pOut->PrintMessage("Action: PASTE_GAME_OBJECT , Click anywhere");
				break;

			case DELETE_GAME_OBJECT:

				pOut->PrintMessage("Action: DELETE_GAME_OBJECT , Click anywhere");
				break;

			case SAVE_GRID:

				pOut->PrintMessage("Action: SAVE_GRID , Click anywhere");
				break;

			case LOAD_GRID:

				pOut->PrintMessage("Action: LOAD_GRID , Click anywhere");
				break;

				///TODO:  ADD Cases similarly for ALL the remaining actions of DESIGN Mode :: done

			case EXECUTE_COMMANDS:
				pOut->PrintMessage("Action: EXECUTE_COMMAND, Click anywhere");
				break;
			case SELECT_COMMAND:
				pOut->PrintMessage("Action: SELECT_COMMAND, Select a command");
				clickedCommandItemIndex = pIn->GetSelectedCommandIndex();
				pOut->PrintMessage("Action: SELECT_COMMAND " + to_string(clickedCommandItemIndex) + " , Click anywhere");
				break;

			case GRID_AREA:
				pOut->PrintMessage("Action: GRID_AREA , Click anywhere");
				break;

			case STATUS:
				pOut->PrintMessage("Action: STATUS , Click anywhere");
				break;

			case TO_DESIGN_MODE:
				pOut->PrintMessage("Action: TO_DESIGN_MODE , Click anywhere");
				pOut->CreateDesignModeToolBar();
				break;

			case REBOOT_AND_REPAIR:

				pOut->PrintMessage("Action: REBOOT_AND_REPAIR , Click anywhere");
				break;

			case USE_CONSUMABLE:

				pOut->PrintMessage("Action: USE_CONSUMABLE , Click anywhere");
				break;

			case NEW_GAME:

				pOut->PrintMessage("Action: NEW_GAME , Click anywhere");
				break;
				///TODO:  ADD Cases similarly for ALL the remaining actions of PLAY Mode :: done

		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


