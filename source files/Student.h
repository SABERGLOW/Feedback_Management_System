#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Admin.h"

class STUDENT : public ADMIN
{
public:
    string STUDENT_PASSWORD;


    STUDENT(); //// Default Constructor ////

    //////////////////////////////////////////////////  LOGIN FUNCTION [OVERLOADED]  /////////////////////////////////////////////////////
    bool LOGIN_VALIDATION_FUNCTION();

    //////////////////////////////////////////////////  STUDENT MAIN MENU  /////////////////////////////////////////////////////
    int STUDENT_MAIN_MENU_FUNCTION(int choice);

    ////////////////////////////////////////    2. FILL_OUT THE FEEDBACK FORM        ///////////////////////////////////////////
    bool STUDENT_FILL_OUT_THE_FEEDBACK_FORM_FUNCTION(int choice);

    ///////////////////////////////////////    3. VIEW YOUR SUBMITTED FEEDBACK [OVERLOADED]        ///////////////////////////////////////////
    bool PRINT_SUBMITTED_FEEDBACK_FORM();

    ///////////////////////////////////////      4. CHANGE YOUR PASSWORD  [OVERLOADED]       ///////////////////////////////////////////
    void CHANGE_PASSWORD();
};
#endif /* STUDENT_H */