USE fenlan;

/* insert profession values */
INSERT INTO profession VALUES ('software engineering','software college');

/* insert class values */
INSERT INTO class VALUES ('1613011','software engineering');
INSERT INTO class VALUES ('1613012','software engineering');
INSERT INTO class VALUES ('1613013','software engineering');
INSERT INTO class VALUES ('1613014','software engineering');
INSERT INTO class VALUES ('1613018','software engineering');
INSERT INTO class VALUES ('1513011','software engineering');
INSERT INTO class VALUES ('1513012','software engineering');
INSERT INTO class VALUES ('1513013','software engineering');
INSERT INTO class VALUES ('1513014','software engineering');
INSERT INTO class VALUES ('1513018','software engineering');
INSERT INTO class VALUES ('1513020','software engineering');
INSERT INTO class VALUES ('1513021','software engineering');
/* insert course values */
INSERT INTO course VALUES ('信号与系统','大二下','compulsory','4');
INSERT INTO course VALUES ('软件工程概论','大二下','compulsory','3');
INSERT INTO course VALUES ('面向对象程序设计','大二下','compulsory','3');
INSERT INTO course VALUES ('毛泽东思想和中国特色社会主义理论体系概论','大二下','compulsory','6');
INSERT INTO course VALUES ('数字电路与系统设计','大二下','compulsory','4');
INSERT INTO course VALUES ('大学英语(IV)','大二下','compulsory','3');
INSERT INTO course VALUES ('数据库概论','大二下','compulsory','3');
INSERT INTO course VALUES ('大学体育(IV)','大二下','compulsory','1');
INSERT INTO course VALUES ('形式与政策','大二下','compulsory','1');
INSERT INTO course VALUES ('计算机组成与结构','大二下','compulsory','4');
INSERT INTO course VALUES ('大二下实验','大二下','compulsory','2');
INSERT INTO course VALUES ('数学建模','大二下','limit_elective','2');
INSERT INTO course VALUES ('职业生涯规划','大二下','limit_elective','2');

INSERT INTO student VALUES ('15130110067','高杰','male','1513011','2015','stay_in');
/* 选修班　*/
INSERT INTO student VALUES ('15130110067','高杰','male','1513020','2015','stay_in');
INSERT INTO student VALUES ('15130110067','高杰','male','1513021','2015','stay_in');

INSERT INTO student VALUES ('15130110066','阳湘源','male','1513011','2015','stay_in');
INSERT INTO student VALUES ('15130110065','刘鹏程','male','1513011','2015','stay_in');

INSERT INTO teacher VALUES ('1','王辉','software college','信号与系统','1513011');
INSERT INTO teacher VALUES ('2','郑有才','software college','软件工程概论','1513011');
INSERT INTO teacher VALUES ('3','李艳妮','software college','面向对象程序设计','1513011');
INSERT INTO teacher VALUES ('4','张丽珍','software college','毛泽东思想和中国特色社会主义理论体系概论','1513011');
INSERT INTO teacher VALUES ('5','宋娟','software college','数字电路与系统设计','1513011');
INSERT INTO teacher VALUES ('6','马琪','software college','大学英语(IV)','1513011');
INSERT INTO teacher VALUES ('7','董洛兵','software college','数据库概论','1513011');
INSERT INTO teacher VALUES ('8','何小艺','software college','大学体育(IV)','1513011');
INSERT INTO teacher VALUES ('9','赵璐','software college','形式与政策','1513011');
INSERT INTO teacher VALUES ('10','顾新','software college','计算机组成与结构','1513011');
INSERT INTO teacher VALUES ('11','高兴','software college','大二下实验','1513011');
INSERT INTO teacher VALUES ('12','李伟','software college','数学建模','1513021');
INSERT INTO teacher VALUES ('13','李瑞','software college','职业生涯规划','1513020');

INSERT INTO score VALUES ('15130110067','信号与系统','82','1');
INSERT INTO score VALUES ('15130110067','软件工程概论','84','1');
INSERT INTO score VALUES ('15130110067','面向对象程序设计','85','1');
INSERT INTO score VALUES ('15130110067','毛泽东思想和中国特色社会主义理论体系概论','82','1');
INSERT INTO score VALUES ('15130110067','数字电路与系统设计','82','1');
INSERT INTO score VALUES ('15130110067','大学英语(IV)','68','1');
INSERT INTO score VALUES ('15130110067','数据库概论','83','1');
INSERT INTO score VALUES ('15130110067','大学体育(IV)','90','1');
INSERT INTO score VALUES ('15130110067','形式与政策','87','1');
INSERT INTO score VALUES ('15130110067','计算机组成与结构','82','1');
INSERT INTO score VALUES ('15130110067','大二下实验','90','1');
INSERT INTO score VALUES ('15130110067','数学建模','87','1');
INSERT INTO score VALUES ('15130110067','职业生涯规划','82','1');

INSERT INTO score VALUES ('15130110066','信号与系统','56','1');
INSERT INTO score VALUES ('15130110066','软件工程概论','50','1');
INSERT INTO score VALUES ('15130110066','面向对象程序设计','54','1');
INSERT INTO score VALUES ('15130110066','毛泽东思想和中国特色社会主义理论体系概论','59','1');
INSERT INTO score VALUES ('15130110066','数字电路与系统设计','45','1');
INSERT INTO score VALUES ('15130110066','大学英语(IV)','34','1');
INSERT INTO score VALUES ('15130110066','数据库概论','45','1');
INSERT INTO score VALUES ('15130110066','大学体育(IV)','22','1');
INSERT INTO score VALUES ('15130110066','大二下实验','22','1');
INSERT INTO score VALUES ('15130110066','形式与政策','45','1');
INSERT INTO score VALUES ('15130110066','计算机组成与结构','45','1');

INSERT INTO score VALUES ('15130110065','信号与系统','62','1');
INSERT INTO score VALUES ('15130110065','软件工程概论','70','1');
INSERT INTO score VALUES ('15130110065','面向对象程序设计','61','1');
INSERT INTO score VALUES ('15130110065','毛泽东思想和中国特色社会主义理论体系概论','35','1');
INSERT INTO score VALUES ('15130110065','数字电路与系统设计','75','1');
INSERT INTO score VALUES ('15130110065','大学英语(IV)','85','1');
INSERT INTO score VALUES ('15130110065','数据库概论','70','1');
INSERT INTO score VALUES ('15130110065','大学体育(IV)','85','1');
INSERT INTO score VALUES ('15130110065','大二下实验','78','1');
INSERT INTO score VALUES ('15130110065','形式与政策','56','1');
INSERT INTO score VALUES ('15130110065','计算机组成与结构','89','1');


INSERT INTO electives VALUES ('15130110067','数学建模');
INSERT INTO electives VALUES ('15130110067','职业生涯规划');