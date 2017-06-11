USE fenlan;

/* 查询学生所选修的课程及成绩　*/
SELECT course, score_value FROM score 
WHERE student_ID = '15130110067' AND course IN (
	SELECT name FROM course WHERE course_type != 'compulsory'
);

/* 查询学生所必修的课程及成绩　*/
SELECT course, score_value FROM score 
WHERE student_ID = '15130110067' AND course IN (
	SELECT name FROM course WHERE course_type = 'compulsory'
);

/* 查询学生必修课程平均分　*/
SELECT AVG(score_value) FROM score
WHERE student_ID = '15130110067' AND course IN (
	SELECT name FROM course WHERE course_type = 'compulsory'
);

/* 查询学生选修课程平均分 */
SELECT AVG(score_value) FROM score
WHERE student_ID = '15130110067' AND course IN (
	SELECT name FROM course WHERE course_type != 'compulsory'
);

/* 查询某一个学生被哪些老师教过 */
SELECT name FROM teacher WHERE class IN (
	SELECT class FROM student WHERE ID = '15130110067'
);

/* 一学期不及格的必修课学分超过１０个　*/
SELECT ID FROM student WHERE (
	SELECT SUM(credits) > 10 FROM course WHERE name IN (
		SELECT course FROM score WHERE student_ID = student.ID AND score_value < 60
	) AND course_type = 'compulsory'
);