/* 
    Assignment -3
    Atishay Jain
    20CS30008
*/

// compile with: gcc sqlInC.c `mysql_config --cflags --libs`

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void finishWithError(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void prettyPrint(MYSQL_RES *result)
{
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    MYSQL_FIELD *field;

    // Get the maximum length of each field
    int max_lengths[num_fields];
    field = mysql_fetch_fields(result);
    for (int i = 0; i < num_fields; i++)
        max_lengths[i] = strlen(field[i].name);

    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            max_lengths[i] = max_lengths[i] < 4 ? 4 : max_lengths[i];
            if (row[i])
                max_lengths[i] = max_lengths[i] < strlen(row[i]) ? strlen(row[i]) : max_lengths[i];
        }
    }

    // Print the separator
    printf("+");
    for (int i = 0; i < num_fields; i++)
    {
        for (int j = 0; j <= max_lengths[i] + 1; j++)
            printf("-");
        printf("+");
    }

    // Print the header
    printf("\n|");
    for (int i = 0; i < num_fields; i++)
        printf(" %-*s |", max_lengths[i], field[i].name);
    printf("\n");

    // Print the separator
    printf("+");
    for (int i = 0; i < num_fields; i++)
    {
        for (int j = 0; j <= max_lengths[i] + 1; j++)
            printf("-");
        printf("+");
    }
    printf("\n");

    // Print the rows
    mysql_data_seek(result, 0);
    while ((row = mysql_fetch_row(result)))
    {
        printf("|");
        for (int i = 0; i < num_fields; i++)
            printf(" %-*s |", max_lengths[i], row[i] ? row[i] : "NULL");
        printf("\n");
    }

    // Print the separator
    printf("+");
    for (int i = 0; i < num_fields; i++)
    {
        for (int j = 0; j < max_lengths[i] + 2; j++)
            printf("-");
        printf("+");
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    MYSQL *con = mysql_init(NULL);

    if (!con)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (!mysql_real_connect(con, "10.5.18.71", "20CS30008", "20CS30008", "20CS30008", 0, NULL, 0))
        finishWithError(con);
    else
        printf("MySQL Database connected...\n");

    const char *queries[] = {
        "select `Physician`.`Name`"
        "from `Physician`, `Trained_In`, `Procedure`"
        "where `Physician`.`EmployeeID` = `Trained_In`.`Physician`"
        "and `Trained_In`.`Treatment` = `Procedure`.`Code`"
        "and `Procedure`.`Name` = \"bypass surgery\";",

        "select `Physician`.`Name`"
        "from `Physician`, `Trained_In`, `Procedure`, `Department`,`Affiliated_With`"
        "where `Physician`.`EmployeeID` = `Affiliated_With`.`Physician`"
        "and `Affiliated_With`.`Department` = `Department`.`DepartmentID`"
        "and `Department`.`Name` = \"cardiology\""
        "and `Physician`.`EmployeeID` = `Trained_In`.`Physician`"
        "and `Trained_In`.`Treatment` = `Procedure`.`Code`"
        "and `Procedure`.`Name` = \"bypass surgery\"",

        "select `Nurse`.`Name` from `Nurse`, `On_Call`, `Block`, `Room`"
        "where `Nurse`.`EmployeeID` = `On_Call`.`Nurse`"
        "and `On_Call`.`BlockFloor` = `Block`.`Floor`"
        "and `On_Call`.`BlockCode` = `Block`.`Code`"
        "and `Block`.`Floor` = `Room`.`BlockFloor`"
        "and `Block`.`Code` = `Room`.`BlockCode`"
        "and `Room`.`Number` = 123;",

        "select `Patient`.`Name`, `Patient`.`Address` from `Patient`, `Prescribe`, `Medication`"
        "where `Patient`.`SSN` = `Prescribe`.`Patient`"
        "and `Prescribe`.`Medication` = `Medication`.`Code`"
        "and `Medication`.`Name` = \"remdesivir\";",

        "select `Patient`.`Name`, `Patient`.`InsuranceID` from `Patient`, `Stay`, `Room`"
        "where `Patient`.`SSN` = `Stay`.`Patient`"
        "and `Stay`.`Room` = `Room`.`Number`"
        "and TIMESTAMPDIFF(DAY,`Stay`.`Start`,`Stay`.`End`)>15;",

        "select `Nurse`.`Name` from `Nurse`, `Undergoes`, `Procedure`"
        "where `Nurse`.`EmployeeID` = `Undergoes`.`AssistingNurse`"
        "and `Undergoes`.`Procedure` = `Procedure`.`Code`"
        "and `Procedure`.`Name` = \"bypass surgery\";",

        "select `Nurse`.`Name` as `Nurse Name`, `Nurse`.`Position` as `Nurse Position`, `Physician`.`Name` as `Physician Name`"
        "from `Nurse`, `Undergoes`, `Procedure`, `Physician`"
        "where `Nurse`.`EmployeeID` = `Undergoes`.`AssistingNurse`"
        "and `Undergoes`.`Procedure` = `Procedure`.`Code`"
        "and `Procedure`.`Name` = \"bypass surgery\""
        "and `Undergoes`.`Physician` = `Physician`.`EmployeeID`;",

        "select `Physician`.`Name` from `Physician`, `Undergoes` "
        "where `Physician`.`EmployeeID` = `Undergoes`.`Physician` "
        "and `Undergoes`.`Procedure` not in "
        "(select `Trained_In`.`Treatment` from `Trained_In` "
        "where `Trained_In`.`Physician` = `Physician`.`EmployeeID`);",

        "select `Physician`.`Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`"
        "where `Physician`.`EmployeeID` = `Undergoes`.`Physician`"
        "and `Undergoes`.`Procedure` = `Procedure`.`Code`"
        "and `Trained_In`.`Treatment`= `Procedure`.`Code`"
        "and `Trained_In`.`Physician` = `Physician`.`EmployeeID`"
        "and `Undergoes`.`Date` > `Trained_In`.`CertificationExpires`;",

        "select `Physician`.`Name`, `Procedure`.`Name`, `Undergoes`.`Date`, `Patient`.`Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`,`Patient`"
        "where `Physician`.`EmployeeID` = `Undergoes`.`Physician`"
        "and `Undergoes`.`Procedure` = `Procedure`.`Code`"
        "and `Trained_In`.`Treatment`= `Procedure`.`Code`"
        "and `Trained_In`.`Physician` = `Physician`.`EmployeeID`"
        "and `Undergoes`.`Date` > `Trained_In`.`CertificationExpires`"
        "and `Undergoes`.`Patient` = `Patient`.`SSN`;",

        "select `Patient`.`Name` as `Patient Name`,`PCP`.`Name`as `Physician Name`"
        "from `Patient`, `Physician` as `PCP`, `Prescribe`, `Undergoes`, `Appointment`, `Affiliated_With`, `Department`,`Procedure`"
        "where `Patient`.`PCP` = `PCP`.`EmployeeID`"
        "and `Prescribe`.`Patient` = `Patient`.`SSN`"
        "and `Prescribe`.`Physician` = `PCP`.`EmployeeID`"
        "and `Undergoes`.`Patient` = `Patient`.`SSN`"
        "and `Undergoes`.`Procedure` = `Procedure`.`Code`"
        "and `Procedure`.`Cost` > 5000 "
        "and `Patient`.`SSN` in ("
        " select `SSN` from"
        " ("
        " select `Patient`.`SSN`,count(*)"
        " from `Patient`,`Appointment`,`Physician`,`Affiliated_With`,`Department`"
        " where `Appointment`.`Patient` = `Patient`.`SSN`"
        " and `Appointment`.`Physician` = `Physician`.`EmployeeID`"
        " and `Physician`.`EmployeeID` = `Affiliated_With`.`Physician`"
        " and `Affiliated_With`.`Department` = `Department`.`DepartmentID`"
        " and `Department`.`Name` = \"cardiology\""
        " group by `Patient`"
        " ) as `count>=2`"
        ")"
        "    and `PCP`.`EmployeeID` not in ("
        "    select `Head`"
        "    from `Department`"
        "    group by `Head`"
        ");",

        "select `Name` as `Medicine Name`,`Brand` as `Medicine Brand`"
        "from"
        "      ("
        "      select `Medication`.`Name`,`Medication`.`Brand`,count(*) as `count`"
        "      from `Prescribe`,`Medication`"
        "      where `Prescribe`.`Medication` = `Medication`.`Code`"
        "      group by `Medication`"
        "      order by `count` desc"
        "      limit 1"
        "      ) as `sub`;"};

    MYSQL_RES *result;

    printf("Select one of the following:\n");
    printf("1.Names of all physicians who are trained in procedure name \"bypass surgery\"\n");
    printf("2.Names of all physicians affiliated with the department name \"cardiology\" and trained in \"bypass surgery\"\n");
    printf("3.Names of all the nurses who have ever been on call for room 123\n");
    printf("4.Names and addresses of all patients who were prescribed the medication named  \"remdesivir\"\n");
    printf("5.Name and insurance id of all patients who stayed in the \"icu\" room type for more than 15 days\n");
    printf("6.Names of all nurses who assisted in the procedure name \"bypass surgery\"\n");
    printf("7.Name and position of all nurses who assisted in the procedure name \"bypass surgery\" along with the names of and the accompanying physicians\n");
    printf("8.Obtain the names of all physicians who have performed a medical procedure they have never been trained to perform\n");
    printf("9.Names of all physicians who have performed a medical procedure that they are trained to perform, but such that the procedure was done at a date (Undergoes.Date) after the physician's certification expired (Trained_In.CertificationExpires)\n");
    printf("10.Same as the previous query, but include the following information in the results: Physician name, name of procedure, date when the procedure was carried out, name of the patient the procedure was carried out on\n");
    printf("11.Names of all patients (also include, for each patient, the name of the patient's physician), such that all the following are true:\n   •The patient has been prescribed some medication by his/her physician\n   •The patient has undergone a procedure with a cost larger that 5000\n   •The patient has had at least two appointment where the physician was affiliated with the cardiology department\n   •The patient's physician is not the head of any department\n");
    printf("12.Name and brand of the medication which has been prescribed to the highest number of patients\n");
    printf("13.Names of all physicians who are trained in procedure name <user input>\n");
    printf("0.Exit\n");

    while (1)
    {
        char q[100];
        printf("Enter your choice: ");
        fgets(q, 99, stdin);
        char *end = NULL;
        int qint = strtol(q, &end, 10);
        if (end == q)
            printf("Invalid Input!\n");
        else if (qint == 0)
            break;
        else if (qint == 13)
        {
            char procedure[256], q13[1024];
            printf("Enter procedure: ");
            fgets(procedure, 99, stdin);
            procedure[strlen(procedure) - 1] = '\0';
            sprintf(q13, "select `Physician`.`Name` from `Physician`, `Trained_In`, `Procedure` where `Physician`.`EmployeeID` = `Trained_In`.`Physician` and `Trained_In`.`Treatment` = `Procedure`.`Code` and `Procedure`.`Name` = \"%s\";", procedure);
            if (mysql_query(con, q13))
            {
                fprintf(stderr, "%s\n", mysql_error(con));
                mysql_close(con);
                exit(1);
            }
            result = mysql_store_result(con);
            if (!result)
                finishWithError(con);
            prettyPrint(result);
            mysql_free_result(result);
        }
        else if (qint > 0 && qint < 13)
        {
            if (mysql_query(con, queries[qint - 1]))
            {
                fprintf(stderr, "%s\n", mysql_error(con));
                mysql_close(con);
                exit(1);
            }
            result = mysql_store_result(con);
            if (result == NULL)
                finishWithError(con);
            prettyPrint(result);
            mysql_free_result(result);
        }
        else
            printf("Invalid Input!\n");
    }

    mysql_close(con);
    return 0;
}
