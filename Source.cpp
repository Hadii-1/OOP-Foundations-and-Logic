#include <iostream>
#include<string>
#include<cstring>
#include"University.h"
#include<ctime>
#include<cstdlib>
#include"GameBoard.h"
#include"Header.h"

using namespace std;
//========================= Question No. 5 =========================
int main() {
    int n = 5;
    printHollowDiamond(n);   
    return 0;
}
//=================================================================

//===================== Question No. 4 ============================
//int main() {
//	
//	printWordsReverse("Object Oriented Programming");
//	return 0;
//}
//=================================================================

//====================== Question No. 2 ===========================
//int main() {
//	int row;
//	int colCount;
//	cout << "Enter the number of rows : ";
//	cin >> row;
//	int* ColInEachRow = new int[row];
//	int** JaggedArray = createJaggedArray(row, ColInEachRow);
//	inputJaggedArray(JaggedArray, ColInEachRow, row);
//	DisplayJaggedArray(JaggedArray, ColInEachRow, row);
//	calculateRowSums(JaggedArray, row, ColInEachRow);
//	DeleteJaggedArray(JaggedArray, row);
//	delete[] ColInEachRow;
//	return 0;
//}
//====================================================================

//================ Question No. 1 ============================

//int main() {
//	srand(time(0));
//	int rows, cols;
//	char moveDirection;
//
//	cout << "Enter number of rows : ";
//	cin >> rows;
//	cout << "Enter number of cols : ";
//	cin >> cols;
//
//	int** grid = createGrid(rows, cols);
//
//	int playerRow = 0, playerCol = 0;
//	int teleportRow, teleportCol;
//
//	// random teleport placement
//	placeTeleport(grid, rows, cols, teleportRow, teleportCol);
//
//	do {
//		
//		updateGrid(grid, rows, cols, playerRow, playerCol, teleportRow, teleportCol);
//		displayGrid(grid, rows, cols);
//
//		cout << "Enter move (W/A/S/D) or Q to quit: ";
//		cin >> moveDirection;
//		system("CLS");  // Clears screen on Windows
//
//		if (moveDirection == 'q' || moveDirection == 'Q') {
//			cout << "Game Over. You quit the game." << endl;
//			break;
//		}
//
//		movePlayer(grid,playerRow, playerCol, moveDirection, rows, cols);
//
//		// check teleport
//		if (playerRow == teleportRow && playerCol == teleportCol) {
//			// teleport player to a new random cell
//			teleportPlayer(playerRow, playerCol, rows, cols, teleportRow, teleportCol);
//			
//		}
//		
//
//	} while (true);
//
//	resetGrid(grid, rows);
//	return 0;
//}
//=============================================================
//=========================== Q3 ================================
//void universityMenu() {
//    cout << "============ University System=============" << endl;
//    cout << "1. Admin login." << endl;
//    cout << "2. Teacher login." << endl;
//    cout << "3. Student login." << endl;
//    cout << "4. Display University." << endl;
//    cout << "5. Exit." << endl;
//
//
//}
//int adminMenu() {
//    int choice;
//    cout << "============ Admin Menu =============" << endl;
//    cout << "1. Add Student." << endl;
//    cout << "2. Add Teacher." << endl;
//    cout << "3. Add Course." << endl;
//    cout << "4. Assign Teacher to Course." << endl;
//    cout << "5. Back to Main Menu." << endl;
//    do {
//        cin >> choice;
//    } while (choice < 1 || choice > 5);
//    return choice;
//}
//int studentMenu() {
//    int choice;
//    cout << "============ Student Menu =============" << endl;
//    cout << "1. View Grades." << endl;
//    cout << "2. Calculate GPA." << endl;
//    cout << "3. Enroll in Course." << endl;
//    cout << "4. Unenroll from Course." << endl;
//    cout << "5. Back to main menu." << endl;
//    do {
//        cin >> choice;
//    } while (choice < 1 || choice > 5);
//    return choice;
//}
//int teacherMenu() {
//    int choice;
//    cout << "============ Teacher Menu =============" << endl;
//    cout << "1. View Assigned Courses." << endl;
//    cout << "2. Assign Grades." << endl;
//    cout << "3. Generate Class Report." << endl;
//    cout << "4. Remove Student from Course." << endl;
//    cout << "5. Class Average Grade." << endl;
//    cout << "6. Class Average GPA." << endl;
//    cout << "7. Back to main menu." << endl;
//    do {
//        cin >> choice;
//    } while (choice < 1 || choice > 7);
//    return choice;
//}
//int main() {
//    University uni;
//    uni.uniName = "My University";
//    uni.totalStudents = 0;
//    uni.totalTeachers = 0;
//    uni.totalCourses = 0;
//    uni.students = nullptr;
//    uni.teachers = nullptr;
//    uni.courses = nullptr;
//
//    int n;
//    while (true) {
//        universityMenu();
//        cin >> n;
//        switch (n) {
//        case 1: { // Admin
//            while (true) {
//                int adminChoice = adminMenu();
//                if (adminChoice == 5) break;
//                if (adminChoice == 1) createStudent(uni);
//                else if (adminChoice == 2) createTeacher(uni);
//                else if (adminChoice == 3) createCourse(uni);
//                else if (adminChoice == 4) {
//                    int teacherID, courseID;
//                    cout << "Enter Teacher ID: ";
//                    cin >> teacherID;
//
//
//                    cin.ignore();
//                    assignTeacherToCourse(uni, teacherID);
//                }
//            }
//            break;
//        }
//        case 2: { // Teacher
//            int teacherID;
//            cout << "Enter Teacher ID to login: ";
//            cin >> teacherID;
//            Teacher* t = nullptr;
//            for (int i = 0; i < uni.totalTeachers; i++) {
//                if (uni.teachers[i].teacherID == teacherID) {
//                    t = &uni.teachers[i];
//                    break;
//                }
//            }
//            if (!t) { cout << "Teacher not found!\n"; break; }
//
//            while (true) {
//                int tchChoice = teacherMenu();
//                if (tchChoice == 7) break;
//
//                if (tchChoice == 1) t->viewAssignedCourses(*t);
//                else if (tchChoice == 2) {
//                    string grade, courseName;
//                    int sid;
//
//                    cout << "Enter Course NAME : ";
//                    cin.ignore();
//                    getline(cin, courseName);
//
//                    cout << "Enter Student ID: ";
//                    cin >> sid;
//
//                    cout << "Enter Grade: ";
//                    cin >> grade;
//
//                    Course* course = uni.findCourseByName(courseName);
//                    if (course) {
//                        t->assignGrade(*course, sid, grade);
//                    }
//                    else {
//                        cout << "Course not found.\n";
//                    }
//                }
//
//                else if (tchChoice == 3) {
//                    string courseName;
//                    cout << "Enter Course Name: ";
//                    cin.ignore();
//                    getline(cin, courseName);
//
//                    Course* c = uni.findCourseByName(courseName);
//                    if (c)
//                        t->generateClassReport(*c);
//                    else
//                        cout << "Course not found!\n";
//                }
//
//                else if (tchChoice == 4) {
//                    string courseName;
//                    int sid;
//                    cout << "Enter Course Name: ";
//                    cin.ignore();
//                    getline(cin, courseName);
//                    cout << "Enter Student ID: ";
//                    cin >> sid;
//
//                    Course* c = uni.findCourseByName(courseName);
//                    if (c)
//                        t->removeStudentFromCourse(*c, sid);
//                    else
//                        cout << "Course not found!\n";
//                }
//
//                else if (tchChoice == 5) {
//                    string code;
//                    cout << "Enter Course Code: ";
//                    cin >> code;
//
//                    Course* c = uni.findCourseByCode(code);
//                    if (c)
//                        cout << "Average Grade: " << t->classAverageGrade(*c) << endl;
//                    else
//                        cout << "Course not found!\n";
//                }
//
//                else if (tchChoice == 6) {
//                    string code;
//                    cout << "Enter Course Code: ";
//                    cin >> code;
//
//                    Course* c = uni.findCourseByCode(code);
//                    if (c)
//                        cout << "Average GPA: " << t->classAverageGPA(*c) << endl;
//                    else
//                        cout << "Course not found!\n";
//                }
//
//            }
//            break;
//        }
//        case 3: { // Student
//            int studentID;
//            cout << "Enter Student ID to login: ";
//            cin >> studentID;
//            Student* s = nullptr;
//            for (int i = 0; i < uni.totalStudents; i++) {
//                if (uni.students[i].studentID == studentID) {
//                    s = &uni.students[i];
//                    break;
//                }
//            }
//            if (!s) { cout << "Student not found!\n"; break; }
//
//            while (true) {
//                int studChoice = studentMenu();
//                if (studChoice == 5) break;
//
//                if (studChoice == 1) s->viewGrades(*s);
//                else if (studChoice == 2) cout << "GPA: " << s->calculateGPA(*s) << endl;
//                else if (studChoice == 3) {
//                    string code;
//                    cout << "Enter Course Code: ";
//                    cin >> code;
//
//                    bool found = false;
//                    for (int i = 0; i < uni.totalCourses; i++) {
//                        if (uni.courses[i].courseCode == code) {
//                            s->enrollInCourse(*s, uni.courses[i]);
//                            found = true;
//                            break;
//                        }
//                    }
//                    if (!found)
//                        cout << "Course not found!\n";
//                }
//
//                else if (studChoice == 4) {
//                    string code;
//                    cout << "Enter Course Code: ";
//                    cin >> code;
//
//                    bool found = false;
//                    for (int i = 0; i < uni.totalCourses; i++) {
//                        if (uni.courses[i].courseCode == code) {
//                            s->unenrollFromCourse(*s, uni.courses[i]);
//                            found = true;
//                            break;
//                        }
//                    }
//                    if (!found)
//                        cout << "Course not found!\n";
//                }
//
//            }
//            break;
//        }
//        case 4:
//            displayUniversity(uni);
//            break;
//        case 5:
//            deleteUniversity(uni);
//            return 0;
//        default:
//            cout << "Invalid choice.\n";
//        }
//    }
//}
//=============================================================