# <p align="center">简易教务系统</p>

## Introduction
教务系统数据库的有关语义如下：
- 一个系可以有若干专业，每个专业每年可以招若干班级，每个班级有若干学生。
- 系里对每个专业每年都制定教学计划，学生每年必须按照计划修完一定学分的课程（必修课、限选课和任选课），如2000年入学的学生大三上学期必修30学分，限选课10学分，任选课6学分。
- 系里的教师可以给多个班带课，但不能给一个班带多门课。
- 一门课程最多允许学生一次补考，学生达到如下条件之一的被开除：
> 一学期不及格的必修课学分超过10个<br>
> 不及格必修课学分累计超过30个<br>
> 不及格选修课学分累计超过20个

## Using
处理要求：
- 查询学生所选修的课程及成绩，并给出必修课平均成绩和选修课平均成绩
- 查某一个学生被哪些老师教过课
- 查询应被开除的学生(假定差2学分即被开除)

## E-R Diagram
![E-R diagram](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/E-R.png)

## Entity Sets
profession<br>
![profession](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/profession.png)
student<br>
![student](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/student.png)
class<br>
![class](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/class.png)
teacher<br>
![teacher](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/teacher.png)
course<br>
![course](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/course.png)
electives<br>
![electives](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/electives.png)
teaching plan<br>
![teaching plan](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/teaching_plan.png)
score<br>
![score](https://github.com/fenlan/Mycode/blob/master/edu_management_system/images/score.png)

## Participant
Design E-R diagram and entity sets with this guy [fanzhonghao](https://github.com/fanzhonghao)