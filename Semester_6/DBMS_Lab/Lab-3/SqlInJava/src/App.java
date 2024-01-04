/* 
    Assignment -3
    Atishay Jain
    20CS30008
*/

import java.sql.*;
import java.util.Scanner;

public class App {

    public static void printResultSet(ResultSet rs) throws SQLException {
        ResultSetMetaData metaData = rs.getMetaData();
        int columns = metaData.getColumnCount();
    
        // Find the maximum length of each column
        int[] widths = new int[columns];
        for (int i = 1; i <= columns; i++) {
            widths[i - 1] = metaData.getColumnLabel(i).length();
            rs.beforeFirst();
            while (rs.next()) {
                int length = rs.getString(i).length();
                if (length > widths[i - 1]) {
                    widths[i - 1] = length;
                }
            }
        }
    
        // Print the header
        System.out.print("+");
        for (int i = 0; i < columns; i++) {
            System.out.print("-".repeat(widths[i] + 2) + "+");
        }
        System.out.println();
        for (int i = 0; i < columns; i++) {
            System.out.printf("| %-" + widths[i] + "s ", metaData.getColumnLabel(i + 1));
        }
        System.out.println("|");
    
        // Print the separator
        System.out.print("+");
        for (int i = 0; i < columns; i++) {
            System.out.print("-".repeat(widths[i] + 2) + "+");
        }
        System.out.println();
    
        // Print the data
        rs.beforeFirst();
        while (rs.next()) {
            for (int i = 0; i < columns; i++) {
                System.out.printf("| %-" + widths[i] + "s ", rs.getString(i + 1));
            }
            System.out.println("|");
        }
    
        // Print the separator
        System.out.print("+");
        for (int i = 0; i < columns; i++) {
            System.out.print("-".repeat(widths[i] + 2) + "+");
        }
        System.out.println();
    }    

    public static void main(String[] args) {
        String[] query = { """
                    select `Physician`.`Name`
                    from `Physician`, `Trained_In`, `Procedure`
                    where `Physician`.`EmployeeID` = `Trained_In`.`Physician`
                    and `Trained_In`.`Treatment` = `Procedure`.`Code`
                    and `Procedure`.`Name` = "bypass surgery";""", """
                    select `Physician`.`Name`
                    from `Physician`, `Trained_In`, `Procedure`, `Department`,`Affiliated_With`
                    where `Physician`.`EmployeeID` = `Affiliated_With`.`Physician`
                    and `Affiliated_With`.`Department` = `Department`.`DepartmentID`
                    and `Department`.`Name` = "cardiology"
                    and `Physician`.`EmployeeID` = `Trained_In`.`Physician`
                    and `Trained_In`.`Treatment` = `Procedure`.`Code`
                    and `Procedure`.`Name` = "bypass surgery";""", """
                    select `Nurse`.`Name` from `Nurse`, `On_Call`, `Block`, `Room`
                    where `Nurse`.`EmployeeID` = `On_Call`.`Nurse`
                    and `On_Call`.`BlockFloor` = `Block`.`Floor`
                    and `On_Call`.`BlockCode` = `Block`.`Code`
                    and `Block`.`Floor` = `Room`.`BlockFloor`
                    and `Block`.`Code` = `Room`.`BlockCode`
                    and `Room`.`Number` = 123;""", """
                    select `Patient`.`Name`, `Patient`.`Address` from `Patient`, `Prescribe`, `Medication`
                    where `Patient`.`SSN` = `Prescribe`.`Patient`
                    and `Prescribe`.`Medication` = `Medication`.`Code`
                    and `Medication`.`Name` = "remdesivir";""", """
                    select `Patient`.`Name`, `Patient`.`InsuranceID` from `Patient`, `Stay`, `Room`
                    where `Patient`.`SSN` = `Stay`.`Patient`
                    and `Stay`.`Room` = `Room`.`Number`
                    and TIMESTAMPDIFF(DAY,`Stay`.`Start`,`Stay`.`End`)>15;""", """
                    select `Nurse`.`Name` from `Nurse`, `Undergoes`, `Procedure`
                    where `Nurse`.`EmployeeID` = `Undergoes`.`AssistingNurse`
                    and `Undergoes`.`Procedure` = `Procedure`.`Code`
                    and `Procedure`.`Name` = "bypass surgery";""",
                """
                    select `Nurse`.`Name` as `Nurse Name`, `Nurse`.`Position` as `Nurse Position`, `Physician`.`Name` as `Physician Name` from `Nurse`, `Undergoes`, `Procedure`, `Physician`
                    where `Nurse`.`EmployeeID` = `Undergoes`.`AssistingNurse`
                    and `Undergoes`.`Procedure` = `Procedure`.`Code`
                    and `Procedure`.`Name` = "bypass surgery"
                    and `Undergoes`.`Physician` = `Physician`.`EmployeeID`;""",
                """
                    select `Physician`.`Name` from `Physician`, `Undergoes`
                    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
                    and `Undergoes`.`Procedure` not in
                    (select `Trained_In`.`Treatment` from `Trained_In`
                    where `Trained_In`.`Physician` = `Physician`.`EmployeeID`);""", """
                    select `Physician`.`Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`
                    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
                    and `Undergoes`.`Procedure` = `Procedure`.`Code`
                    and `Trained_In`.`Treatment`= `Procedure`.`Code`
                    and `Trained_In`.`Physician` = `Physician`.`EmployeeID`
                    and `Undergoes`.`Date` > `Trained_In`.`CertificationExpires`;""",
                """
                    select `Physician`.`Name` as `Physician Name`, `Procedure`.`Name` as `Procedure Name`, `Undergoes`.`Date`, `Patient`.`Name` as `Patient Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`,`Patient`
                    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
                    and `Undergoes`.`Procedure` = `Procedure`.`Code`
                    and `Trained_In`.`Treatment`= `Procedure`.`Code`
                    and `Trained_In`.`Physician` = `Physician`.`EmployeeID`
                    and `Undergoes`.`Date` > `Trained_In`.`CertificationExpires`
                    and `Undergoes`.`Patient` = `Patient`.`SSN`;""",
                """
                    select `Patient`.`Name` as `Patient Name`,`PCP`.`Name`as `Physician Name`
                    from `Patient`, `Physician` as `PCP`, `Prescribe`, `Undergoes`, `Appointment`, `Affiliated_With`, `Department`,`Procedure`
                    where `Patient`.`PCP` = `PCP`.`EmployeeID`
                    and `Prescribe`.`Patient` = `Patient`.`SSN`
                    and `Prescribe`.`Physician` = `PCP`.`EmployeeID`
                    and `Undergoes`.`Patient` = `Patient`.`SSN`
                    and `Undergoes`.`Procedure` = `Procedure`.`Code`
                    and `Procedure`.`Cost` > 5000
                    and `Patient`.`SSN` in (
                        select `SSN` from
                            (
                            select `Patient`.`SSN`,count(*)
                            from `Patient`,`Appointment`,`Physician`,`Affiliated_With`,`Department`
                            where `Appointment`.`Patient` = `Patient`.`SSN`
                            and `Appointment`.`Physician` = `Physician`.`EmployeeID`
                            and `Physician`.`EmployeeID` = `Affiliated_With`.`Physician`
                            and `Affiliated_With`.`Department` = `Department`.`DepartmentID`
                            and `Department`.`Name` = "cardiology"
                            group by `Patient`
                            ) as `count>=2`
                    )
                    and `PCP`.`EmployeeID` not in (
                        select `Head`
                        from `Department`
                        group by `Head`
                    );""",
                """
                    select `Name` as `Medicine Name`,`Brand` as `Medicine Brand`
                    from
                    (
                        select `Medication`.`Name`,`Medication`.`Brand`,count(*) as `count`
                        from `Prescribe`,`Medication`
                        where `Prescribe`.`Medication` = `Medication`.`Code`
                        group by `Medication`
                        order by `count` desc
                        limit 1
                    ) as `sub`;""" };

        // scanner object to take input from user
        Scanner input = new Scanner(System.in);
        Connection con = null;
        Statement stmt = null;
        ResultSet rs;

        try {
            // Connect to MySQL database
            con = DriverManager.getConnection("jdbc:mysql://20CS30008@10.5.18.71/20CS30008", "20CS30008", "20CS30008");
            stmt = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE, ResultSet.CONCUR_UPDATABLE);
            // present query menu to user and execute applicable query
        } catch (SQLException e) {
            System.out.println(e);
            System.exit(0);
        }
        System.out.println("Select one of the following:");
        System.out.println("1.Names of all physicians who are trained in procedure name \"bypass surgery\"");
        System.out.println(
                "2.Names of all physicians affiliated with the department name \"cardiology\" and trained in \"bypass surgery\"");
        System.out.println("3.Names of all the nurses who have ever been on call for room 123");
        System.out.println("4.Names and addresses of all patients who were prescribed the medication named  \"remdesivir\"");
        System.out.println("5.Name and insurance id of all patients who stayed in the \"icu\" room type for more than 15 days");
        System.out.println("6.Names of all nurses who assisted in the procedure name \"bypass surgery\"");
        System.out.println("7.Name and position of all nurses who assisted in the procedure name \"bypass surgery\" along with the names of and the accompanying physicians");
        System.out.println("8.Obtain the names of all physicians who have performed a medical procedure they have never been trained to perform");
        System.out.println("9.Names of all physicians who have performed a medical procedure that they are trained to perform, but such that the procedure was done at a date (Undergoes.Date) after the physician's certification expired (Trained_In.CertificationExpires)");
        System.out.println("10.Same as the previous query, but include the following information in the results: Physician name, name of procedure, date when the procedure was carried out, name of the patient the procedure was carried out on");
        System.out.println("11.Names of all patients (also include, for each patient, the name of the patient's physician), such that all the following are true:\n   •The patient has been prescribed some medication by his/her physician\n   •The patient has undergone a procedure with a cost larger that 5000\n   •The patient has had at least two appointment where the physician was affiliated with the cardiology department\n   •The patient's physician is not the head of any department");
        System.out.println("12.Name and brand of the medication which has been prescribed to the highest number of patients");
        System.out.println("13.Names of all physicians who are trained in procedure name <user input>");
        System.out.println("0.Exit");

        while (true) {
            int ch;
            System.out.print("\nEnter your choice: ");
            try {
                ch = Integer.parseInt(input.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Invalid Input!");
                continue;
            }
            if (ch == 0)
                break;
            else if (ch == 13) {
                System.out.print("\nEnter procedure: ");
                String q13, procedure = input.nextLine();
                q13 = "select `Physician`.`Name` from `Physician`, `Trained_In`, `Procedure` where `Physician`.`EmployeeID` = `Trained_In`.`Physician` and `Trained_In`.`Treatment` = `Procedure`.`Code` and `Procedure`.`Name` = \""
                        + procedure + "\";";
                try {
                    rs = stmt.executeQuery(q13);
                    printResultSet(rs);
                } catch (SQLException e) {
                    System.out.println(e);
                }
            } else if (ch > 0 && ch < 13) {
                try {
                    rs = stmt.executeQuery(query[ch - 1]);
                    printResultSet(rs);
                } catch (SQLException e) {
                    System.out.println(e);
                }
            } else {
                System.out.println("Invalid Input!");
            }
        }
        try {
            // close databse connection
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
        // close scanner
        input.close();
    }
}
