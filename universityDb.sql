DROP DATABASE IF EXISTS UniversityDB;

-- Create Database
CREATE DATABASE UniversityDB;
USE UniversityDB;

-- Users Table
CREATE TABLE Users (
    UserID INT AUTO_INCREMENT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) NOT NULL UNIQUE,
    Password VARCHAR(100) NOT NULL,
    UserType ENUM('Student', 'Faculty', 'Admin') NOT NULL
);
Create table admin(
    userId int primary key,
    foreign key (userId) references Users(UserId) on delete cascade
)
-- Students Table
CREATE TABLE Students (
    UserID INT PRIMARY KEY,
    DateOfBirth DATE NOT NULL,
    Major ENUM('BA', 'CS', 'ECO', 'ME', 'EE', 'CE') NOT NULL,
    EnrollmentDate DATE NOT NULL,
    Picture LONGBLOB,
    FOREIGN KEY (UserID) REFERENCES Users(UserID) ON DELETE CASCADE
);

-- Faculty Table
CREATE TABLE Faculty (
    UserID INT PRIMARY KEY,
    Department ENUM('Engineering', 'CSIS', 'Humanities') NOT NULL,
    DateOfAppointment DATE,
    FOREIGN KEY (UserID) REFERENCES Users(UserID) ON DELETE CASCADE
);

-- Courses Table
CREATE TABLE Courses (
    CourseID INT AUTO_INCREMENT PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL,
    Credits DOUBLE NOT NULL CHECK (Credits > 0),
    Semester ENUM('Spring', 'Fall') NOT NULL,
    MaxEnrollment INT NOT NULL
);

-- Linking Courses to Faculty
CREATE TABLE CourseFaculty (
    UserID INT NOT NULL,
    CourseID INT NOT NULL,
    PRIMARY KEY (UserID, CourseID),
    FOREIGN KEY (UserID) REFERENCES Faculty(UserID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);

-- Enrollments Table
CREATE TABLE Enrollments (
    EnrollmentID VARCHAR(36) PRIMARY KEY,
    StudentID INT NOT NULL,
    CourseID INT NOT NULL,
    Semester ENUM('Spring', 'Fall') NOT NULL,
    Grade ENUM('A+', 'A', 'B+', 'B', 'C+', 'C', 'D+', 'D', 'F') DEFAULT NULL,
    EnrollmentDate DATE NOT NULL,
    FOREIGN KEY (StudentID) REFERENCES Students(UserID) ON DELETE CASCADE,
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID) ON DELETE CASCADE
);

-- Audit Trail
CREATE TABLE AuditTrail (
    AuditID INT AUTO_INCREMENT PRIMARY KEY,
    UserID INT,
    Action VARCHAR(255),
    ActionDate DATETIME,
    FOREIGN KEY (UserID) REFERENCES Users(UserID)
);

CREATE INDEX IX_AuditTrail_UserID ON AuditTrail(UserID);
CREATE INDEX IX_AuditTrail_ActionDate ON AuditTrail(ActionDate);

-- Stored Procedure for Enrolling a Student
DELIMITER //

CREATE PROCEDURE sp_EnrollStudent(
    IN StudentID INT,
    IN CourseID INT,
    IN Semester ENUM('Spring', 'Fall')
)
BEGIN
    DECLARE CurrentEnrollment INT DEFAULT 0;
    DECLARE MaxEnrollment INT DEFAULT 0;

    -- Get current enrollment count
    SELECT COUNT(*) INTO CurrentEnrollment
    FROM Enrollments
    WHERE Enrollments.CourseID = CourseID AND Enrollments.Semester = Semester;

    -- Get maximum enrollment allowed
    SELECT MaxEnrollment INTO MaxEnrollment
    FROM Courses
    WHERE Courses.CourseID = CourseID;

    -- Check if capacity allows enrollment
    IF CurrentEnrollment < MaxEnrollment THEN
        INSERT INTO Enrollments (EnrollmentID, StudentID, CourseID, Semester, EnrollmentDate)
        VALUES (UUID(), StudentID, CourseID, Semester, CURDATE());
    ELSE
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Course is full';
    END IF;
END //

DELIMITER ;
