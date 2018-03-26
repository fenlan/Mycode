import java.util.ArrayList;
import java.util.List;

public class CRS {
    private static StringBuilder str = new StringBuilder();
    private static List<Course> allCourses = new ArrayList<>();

    static class Book {
        private String bookName;

        public Book(String bookName) { this.bookName = bookName; }
    }

    static class Course {
        private String courseName;
        private List<Book> bookList = new ArrayList<>();

        public Course(String courseName) { this.courseName = courseName; }

        public void addBook(Book book) { bookList.add(book); }

        public void removeBook(Book book) { bookList.remove(book); }

        public void print() {
            if (bookList.size() == 0)       System.out.print("no book");
            else if (bookList.size() == 1)   str.append(bookList.get(0).bookName);
            else {
                str.append("books ");
                for (Book book : bookList)  str.append(book.bookName + ", ");
                str.deleteCharAt(str.length() - 1);
                str.deleteCharAt(str.length() - 1);
            }
        }
    }

    static class Student {
        private long num;
        private List<Course> courses = new ArrayList<>();

        public Student() { num = 0; }

        public Student(long num) { this.num = num; }

        public Student(long num, List<Course> courses) {
            this.num = num;
            this.courses = courses;
        }

        private void selectCourse(Course course) { courses.add(course); }

        public void print() {
            if (num == 0)                   System.out.println("Nobody!!!");
            else if (courses.size() == 0)   System.out.println(num + " didn't select course!!!");
            else if (courses.size() == 1) {
                str.append(num + " select " + courses.get(0).courseName + " with ");
                courses.get(0).print();
                System.out.print(str + "\n");
            }
            else {
                str.append(num + " select ");
                for (Course course : courses) {
                    str.append(course.courseName + " with ");
                    course.print();
                    str.append("; ");
                }
                str.replace(str.length()-2, str.length()-1, ".");
                System.out.println(str);
            }
        }
    }

    public static void main(String[] args) {
        Book thinkingInJava = new Book("Thinking in Java");
        Book java8 = new Book("Java 8");
        Book webEngineering = new Book("Web Engineering");


        Course javaCourse = new Course("Java");
        Course webCourse = new Course("WebEngineering");

        javaCourse.addBook(thinkingInJava);
        javaCourse.addBook(java8);
        webCourse.addBook(webEngineering);
        allCourses.add(javaCourse);
        allCourses.add(webCourse);

        if (args.length == 0) {
            Student student = new Student();
            student.print();
        } else if (args.length == 1) {
            Student student = new Student(Long.parseLong(args[0]));
            student.print();
        } else {
            Student student = new Student(Long.parseLong((args[0])));
            for (int i = 1; i < args.length; i++) {
                try {
                    Course getCourse = checkCourse(args[i]);
                    student.selectCourse(getCourse);
                } catch (NullPointerException e) {
                    System.out.println("Don't have " + args[i]);
                }
            }
            student.print();
        }

    }

    private static Course checkCourse(String courseName) {
        for (Course course : allCourses) {
            if (courseName.equals(course.courseName))  return course;
        }
        
        throw new NullPointerException(courseName);
    }
}
