#include "includes/Intern.hpp"
#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* forward declaration of test runner */
void runAllTests(void);

int main()
{
    std::srand(std::time(NULL));
    runAllTests();
    return 0;
}
