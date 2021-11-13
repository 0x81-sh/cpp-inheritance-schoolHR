#include <iostream>
#include "People/HeadOfDepartment.h"
#include "People/Teacher.h"
#include "People/Pupil.h"
#include "People/Person.h"

int main() {
    Person p1("Person", "Object", 123, {1, 1, 1234});
    Teacher t1("Teacher", "Object", 123, {1, 1, 1234}, 456);
    HeadOfDepartment h1("HoD", "Object", 123, {1, 1, 1234}, 456, "some department");
    Pupil s1("Pupil", "Object", 123, {1, 1, 1234}, "some class");

    std::cout << p1.toJSON() << "\n" << t1.toJSON() << "\n" << h1.toJSON() << "\n" << s1.toJSON() << "\n";

    return 0;
}
