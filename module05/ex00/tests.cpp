#include "includes/Bureaucrat.hpp"
#include "includes/tests.hpp"

void invalidSituationsForBuroucrats(void)
{
    std::cout << BRIGHT_CYAN "========= Situação inválida =========" RESET << std::endl;
    try {
        std::cout << BRIGHT_CYAN "=== Teste 1: burocrata com grade -42 === " RESET << std::endl;
        Bureaucrat invalid1("lower", -42);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Teste 2: burocrata com grade 151 === " RESET << std::endl;
        Bureaucrat invalid2("high", 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Teste 3: tentar aumentar além do máximo === " RESET << std::endl;
        Bureaucrat invalid3("Senior", 1);
        invalid3.upGrade();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Teste 4: não pode diminuir mais === " RESET << std::endl;
        Bureaucrat invalid4("Intern", 150);
        invalid4.downGrade();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
    std::cout << BRIGHT_CYAN "=== Teste 5: ultrapassando os limites === " RESET << std::endl;

    Bureaucrat invalid5("Olívia", 50);
    std::cout << invalid5 << std::endl;

    for (; invalid5.getGrade() >= 1;) {
        invalid5.upGrade();
    }

    } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
    }
}

void validSituationsForBuroucrats(void)
{
    std::cout << BRIGHT_CYAN "========= Situações válidas =========" RESET << std::endl;
    std::cout << BRIGHT_CYAN "=== Teste 1: nível médio === " RESET << std::endl;
    Bureaucrat valid("Arthur", 50);
    std::cout << valid << std::endl;
    
    try {
    std::cout << BRIGHT_CYAN "=== Teste 2: burocrata no grau mínimo (150) === " RESET << std::endl;
    Bureaucrat john("Intern", 150);
    std::cout << john << std::endl;
    } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    }


    std::cout << BRIGHT_CYAN "=== Teste 3: reduzindo (down) a grade === " RESET << std::endl;
    valid.downGrade();
    std::cout << valid << std::endl;
    std::cout << BRIGHT_CYAN "=== Teste 4: subindo (up) até o topo === " RESET << std::endl;
    for (; valid.getGrade() > 1; ) {
    valid.upGrade();
    std::cout << valid << std::endl;
    }

    std::cout << BRIGHT_CYAN "=== Teste 5: cópia === " RESET << std::endl;
    
    Bureaucrat newMidle;
    newMidle = valid;
    std::cout << newMidle << std::endl;
}
