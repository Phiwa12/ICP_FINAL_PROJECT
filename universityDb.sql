drop database if exists  UniversityDB;
#Create database

SHOW DATABASES;
CREATE DATABASE UniversityDB;
SHOW DATABASES;
USE UniversityDB;

-- Users Table: Stores all users in the system (students, faculty, etc.)
CREATE TABLE Users (
    UserID VARCHAR(20) PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) NOT NULL UNIQUE,
    Password VARCHAR(100) NOT NULL,
    UserType ENUM('Student', 'Faculty', 'Admin') NOT NULL -- Replaced CHECK with ENUM for UserType
);

-- Students Table: Stores student-specific information
CREATE TABLE Students (
    StudentID VARCHAR(20) PRIMARY KEY,
    UserID VARCHAR(20) UNIQUE NOT NULL,
    DateOfBirth DATE,
    Major VARCHAR(50),
    EnrollmentDate DATE,
    Picture LONGBLOB, -- Changed VARBINARY(MAX) to LONGBLOB for MySQL compatibility
    FOREIGN KEY (UserID) REFERENCES Users(UserID) ON DELETE CASCADE
);

-- Faculty Table: Stores faculty-specific information
CREATE TABLE Faculty (
    FacultyID VARCHAR(20) PRIMARY KEY,
    UserID VARCHAR(20) UNIQUE NOT NULL,
    Department VARCHAR(50),
    DateOfAppointment DATE,
    FOREIGN KEY (UserID) REFERENCES Users(UserID) ON DELETE CASCADE
);

-- Courses Table: Stores course information
CREATE TABLE Courses (
    CourseID VARCHAR(20) PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL,
    Credits INT NOT NULL CHECK (Credits > 0), -- Note: MySQL doesn't enforce CHECK, use INT > 0 constraint in app logic
    FacultyID VARCHAR(20),
    Semester VARCHAR(20),
    MaxEnrollment INT NOT NULL, -- Note: MySQL doesn't enforce CHECK, so validate in app
    FOREIGN KEY (FacultyID) REFERENCES Faculty(FacultyID) ON DELETE SET NULL
);

-- Enrollments Table: Stores information about enrollments
CREATE TABLE Enrollments (
    EnrollmentID VARCHAR(20) PRIMARY KEY,
    StudentID VARCHAR(20) NOT NULL,
    CourseID VARCHAR(20) NOT NULL,
    Semester VARCHAR(20),
    Grade DECIMAL(4,2), -- Assuming a GPA scale; use app logic to enforce range
    EnrollmentDate DATE,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE CASCADE,
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID) ON DELETE CASCADE
);

-- Stored Procedure for Enrolling a Student in a Course
DELIMITER //

CREATE PROCEDURE sp_EnrollStudent(
    IN StudentID VARCHAR(20),
    IN CourseID VARCHAR(20),
    IN Semester VARCHAR(20)
)
BEGIN
    DECLARE CurrentEnrollment INT DEFAULT 0;
    DECLARE MaxEnrollment INT DEFAULT 0;

    -- Get current enrollment count for the course
    SELECT COUNT(*) INTO CurrentEnrollment
    FROM Enrollments
    WHERE CourseID = CourseID AND Semester = Semester;

    -- Get maximum enrollment allowed
    SELECT MaxEnrollment INTO MaxEnrollment
    FROM Courses
    WHERE CourseID = CourseID;

    -- Check if capacity allows enrollment
    IF CurrentEnrollment < MaxEnrollment THEN
        INSERT INTO Enrollments (EnrollmentID, StudentID, CourseID, Semester, EnrollmentDate)
        VALUES (UUID(), StudentID, CourseID, Semester, CURDATE());
    ELSE
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Course is full';
    END IF;
END //

DELIMITER ;
