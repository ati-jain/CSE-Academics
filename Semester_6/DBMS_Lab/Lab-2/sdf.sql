--Queries

-- Names of all physicians who are trained in procedure name “bypass surgery” 
select physician.name as "Physician Name" from procedure, physician, trained_in where procedure.name = 'bypass surgery'and trained_in.treatment = procedure.code and trained_in.physician = physician.employeeid;

-- Names of all physicians affiliated with the department name “cardiology” and trained in “bypass surgery”

select physician.name as "Physician Name" from physician, trained_in, affiliated_with, department, procedure where procedure.name = 'bypass surgery' and trained_in.treatment = procedure.code and trained_in.physician = physician.employeeid and physician.employeeid = affiliated_with.physician and affiliated_with.department = department.departmentid and department.name = 'cardiology';

-- Names of all the nurses who have ever been on call for room 123

select nurse.name as "Nurse Name" from nurse, on_call, block, room where on_call.nurse = nurse.employeeid and (on_call.BlockFloor, on_call.BlockCode) = (block.Floor, block.Code) and (block.Floor, block.Code) =(room.BlockFloor, room.BlockCode) and room.number = 123;

-- Names and addresses of all patients who were prescribed the medication named “remdesivir”

select patient.name as "Patient Name", patient.address as "Patient Address" from patient, prescribe, medication where prescribe.patient = patient.ssn and prescribe.medication = medication.code and medication.name = 'remdesivir';

-- Name and insurance id of all patients who stayed in the “icu” room type for more than 15 days

select patient.name as "Patient Name", patient.insuranceid as "Insurance ID" from patient, stay, room where room.type = 'icu' and room.number = stay.room and stay.patient = patient.ssn and stay.end > stay.start + '15 days'::interval;

select patient.name as "Patient Name", patient.insuranceid as "Insurance ID" from patient, stay, room where room.type = 'icu' and room.number = stay.room and stay.patient = patient.ssn and stay.end - stay.start > '15 days'::interval;

-- Names of all nurses who assisted in the procedure name “bypass surgery"

select nurse.name as "Nurse Name" from nurse, undergoes, procedure where procedure.name = 'bypass surgery' and undergoes.procedure = procedure.code and undergoes.assistingnurse = nurse.employeeid;

-- Name and position of all nurses who assisted in the procedure name “bypass surgery” along with the names of and the accompanying physicians 

select physician.name as "Physician Name", physician.position as "Physician Position", nurse.name as "Assisting Nurse Name", nurse.position as "Nurse Position" from nurse, undergoes, procedure, physician where procedure.name = 'bypass surgery' and undergoes.procedure = procedure.code and undergoes.assistingnurse = nurse.employeeid and undergoes.physician = physician.employeeid;

-- Obtain the names of all physicians who have performed a medical procedure they have never been trained to perform

select physician.name as "Physician Name" from physician, undergoes where undergoes.physician = physician.employeeid and undergoes.procedure not in (select trained_in.treatment from trained_in where trained_in.physician = physician.employeeid);

-- Names of all physicians who have performed a medical procedure that they are trained to perform, but such that the procedure was done at a date (Undergoes.Date) after the physician's certification expired (Trained_In.CertificationExpires)

select physician.name as "Physician Name" from physician, undergoes, trained_in where undergoes.physician = physician.employeeid and undergoes.procedure = trained_in.treatment and trained_in.physician = physician.employeeid and undergoes.date > trained_in.certificationexpires;

-- Same as the previous query, but include the following information in the results: Physician name, name of procedure, date when the procedure was carried out, name of the patient the procedure was carried out on

select physician.name as "Physician Name", procedure.name as "Name of Procedure", undergoes.date as "Date", patient.name as "Patient name" from physician, undergoes, trained_in, procedure, patient where undergoes.physician = physician.employeeid and undergoes.procedure = trained_in.treatment and trained_in.physician = physician.employeeid and undergoes.date > trained_in.certificationexpires and undergoes.procedure = procedure.code and undergoes.patient = patient.ssn;

-- Names of all patients (also include, for each patient, the name of the patient's physician), such that all the following are true:
-- • The patient has been prescribed some medication by his/her physician
-- • The patient has undergone a procedure with a cost larger that 5000
-- • The patient has had at least two appointment where the physician was affiliated with the cardiology department
-- • The patient's physician is not the head of any department

select patient.name as "Patient Name", physician.name as "Patient's Physician" from patient, physician, prescribe, undergoes, procedure, appointment, affiliated_with, department where prescribe.patient = patient.ssn and undergoes.patient = patient.ssn and undergoes.procedure = procedure.code and procedure.cost > 5000 and appointment.patient = patient.ssn and appointment.physician = physician.employeeid and affiliated_with.physician = physician.employeeid and affiliated_with.department = department.departmentid and department.name='cardiology' and physician.employeeid not in (select physician.employeeid from physician, department where physician.employeeid = department.head) group by patient.name, physician.name having count(appointment.appointmentid) >= 2;

--Name and brand of the medication which has been prescribed to the highest number of patients

select medication.name as "Medication Name", medication.brand as "Brand" from medication, prescribe where prescribe.medication = medication.code group by medication.name, medication.brand order by count(prescribe.medication) desc limit 1;