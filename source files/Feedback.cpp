#include "Student.h"

using namespace std;

bool ITS_ADMIN;
bool ITS_STUDENT;
int CHOICE;

int main()
{
    ADMIN ADMINISTRATOR;
    STUDENT STUDENT;

    TITLE();
LOGIN_SCREEN:

    //////////////////////////////////////////      ADMIN RELATED FUNCTIONS AND IMPLEMENTATIONS          ///////////////////////////////////////

    if (ADMINISTRATOR.LOGIN_FUNCTION(ITS_ADMIN)) ///// Returns TRUE if ADMIN is trying to login /////
    {
        if (ADMINISTRATOR.LOGIN_VALIDATION_FUNCTION())///// Returns TRUE if PASSWORD is correct /////
        {
            ITS_ADMIN = TRUE;
            ITS_STUDENT = FALSE;

        Admin_Main_Menu:
            CHOICE = ADMINISTRATOR.ADMIN_MAIN_MENU_FUNCTION(CHOICE);///// Returns the choice made by user for the Main Menu /////

            if (CHOICE == 1) /////..... User Selected: Manage Feedback Form ...../////
            {
                cout << flush;
                CHOICE = ADMINISTRATOR.ADMIN_MANAGE_FEEDBACK_FORM_MENU_FUNCTION(CHOICE);
                {
                    if (CHOICE == 1) /////..... User Selected: View Feedback Form ...../////
                    {
                        CLEAR_SCREEN();
                        cout << flush;
                        TITLE();
                        ADMINISTRATOR.PRINT_FEEDBACK_FORM();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                            {
                                goto Admin_Main_Menu;
                            }
                            else////////......... User Selected: Exit .........////////
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 2) /////..... User Selected: Edit Feedback Form ...../////
                    {
                        cout << flush;
                        CHOICE = ADMINISTRATOR.ADMIN_EDIT_FEEDBACK_FORM_MENU_FUNCTION(CHOICE);
                        if(CHOICE == 1)/////..... User Selected: Add A New Question ...../////
                        {
                            ADMINISTRATOR.ADD_QUESTION();
                            CHOICE = 0;
                            CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                            {
                                if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                                {
                                    goto Admin_Main_Menu;
                                }
                                else////////......... User Selected: Exit .........////////
                                {
                                    CHOICE = 0;
                                    EXIT();
                                }
                            }
                        }
                        if(CHOICE == 2)/////..... User Selected: Remove A Question ...../////
                        {
                            ADMINISTRATOR.REMOVE_QUESTION();
                            CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                            {
                                if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                                {
                                    goto Admin_Main_Menu;
                                }
                                else////////......... User Selected: Exit .........////////
                                {
                                    CHOICE = 0;
                                    EXIT();
                                }
                            }
                        }
                        if (CHOICE == 3)/////..... User Selected: Return to Main Menu ...../////
                        {
                            goto Admin_Main_Menu;
                        }
                        if (CHOICE == 4)////////......... User Selected: Exit .........////////
                        {
                            EXIT();
                        }                        
                    }
                    if (CHOICE == 3) /////..... User Selected: Search Feedback Form ...../////
                    {
                        CLEAR_SCREEN();
                        cout << flush;
                        TITLE();
                        if(ADMINISTRATOR.SEARCH_IN_FEEDBACK_FORM())
                        {
                            cout << "              __________________________________________________\n";
                            cout << "             |                QUERY FOUND...!!!                 |\n";
                            cout << "             |__________________________________________________|\n";
                            cout << "\n";
                        }
                        else
                        {
                            cout << "              __________________________________________________\n";
                            cout << "             |  Your Query doesn't exist in the Feedback Form   |\n";
                            cout << "             |__________________________________________________|\n";
                            cout << "\n";
                        }
                        
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                            {
                                goto Admin_Main_Menu;
                            }
                            else////////......... User Selected: Exit .........////////
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 4)/////..... User Selected: Return to Main Menu ...../////
                    {
                        goto Admin_Main_Menu;
                    }
                    if (CHOICE == 5)////////......... User Selected: Exit .........////////
                    {
                        EXIT();
                    }
                }
            }
            if (CHOICE == 2)/////.....  User Selected: Manage Students    ...../////
            {
                cout << flush;
                CHOICE = ADMINISTRATOR.ADMIN_MANAGE_STUDENTS_MENU_FUNCTION(CHOICE);
                {
                    if (CHOICE == 1)/////..... User Selected: Check Total Number of Students...../////
                    {
                        ADMINISTRATOR.TOTAL_STUDENTS();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                            {
                                goto Admin_Main_Menu;
                            }
                            else////////......... User Selected: Exit .........////////
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 2)/////..... User Selected: Search A Student  [NEPTUN CODE]...../////
                    {
                        ADMINISTRATOR.SEARCH_STUDENT();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                            {
                                goto Admin_Main_Menu;
                            }
                            else////////......... User Selected: Exit .........////////
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 3)/////..... User Selected: Remove A Student  [NEPTUN CODE]...../////
                    {
                        ADMINISTRATOR.REMOVE_STUDENT();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                            {
                                goto Admin_Main_Menu;
                            }
                            else////////......... User Selected: Exit .........////////
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 4)/////..... User Selected: Add A New Student [NEPTUN CODE]...../////
                    {
                        ADMINISTRATOR.ADD_STUDENT();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                            {
                                goto Admin_Main_Menu;
                            }
                            else////////......... User Selected: Exit .........////////
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 5)/////..... User Selected: Return to Main Menu ...../////
                    {
                        goto Admin_Main_Menu;
                    }
                    if (CHOICE == 6)////////......... User Selected: Exit .........////////
                    {
                        EXIT();
                    }
                }
            }
            if (CHOICE == 3)//.....User Selected: Manage Submitted Feedbacks.....///
            {
                CLEAR_SCREEN();
                cout << flush;
                TITLE();
                CHOICE = ADMINISTRATOR.ADMIN_MANAGE_SUBMITTED_FEEDBACKS_MENU_FUNCTION(CHOICE);
                {
                    if (CHOICE == 1)/////..... User Selected: Check Total Number of Submitted Feedbacks ...../////
                    {
                        ADMINISTRATOR.TOTAL_SUBMITTED_FEEDBACKS();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                            {
                                goto Admin_Main_Menu;
                            }
                            else////////......... User Selected: Exit .........////////
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 2)////////......... User Selected: Print  A Student's Feedback .........////////
                    {
                        if (!ADMINISTRATOR.PRINT_SUBMITTED_FEEDBACK_FORM())//...........The feedback wasn't submitted yet...
                        {
                            CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                            {
                                if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                                {
                                    goto Admin_Main_Menu;
                                }
                                else////////......... User Selected: Exit .........////////
                                {
                                    EXIT();
                                }
                            }
                        }
                        else
                        {
                            CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                            {
                                if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                                {
                                    goto Admin_Main_Menu;
                                }
                                else////////......... User Selected: Exit .........////////
                                {
                                    EXIT();
                                }
                            }
                        }

                    }
                    if (CHOICE == 3)/////..... User Selected: Remove A Student's Feedback ...../////
                    {
                        ADMINISTRATOR.REMOVE_SUBMITTED_FEEDBACK();
                        CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                        {
                            if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                            {
                                goto Admin_Main_Menu;
                            }
                            else////////......... User Selected: Exit .........////////
                            {
                                CHOICE = 0;
                                EXIT();
                            }
                        }
                    }
                    if (CHOICE == 4)/////..... User Selected: Return to Main Menu ...../////
                    {
                        goto Admin_Main_Menu;
                    }
                    if (CHOICE == 5)////////......... User Selected: Exit .........////////
                    {
                        EXIT();
                    }
                }
            }
            if (CHOICE == 4)/////..... User Selected: Change Your Password  ...../////
            {
                ADMINISTRATOR.CHANGE_PASSWORD();
                CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                {
                    if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                    {
                        goto Admin_Main_Menu;
                    }
                    else////////......... User Selected: Exit .........////////
                    {
                        CHOICE = 0;
                        EXIT();
                    }
                }
            }
            if (CHOICE == 5)/////..... User Selected: Log Out ...../////
            {
                CLEAR_SCREEN();
                TITLE();
                goto LOGIN_SCREEN;
            }
            if (CHOICE == 6)////////......... User Selected: Exit .........////////
            {
                EXIT();
            }

        }
        else
        {
            goto LOGIN_SCREEN; //....... Incase the Password wasn't correct, we move back to LOGIN screen.....//
        }

    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////      STUDENT RELATED FUNCTIONS AND IMPLEMENTATIONS          /////////////////////////////////////
    else
    {
        STUDENT.SET_USERNAME(ADMINISTRATOR.GET_USERNAME()); //// If USERNAME wasn't "ADMIN", then obviously it's a Student...////

        if (STUDENT.LOGIN_VALIDATION_FUNCTION())   /////...................... Returns TRUE if PASSWORD is correct /////
        {
            ITS_ADMIN = FALSE;
            ITS_STUDENT = TRUE;

        Student_Main_Menu:
            CHOICE = STUDENT.STUDENT_MAIN_MENU_FUNCTION(CHOICE);

            if (CHOICE == 1) /////..... User Selected: View Feedback Form ...../////
            {
                CLEAR_SCREEN();
                cout << flush;
                TITLE();
                ADMINISTRATOR.PRINT_FEEDBACK_FORM();
                CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                {
                    if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                    {
                        goto Student_Main_Menu;
                    }
                    else////////......... User Selected: Exit .........////////
                    {
                        CHOICE = 0;
                        EXIT();
                    }
                }


            }
            if (CHOICE == 2)///... User Selected: Fill_Out The Feedback Form  ...///
            {
                if (!STUDENT.STUDENT_FILL_OUT_THE_FEEDBACK_FORM_FUNCTION(CHOICE))//...........The feedback was already submitted...
                {
                    CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                    {
                        if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                        {
                            goto Student_Main_Menu;
                        }
                        else////////......... User Selected: Exit .........////////
                        {
                            EXIT();
                        }
                    }
                }
                else
                {
                    CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                    {
                        if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                        {
                            goto Student_Main_Menu;
                        }
                        else////////......... User Selected: Exit .........////////
                        {
                            EXIT();
                        }
                    }
                }

            }
            if (CHOICE == 3)//... User Selected: View Your Submitted Feedback  ..///
            {
                if (!STUDENT.PRINT_SUBMITTED_FEEDBACK_FORM())//...........The feedback wasn't submitted yet...
                {
                    CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                    {
                        if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                        {
                            goto Student_Main_Menu;
                        }
                        else////////......... User Selected: Exit .........////////
                        {
                            EXIT();
                        }
                    }
                }
                else
                {
                    CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                    {
                        if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                        {
                            goto Student_Main_Menu;
                        }
                        else////////......... User Selected: Exit .........////////
                        {
                            EXIT();
                        }
                    }
                }
            }
            if (CHOICE == 4)/////..... User Selected: Change Your Password  ...../////
            {
                STUDENT.CHANGE_PASSWORD();
                CHOICE = MAIN_MENU_OR_EXIT(CHOICE);
                {
                    if (CHOICE == 1)/////..... User Selected: Return to Main Menu ...../////
                    {
                        goto Student_Main_Menu;
                    }
                    else////////......... User Selected: Exit .........////////
                    {
                        CHOICE = 0;
                        EXIT();
                    }
                }
            }
            if (CHOICE == 5)/////..... User Selected: Log Out ...../////
            {
                CLEAR_SCREEN();
                TITLE();
                goto LOGIN_SCREEN;
            }
            if (CHOICE == 6)////////......... User Selected: Exit .........////////
            {
                EXIT();
            }
        }
        else
        {
            goto LOGIN_SCREEN; //......... Incase the Password wasn't correct, we move back to LOGIN screen....//
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //system("pause");

    return 0;
}