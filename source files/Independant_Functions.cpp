#include "Independant_Functions.h"

/////////////////////////////////////              CLear Console Screen           //////////////////////////////////
void CLEAR_SCREEN()
{
    system("cls"); // clearing the console screen, making use of stdlib.h library
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////              Exit  /  Terminte           ////////////////////////////////////
void EXIT()
{
    cout << "\n\n\n";
    cout << "          __________________________________________________\n";
    cout << "         |    Terminating the Program in 1 second...!!!     |\n";
    cout << "         |__________________________________________________|\n";
    Sleep(1000); // waiting 1s before exiting...just for "dramatic effect"
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////  TITLE SCREEN   //////////////////////////////////////////////////
void TITLE()
{
    cout << "\n\n";
    cout << "              ________________________________________________________________\n";
    cout << "             |               COURSE FEEDBACK MANAGEMENT SYSTEM                |\n";
    cout << "             |________________________________________________________________|\n";
    cout << "\n\n\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////   MAIN MENU 0R EXIT   //////////////////////////////////////////////
int MAIN_MENU_OR_EXIT(int choice)
{
    cout << "\n\n";
    cout << "          >> Please choose one of the following options:\n\n";
    cout << "           ____________________________________________" << endl;
    cout << "          |1. Return to Main Menu                      |" << endl;
    cout << "          |2. Exit                                     |" << endl;
    {
        cout << "\n          Answer: ";

                 //////////////////////////////////////////////////////////
        try     //....   Exception Handling incase of Wrong Input    ...//
        {      //////////////////////////////////////////////////////////
            cin >> choice;
            if ((choice == 2) || (choice == 1))
            {
                return choice; // returning right choice...
            }
            else
            {
                throw choice; // throwing bad input for chocie...
            }
        }
        catch (int choice)
        {
            cout << '\a';
            cin.clear();
            cin.ignore(256, '\n');
            choice = 0;
            CLEAR_SCREEN();
            cout << flush;
            for (int i = 3; i > 0; i--)  // incase of wrong input, user waits for i seconds to try again...prevents spamming...
            {
                cout << "\n\n\n";
                cout << "          __________________________________________________\n";
                cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                cout << "         |__________________________________________________\n";
                Sleep(1000);
                CLEAR_SCREEN();
            }
            TITLE();
            MAIN_MENU_OR_EXIT(choice);
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////