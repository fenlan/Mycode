USE fenlan;

CREATE TABLE profession (
	name		CHAR(30)		PRIMARY KEY,
	department	CHAR(30)
);

CREATE TABLE class (
	ID			NUMERIC(7)		PRIMARY KEY,
	profession	CHAR(30),
	FOREIGN KEY (profession) REFERENCES profession(name)
);

CREATE TABLE student (
	ID			NUMERIC(11),
	name		CHAR(30),
	sex			CHAR(6),
	class		NUMERIC(7),
	in_time		NUMERIC(4),
	status		CHAR(7),
	PRIMARY KEY (ID,class),
	CHECK(sex IN ('male','female')),
	FOREIGN KEY (class) REFERENCES class(ID),
	CHECK(status IN ('stay_in','remove'))
);

CREATE TABLE course (
	name		CHAR(30)		PRIMARY KEY,
	grade		CHAR(10),
	course_type	CHAR(30),
	credits		NUMERIC(1),
	CHECK (credits > 0),
	CHECK(course_type IN ('compulsory','elective','limit_elective'))
);

CREATE TABLE teacher (
	ID			NUMERIC(11),
	name		CHAR(30),
	department	CHAR(30),
	course		CHAR(30),
	class		NUMERIC(7),
	PRIMARY KEY (course,class),
	FOREIGN KEY (course) REFERENCES course(name),
	FOREIGN KEY (class) REFERENCES class(ID)
);

CREATE TABLE electives (
	student_ID		NUMERIC(11),
	name			CHAR(30),
	FOREIGN KEY (student_ID) REFERENCES student(ID),
	FOREIGN KEY (name) REFERENCES course(name)
);

CREATE TABLE teaching_plan (
	profession		CHAR(30),
	major_credits	NUMERIC(2),
	limit_minor_credits		NUMERIC(2),
	minor_credits	NUMERIC(2),
	grade			CHAR(10),
	FOREIGN KEY (profession) REFERENCES profession(name)
);

CREATE TABLE score (
	student_ID		NUMERIC(11),
	course			CHAR(30),
	score_value		NUMERIC(3.1),
	exam_times		NUMERIC(1),
	PRIMARY KEY (student_ID, course),
	FOREIGN KEY (student_ID) REFERENCES student(ID),
	FOREIGN KEY (course) REFERENCES course(name)
);
