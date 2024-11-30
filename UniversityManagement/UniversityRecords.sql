-- Drop existing database if it exists and create a fresh one
DROP DATABASE IF EXISTS UniversityRecords;
CREATE DATABASE UniversityRecords;
USE UniversityRecords;

-- Create Users table to store general user details
CREATE TABLE Users (
    UserID INT AUTO_INCREMENT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    DateOfBirth DATE NOT NULL,
    Email VARCHAR(100) UNIQUE NOT NULL,
    Password VARCHAR(255) NOT NULL,
    Role ENUM('student', 'faculty', 'admin') NOT NULL DEFAULT 'student'
);

-- Create Admin table linked to Users
CREATE TABLE Admin (
    AdminID INT PRIMARY KEY,
    FOREIGN KEY (AdminID) REFERENCES Users(UserID) ON DELETE CASCADE
);

-- Create Students table linked to Users
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    Major ENUM('Computer Science', 'Business Administration', 'Computer Engineering', 'Mechanical Engineering', 'Electrical Engineering', 'Mechatronics') NOT NULL,
    EnrollmentDate DATE NOT NULL,
    FOREIGN KEY (StudentID) REFERENCES Users(UserID) ON DELETE CASCADE
);

-- Create Faculty table linked to Users
CREATE TABLE Faculty (
    FacultyID INT PRIMARY KEY,
    AppointmentDate DATE NOT NULL DEFAULT CURRENT_DATE(),
    Department ENUM('CSIS', 'Humanities', 'Engineering') NOT NULL,
    FOREIGN KEY (FacultyID) REFERENCES Users(UserID) ON DELETE CASCADE
);

-- Create Courses table
CREATE TABLE Courses (
    CourseID INT AUTO_INCREMENT PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL,
    Credits INT NOT NULL,
    Semester ENUM('Spring', 'Fall') NOT NULL DEFAULT 'Spring',
    MaxEnrollment INT NOT NULL DEFAULT 30,
    Availability ENUM('true', 'false')
);

CREATE TABLE `coursematerials` (
  `MaterialID` int(11) NOT NULL,
  `CourseID` int(11) NOT NULL,
  `MaterialName` varchar(255) NOT NULL,
  `MaterialType` enum('File','Link','Video','Book') NOT NULL,
  `MaterialSource` text NOT NULL,
  `MaterialDescription` text DEFAULT NULL,
  `UploadDate` datetime DEFAULT current_timestamp(),
  `UploadedBy` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Create Enrollments table to link Students and Courses
CREATE TABLE Enrollments (
    EnrollmentID INT AUTO_INCREMENT PRIMARY KEY,
    StudentID INT NOT NULL,
    CourseID INT NOT NULL,
    Semester ENUM('Spring', 'Fall') NOT NULL DEFAULT 'Spring',
    Grade ENUM('A+', 'A', 'B+', 'B', 'C+', 'C', 'D+', 'D', 'E', 'F'),
    EnrollmentDate DATE NOT NULL DEFAULT CURRENT_DATE(),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE CASCADE,
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID) ON DELETE CASCADE
);

-- Create CourseFaculty table to assign faculty to courses
CREATE TABLE CourseFaculty (
    FacultyCourseID INT AUTO_INCREMENT PRIMARY KEY,
    FacultyID INT NOT NULL,
    CourseID INT NOT NULL,
    FOREIGN KEY (FacultyID) REFERENCES Faculty(FacultyID) ON DELETE CASCADE,
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID) ON DELETE CASCADE
);

-- Create Prerequisites table to define course dependencies
CREATE TABLE Prerequisites (
    CourseID INT NOT NULL,
    PrerequisiteID INT NOT NULL,
    PRIMARY KEY (CourseID, PrerequisiteID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID) ON DELETE CASCADE,
    FOREIGN KEY (PrerequisiteID) REFERENCES Courses(CourseID) ON DELETE CASCADE
);

-- Create Schedule table for course timings
CREATE TABLE Schedule (
    ScheduleID INT AUTO_INCREMENT PRIMARY KEY,
    CourseID INT NOT NULL,
    StartTime TIME NOT NULL,
    EndTime TIME NOT NULL,
    Day ENUM('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday') NOT NULL,
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID) ON DELETE CASCADE
);

-- Create Payments table for managing student payments
CREATE TABLE Payments (
    PaymentID INT AUTO_INCREMENT PRIMARY KEY,
    StudentID INT NOT NULL,
    Semester ENUM('Spring', 'Fall') NOT NULL DEFAULT 'Spring',
    TotalAmount DECIMAL(10, 2),
    PaidAmount DECIMAL(10, 2),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID) ON DELETE CASCADE
);

-- Audit Trail
CREATE TABLE AuditTrail (
    AuditID INT AUTO_INCREMENT PRIMARY KEY,
    UserID INT,
    Action VARCHAR(255),
    Timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    Details TEXT,
    FOREIGN KEY (UserID) REFERENCES Users(UserID)
);

-- Indexes for AuditTrail
CREATE INDEX IX_AuditTrail_UserID ON AuditTrail(UserID);
CREATE INDEX IX_AuditTrail_Timestamp ON AuditTrail(Timestamp);

-- Stored Procedure for Enrolling a Student
DELIMITER //

CREATE PROCEDURE sp_EnrollStudent(
    IN StudentID INT,
    IN CourseID INT,
    IN Semester VARCHAR(10) -- Changed to VARCHAR
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
        INSERT INTO Enrollments (StudentID, CourseID, Semester, EnrollmentDate)
        VALUES (StudentID, CourseID, Semester, CURDATE());
    ELSE
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Course is full';
    END IF;
END //

DELIMITER ;
