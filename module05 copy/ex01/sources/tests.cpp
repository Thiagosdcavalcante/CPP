#include "../includes/tests.hpp"
#include "../includes/Colors.hpp"
#include <iostream>

void invalidFormTests(void)
{
    std::cout << CLR_HEADER << "========= Testes inválidos de Form =========" << CLR_RESET << std::endl;
    try {
        std::cout << "Teste 1: construir Form com gradeToSign = 0" << std::endl;
        Form f1("F1", 0, 50);
        (void)f1;
    } catch (std::exception &e) {
    std::cerr << CLR_ERROR << e.what() << CLR_RESET << std::endl;
    }
    try {
        std::cout << "Teste 2: construir Form com gradeToSign = 151" << std::endl;
        Form f2("F2", 151, 50);
        (void)f2;
    } catch (std::exception &e) {
    std::cerr << CLR_ERROR << e.what() << CLR_RESET << std::endl;
    }
    try {
        std::cout << "Teste 3: construir Form com gradeToExecute = 0" << std::endl;
        Form f3("F3", 50, 0);
        (void)f3;
    } catch (std::exception &e) {
    std::cerr << CLR_ERROR << e.what() << CLR_RESET << std::endl;
    }
    try {
        std::cout << "Teste 4: construir Form com gradeToExecute = 151" << std::endl;
        Form f4("F4", 50, 151);
        (void)f4;
    } catch (std::exception &e) {
    std::cerr << CLR_ERROR << e.what() << CLR_RESET << std::endl;
    }
    try {
        std::cout << "Teste 5: assinar com burocrata de baixa autoridade" << std::endl;
        Form f5("Contrato", 10, 10);
        Bureaucrat low("Trabalhador", 50);
        std::cout << f5 << std::endl;
        f5.beSigned(low);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << CLR_DIM << "============================================" << CLR_RESET << std::endl;
}

void validFormTests(void)
{
    std::cout << CLR_HEADER << "========= Testes válidos de Form =========" << CLR_RESET << std::endl;
    try {
        std::cout << "Teste 1: assinar com autoridade suficiente" << std::endl;
        Form r1("Relatorio", 50, 25);
        Bureaucrat manager("Gerente", 40);
        std::cout << r1 << std::endl;
        manager.signForm(r1);
        std::cout << r1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << CLR_ERROR << e.what() << CLR_RESET << std::endl;
    }
    try {
        std::cout << "Teste 2: assinar com exatamente o grau necessário" << std::endl;
        Form p1("Permissao", 50, 50);
        Bureaucrat exact("Exato", 50);
        std::cout << p1 << std::endl;
        exact.signForm(p1);
        std::cout << p1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << CLR_ERROR << e.what() << CLR_RESET << std::endl;
    }
    try {
        std::cout << "Teste 3: cópia do formulário assinado" << std::endl;
        Form original("Original", 75, 75);
        Bureaucrat signer("Assinante", 50);
        signer.signForm(original);
        Form copia(original);
        std::cout << copia << std::endl;
    } catch (std::exception &e) {
        std::cerr << CLR_ERROR << e.what() << CLR_RESET << std::endl;
    }

    std::cout << CLR_SUCCESS << "==========================================" << CLR_RESET << std::endl;
}
