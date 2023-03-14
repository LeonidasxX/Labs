-- 1

create table salary_raise(ins_id int,raise_date date,raise_amt float);

DECLARE
   dept instructor.dept_name%TYPE;
   CURSOR c(dept instructor.dept_name%TYPE) is select * from instructor where dept_name = dept; 
BEGIN
    dept := '&d';
    for i in c(dept)
    LOOP
        insert into salary_raise values(i.id,current_date, i.salary*0.05);
        update instructor set salary = 1.05*salary where id=i.id; 
    END LOOP;
    IF SQL%FOUND THEN DBMS_OUTPUT.PUT_LINE ('Update succeeded for instructor');
    ELSE DBMS_OUTPUT.PUT_LINE ('No change'); 
    END IF;
END;
/

--2
DECLARE
	cursor c is select * from student order by tot_cred;
	s student%rowtype;
BEGIN
	dbms_output.put_line(rpad('ID', 6) || rpad('Name', 10) || rpad('Department Name', 20) || rpad('Total Credits', 15));
	open c;
		loop
		  fetch c into s;
		  exit when c%rowcount > 10 or c%notfound;
		  dbms_output.put_line(rpad(to_char(stud.id), 6) || rpad(to_char(stud.name), 10) || rpad(to_char(stud.dept_name), 20) || rpad(to_char(stud.tot_cred), 15));
		end loop;

END;
/

--4
declare 
    cursor c is select * from takes natural join student;

begin 
    for stud in c
    loop
        if stud.course_id='CS-101' and stud.tot_cred<30 then
            delete from takes where id=stud.id;
        end if;
    end loop;

end;
/

--3
DECLARE
    cursor c is with stud as (select * from (student natural join takes natural join section)),ins as (select * from (instructor natural join teaches natural join section))
                select course_id,title,ins.dept_name,credits,ins.name,ins.building,ins.room_number,ins.time_slot_id,count(*) as no_of_students from stud inner join  ins using(course_id,sec_id,semester,year) natural join course
                group by (course_id,title,ins.dept_name,credits,ins.name,ins.building,ins.room_number,ins.time_slot_id);
    sc student%rowtype;
BEGIN
    for temp in c
        loop
            dbms_output.put_line(rpad(to_char(stud.id), 6) || rpad(to_char(stud.name), 10) || rpad(to_char(stud.dept_name), 20) || rpad(to_char(stud.tot_cred), 15));
            dbms_output.put_line('Course ID : '|| temp.course_id);
            dbms_output.put_line('Title : '|| temp.title);
            dbms_output.put_line('Department : '|| temp.dept_name);
            dbms_output.put_line('Credits : '|| temp.credits);
            dbms_output.put_line('Instructor Name : '|| temp.name);
            dbms_output.put_line('Building : '|| temp.building);
            dbms_output.put_line('Room Number : '|| temp.room_number);
            dbms_output.put_line('Time Slot ID : '|| temp.time_slot_id);
            dbms_output.put_line('Total Students : '|| temp.no_of_students);
            dbms_output.put_line('---------------------------');
            dbms_output.put_line('---------------------------');
        end loop;
END;
/
DECLARE
    cursor c is with stud as (select * from (student natural join takes natural join section)),ins as (select * from (instructor natural join teaches natural join section))
                select course_id,title,ins.dept_name,credits,ins.name,ins.building,ins.room_number,ins.time_slot_id,count(*) as no_of_students from stud inner join  ins using(course_id,sec_id,semester,year) natural join course
                group by (course_id,title,ins.dept_name,credits,ins.name,ins.building,ins.room_number,ins.time_slot_id);
    sc student%rowtype;
BEGIN
    for temp in c
        loop
            dbms_output.put_line('Course ID : '|| temp.course_id);
            dbms_output.put_line('Title : '|| temp.title);
            dbms_output.put_line('Department : '|| temp.dept_name);
            dbms_output.put_line('Credits : '|| temp.credits);
            dbms_output.put_line('Instructor Name : '|| temp.name);
            dbms_output.put_line('Building : '|| temp.building);
            dbms_output.put_line('Room Number : '|| temp.room_number);
            dbms_output.put_line('Time Slot ID : '|| temp.time_slot_id);
            dbms_output.put_line('Total Students : '|| temp.no_of_students);
            dbms_output.put_line('---------------------------');
            dbms_output.put_line('---------------------------');
        end loop;
END;
/

-- 6
DECLARE
    dept teaches.course_id%TYPE;
    cursor c(cid teaches.course_id%TYPE) is select * from instructor natural join teaches where course_id=cid;
begin
    for i in c('CS-101')
loop
    dbms_output.put_line('Instructor ID:'||i.id);
    dbms_output.put_line('Instructor Name:'||i.name);
    dbms_output.put_line('---------------------------');
end loop;
end;
/

--8
DECLARE
mon department.budget%TYPE;
bud department.budget%TYPE;
BEGIN
    Savepoint no_raise;
    update instructor set salary = 1.2*salary where dept_name='Biology';
    select sum(salary) into mon from instructor where dept_name='Biology';
    select budget into bud from department where dept_name='Biology';
    if(mon > bud) then
        Rollback to Savepoint no_raise;
    end if;
    commit;
END;
/


--7

DECLARE
    cursor c1(a_id advisor.i_id%type,c_id takes.course_id%type) is
    select * from ((student s natural join takes t) inner join advisor a
    on (id=a.s_id)) where course_id = c_id and a_id=i_id;
    cursor c2 is select * from (instructor natural join teaches);
BEGIN
    for ins_info in c2
        loop
            for info in c1(ins_info.id,ins_info.course_id)
                loop
                    dbms_output.put_line(info.name);
                end loop;
        end loop;
END;
/
