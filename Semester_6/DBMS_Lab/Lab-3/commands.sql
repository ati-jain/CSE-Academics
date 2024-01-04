 CREATE TABLE `Physician`(
    `EmployeeID` INTEGER NOT NULL PRIMARY KEY,
    `Name` TEXT NOT NULL,
    `Position` TEXT NOT NULL,
    `SSN` INTEGER NOT NULL
    );
    CREATE TABLE `Patient`(
    `SSN` INTEGER NOT NULL PRIMARY KEY,
    `Name` TEXT NOT NULL,
    `Address` TEXT NOT NULL,
    `Phone` TEXT NOT NULL,
    `InsuranceID` INTEGER NOT NULL,
    `PCP` INTEGER NOT NULL references `Physician`(`EmployeeID`)
    );
    CREATE TABLE `Nurse`(
    `EmployeeID` INTEGER NOT NULL PRIMARY KEY,
    `Name` TEXT NOT NULL,
    `Position` TEXT NOT NULL,
    `Registered` boolean NOT NULL,
    `SSN` INTEGER NOT NULL
    );
    CREATE TABLE `Appointment`(
    `AppointmentID` INTEGER NOT NULL PRIMARY KEY,
    `Patient` INTEGER  NOT NULL references `Patient`(`SSN`),
    `PrepNurse` INTEGER references `Nurse`(`EmployeeID`),
    `Physician` INTEGER NOT NULL references `Physician`(`EmployeeID`),
    `Start` DATETIME NOT NULL,
    `End` DATETIME NOT NULL,
    `ExaminationRoom` TEXT NOT NULL
    );
    
    CREATE TABLE `Medication`(
    `Code` INTEGER NOT NULL PRIMARY KEY,
    `Name` TEXT NOT NULL,
    `Brand` TEXT NOT NULL,
    `Description` TEXT NOT NULL
    );

    CREATE TABLE `Prescribe`(
    `Physician` INTEGER NOT NULL references `Physician`(`EmployeeID`),
    `Patient` INTEGER NOT NULL references `Patient`(`SSN`),
    `Medication` INTEGER NOT NULL references `Medication`(`Code`),
    `Date` DATETIME NOT NULL,
    `Appointment` INTEGER references `Appointment`(`AppointmentID`),
    `Dose` TEXT NOT NULL,
    PRIMARY KEY(`Physician`, `Patient`, `Medication`, `Date`)
    );

    CREATE TABLE `Department`(
    `DepartmentID` INTEGER NOT NULL PRIMARY KEY,
    `Name` TEXT NOT NULL,
    `Head` INTEGER NOT NULL references `Physician`(`EmployeeID`)
    );

    CREATE TABLE `Affiliated_With`(
    `Physician` INTEGER NOT NULL references `Physician`(`EmployeeID`),
    `Department` INTEGER NOT NULL references `Department`(`DepartmentID`),
    `PrimaryAffiliation` boolean NOT NULL,
    PRIMARY KEY(`Physician`, `Department`)
    );
    
    CREATE TABLE `Block`(
    `Floor` INTEGER NOT NULL,
    `Code` INTEGER NOT NULL,
    PRIMARY KEY (`Floor`, `Code`)
    );
    
    CREATE TABLE `Room`(
    `Number` INTEGER NOT NULL PRIMARY KEY,
    `Type` TEXT NOT NULL,
    `BlockFloor` INTEGER NOT NULL,
    `BlockCode` INTEGER NOT NULL,
    `Unavailable` boolean NOT NULL,
    Foreign KEY(`BlockFloor`, `BlockCode`) references `Block`(`Floor`, `Code`)
    );
    
    CREATE TABLE `Stay`(
    `StayID` INTEGER NOT NULL PRIMARY KEY,
    `Patient` INTEGER NOT NULL references `Patient`(`SSN`),
    `Room` INTEGER NOT NULL references `Room`(`Number`),
    `Start` DATETIME NOT NULL,
    `End` DATETIME NOT NULL
    );
    
    CREATE TABLE `On_Call`(
    `Nurse` INTEGER NOT NULL references `Nurse`(`EmployeeID`),
    `BlockFloor` INTEGER NOT NULL,
    `BlockCode` INTEGER NOT NULL,
    `Start` DATETIME NOT NULL,
    `End` DATETIME NOT NULL,
    PRIMARY KEY(`Nurse`, `BlockFloor`, `BlockCode`, `Start`, `End`),
    Foreign KEY(`BlockFloor`, `BlockCode`) references `Block`(`Floor`, `Code`)
    );
    
    CREATE TABLE `Procedure`(
    `Code` INTEGER NOT NULL PRIMARY KEY,
    `Name` TEXT NOT NULL,
    `Cost` INTEGER NOT NULL
    );

    CREATE TABLE `Trained_In`(
    `Physician` INTEGER NOT NULL references `Physician`(`EmployeeID`),
    `Treatment` INTEGER NOT NULL references `Procedure`(`Code`),
    `CertificationDate` DATETIME NOT NULL,
    `CertificationExpires` DATETIME NOT NULL,
    PRIMARY KEY(`Physician`, `Treatment`)
    );

    CREATE TABLE `Undergoes`(
    `Patient` INTEGER NOT NULL references `Patient`(`SSN`),
    `Procedure` INTEGER NOT NULL references `Procedure`(`Code`),
    `Stay` INTEGER NOT NULL references `Stay`(`StayID`),
    `Date` DATETIME NOT NULL,
    `Physician` INTEGER NOT NULL references `Physician`(`EmployeeID`),
    `AssistingNurse` INTEGER references `Nurse`(`EmployeeID`),
    PRIMARY KEY(`Patient`, `Procedure`, `Stay`, `Date`)
    );

    -- populate tables

    INSERT INTO `Physician` (`EmployeeID`, `Name`, `Position`, `SSN`) VALUES
    (1, 'Dr.Cardio', 'HOD', 1001),
    (2, 'Dr.Neuron', 'HOD', 1002),
    (3, 'Dr.Average', 'General Physician', 1003),
    (4, 'Dr.Afilia', 'General Physician', 1004),
    (5, 'Dr.Surgeon', 'HOD', 1005);

    INSERT INTO `Department` (`DepartmentID`, `Name`, `Head`) VALUES 
    (1, 'cardiology',1),
    (2, 'neurology', 2),
    (3, 'surgery', 5);
    
    INSERT INTO `Appointment`(`AppointmentID`, `Patient`, `PrepNurse`, `Physician`, `Start`, `End`, `ExaminationRoom`) VALUES 
    (1, 1, 1, 1, '2020-04-01 6:00:00', '2020-04-01 11:00:00', 'A-121'),
    (2, 2, 2, 2, '2020-03-07 6:00:00', '2020-03-07 11:00:00', 'A-122'),
    (3, 3, 3, 3, '2020-04-03 6:00:00', '2020-04-03 11:00:00', 'A-123'),
    (4, 4, 3, 1, '2020-04-05 6:00:00', '2020-04-05 11:00:00', 'A-125'),
    (5, 4, 3, 4, '2020-04-03 6:00:00', '2020-04-03 11:00:00', 'A-125');
    
    INSERT INTO `Affiliated_with` (`Physician`, `Department`, `PrimaryAffiliation`) VALUES 
    (1, 1, TRUE),
    (2, 2, FALSE),
    (3, 3, FALSE),
    (4, 1,TRUE),
    (4, 2,FALSE),
    (4, 3,FALSE),
    (5, 3,TRUE)
    ;
    
    INSERT INTO `Trained_In` (`Physician`, `Treatment`, `CertificationDate`, `CertificationExpires`) VALUES 
    (1, 1, '2020-04-01', '2022-04-01'),
    (2, 2, '2020-03-07', '2024-03-07'),
    (3, 3, '2020-04-03', '2024-04-03');
    
    INSERT INTO `Procedure` (`Code`, `Name`, `Cost`) VALUES 
    (1, 'bypass surgery', 60000),
    (2, 'kidney transplant', 2000),
    (3, 'eye cataract', 55000);
    
    INSERT INTO `Undergoes` (`Patient`, `Procedure`, `Stay`, `Date`, `Physician`, `AssistingNurse`) VALUES 
    (1, 1, 1, '2023-01-01 3:30:00', 1, 1), 
    (1, 2, 1, '2023-02-01 3:30:00', 1, 1),
    (1, 3, 1, '2023-03-01 3:30:00', 1, 1),
    (2, 2, 2, '2023-01-07 3:30:00', 2, 2), 
    (3, 3, 3, '2023-01-03 3:30:00', 3, 3),
    (4,3,3, '2023-05-03 3:30:00',4, 3);
    
    
    INSERT INTO `Patient` (`SSN`, `Name`, `Address`, `Phone`, `InsuranceID`, `PCP`) VALUES
    (1, 'P.Abraham', '2631/A,ABC road,Kolkata', '+919876545678', 1, 1),
    (2, 'P.Bill', 'A-23 B-block, Kolkata', '+919789547586', 2, 2),
    (3, 'P.Cassie', '23/A, JC BOSE road,Kolkata', '+919843114565', 3, 3),
    (4, 'P.Drake', '23/A, KC BOSE road,Kolkata', '+919843114565', 4, 4),
    (5, 'P.Emile', '23/A, MC BOSE road,Kolkata', '+919843114565', 5, 5);
    
    INSERT INTO `Prescribe` (`Physician`, `Patient`, `Medication`, `Date`, `Appointment`, `Dose`) VALUES 
    (1, 1, 1, '2023-01-02 2:30:00', 1, '2 times a day'), 
    (2, 1, 1, '2023-02-05 2:30:00', 1, '3 times a day'),
    (2, 2, 2, '2023-01-08 3:30:00', 2, '1 time a day'), 
    (3, 3, 3, '2023-01-05 5:30:00', 3, 'when needed'),
    (4, 4, 1, '2023-01-05 5:30:00', 4, '3 times a day');
    
    INSERT INTO `Medication` (`Code`, `Name`, `Brand`, `Description`) VALUES
    (1, 'remdesivir', 'Rnabaxy', 'two times a day'),
    (2, 'bismuth subsalicylate', 'Pepto-Bismol', 'empty stomach'),
    (3, 'montelukast', 'telekast', 'for stomach pain');

    INSERT INTO `Stay` (`StayID`, `Patient`, `Room`, `Start`, `End`) VALUES 
    (1, 1, 121, '2020-04-01 09:34:21', '2020-04-20 12:30:00'),
    (2, 2, 122, '2020-03-07 09:30:00', '2020-03-07 12:30:00'),
    (3, 3, 123, '2020-04-03 09:20:00', '2020-04-03 12:30:00');
    
    INSERT INTO `Block` (`Floor`, `Code`) VALUES 
    (1, 1),
    (1, 2),
    (1, 3);
    
    INSERT INTO `Room` (`Number`, `Type`, `BlockFloor`, `BlockCode`, `Unavailable`) VALUES 
    (121, 'icu', 1, 1, FALSE),
    (122, 'hdu', 1, 2, FALSE),
    (123, 'general', 1, 3, FALSE);
    
    INSERT INTO `On_Call` (`Nurse`, `BlockFloor`, `BlockCode`, `Start`, `End`) VALUES 
    (1, 1, 1, '2020-04-01 09:34:21', '2020-04-01 12:30:00'),
    (2, 1, 2, '2020-03-07 09:30:00', '2020-03-07 12:30:00'),
    (3, 1, 3, '2020-04-03 09:34:21', '2020-04-03 12:30:00');

    INSERT INTO `Nurse` (`EmployeeID`, `Name`, `Position`, `Registered`, `SSN`) VALUES 
    (1, 'Meena', 'General Nurse', TRUE, 101),
    (2, 'Tina', 'General Nurse', TRUE, 102),
    (3, 'Sheena', 'General Nurse', TRUE, 103);
    
    -- Queries
    
    -- 1.Names of all physicians who are trained in procedure name “bypass surgery” 
    select distinct `Physician`.`Name` from `Physician`, `Trained_In`, `Procedure`
    where `Physician`.`EmployeeID` = `Trained_In`.`Physician`
    and `Trained_In`.`Treatment` = `Procedure`.`Code`
    and `Procedure`.`Name` = "bypass surgery";
    
    -- 2.Names of all physicians affiliated with the department name “cardiology” and trained in “bypass surgery”
    
    select distinct `Physician`.`Name` from `Physician`, `Trained_In`, `Procedure`, `Department`,`Affiliated_with`
    where `Physician`.`EmployeeID` = `Affiliated_with`.`Physician`
    and `Affiliated_with`.`Department` = `Department`.`DepartmentID`
    and `Department`.`Name` = "cardiology"
    and `Physician`.`EmployeeID` = `Trained_In`.`Physician`
    and `Trained_In`.`Treatment` = `Procedure`.`Code`
    and `Procedure`.`Name` = "bypass surgery";
    
    -- 3.Names of all the nurses who have ever been on call for room 123
    
    select distinct `Nurse`.`Name` from `Nurse`, `On_Call`, `Block`, `Room`
    where `Nurse`.`EmployeeID` = `On_Call`.`Nurse`
    and `On_Call`.`BlockFloor` = `Block`.`Floor`
    and `On_Call`.`BlockCode` = `Block`.`Code`
    and `Block`.`Floor` = `Room`.`BlockFloor`
    and `Block`.`Code` = `Room`.`BlockCode`
    and `Room`.`Number` = 123;
    
    -- 4.Names and addresses of all patients who were prescribed the medication named  “remdesivir”
    select distinct `Patient`.`Name`, `Patient`.`Address` from `Patient`, `Prescribe`, `Medication`
    where `Patient`.`SSN` = `Prescribe`.`Patient`
    and `Prescribe`.`Medication` = `Medication`.`Code`
    and `Medication`.`Name` = "remdesivir";

    -- 5.Name and insurance id of all patients who stayed in the “icu” room type for more than 15 days
    
    select distinct`Patient`.`Name`, `Patient`.`InsuranceID` from `Patient`, `Stay`, `Room`
    where `Patient`.`SSN` = `Stay`.`Patient`
    and `Stay`.`Room` = `Room`.`Number`
    and TIMESTAMPDIFF(DAY,`Stay`.`Start`,`Stay`.`End`)>15;
    
    -- 6.Names of all nurses who assisted in the procedure name “bypass surgery"

    select distinct `Nurse`.`Name` from `Nurse`, `Undergoes`, `Procedure`
    where `Nurse`.`EmployeeID` = `Undergoes`.`AssistingNurse`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Procedure`.`Name` = "bypass surgery";


-- 7.Name and position of all nurses who assisted in the procedure name “bypass surgery” along with the names of and the accompanying physicians 
    select distinct `Nurse`.`Name`, `Nurse`.`Position`, `Physician`.`Name` from `Nurse`, `Undergoes`, `Procedure`, `Physician`
    where `Nurse`.`EmployeeID` = `Undergoes`.`AssistingNurse`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Procedure`.`Name` = "bypass surgery"
    and `Undergoes`.`Physician` = `Physician`.`EmployeeID`;

-- 8.Obtain the names of all physicians who have performed a medical procedure they have never been trained to perform

    select distinct `Physician`.`Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`
    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Trained_In`.`Treatment`= `Procedure`.`Code`
    and `Trained_In`.`Physician` != `Physician`.`EmployeeID`;

-- 9.Names of all physicians who have performed a medical procedure that they are trained to perform, but such that the procedure was done at a date (Undergoes.Date) after the physician's certification expired (Trained_In.CertificationExpires)
    
    select distinct `Physician`.`Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`
    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Trained_In`.`Treatment`= `Procedure`.`Code`
    and `Trained_In`.`Physician` = `Physician`.`EmployeeID`
    and `Undergoes`.`Date` > `Trained_In`.`CertificationExpires`;

-- 10.Same as the previous query, but include the following information in the results: Physician name, name of procedure, date when the procedure was carried out, name of the patient the procedure was carried out on

    select distinct `Physician`.`Name`, `Procedure`.`Name`, `Undergoes`.`Date`, `Patient`.`Name` from `Physician`, `Undergoes`, `Procedure`, `Trained_In`,`Patient`
    where `Physician`.`EmployeeID` = `Undergoes`.`Physician`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Trained_In`.`Treatment`= `Procedure`.`Code`
    and `Trained_In`.`Physician` = `Physician`.`EmployeeID`
    and `Undergoes`.`Date` > `Trained_In`.`CertificationExpires`
    and `Undergoes`.`Patient` = `Patient`.`SSN`;

-- 11.Names of all patients (also include, for each patient, the name of the patient's physician), such that all the following are true:
-- •The patient has been prescribed some medication by his/her physician
-- •The patient has undergone a procedure with a cost larger that 5000
-- •The patient has had at least two appointment where the physician was affiliated with the cardiology department
-- •The patient's physician is not the head of any department 

    select distinct `Patient`.`Name` as `Patient Name`,`PCP`.`Name`as `PCP Name`
    from `Patient`, `Physician` as `PCP`, `Prescribe`, `Undergoes`, `Appointment`, `Affiliated_with`, `Department`,`Procedure`
    where `Patient`.`PCP` = `PCP`.`EmployeeID`
    -- •The patient has been prescribed some medication by his/her physician
    and `Prescribe`.`Patient` = `Patient`.`SSN`
    and `Prescribe`.`Physician` = `PCP`.`EmployeeID`
    -- •The patient has undergone a procedure with a cost larger that 5000
    and `Undergoes`.`Patient` = `Patient`.`SSN`
    and `Undergoes`.`Procedure` = `Procedure`.`Code`
    and `Procedure`.`Cost` > 5000
    -- •The patient has had at least two appointment where the physician was affiliated with the cardiology department
    and `Patient`.`SSN` in (
        select `SSN` from
          (
            select `Patient`.`SSN`,count(*)
            from `Patient`,`Appointment`,`Physician`,`Affiliated_with`,`Department`
            where `Appointment`.`Patient` = `Patient`.`SSN`
            and `Appointment`.`Physician` = `Physician`.`EmployeeID`
            and `Physician`.`EmployeeID` = `Affiliated_with`.`Physician`
            and `Affiliated_with`.`Department` = `Department`.`DepartmentID`
            and `Department`.`Name` = "cardiology"
            group by `Patient`
          ) as `count>=2`
    )
    -- •The patient's physician is not the head of any department 
    and `PCP`.`EmployeeID` not in (
        select `Head`
        from `Department`
        group by `Head`
    );

-- 12.Name and brand of the medication which has been prescribed to the highest number of patients
    select `Name`as `Medicine Name`,`Brand` as `Medicine Brand`
    from
    (
        select `Medication`.`Name`,`Medication`.`Brand`,count(*) as `count`
        from `Prescribe`,`Medication`
        where `Prescribe`.`Medication` = `Medication`.`Code`
        group by `Medication`
        order by `count` desc
        limit 1
    ) as `sub`;
