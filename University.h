
#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Grade {
	string letter; // e.g., "A-", "B+"
	double gpaValue; // numeric equivalent
};
struct Course {
	string courseCode;
	string courseName;
	int creditHours;
	int totalStudents;
	int* studentIDs; // dynamic array of enrolled student IDs
	Grade* grades; // parallel array of grades
};
struct RetakeRequest {
	int studentID;
	string courseCode;
	string reason;
	bool approved; // initially false
	bool processed; // initially false
};
struct Student {
	int studentID;
	string name;
	double gpa;
	int enrolledCount;
	Course** enrolledCourses; // dynamic array of course pointers
	RetakeRequest* requests; // dynamic array of retake requests
	int totalRequests;
	// functions
	void viewGrades(const Student& s) {
		if (s.enrolledCount == 0) {
			cout << "No courses enrolled yet." << endl;
			return;
		}
		cout << "Grades for " << s.name << " (ID: " << s.studentID << "):" << endl;
		for (int i = 0; i < s.enrolledCount; i++) {
			Course* c = s.enrolledCourses[i];
			cout << c->courseCode << " - " << c->courseName << ": ";
			// find the student's grade in the course
			bool found = false;
			for (int j = 0; j < c->totalStudents; j++) {
				if (c->studentIDs[j] == s.studentID) {
					found = true;
					cout << c->grades[j].letter
						<< " (GPA " << c->grades[j].gpaValue << ")" << endl;
					break;
				}
			}
			if (!found) {
				cout << "No grade assigned yet." << endl;
			}
		}
	}
	double calculateGPA(const Student& s) {
		if (s.enrolledCount == 0)
			return 0.0;
		double totalGPA = 0.0;
		int gradedCourses = 0;
		for (int i = 0; i < s.enrolledCount; i++) {
			Course* c = s.enrolledCourses[i];
			// find the student's grade in the course
			for (int j = 0; j < c->totalStudents; j++) {
				if (s.studentID == c->studentIDs[j]) {
					if (c->grades[j].letter != "") { // if grade assigned
						totalGPA += c->grades[j].gpaValue;
						gradedCourses++;
					}
					break;
				}
			}

		}
		if (gradedCourses > 0)
			return totalGPA / gradedCourses;
		else
			return 0.0;
	}
	void enrollInCourse(Student& s, Course& c) {
		// check if already enrolled
		for (int i = 0; i < s.enrolledCount; i++) {
			if (s.enrolledCourses[i]->courseCode == c.courseCode) {
				cout << "Already enrolled in " << c.courseCode << endl;
				return;
			}
		}
		// enroll student in course
		if (s.enrolledCount == 0) {
			s.enrolledCourses = new Course * [1];
			s.enrolledCourses[0] = &c;
		}
		else {
			Course** temp = new Course * [s.enrolledCount + 1];
			for (int i = 0; i < s.enrolledCount; i++) {
				temp[i] = s.enrolledCourses[i];
			}
			temp[s.enrolledCount] = &c;
			delete[] s.enrolledCourses;
			s.enrolledCourses = temp;
		}
		s.enrolledCount++;
		// add student to course's student list
		if (c.totalStudents == 0) {
			c.studentIDs = new int[1];
			c.grades = new Grade[1];
			c.studentIDs[0] = s.studentID;
			c.grades[0] = { "", 0.0 }; // no grade yet
		}
		else {
			int* tempIDs = new int[c.totalStudents + 1];
			Grade* tempGrades = new Grade[c.totalStudents + 1];
			for (int i = 0; i < c.totalStudents; i++) {
				tempIDs[i] = c.studentIDs[i];
				tempGrades[i] = c.grades[i];
			}
			tempIDs[c.totalStudents] = s.studentID;
			tempGrades[c.totalStudents] = { "", 0.0 }; // no grade yet
			delete[] c.studentIDs;
			delete[] c.grades;
			c.studentIDs = tempIDs;
			c.grades = tempGrades;
		}
		c.totalStudents++;
		cout << "Enrolled " << s.name << " in " << c.courseCode << endl;
	}
	void unenrollFromCourse(Student& s, Course& c) {
		bool found = false;
		for (int i = 0; i < s.enrolledCount; i++) {
			if (s.enrolledCourses[i]->courseCode == c.courseCode) {
				found = true;
				// remove course by shifting array
				for (int j = i; j < s.enrolledCount - 1; j++) {
					s.enrolledCourses[j] = s.enrolledCourses[j + 1];
				}
				s.enrolledCount--;
				cout << "Unenrolled " << s.name << " from " << c.courseCode << endl;
				break;
			}
		}
		if (!found) {
			cout << "Not enrolled in " << c.courseCode << endl;
			return;
		}
		// remove student from course's student list
		found = false;
		for (int i = 0; i < c.totalStudents; i++) {
			if (c.studentIDs[i] == s.studentID) {
				found = true;
				// remove student by shifting arrays
				for (int j = i; j < c.totalStudents - 1; j++) {
					c.studentIDs[j] = c.studentIDs[j + 1];
					c.grades[j] = c.grades[j + 1];
				}
				c.totalStudents--;
				break;
			}
		}
		if (!found) {
			cout << "Student ID " << s.studentID
				<< " not found in course " << c.courseCode << endl;
		}

	}
};
struct Teacher {
	int teacherID;
	string name;
	int totalCourses;
	Course** assignedCourses; // courses teacher teaches

	// functions 
	void viewAssignedCourses(const Teacher& t) {
		if (t.totalCourses == 0) {
			cout << "No courses assigned yet." << endl;
			return;
		}
		cout << "Assigned Courses:" << endl;
		for (int i = 0; i < t.totalCourses; i++) {
			cout << t.assignedCourses[i]->courseCode << " - " << t.assignedCourses[i]->courseName << endl;
		}
	}
	double convertToGPA(const string& letter) {
		if (letter == "A")  return 4.0;
		if (letter == "A-") return 3.7;
		if (letter == "B+") return 3.3;
		if (letter == "B")  return 3.0;
		if (letter == "B-") return 2.7;
		if (letter == "C+") return 2.3;
		if (letter == "C")  return 2.0;
		if (letter == "C-") return 1.7;
		if (letter == "D")  return 1.0;
		if (letter == "F")  return 0.0;
		return 0.0;
	}
	void assignGrade(Course& c, int studentID, string letter) {
		cout << &c << " <- course address in assignGrade\n";

		bool found = false;
		for (int i = 0; i < c.totalStudents; i++) {
			if (c.studentIDs[i] == studentID) {
				found = true;
				// assign grade in parallel array
				c.grades[i].letter = letter;
				c.grades[i].gpaValue = convertToGPA(letter);
				cout << "Assigned grade " << letter
					<< " (GPA " << c.grades[i].gpaValue
					<< ") to student " << studentID
					<< " in course " << c.courseCode << endl;

				break;
			}
		}

		if (!found) {
			cout << "Student " << studentID
				<< " is not enrolled in " << c.courseCode << endl;
		}
	}
	double classAverageGPA(const Course& c) {
		if (c.totalStudents == 0)
			return 0.0;
		double totalGPA = 0.0;
		for (int i = 0; i < c.totalStudents; i++) {
			totalGPA += c.grades[i].gpaValue;
		}
		return totalGPA / c.totalStudents;
	}
	string classAverageGrade(const Course& c) {
		double avgGPA = classAverageGPA(c);
		if (avgGPA >= 3.85) return "A";
		if (avgGPA >= 3.5)  return "A-";
		if (avgGPA >= 3.15) return "B+";
		if (avgGPA >= 2.85) return "B";
		if (avgGPA >= 2.5)  return "B-";
		if (avgGPA >= 2.15) return "C+";
		if (avgGPA >= 1.85) return "C";
		if (avgGPA >= 1.5)  return "C-";
		if (avgGPA >= 1.0)  return "D";
		return "F";
	}
	void generateClassReport(const Course& c) {
		cout << &c << " <- course address in report\n";

		cout << "Class Report for " << c.courseCode << " - " << c.courseName << endl;
		cout << "Total Students: " << c.totalStudents << endl;
		cout << "Average GPA: " << classAverageGPA(c) << endl;
		cout << "Average Grade: " << classAverageGrade(c) << endl;
		cout << "Student Grades:" << endl;
		for (int i = 0; i < c.totalStudents; i++) {
			cout << "Student ID: " << c.studentIDs[i]
				<< ", Grade: " << c.grades[i].letter
				<< " (GPA " << c.grades[i].gpaValue << ")" << endl;
		}
	}
	void removeStudentFromCourse(Course& c, int studentID) {
		bool found = false;
		for (int i = 0; i < c.totalStudents; i++) {
			if (c.studentIDs[i] == studentID) {
				found = true;

				for (int j = i; j < c.totalStudents - 1; j++) {
					c.studentIDs[j] = c.studentIDs[j + 1];
					c.grades[j] = c.grades[j + 1];
				}
				c.totalStudents--;
				cout << "Removed student " << studentID
					<< " from course " << c.courseCode << endl;
				break;
			}
		}
		if (!found) {
			cout << "Student " << studentID
				<< " is not enrolled in " << c.courseCode << endl;
		}
	}
};


struct University {
	string uniName;
	int totalStudents;
	int totalTeachers;
	int totalCourses;
	Student* students;
	Teacher* teachers;
	Course* courses;

	Course* findCourseByName(const string& name) {
		for (int i = 0; i < totalCourses; i++) {
			if (courses[i].courseName == name)
				return &courses[i];
		}
		return nullptr;
	}
	Course* findCourseByCode(const string& code) {
		for (int i = 0; i < totalCourses; i++) {
			if (courses[i].courseCode == code)
				return &courses[i];
		}
		return nullptr;
	}

};
// admin functions 
void createStudent(University& u) {
	Student s;
	cin.ignore();
	cout << "Enter the Name of Student : ";
	getline(cin, s.name);
	cout << "Enter the Student ID : ";
	cin >> s.studentID;
	s.gpa = 0.0;
	s.enrolledCount = 0;
	s.enrolledCourses = nullptr;
	s.requests = nullptr;
	s.totalRequests = 0;
	// add the student to the university students array , increment totalStudents
	if (u.totalStudents == 0) {
		u.students = new Student[1];
		u.students[0] = s;
	}
	else {
		Student* temp = new Student[u.totalStudents + 1];
		for (int i = 0; i < u.totalStudents; i++) {
			temp[i] = u.students[i];
		}
		temp[u.totalStudents] = s;
		delete[] u.students;
		u.students = temp;
	}
	u.totalStudents++;
}
void createTeacher(University& u) {
	Teacher t;
	cin.ignore();
	cout << "Enter the Name of Teacher : ";
	getline(cin, t.name);
	cout << "Enter the Teacher ID : ";
	cin >> t.teacherID;
	t.totalCourses = 0;
	t.assignedCourses = nullptr;
	// add the teacher to the university teachers array , increment totalTeachers
	if (u.totalTeachers == 0) {
		u.teachers = new Teacher[1];
		u.teachers[0] = t;
	}
	else {
		Teacher* temp = new Teacher[u.totalTeachers + 1];
		for (int i = 0; i < u.totalTeachers; i++) {
			temp[i] = u.teachers[i];
		}
		temp[u.totalTeachers] = t;
		delete[] u.teachers;
		u.teachers = temp;
	}
	u.totalTeachers++;
}
void createCourse(University& u) {
	Course c;
	cin.ignore();
	cout << "Enter the Course Code : ";
	getline(cin, c.courseCode);
	cout << "Enter the Course Name : ";
	getline(cin, c.courseName);
	cout << "Enter the Credit Hours : ";
	cin >> c.creditHours;
	c.totalStudents = 0;
	c.studentIDs = nullptr;
	c.grades = nullptr;

	// Add the course to the university
	if (u.totalCourses == 0) {
		u.courses = new Course[1];
		u.courses[0] = c;
	}
	else {
		Course* temp = new Course[u.totalCourses + 1];
		for (int i = 0; i < u.totalCourses; i++) {
			temp[i] = u.courses[i];
		}
		temp[u.totalCourses] = c;
		delete[] u.courses;
		u.courses = temp;
	}
	u.totalCourses++;
	cout << "Course created successfully: " << c.courseCode << endl;
}

void assignTeacherToCourse(University& u, int teacherID) {
	string code;
	cout << "Enter Course Code to assign: ";
	cin >> code;

	// find teacher
	Teacher* t = nullptr;
	for (int i = 0; i < u.totalTeachers; i++) {
		if (u.teachers[i].teacherID == teacherID) {
			t = &u.teachers[i];
			break;
		}
	}
	if (!t) {
		cout << "Teacher not found!\n";
		return;
	}

	// find course by course code
	Course* c = nullptr;
	for (int i = 0; i < u.totalCourses; i++) {
		if (u.courses[i].courseCode == code) {
			c = &u.courses[i];
			break;
		}
	}
	if (!c) {
		cout << "Course with code " << code << " not found!\n";
		return;
	}

	// assign course to teacher
	if (t->totalCourses == 0) {
		t->assignedCourses = new Course * [1];
		t->assignedCourses[0] = c;
	}
	else {
		Course** temp = new Course * [t->totalCourses + 1];
		for (int i = 0; i < t->totalCourses; i++)
			temp[i] = t->assignedCourses[i];
		temp[t->totalCourses] = c;
		delete[] t->assignedCourses;
		t->assignedCourses = temp;
	}
	t->totalCourses++;
	cout << "Assigned " << c->courseCode << " to " << t->name << endl;
}

//display functions
void displayCourse(const Course& c) {
	cout << "Course Code: " << c.courseCode << endl;
	cout << "Course Name: " << c.courseName << endl;
	cout << "Credit Hours: " << c.creditHours << endl;
	cout << "Total Students Enrolled: " << c.totalStudents << endl;

}
void displayStudent(const Student& s) {
	cout << "Student ID: " << s.studentID << endl;
	cout << "Name: " << s.name << endl;
	cout << "GPA: " << s.gpa << endl;
	cout << "Enrolled Courses: " << s.enrolledCount << endl;
	for (int i = 0; i < s.enrolledCount; i++) {
		cout << "  - " << s.enrolledCourses[i]->courseCode
			<< " : " << s.enrolledCourses[i]->courseName << endl;
	}
}
void displayTeacher(const Teacher& t) {
	cout << "Teacher ID: " << t.teacherID << endl;
	cout << "Name: " << t.name << endl;
	cout << "Total Courses Assigned: " << t.totalCourses << endl;
	for (int i = 0; i < t.totalCourses; i++) {
		cout << "  - " << t.assignedCourses[i]->courseCode
			<< " : " << t.assignedCourses[i]->courseName << endl;
	}
}
void displayUniversity(const University& u) {
	cout << "University Name: " << u.uniName << endl;
	cout << "Total Students: " << u.totalStudents << endl;
	for (int i = 0; i < u.totalStudents; i++) {
		displayStudent(u.students[i]);
	}
	cout << "Total Teachers: " << u.totalTeachers << endl;
	for (int i = 0; i < u.totalTeachers; i++) {
		displayTeacher(u.teachers[i]);
	}
	cout << "Total Courses: " << u.totalCourses << endl;
	for (int i = 0; i < u.totalCourses; i++) {
		displayCourse(u.courses[i]);
	}
}
// memory cleanup
void deleteUniversity(University& u) {
	// Free student arrays
	for (int i = 0; i < u.totalStudents; i++) {
		delete[] u.students[i].enrolledCourses;
	}
	delete[] u.students;

	// Free teacher arrays
	for (int i = 0; i < u.totalTeachers; i++) {
		delete[] u.teachers[i].assignedCourses;
	}
	delete[] u.teachers;

	// Free course arrays
	for (int i = 0; i < u.totalCourses; i++) {
		delete[] u.courses[i].studentIDs;
		delete[] u.courses[i].grades;
	}
	delete[] u.courses;
	u.totalStudents = 0;
	u.totalTeachers = 0;
	u.totalCourses = 0;
}