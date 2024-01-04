-- Creating the Tables

create table Physician(
    EmployeeID integer not null primary key,
    Name text not null,
    Position text not null,
    SSN integer not null
);

create table Procedure(
    Code integer not null primary key,
    Name text not null,
    Cost integer not null
);

create table Medication(
    Code integer not null primary key,
    Name text not null,
    Brand text not null,
    Description text not null
);

create table Nurse(
    EmployeeID integer not null primary key,
    Name text not null,
    Position text not null,
    Registered boolean not null,
    SSN integer not null
);

create table Department(
    DepartmentID integer not null primary key,
    Name text not null,
    Head integer not null references Physician(EmployeeID)
);

create table Patient(
    SSN integer not null primary key,
    Name text not null,
    Address text not null,
    Phone text not null,
    InsuranceID integer not null,
    PCP integer not null references Physician(EmployeeID)
);

create table Block(
    Floor integer not null,
    Code integer not null,
    Primary Key (Floor, Code)
);

create table Appointment(
    AppointmentID integer not null primary key,
    Patient integer not null references Patient(SSN),
    PrepNurse integer references Nurse(EmployeeID),
    Physician integer not null references Physician(EmployeeID),
    Start timestamp not null,
    "end" timestamp not null,
    ExaminationRoom text not null
);

create table Room(
    Number integer not null primary key,
    Type text not null,
    BlockFloor integer not null,
    BlockCode integer not null,
    Unavailable boolean not null,
    Foreign Key(BlockFloor, BlockCode) references Block(Floor, Code)
);

create table Stay(
    StayID integer not null primary key,
    Patient integer not null references Patient(SSN),
    Room integer not null references Room(Number),
    Start timestamp not null,
    "end" timestamp not null
);

create table On_Call(
    Nurse integer not null references Nurse(EmployeeID),
    BlockFloor integer not null,
    BlockCode integer not null,
    Start timestamp not null,
    "end" timestamp not null,
    Primary Key(Nurse, BlockFloor, BlockCode, Start, "end"),
    Foreign Key(BlockFloor, BlockCode) references Block(Floor, Code)
);

create table Prescribe(
    Physician integer not null references Physician(EmployeeID),
    Patient integer not null references Patient(SSN),
    Medication integer not null references Medication(Code),
    Date timestamp not null,
    Appointment integer references Appointment(AppointmentID),
    Dose text not null,
    Primary Key(Physician, Patient, Medication, Date)
);

create table Affiliated_with(
    Physician integer not null references Physician(EmployeeID),
    Department integer not null references Department(DepartmentID),
    PrimaryAffiliation boolean not null,
    Primary Key(Physician, Department)
);

create table Trained_In(
    Physician integer not null references Physician(EmployeeID),
    Treatment integer not null references Procedure(Code),
    CertificationDate timestamp not null,
    CertificationExpires timestamp not null,
    Primary Key(Physician, Treatment)
);

create table Undergoes(
    Patient integer not null references Patient(SSN),
    Procedure integer not null references Procedure(Code),
    Stay integer not null references Stay(StayID),
    Date timestamp not null,
    Physician integer not null references Physician(EmployeeID),
    AssistingNurse integer references Nurse(EmployeeID),
    Primary Key(Patient, Procedure, Stay, Date)
);

-- Inserting the values in the tables

insert into Physician values(1, 'Alan Donald', 'Intern', 111111111);
insert into Physician values(2, 'Bruce Reid', 'Attending Physician', 222222222);
insert into Physician values(3, 'Courtney Walsh', 'Surgeon Physician', 333333333);
insert into Physician values(4, 'Malcom Marshall', 'Senior Physician', 444444444);
insert into Physician values(5, 'Dennis Lillee', 'Head Chief of Medicine', 555555555);
insert into Physician values(6, 'Jeff Thomson', 'Surgeon Physician', 666666666);
insert into Physician values(7, 'Richard Hadlee', 'Surgeon Physician', 777777777);
insert into Physician values(8, 'Kapil  Dev', 'Resident', 888888888);
insert into Physician values(9, 'Ishant Sharma', 'Psychiatrist', 999999999);

insert into Department values(1, 'medicine', 4);
insert into Department values(2, 'surgery', 7);
insert into Department values(3, 'psychiatry', 9);
insert into Department values(4, 'cardiology', 8);

insert into Affiliated_With values(1, 1, '1');
insert into Affiliated_With values(2, 1, '1');
insert into Affiliated_With values(3, 1, '0');
insert into Affiliated_With values(3, 2, '1');
insert into Affiliated_With values(4, 1, '1');
insert into Affiliated_With values(5, 1, '1');
insert into Affiliated_With values(6, 2, '1');
insert into Affiliated_With values(7, 1, '0');
insert into Affiliated_With values(7, 2, '1');
insert into Affiliated_With values(8, 1, '1');
insert into Affiliated_With values(9, 3, '1');

insert into Procedure values(1, 'bypass surgery', 1500.0);
insert into Procedure values(2, 'angioplasty', 3750.0);
insert into Procedure values(3, 'arthoscopy', 4500.0);
insert into Procedure values(4, 'carotid endarterectomy', 10000.0);
insert into Procedure values(5, 'cholecystectomy', 4899.0);
insert into Procedure values(6, 'tonsillectomy', 5600.0);
insert into Procedure values(7, 'cataract surgery', 25.0);

insert into Patient values(100000001, 'Dilip Vengsarkar', '42 Foobar Lane', '555-0256', 68476213, 1);
insert into Patient values(100000002, 'Richie Richardson', '37 Infinite Loop', '555-0512', 36546321, 2);
insert into Patient values(100000003, 'Mark Waugh', '101 Parkway Street', '555-1204', 65465421, 2);
insert into Patient values(100000004, 'Ramiz Raza', '1100 Sparks Avenue', '555-2048', 68421879, 3);

insert into Nurse values(101, 'Eknath Solkar', 'Head Nurse', 1, 111111110);
insert into Nurse values(102, 'David Boon', 'Nurse', 1, 222222220);
insert into Nurse values(103, 'Andy Flowers', 'Nurse', 0, 333333330);

insert into Appointment values(13216584, 100000001, 101, 1, '2018-04-24 10:00', '2018-04-24 11:00', 'A');
insert into Appointment values(26548913, 100000002, 101, 2, '2018-04-24 10:00', '2018-04-24 11:00', 'B');
insert into Appointment values(36549879, 100000001, 102, 1, '2018-04-25 10:00', '2018-04-25 11:00', 'A');
insert into Appointment values(46846589, 100000004, 103, 4, '2018-04-25 10:00', '2018-04-25 11:00', 'B');
insert into Appointment values(59871321, 100000004, NULL, 4, '2018-04-26 10:00', '2018-04-26 11:00', 'C');
insert into Appointment values(69879231, 100000003, 103, 2, '2018-04-26 11:00', '2018-04-26 12:00', 'C');
insert into Appointment values(76983231, 100000001, NULL, 3, '2018-04-26 12:00', '2018-04-26 13:00', 'C');
insert into Appointment values(86213939, 100000004, 102, 9, '2018-04-27 10:00', '2018-04-21 11:00', 'A');
insert into Appointment values(93216548, 100000002, 101, 2, '2018-04-27 10:00', '2018-04-27 11:00', 'B');

insert into Medication values(1, 'Paracetamol', 'Z', 'N/A');
insert into Medication values(2, 'Actemra', 'Foolki Labs', 'N/A');
insert into Medication values(3, 'Molnupiravir', 'Bale Laboratories', 'N/A');
insert into Medication values(4, 'Paxlovid', 'Bar Industries', 'N/A');
insert into Medication values(5, 'Remdesivir', 'Donald Pharmaceuticals', 'N/A');

insert into Prescribe values(1, 100000001, 1, '2018-04-24 10:47', 13216584, '5');
insert into Prescribe values(9, 100000004, 2, '2018-04-27 10:53', 86213939, '10');
insert into Prescribe values(9, 100000004, 2, '2018-04-30 16:53', NULL, '5');

insert into Block values(1, 1);
insert into Block values(1, 2);
insert into Block values(1, 3);
insert into Block values(2, 1);
insert into Block values(2, 2);
insert into Block values(2, 3);
insert into Block values(3, 1);
insert into Block values(3, 2);
insert into Block values(3, 3);
insert into Block values(4, 1);
insert into Block values(4, 2);
insert into Block values(4, 3);

insert into Room values(101, 'Single', 1, 1, 0);
insert into Room values(102, 'Single', 1, 1, 0);
insert into Room values(103, 'Single', 1, 1, 0);
insert into Room values(111, 'Single', 1, 2, 0);
insert into Room values(112, 'Single', 1, 2, 1);
insert into Room values(113, 'Single', 1, 2, 0);
insert into Room values(121, 'Single', 1, 3, 0);
insert into Room values(122, 'Single', 1, 3, 0);
insert into Room values(123, 'Single', 1, 3, 0);
insert into Room values(201, 'Single', 2, 1, 1);
insert into Room values(202, 'Single', 2, 1, 0);
insert into Room values(203, 'Single', 2, 1, 0);
insert into Room values(211, 'Single', 2, 2, 0);
insert into Room values(212, 'Single', 2, 2, 0);
insert into Room values(213, 'Single', 2, 2, 1);
insert into Room values(221, 'Single', 2, 3, 0);
insert into Room values(222, 'Single', 2, 3, 0);
insert into Room values(223, 'Single', 2, 3, 0);
insert into Room values(301, 'Single', 3, 1, 0);
insert into Room values(302, 'Single', 3, 1, 1);
insert into Room values(303, 'Single', 3, 1, 0);
insert into Room values(311, 'Single', 3, 2, 0);
insert into Room values(312, 'Single', 3, 2, 0);
insert into Room values(313, 'Single', 3, 2, 0);
insert into Room values(321, 'Single', 3, 3, 1);
insert into Room values(322, 'Single', 3, 3, 0);
insert into Room values(323, 'Single', 3, 3, 0);
insert into Room values(401, 'Single', 4, 1, 0);
insert into Room values(402, 'Single', 4, 1, 1);
insert into Room values(403, 'Single', 4, 1, 0);
insert into Room values(411, 'Single', 4, 2, 0);
insert into Room values(412, 'Single', 4, 2, 0);
insert into Room values(413, 'Single', 4, 2, 0);
insert into Room values(421, 'Single', 4, 3, 1);
insert into Room values(422, 'Single', 4, 3, 0);
insert into Room values(423, 'Single', 4, 3, 0);

insert into On_Call values(101, 1, 1, '2018-11-04 11:00', '2018-11-04 19:00');
insert into On_Call values(101, 1, 2, '2018-11-04 11:00', '2018-11-04 19:00');
insert into On_Call values(102, 1, 3, '2018-11-04 11:00', '2018-11-04 19:00');
insert into On_Call values(103, 1, 1, '2018-11-04 19:00', '2018-11-05 03:00');
insert into On_Call values(103, 1, 2, '2018-11-04 19:00', '2018-11-05 03:00');
insert into On_Call values(103, 1, 3, '2018-11-04 19:00', '2018-11-05 03:00');

insert into Stay values(3215, 100000001, 111, '2018-05-01', '2018-05-04');
insert into Stay values(3216, 100000003, 123, '2018-05-03', '2018-05-14');
insert into Stay values(3217, 100000004, 112, '2018-05-02', '2018-05-03');

insert into Undergoes values(100000001, 6, 3215, '2018-05-02', 3, 101);
insert into Undergoes values(100000001, 2, 3215, '2018-05-03', 7, 101);
insert into Undergoes values(100000004, 1, 3217, '2018-05-07', 3, 102);
insert into Undergoes values(100000004, 5, 3217, '2018-05-09', 6, NULL);
insert into Undergoes values(100000001, 7, 3217, '2018-05-10', 7, 101);
insert into Undergoes values(100000004, 4, 3217, '2018-05-13', 3, 103);

insert into Trained_In values(3, 1, '2018-01-01', '2018-12-31');
insert into Trained_In values(3, 2, '2018-01-01', '2018-12-31');
insert into Trained_In values(3, 5, '2018-01-01', '2018-12-31');
insert into Trained_In values(3, 6, '2018-01-01', '2018-12-31');
insert into Trained_In values(3, 7, '2018-01-01', '2018-12-31');
insert into Trained_In values(6, 2, '2018-01-01', '2018-12-31');
insert into Trained_In values(6, 5, '2017-01-01', '2017-12-31');
insert into Trained_In values(6, 6, '2018-01-01', '2018-12-31');
insert into Trained_In values(7, 1, '2018-01-01', '2018-12-31');
insert into Trained_In values(7, 2, '2018-01-01', '2018-12-31');
insert into Trained_In values(7, 3, '2018-01-01', '2018-12-31');
insert into Trained_In values(7, 4, '2018-01-01', '2018-12-31');
insert into Trained_In values(7, 5, '2018-01-01', '2018-12-31');
insert into Trained_In values(7, 6, '2018-01-01', '2018-12-31');
insert into Trained_In values(7, 7, '2018-01-01', '2018-12-31');

-- Running the Queries

select physician.name as "Physician Name" from physician, procedure, trained_in where trained_in.physician = physician.employeeid and procedure.name = 'bypass surgery'and trained_in.treatment = procedure.code;

select physician.name as "Physician Name" from physician, affiliated_with, department, trained_in, procedure where trained_in.treatment = procedure.code and trained_in.physician = physician.employeeid and physician.employeeid = affiliated_with.physician and affiliated_with.department = department.departmentid and  procedure.name = 'bypass surgery' and department.name = 'cardiology';

select nurse.name as "Nurse Name" from nurse, on_call, block, room where on_call.nurse = nurse.employeeid and (on_call.BlockFloor, on_call.BlockCode) = (block.Floor, block.Code) and (block.Floor, block.Code) = (room.BlockFloor, room.BlockCode) and room.number = 123;

select patient.name as "Patient Name", patient.address as "Patient Address" from patient, prescribe, medication where prescribe.patient = patient.ssn and prescribe.medication = medication.code and medication.name = 'remdesivir';

select patient.name as "Patient Name", patient.insuranceid as "Insurance ID" from patient, stay, room where stay.patient = patient.ssn and room.number = stay.room and room.type = 'icu'  and stay.end > stay.start + '15 days'::interval;

select nurse.name as "Nurse Name" from nurse, undergoes, procedure where undergoes.procedure = procedure.code and undergoes.assistingnurse = nurse.employeeid and procedure.name = 'bypass surgery';

select physician.name as "Physician Name", nurse.name as "Assisting Nurse Name", nurse.position as "Nurse Position" from physician, nurse, undergoes, procedure where undergoes.procedure = procedure.code and undergoes.assistingnurse = nurse.employeeid and undergoes.physician = physician.employeeid and procedure.name = 'bypass surgery';

select physician.name as "Physician Name" from physician, undergoes where undergoes.physician = physician.employeeid and undergoes.procedure not in (select trained_in.treatment from trained_in where trained_in.physician = physician.employeeid);

select physician.name as "Physician Name" from physician, undergoes, trained_in where undergoes.physician = physician.employeeid and trained_in.physician = physician.employeeid and undergoes.procedure = trained_in.treatment and undergoes.date > trained_in.certificationexpires;

select physician.name as "Physician Name", procedure.name as "Name of Procedure", undergoes.date as "Date", patient.name as "Patient name" from physician, undergoes, trained_in, procedure, patient where undergoes.physician = physician.employeeid and undergoes.procedure = trained_in.treatment and trained_in.physician = physician.employeeid and undergoes.procedure = procedure.code and undergoes.patient = patient.ssn and undergoes.date > trained_in.certificationexpires;

select patient.name as "Patient Name", physician.name as "Patient's Physician" from patient, physician, prescribe, undergoes, affiliated_with, department, procedure, appointment where prescribe.patient = patient.ssn and undergoes.procedure = procedure.code and appointment.patient = patient.ssn and affiliated_with.department = department.departmentid and undergoes.patient = patient.ssn and appointment.physician = physician.employeeid and affiliated_with.physician = physician.employeeid and department.name='cardiology' and procedure.cost > 5000 and physician.employeeid not in (select physician.employeeid from physician, department where physician.employeeid = department.head) group by patient.name, physician.name having count(appointment.appointmentid) >= 2;

select medication.name as "Medication Name", medication.brand as "Brand" from medication, prescribe where prescribe.medication = medication.code group by medication.name, medication.brand order by count(prescribe.medication) desc fetch first 1 rows only;

-- Delete all tables(in required order)

drop table trained_in;
drop table Undergoes;
drop table stay;
drop table on_call;
drop table room;
drop table block;
drop table prescribe;
drop table medication;
drop table appointment;
drop table nurse;
drop table patient;
drop table procedure;
drop table affiliated_with;
drop table department;
drop table physician;

-- Delete all entries from all tables

delete from trained_in;
delete from Undergoes;
delete from stay;
delete from on_call;
delete from room;
delete from block;
delete from prescribe;
delete from medication;
delete from appointment;
delete from nurse;
delete from patient;
delete from procedure;
delete from affiliated_with;
delete from department;
delete from physician;