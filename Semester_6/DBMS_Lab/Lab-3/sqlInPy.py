"""
    Assignment -3
    Atishay Jain
    20CS30008
"""

import mysql.connector
from prettytable import PrettyTable

cnc = mysql.connector.connect(
    host="10.5.18.71",
    database="20CS30008",
    user="20CS30008",
    password="20CS30008"
)
print("Connected to the server!\n")
cursor = cnc.cursor()

# Creating an array for all the queries
queries = []
queries.append('''select `Physician`.`Name`
    from `Physician`, `Trained_In`, `Procedure`
    where `Physician`.`EmployeeID` = `Trained_In`.`Physician`
    and `Trained_In`.`Treatment` = `Procedure`.`Code`
    and `Procedure`.`Name` = "bypass surgery";''')
queries.append('''select `Physician`.`Name`
    from `Physician`, `Trained_In`, `Procedure`, `Department`,`Affiliated_With`
    where `Physician`.`EmployeeID` = `Affiliated_With`.`Physician`
    and `Affiliated_With`.`Department` = `Department`.`DepartmentID`
    and `Department`.`Name` = "cardiology"
    and `Physician`.`EmployeeID` = `Trained_In`.`Physician`
    and `Trained_In`.`Treatment` = `Procedure`.`Code`
    and `Procedure`.`Name` = "bypass surgery";''')
queries.append('''select `Nurse`.`Name` from `Nurse`, `On_Call`, `Block`, `Room`
    where `Nurse`.`EmployeeID` = `On_Call`.`Nurse`
    and `On_Call`.`BlockFloor` = `Block`.`Floor`
    and `On_Call`.`BlockCode` = `Block`.`Code`
    and `Block`.`Floor` = `Room`.`BlockFloor`
    and `Block`.`Code` = `Room`.`BlockCode`
    and `Room`.`Number` = 123;''')
queries.append('''select `Patient`.`Name`, `Patient`.`Address` from `Patient`, `Prescribe`, `Medication`
    where `Patient`.`SSN` = `Prescribe`.`Patient`
    and `Prescribe`.`Medication` = `Medication`.`Code`
    and `Medication`.`Name` = "remdesivir";''')
queries.append('''select `Patient`.`Name`, `Patient`.`InsuranceID` from `Patient`, `Stay`, `Room`
    where `Patient`.`SSN` = `Stay`.`Patient`
    and `Stay`.`Room` = `Room`.`Number`
    and TIMESTAMPDIFF(DAY,`Stay`.`Start`,`Stay`.`End`)>15;''')
queries.append('''select `Nurse`.`Name` from `Nurse`, `Undergoes`, `Procedure`
    where `Nurse`.`EmployeeID` = `Undergoes`.`AssistingNurse`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Procedure`.`Name` = "bypass surgery";''')
queries.append('''select `Nurse`.`Name` as `Nurse Name`, `Nurse`.`Position` as `Nurse Position`, `Physician`.`Name` as `Physician Name` from `Nurse`, `Undergoes`, `Procedure`, `Physician`
    where `Nurse`.`EmployeeID` = `Undergoes`.`AssistingNurse`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Procedure`.`Name` = "bypass surgery"
    and `Undergoes`.`Physician` = `Physician`.`EmployeeID`;''')
queries.append('''select `Physician`.`Name` from `Physician`, `Undergoes`
    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
    and `Undergoes`.`Procedure` not in 
    (select `Trained_In`.`Treatment` from `Trained_In`
    where `Trained_In`.`Physician` = `Physician`.`EmployeeID`);''')
queries.append('''select `Physician`.`Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`
    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Trained_In`.`Treatment`= `Procedure`.`Code`
    and `Trained_In`.`Physician` = `Physician`.`EmployeeID`
    and `Undergoes`.`Date` > `Trained_In`.`CertificationExpires`;''')
queries.append('''select `Physician`.`Name` as `Physician Name`, `Procedure`.`Name` as `Procedure Name`, `Undergoes`.`Date`, `Patient`.`Name` as `Patient Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`,`Patient`
    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Trained_In`.`Treatment`= `Procedure`.`Code`
    and `Trained_In`.`Physician` = `Physician`.`EmployeeID`
    and `Undergoes`.`Date` > `Trained_In`.`CertificationExpires`
    and `Undergoes`.`Patient` = `Patient`.`SSN`;''')
queries.append('''select `Patient`.`Name` as `Patient Name`,`PCP`.`Name`as `Physician Name`
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
    );''')
queries.append('''select `Name` as `Medicine Name`,`Brand` as `Medicine Brand`
    from
    (
        select `Medication`.`Name`,`Medication`.`Brand`,count(*) as `count`
        from `Prescribe`,`Medication`
        where `Prescribe`.`Medication` = `Medication`.`Code`
        group by `Medication`
        order by `count` desc
        limit 1
    ) as `sub`;''')


print("Select one of the following:")
print("1.Names of all physicians who are trained in procedure name \"bypass surgery\"")
print("2.Names of all physicians affiliated with the department name \"cardiology\" and trained in \"bypass surgery\"")
print("3.Names of all the nurses who have ever been on call for room 123")
print("4.Names and addresses of all patients who were prescribed the medication named  \"remdesivir\"")
print("5.Name and insurance id of all patients who stayed in the \"icu\" room type for more than 15 days")
print("6.Names of all nurses who assisted in the procedure name \"bypass surgery\"")
print("7.Name and position of all nurses who assisted in the procedure name \"bypass surgery\" along with the names of and the accompanying physicians")
print("8.Obtain the names of all physicians who have performed a medical procedure they have never been trained to perform")
print("9.Names of all physicians who have performed a medical procedure that they are trained to perform, but such that the procedure was done at a date (Undergoes.Date) after the physician's certification expired (Trained_In.CertificationExpires)")
print("10.Same as the previous query, but include the following information in the results: Physician name, name of procedure, date when the procedure was carried out, name of the patient the procedure was carried out on")
print("11.Names of all patients (also include, for each patient, the name of the patient's physician), such that all the following are true:\n   •The patient has been prescribed some medication by his/her physician\n   •The patient has undergone a procedure with a cost larger that 5000\n   •The patient has had at least two appointment where the physician was affiliated with the cardiology department\n   •The patient's physician is not the head of any department")
print("12.Name and brand of the medication which has been prescribed to the highest number of patients")
print("13.Names of all physicians who are trained in procedure name <user input>")
print("0.Exit")

# Executing the command in loop
while 1:
    q = input("Select One: ")
    try:
        q = int(q)
    except ValueError:
        print("Invalid input!")
        continue
    if q == 13:
        s = input("Enter Procedure: ")
        cursor.execute("select `Physician`.`Name` from `Physician`, `Trained_In`, `Procedure` where `Physician`.`EmployeeID` = `Trained_In`.`Physician` and `Trained_In`.`Treatment` = `Procedure`.`Code` and `Procedure`.`Name` = \"" + s + "\";")
    elif q == 0:
        break
    elif q > 0 and q < 13:
        cursor.execute(queries[q-1])
    else:
        print("Invalid Input!")
        continue
    t = PrettyTable()
    t.field_names = [column[0] for column in cursor.description]
    rows = cursor.fetchall()
    t.add_rows([entry for entry in rows])
    print(t)

cursor.close()
print("\nConnection Closed!")
# Closing the connection
cnc.close()
