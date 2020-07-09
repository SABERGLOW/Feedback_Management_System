#ifndef PROJECT_HEADERS_H
#define PROJECT_HEADERS_H

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <filesystem>

//#include <sstream>
//#include <iomanip>
//#include <stdlib>

using namespace std;


/////////////////////////////////////              CLear Console Screen           //////////////////////////////////
void CLEAR_SCREEN()
{
    system("cls");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////              Exit  /  Terminte           //////////////////////////////////
void EXIT()
{
    cout << "\n\n\n";
    cout << "          __________________________________________________\n";
    cout << "         |    Terminating the Program in 1 second...!!!     |\n";
    cout << "         |__________________________________________________|\n";
    Sleep(1000);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////  TITLE SCREEN   ///////////////////////////////////////////////
void TITLE()
{
    cout << "\n\n";
    cout << "              ________________________________________________________________\n";
    cout << "             |               COURSE FEEDBACK MANAGEMENT SYSTEM                |\n";
    cout << "             |________________________________________________________________|\n";
    cout << "\n\n\n";
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////   MAIN MENU 0R EXIT   /////////////////////////////////////////////
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
                return choice;
            }
            else
            {
                throw choice;
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
            for (int i = 3; i > 0; i--)
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






class ADMIN
{
    string USERNAME;
    string PASSWORD;
public:
    //string USERNAME;
    string LOWER_USERNAME;
    //string PASSWORD;
    bool LOGIN_SUCCESSFUL;

    ADMIN() //// Default Constructor ////
    {
        LOGIN_SUCCESSFUL = false;
    }

    void SET_USERNAME(string SET_THIS_USERNAME) //// Setter for USERNAME ////
    {
        USERNAME = SET_THIS_USERNAME;
    }
    string GET_USERNAME() //// Getter for USERNAME ////
    {
        return USERNAME;
    }

    void SET_PASSWORD(string SET_THIS_PASSWORD) //// Setter for PASSWORD ////
    {
        PASSWORD = SET_THIS_PASSWORD;
    }
    string GET_PASSWORD() //// Getter for PASSWORD ////
    {
        return PASSWORD;
    }

    //////////////////////////////////////////////////  LOGIN FUNCTION  /////////////////////////////////////////////////////
    bool LOGIN_FUNCTION(bool ITS_ADMIN)
    {
        cout << "Enter your LOGIN: " << flush;
        cin >> USERNAME;

        //------------function to convert string into lowercase---------------
        LOWER_USERNAME = USERNAME;
        transform(LOWER_USERNAME.begin(), LOWER_USERNAME.end(), LOWER_USERNAME.begin(), ::tolower);
        //////////////////////////////////////////////////////////////////////
        if (LOWER_USERNAME == "admin")
        {
            ITS_ADMIN = TRUE;
            return ITS_ADMIN;
        }
        else
        {
            ITS_ADMIN = FALSE;
            return ITS_ADMIN;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////  LOGIN VALIDATION FUNCTION  /////////////////////////////////////////////////////
    virtual bool LOGIN_VALIDATION_FUNCTION()
    {
        cout << "Enter your PASSWORD: " << flush;
        cin >> PASSWORD;
        string ADMIN_FILE_PATH = "./Admin/ADMIN_LOGIN.txt";
        string CHECK = GET_LOGIN_DATA(ADMIN_FILE_PATH.c_str());
        ///////////////////////////////////////////////////////////
        try     //... Exception Handling incase of Unsuccessful Login ...//
        {      //////////////////////////////////////////////////////////
            if (CHECK == USERNAME)
            {
                ADMIN_FILE_PATH = "./Admin/ADMIN_PASSWORD.txt";
                CHECK = GET_LOGIN_DATA(ADMIN_FILE_PATH.c_str());
                if (CHECK == PASSWORD)
                {
                    cout << "LOGIN SUCCESSFUL...!" << endl;
                    LOGIN_SUCCESSFUL = true;
                    return TRUE;
                }
                else
                {
                    throw LOGIN_SUCCESSFUL;
                }
            }
            else
            {
                throw LOGIN_SUCCESSFUL;
            }
        }
        catch (bool LOGIN_SUCCESSFUL)
        {
            UNREFERENCED_PARAMETER(LOGIN_SUCCESSFUL);
            CLEAR_SCREEN();
            cout << flush;
            TITLE();
            cout << "login Failed, Try Again..." << endl << endl;
            bool ITS_ADMIN = FALSE;
            return FALSE;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////  GET USERNAME & PASSWORD FUNCTION  ///////////////////////////////////////////
    string GET_LOGIN_DATA(const string& FILE_NAME)
    {
        string LINE;
        fstream READ;
        READ.open(FILE_NAME.c_str(), ios::in);
        {
            if (READ.is_open())
            {
                getline(READ, LINE);
            }
        }
        READ.close();
        return LINE;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////  ADMIN MAIN MENU  /////////////////////////////////////////////////////
    int ADMIN_MAIN_MENU_FUNCTION(int choice)
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "          You're now logged in as an ADMINISTRATOR...." << endl << endl << endl;

        cout << "          >> Please choose one of the following options:\n\n";

        cout << "           ____________________________________________" << endl;
        cout << "          |1. Manage Feedback Form                     |" << endl;
        cout << "          |2. Manage Students                          |" << endl;
        cout << "          |3. Manage Submitted Feedbacks               |" << endl;
        cout << "          |4. Change Your Password                     |" << endl;
        cout << "          |5. Log-Out                                  |" << endl;
        cout << "          |6. Exit                                     |" << endl;
        {
            cout << "\n          Answer: ";

            //////////////////////////////////////////////////////////
            try     //....   Exception Handling incase of Wrong Input    ...//
            {      //////////////////////////////////////////////////////////
                cin >> choice;
                if ((choice <= 6) && (choice >= 1))
                {
                    return choice;
                }
                else
                {
                    throw choice;
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
                for (int i = 3; i > 0; i--)
                {
                    cout << "\n\n\n";
                    cout << "          __________________________________________________\n";
                    cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                    cout << "         |__________________________________________________\n";
                    Sleep(1000);
                    CLEAR_SCREEN();
                }
                ADMIN_MAIN_MENU_FUNCTION(choice);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////  1.ADMIN MANAGE FEEDBACK FORM MENU /////////////////////////////////////////////////
    int ADMIN_MANAGE_FEEDBACK_FORM_MENU_FUNCTION(int choice)
    {
        CLEAR_SCREEN();
        TITLE();

        cout << "          >> Please choose one of the following options:\n\n";

        cout << "           ____________________________________________" << endl;
        cout << "          |1. Print Feedback Form                      |" << endl;
        cout << "          |2. Edit Feedback Form                       |" << endl;
        cout << "          |3. Search Feedback Form                     |" << endl;
        cout << "          |4. Return to Main Menu                      |" << endl;
        cout << "          |5. Exit                                     |" << endl;
        {
            cout << "\n          Answer: ";

            //////////////////////////////////////////////////////////
            try     //....   Exception Handling incase of Wrong Input    ...//
            {      //////////////////////////////////////////////////////////
                cin >> choice;
                if ((choice <= 5) && (choice >= 1))
                {
                    return choice;
                }
                else
                {
                    throw choice;
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
                for (int i = 3; i > 0; i--)
                {
                    cout << "\n\n\n";
                    cout << "          __________________________________________________\n";
                    cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                    cout << "         |__________________________________________________\n";
                    Sleep(1000);
                    CLEAR_SCREEN();
                }
                ADMIN_MANAGE_FEEDBACK_FORM_MENU_FUNCTION(choice);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////  1.1.PRINT THE FEEDBACK FORM  ////////////////////////////////////////////////
    void PRINT_FEEDBACK_FORM()
    {
        cout << "              _________________________________\n";
        cout << "             |          FEEDBACK FORM          |\n";
        cout << "             |_________________________________|\n";
        cout << "\n";
        string *FEEDBACK_FORM;
        int LINE_COUNT = 0;
        int COUNTER = 0;

        fstream READ;
        string READ_LINE;
        READ.open("./Feedback Form/Feedback Form.txt", ios::in);
        {
            while (getline(READ, READ_LINE))
            {
                LINE_COUNT++;
            }
        }
        READ.close();
                                                 ///////////////////////////////////////////////////////////////////////////////
        FEEDBACK_FORM = new string [LINE_COUNT];//...Dynamic String Array that has element number = lines in feedback form...// 
                                              //... [each line has one question, hence each index will carry one question]..//
        
        READ.open("./Feedback Form/Feedback Form.txt", ios::in);
        {
            while (getline(READ, READ_LINE))
            {
                FEEDBACK_FORM[COUNTER] = READ_LINE;
                COUNTER++;
            }
        }
        READ.close();

        for(int i=0; i<LINE_COUNT; i++)
        {
            cout<<FEEDBACK_FORM[i]<<endl;
        }
        delete []FEEDBACK_FORM;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////  1.2. ADMIN EDIT FEEDBACK FORM MENU /////////////////////////////////////////////
    int ADMIN_EDIT_FEEDBACK_FORM_MENU_FUNCTION(int choice)
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "           ________________________________________________\n";
        cout << "          |               EDIT FEEDBACK FORM               |\n";
        cout << "          |________________________________________________|\n";
        cout << "\n";

        cout << "          >> Please choose one of the following options:\n\n";

        cout << "           ____________________________________________" << endl;
        cout << "          |1. Add A New Question                       |" << endl;
        cout << "          |2. Remove A Question                        |" << endl;
        cout << "          |3. Return to Main Menu                      |" << endl;
        cout << "          |4. Exit                                     |" << endl;
        {
            cout << "\n          Answer: ";

            //////////////////////////////////////////////////////////
            try     //....   Exception Handling incase of Wrong Input    ...//
            {      //////////////////////////////////////////////////////////
                cin >> choice;
                if ((choice <= 4) && (choice >= 1))
                {
                    return choice;
                }
                else
                {
                    throw choice;
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
                for (int i = 3; i > 0; i--)
                {
                    cout << "\n\n\n";
                    cout << "          __________________________________________________\n";
                    cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                    cout << "         |__________________________________________________\n";
                    Sleep(1000);
                    CLEAR_SCREEN();
                }
                ADMIN_EDIT_FEEDBACK_FORM_MENU_FUNCTION(choice);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////      1.2.1 ADD A NEW QUESTION     ////////////////////////////////////////////////////
    void ADD_QUESTION()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              __________________________________________________\n";
        cout << "             |                ADD A NEW QUESTION                |\n";
        cout << "             |__________________________________________________|\n";
        cout << "\n";

        string QUESTION;
        cout << "              Enter The NEW QUESTION: ";
        cin.ignore();
        getline(cin, QUESTION);

        fstream READ;
        string READ_LINE;
        int LINE_COUNT = 0;
        READ.open("./Feedback Form/Feedback Form.txt", ios::in);
        {
            while (getline(READ, READ_LINE))
            {
                LINE_COUNT++;
            }
        }
        READ.close();

        QUESTION = to_string(LINE_COUNT+1) + ") " + QUESTION;

        READ.open("./Feedback Form/Feedback Form.txt", ios::app);
        {
            READ<<endl<<QUESTION;
        }
        READ.close();
        
        cout << "              __________________________________________________\n";
        cout << "             | NEW QUESTION ADDED SUCCESSFULLY...               |\n";
        cout << "             |__________________________________________________|\n";
        cout << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////      1.2.2 REMOVE A QUESTION     ////////////////////////////////////////////////////
    void REMOVE_QUESTION()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              __________________________________________________\n";
        cout << "             |                REMOVE A QUESTION                 |\n";
        cout << "             |__________________________________________________|\n";
        cout << "\n";

        int QUESTION;
        cout << "              Enter the Question Number that you want to remove: ";

        fstream READ;
        string READ_LINE;
        int LINE_COUNT = 0;
        READ.open("./Feedback Form/Feedback Form.txt", ios::in);
        {
            while (getline(READ, READ_LINE))
            {
                LINE_COUNT++;
            }
        }
        READ.close();

                     //////////////////////////////////////////////////////////
            try     //....   Exception Handling incase of Wrong Input    ...//
            {      //////////////////////////////////////////////////////////
                cin >> QUESTION;
                if ((QUESTION <= LINE_COUNT) && (QUESTION >= 1))
                {
                    string *FEEDBACK_FORM;
                    int COUNTER = 0;
                                                             ///////////////////////////////////////////////////////////////////////////////
                    FEEDBACK_FORM = new string [LINE_COUNT];//...Dynamic String Array that has element number = lines in feedback form...// 
                                                           //... [each line has one question, hence each index will carry one question]..//
                    READ.open("./Feedback Form/Feedback Form.txt", ios::in);
                    {
                        while (getline(READ, READ_LINE))
                        {
                            if((COUNTER+1) != QUESTION)
                            {
                                FEEDBACK_FORM[COUNTER] = READ_LINE;
                                COUNTER++;
                            }
                            else
                            {
                                COUNTER++;
                            }
                        }
                    }
                    READ.close();

                    ofstream OVER_WRITE;
                    OVER_WRITE.open("./Feedback Form/Feedback Form.txt");
                    {
                        for(int i=0; i<LINE_COUNT; i++)
                        {
                            if(i != QUESTION-1)
                            {
                                OVER_WRITE<<FEEDBACK_FORM[i]<<endl;
                            }
                        }
                    }
                    OVER_WRITE.close();

                    cout << "              __________________________________________________\n";
                    cout << "             | NEW QUESTION REMOVED SUCCESSFULLY...             |\n";
                    cout << "             |__________________________________________________|\n";
                    cout << "\n";
                    delete []FEEDBACK_FORM;
                }
                else
                {
                    throw QUESTION;
                }
            }
            catch (int QUESTION)
            {
                cout << '\a';
                cin.clear();
                cin.ignore(256, '\n');
                QUESTION = 0;
                CLEAR_SCREEN();
                cout << flush;
                for (int i = 3; i > 0; i--)
                {
                    cout << "\n\n\n";
                    cout << "          __________________________________________________\n";
                    cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                    cout << "         |__________________________________________________\n";
                    Sleep(1000);
                    CLEAR_SCREEN();
                }
                REMOVE_QUESTION();
            }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////      1.3 SEARCH IN FEEDBACK FORM     ////////////////////////////////////////////////////
    bool SEARCH_IN_FEEDBACK_FORM()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              __________________________________________________\n";
        cout << "             |              SEARCH IN FEEDBACK FORM             |\n";
        cout << "             |__________________________________________________|\n";
        cout << "\n";

        string QUERY;
        cout << "              Enter your Search Query: ";
        cin.ignore();
        getline(cin, QUERY);

        string *FEEDBACK_FORM;
        int LINE_COUNT = 0;
        int COUNTER = 0;

        fstream READ;
        string READ_LINE;
        READ.open("./Feedback Form/Feedback Form.txt", ios::in);
        {
            while (getline(READ, READ_LINE))
            {
                LINE_COUNT++;
            }
        }
        READ.close();
                                                 ///////////////////////////////////////////////////////////////////////////////
        FEEDBACK_FORM = new string [LINE_COUNT];//...Dynamic String Array that has element number = lines in feedback form...// 
                                              //... [each line has one question, hence each index will carry one question]..//
        
        READ.open("./Feedback Form/Feedback Form.txt", ios::in);
        {
            while (getline(READ, READ_LINE))
            {
                FEEDBACK_FORM[COUNTER] = READ_LINE;
                COUNTER++;
            }
        }
        READ.close();

        for(int i=0; i<LINE_COUNT; i++)
        {
            if (FEEDBACK_FORM[i].find(QUERY) != string::npos)
            {
                return TRUE;
            } 
        }
        return FALSE;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    
    //////////////////////////////////////////////  2.ADMIN MANAGE STUDENTS MENU   /////////////////////////////////////////////////
    int ADMIN_MANAGE_STUDENTS_MENU_FUNCTION(int choice)
    {
        CLEAR_SCREEN();
        TITLE();

        cout << "          >> Please choose one of the following options:\n\n";

        cout << "           ____________________________________________" << endl;
        cout << "          |1. Check Total Number of Students           |" << endl;
        cout << "          |2. Search A Student  [NEPTUN CODE]          |" << endl;
        cout << "          |3. Remove A Student  [NEPTUN CODE]          |" << endl;
        cout << "          |4. Add A New Student [NEPTUN CODE]          |" << endl;
        cout << "          |5. Return to Main Menu                      |" << endl;
        cout << "          |6. Exit                                     |" << endl;
        {
            cout << "\n          Answer: ";

            //////////////////////////////////////////////////////////
            try     //....   Exception Handling incase of Wrong Input    ...//
            {      //////////////////////////////////////////////////////////
                cin >> choice;
                if ((choice <= 6) && (choice >= 1))
                {
                    return choice;
                }
                else
                {
                    throw choice;
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
                for (int i = 3; i > 0; i--)
                {
                    cout << "\n\n\n";
                    cout << "          __________________________________________________\n";
                    cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                    cout << "         |__________________________________________________\n";
                    Sleep(1000);
                    CLEAR_SCREEN();
                }
                ADMIN_MANAGE_STUDENTS_MENU_FUNCTION(choice);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////  2.1.CHECK TOTAL NUMBER OF STUDENTS   ///////////////////////////////////////////////
    void TOTAL_STUDENTS()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              ________________________________________________\n";
        cout << "             |                  TOTAL STUDENTS                |\n";
        cout << "             |________________________________________________|\n";
        cout << "\n";

        int TOTAL_FILES = 0;
        string FILE_PATH = "./Students/";                          //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (auto& p : filesystem::directory_iterator(FILE_PATH)) // This Loop was inspired by Stack Overflow Discussion on File Counting Methods, It makes use of FILESYSTEM library.....//
        {                                                        // https://stackoverflow.com/questions/41304891/how-to-count-the-number-of-files-in-a-directory-using-standard/41305019 //
            TOTAL_FILES++;                                      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        }
        cout << "\n               >> Total Number of Students: " << TOTAL_FILES<<" <<"<<endl<<endl<<endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////      2.2.SEARCH A STUDENT [NEPTUN CODE]      /////////////////////////////////////
    void SEARCH_STUDENT()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              __________________________________________________\n";
        cout << "             |                 SEARCH A STUDENT                 |\n";
        cout << "             |__________________________________________________|\n";
        cout << "\n";

        string NEPTUN;
        cout << "              Enter NEPTUN CODE: ";
        cin >> NEPTUN;

        string FILE_PATH = "./Students/" + NEPTUN + ".txt";

        if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  No Student exists under this NEPTUN Code...     \n";
            cout << "         |__________________________________________________\n";
        }
        else
        {
            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  Student Exists In The Database...                \n";
            cout << "         |__________________________________________________\n";
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////      2.3.REMOVE A STUDENT [NEPTUN CODE]      /////////////////////////////////////
    void REMOVE_STUDENT()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              __________________________________________________\n";
        cout << "             |                 REMOVE A STUDENT                 |\n";
        cout << "             |__________________________________________________|\n";
        cout << "\n";
        cout<<"            >> Please be aware, removing a student will also remove his/her submitted feedbacks...!!!"<<endl<<endl;

        string NEPTUN;
        cout << "              Enter NEPTUN CODE: ";
        cin >> NEPTUN;

        string FILE_PATH = "./Students/" + NEPTUN + ".txt";

        if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  No Student exists under this NEPTUN Code...     \n";
            cout << "         |__________________________________________________\n";
        }
        else
        {
            remove(FILE_PATH.c_str());//......................................................removing student
            string FILE_PATH = "./Feedback Form/Submitted Feedbacks/" + NEPTUN + ".txt";//...changing path to submitted feedback
            remove(FILE_PATH.c_str());//....................................................removing submitted feedback

            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  Student Deleted Successfully...                 \n";
            cout << "         |__________________________________________________\n";
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////      2.4.ADD A NEW STUDENT [NEPTUN CODE]      /////////////////////////////////////
    void ADD_STUDENT()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              __________________________________________________\n";
        cout << "             |                   ADD A STUDENT                  |\n";
        cout << "             |__________________________________________________|\n";
        cout << "\n";

        string NEPTUN;
        cout << "              Enter NEPTUN CODE: ";
        cin >> NEPTUN;

        
        string FILE_PATH = "./Students/" + NEPTUN + ".txt";

        if (CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  Student already exists...                       \n";
            cout << "         |__________________________________________________\n";
        }
        else
        {
            string PASSWORD;
            cout << "              Set A New PASSWORD: ";
            cin >> PASSWORD;

            fstream ADD;
            ADD.open(FILE_PATH.c_str(), ios::app);
            {
                ADD<<PASSWORD;
            }
            ADD.close();

            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  Student Added Successfully...                 \n";
            cout << "         |__________________________________________________\n";
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////  3.ADMIN MANAGE SUBMITTED FEEDBACKS MENU   ///////////////////////////////////////////////
    int ADMIN_MANAGE_SUBMITTED_FEEDBACKS_MENU_FUNCTION(int choice)
    {
        CLEAR_SCREEN();
        TITLE();

        cout << "          >> Please choose one of the following options:\n\n";

        cout << "           _________________________________________________" << endl;
        cout << "          |1. Check Total Number of Submitted Feedbacks     |" << endl;
        cout << "          |2. Print  A Student's Feedback [NEPTUN CODE]     |" << endl;
        cout << "          |3. Remove A Student's Feedback [NEPTUN CODE]     |" << endl;
        cout << "          |4. Return to Main Menu                           |" << endl;
        cout << "          |5. Exit                                          |" << endl;
        {
            cout << "\n          Answer: ";

            //////////////////////////////////////////////////////////
            try     //....   Exception Handling incase of Wrong Input    ...//
            {      //////////////////////////////////////////////////////////
                cin >> choice;
                if ((choice <= 5) && (choice >= 1))
                {
                    return choice;
                }
                else
                {
                    throw choice;
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
                for (int i = 3; i > 0; i--)
                {
                    cout << "\n\n\n";
                    cout << "          __________________________________________________\n";
                    cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                    cout << "         |__________________________________________________\n";
                    Sleep(1000);
                    CLEAR_SCREEN();
                }
                ADMIN_MANAGE_SUBMITTED_FEEDBACKS_MENU_FUNCTION(choice);
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////  3.1.CHECK TOTAL NUMBER OF SUBMITTED FEEDBACKS   ///////////////////////////////////////
    void TOTAL_SUBMITTED_FEEDBACKS()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              ________________________________________________\n";
        cout << "             |         TOTAL SUBMITTED FEEDBACK FORMS         |\n";
        cout << "             |________________________________________________|\n";
        cout << "\n";

        int TOTAL_FILES = 0;
        string FILE_PATH = "./Feedback Form/Submitted Feedbacks/"; //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (auto& p : filesystem::directory_iterator(FILE_PATH)) // This Loop was inspired by Stack Overflow Discussion on File Counting Methods, It makes use of FILESYSTEM library.....//
        {                                                        // https://stackoverflow.com/questions/41304891/how-to-count-the-number-of-files-in-a-directory-using-standard/41305019 //
            TOTAL_FILES++;                                      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        }
        cout << "\n               >> Total Number of Submitted Feedback Files: " << TOTAL_FILES<<" <<"<<endl<<endl<<endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////  3.2.PRINT A STUDENT'S FEEDBACK [NEPTUN CODE]  /////////////////////////////////////
    virtual bool PRINT_SUBMITTED_FEEDBACK_FORM()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              ___________________________________________\n";
        cout << "             |          SUBMITTED FEEDBACK FORM          |\n";
        cout << "             |___________________________________________|\n";
        cout << "\n";

        string NEPTUN;
        cout << "              Enter NEPTUN CODE: ";
        cin >> NEPTUN;

        string FILE_PATH = "./Feedback Form/Submitted Feedbacks/" + NEPTUN + ".txt";

        if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  No Feedback Submitted by this student yet...    \n";
            cout << "         |__________________________________________________\n";
            return FALSE;
        }
        else
        {
            string SUBMITTED_FEEDBACK_FORM;
            fstream READ;
            READ.open(FILE_PATH.c_str(), ios::in);
            {
                while (getline(READ, SUBMITTED_FEEDBACK_FORM))
                {
                    cout << SUBMITTED_FEEDBACK_FORM << endl;
                }
            }
            READ.close();
            return TRUE;
        }

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////  3.3.REMOVE A STUDENT'S FEEDBACK [NEPTUN CODE]  /////////////////////////////////////
    void REMOVE_SUBMITTED_FEEDBACK()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              __________________________________________________\n";
        cout << "             |          REMOVE SUBMITTED FEEDBACK FORM          |\n";
        cout << "             |__________________________________________________|\n";
        cout << "\n";

        string NEPTUN;
        cout << "              Enter NEPTUN CODE: ";
        cin >> NEPTUN;

        string FILE_PATH = "./Feedback Form/Submitted Feedbacks/" + NEPTUN + ".txt";

        if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  No Feedback Submitted by this student yet...    \n";
            cout << "         |__________________________________________________\n";
        }
        else
        {
            remove(FILE_PATH.c_str());

            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  Submitted Feedback File Deleted Successfully... \n";
            cout << "         |__________________________________________________\n";
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////      4. CHANGE YOUR PASSWORD         ///////////////////////////////////////////
    virtual void CHANGE_PASSWORD()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              ________________________________________________\n";
        cout << "             |             CHANGE YOUR PASSWORD               |\n";
        cout << "             |________________________________________________|\n";
        cout << "\n";

        string NEW_PASSWORD;
        cout<<"               >> Enter your NEW PASSWORD: ";
        cin >> NEW_PASSWORD;

        string FILE_PATH = "./Admin/ADMIN_PASSWORD.txt";
        ofstream OVER_WRITE;
        OVER_WRITE.open(FILE_PATH.c_str());
        {
            OVER_WRITE<<NEW_PASSWORD;
        }
        OVER_WRITE.close();

        cout << "              ________________________________________________\n";
        cout << "             |           PASSWORD CHANGED SUCCESSFULLY...     |\n";
        cout << "             |________________________________________________|\n";
        cout << "\n";


    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////          CHECK EXISTING FILE          ///////////////////////////////////////////
    bool CHECK_EXISTING_FILE(const string& FILE_NAME)
    {
        fstream READ;
        READ.open(FILE_NAME.c_str(), ios::in);
        {
            if (READ.is_open())
            {
                READ.close();
                return TRUE;
            }
            return false;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

};





class STUDENT : public ADMIN
{
public:
    string STUDENT_PASSWORD;

    STUDENT() //// Default Constructor ////
    {
        LOGIN_SUCCESSFUL = false;
    }
    //////////////////////////////////////////////////  LOGIN FUNCTION [OVERLOADED]  /////////////////////////////////////////////////////
    bool LOGIN_VALIDATION_FUNCTION()
    {
        cout << "Enter your PASSWORD: " << flush;
        cin >> STUDENT_PASSWORD;
        SET_PASSWORD(STUDENT_PASSWORD);
        string STUDENT_FILE_PATH = "./Students/" + GET_USERNAME() + ".txt";

        fstream CHECK_FILE_EXIST;
        CHECK_FILE_EXIST.open(STUDENT_FILE_PATH.c_str(), ios::in);

        if (CHECK_FILE_EXIST.is_open())
        {
            CHECK_FILE_EXIST.close();
            string CHECK = GET_LOGIN_DATA(STUDENT_FILE_PATH.c_str());
            ///////////////////////////////////////////////////////////
            try     //... Exception Handling incase of Unsuccessful Login ...//
            {      //////////////////////////////////////////////////////////
                if (CHECK == GET_PASSWORD())
                {
                    cout << "LOGIN SUCCESSFUL...!" << endl;
                    LOGIN_SUCCESSFUL = true;
                    return TRUE;
                }
                else
                {
                    throw LOGIN_SUCCESSFUL;
                }
            }
            catch (bool LOGIN_SUCCESSFUL)
            {
                UNREFERENCED_PARAMETER(LOGIN_SUCCESSFUL);
                CLEAR_SCREEN();
                cout << flush;
                TITLE();
                cout << "login Failed, Try Again..." << endl << endl;
                bool ITS_STUDENT = FALSE;
                return FALSE;
            }
        }
        else
        {
            CLEAR_SCREEN();
            cout << flush;
            TITLE();
            cout << "login Failed, Try Again..." << endl << endl;
            bool ITS_STUDENT = FALSE;
            return FALSE;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////  STUDENT MAIN MENU  /////////////////////////////////////////////////////
    int STUDENT_MAIN_MENU_FUNCTION(int choice)
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "          You're now logged in as a STUDENT...." << endl << endl << endl;

        cout << "          >> Please choose one of the following options:\n\n";

        cout << "           ____________________________________________" << endl;
        cout << "          |1. View The Feedback Form                   |" << endl;
        cout << "          |2. Fill_Out The Feedback Form               |" << endl;
        cout << "          |3. View Your Submitted Feedback             |" << endl;
        cout << "          |4. Change Your Password                     |" << endl;
        cout << "          |5. Log_Out                                  |" << endl;
        cout << "          |6. Exit                                     |" << endl;


        {
            cout << "\n          Answer: ";

            //////////////////////////////////////////////////////////
            try     //....   Exception Handling incase of Wrong Input    ...//
            {      //////////////////////////////////////////////////////////
                cin >> choice;
                if ((choice <= 6) && (choice >= 1))
                {
                    return choice;
                }
                else
                {
                    throw choice;
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
                for (int i = 3; i > 0; i--)
                {
                    cout << "\n\n\n";
                    cout << "          __________________________________________________\n";
                    cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                    cout << "         |__________________________________________________\n";
                    Sleep(1000);
                    CLEAR_SCREEN();
                }
                STUDENT_MAIN_MENU_FUNCTION(choice);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////    1. VIEW THE FEEDBACK FORM        ///////////////////////////////////////////
        //..................................................................................................................
        //... Using the Function from ADMIN CLASS IMPLEMENTATIONS [1.1.PRINT THE FEEDBACK FORM].............................
        //..................................................................................................................
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////    2. FILL_OUT THE FEEDBACK FORM        ///////////////////////////////////////////
    bool STUDENT_FILL_OUT_THE_FEEDBACK_FORM_FUNCTION(int choice)
    {
        CLEAR_SCREEN();
        TITLE();

        string FILE_PATH = "./Feedback Form/Submitted Feedbacks/" + GET_USERNAME() + ".txt";

        if (CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  FEEDBACK ALREADY SUBMITTED...!                  \n";
            cout << "         |__________________________________________________\n";
            return FALSE;
        }

        string QUESTION_LINE;
        fstream READ_FEEDBACK_FORM;
        fstream WRITE_FEEDBACK_ANSWERS;
        READ_FEEDBACK_FORM.open("./Feedback Form/Feedback Form.txt", ios::in);
        WRITE_FEEDBACK_ANSWERS.open(FILE_PATH.c_str(), ios::app);
        {
            while (getline(READ_FEEDBACK_FORM, QUESTION_LINE))
            {
                cout << QUESTION_LINE << endl << "    1. STRONGLY AGREE    2. AGREE    3. NEUTRAL    4. DISAGREE    5. STRONGLY DISAGREE" << endl;

            CHOICE_SELECTION:
                cout << endl << "ENTER A CHOICE: ";

                //////////////////////////////////////////////////////////
                try     //....   Exception Handling incase of Wrong Input    ...//
                {      //////////////////////////////////////////////////////////
                    cin >> choice;
                    cout << endl;
                    if ((choice <= 5) && (choice >= 1))
                    {
                        if (choice == 1)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    1. STRONGLY AGREE" << endl << endl;
                        }
                        if (choice == 2)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    2. AGREE" << endl << endl;
                        }
                        if (choice == 3)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    3. NEUTRAL" << endl << endl;
                        }
                        if (choice == 4)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    4. DISAGREE" << endl << endl;
                        }
                        if (choice == 5)
                        {
                            WRITE_FEEDBACK_ANSWERS << QUESTION_LINE << endl << "    5. STRONGLY DISAGREE" << endl << endl;
                        }
                    }
                    else
                    {
                        throw choice;
                    }
                }
                catch (int choice)
                {
                    cout << '\a';
                    cin.clear();
                    cin.ignore(256, '\n');
                    choice = 0;
                    for (int i = 1; i > 0; i--)
                    {
                        cout << "\n\n\n";
                        cout << "          __________________________________________________\n";
                        cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...!!!\n";
                        cout << "         |__________________________________________________\n";
                        Sleep(1000);
                        cout << endl << endl << " ERROR: INVALID INPUT: ENTER AGAIN: ";
                    }
                    goto CHOICE_SELECTION;
                }
            }
        }
        READ_FEEDBACK_FORM.close();
        WRITE_FEEDBACK_ANSWERS.close();
        return true;

    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////    3. VIEW YOUR SUBMITTED FEEDBACK [OVERLOADED]        ///////////////////////////////////////////
    bool PRINT_SUBMITTED_FEEDBACK_FORM()
    {
        CLEAR_SCREEN();
        TITLE();

        string FILE_PATH = "./Feedback Form/Submitted Feedbacks/" + GET_USERNAME() + ".txt";

        if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
        {
            cout << "\n\n\n";
            cout << "          __________________________________________________\n";
            cout << "         |  No Feedback Submitted by this student yet...    \n";
            cout << "         |__________________________________________________\n";
            return FALSE;
        }

        else
        {
            string SUBMITTED_FEEDBACK_FORM;
            fstream READ;
            READ.open(FILE_PATH.c_str(), ios::in);
            {
                while (getline(READ, SUBMITTED_FEEDBACK_FORM))
                {
                    cout << SUBMITTED_FEEDBACK_FORM << endl;
                }
            }
            READ.close();
            return TRUE;
        }

    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////      4. CHANGE YOUR PASSWORD  [OVERLOADED]       ///////////////////////////////////////////
    void CHANGE_PASSWORD()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              ________________________________________________\n";
        cout << "             |             CHANGE YOUR PASSWORD               |\n";
        cout << "             |________________________________________________|\n";
        cout << "\n";

        string NEW_PASSWORD;
        cout<<"               >> Enter your NEW PASSWORD: ";
        cin >> NEW_PASSWORD;

        string FILE_PATH = "./Students/" + GET_USERNAME() + ".txt";
        ofstream OVER_WRITE;
        OVER_WRITE.open(FILE_PATH.c_str());
        {
            OVER_WRITE<<NEW_PASSWORD;
        }
        OVER_WRITE.close();

        cout << "              ________________________________________________\n";
        cout << "             |           PASSWORD CHANGED SUCCESSFULLY...     |\n";
        cout << "             |________________________________________________|\n";
        cout << "\n";


    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};


#endif /* PROJECT_HEADERS_H */