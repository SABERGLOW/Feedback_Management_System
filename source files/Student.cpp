#include "Student.h"

    STUDENT::STUDENT() //// Default Constructor ////
    {
        LOGIN_SUCCESSFUL = false;
    }
    //////////////////////////////////////////////////  LOGIN FUNCTION [OVERLOADED]   /////////////////////////////////////////////////////
    bool STUDENT::LOGIN_VALIDATION_FUNCTION()
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
            DECRYPT(STUDENT_FILE_PATH.c_str());
            string CHECK = GET_LOGIN_DATA(STUDENT_FILE_PATH.c_str());
            ///////////////////////////////////////////////////////////
            try     //... Exception Handling incase of Unsuccessful Login ...//
            {      //////////////////////////////////////////////////////////
                if (CHECK == GET_PASSWORD())
                {
                    cout << "LOGIN SUCCESSFUL...!" << endl;
                    LOGIN_SUCCESSFUL = true;
                    ENCRYPT(STUDENT_FILE_PATH.c_str());
                    return TRUE;
                }
                else
                {
                    ENCRYPT(STUDENT_FILE_PATH.c_str());
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
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////             STUDENT MAIN MENU              /////////////////////////////////////////////////////
    int STUDENT::STUDENT_MAIN_MENU_FUNCTION(int choice)
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
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////          1. VIEW THE FEEDBACK FORM                 ///////////////////////////////////////////
    /*
        //..................................................................................................................
        //... Using the Function from ADMIN CLASS IMPLEMENTATIONS [1.1.PRINT THE FEEDBACK FORM].............................
        //..................................................................................................................
    */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////      2. FILL_OUT THE FEEDBACK FORM                 ///////////////////////////////////////////
    bool STUDENT::STUDENT_FILL_OUT_THE_FEEDBACK_FORM_FUNCTION(int choice)
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
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////    3. VIEW YOUR SUBMITTED FEEDBACK [OVERLOADED]     ///////////////////////////////////////////
    bool STUDENT::PRINT_SUBMITTED_FEEDBACK_FORM()
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
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////      4. CHANGE YOUR PASSWORD  [OVERLOADED]            ///////////////////////////////////////////
    void STUDENT::CHANGE_PASSWORD()
    {
        CLEAR_SCREEN();
        TITLE();
        cout << "              ________________________________________________\n";
        cout << "             |             CHANGE YOUR PASSWORD               |\n";
        cout << "             |________________________________________________|\n";
        cout << "\n";

        string NEW_PASSWORD;
        cout << "               >> Enter your NEW PASSWORD: ";
        cin >> NEW_PASSWORD;

        string FILE_PATH = "./Students/" + GET_USERNAME() + ".txt";
        ofstream OVER_WRITE;
        OVER_WRITE.open(FILE_PATH.c_str());
        {
            OVER_WRITE << NEW_PASSWORD;
        }
        OVER_WRITE.close();
        ENCRYPT(FILE_PATH.c_str());

        cout << "              ________________________________________________\n";
        cout << "             |           PASSWORD CHANGED SUCCESSFULLY...     |\n";
        cout << "             |________________________________________________|\n";
        cout << "\n";


    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////