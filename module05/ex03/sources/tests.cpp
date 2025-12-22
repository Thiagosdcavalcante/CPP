#include "../includes/Intern.hpp"
#include "../includes/Colors.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

static bool fileExists(const std::string &name) {
    std::ifstream f(name.c_str());
    return f.good();
}

void runAllTests(void) {
    std::cout << CLR_HEADER << "=== ex03: testes do Intern e formulários ===" << CLR_RESET << std::endl;

    // Teste 1: Criação de Shrubbery, assinatura e execução
    std::cout << CLR_INFO << "Teste 1: Criação de Shrubbery" << CLR_RESET << std::endl;
    Intern i;
    AForm *sh = i.makeForm("shrubbery creation", "casa_test");
    if (sh) {
        Bureaucrat signer("Signer", 140);
        signer.signForm(*sh);
        Bureaucrat executor("Executor", 137);
        executor.executeForm(*sh);
        std::string fname = std::string("casa_test_shrubbery");
        if (fileExists(fname))
            std::cout << CLR_SUCCESS << "Arquivo criado: " << fname << CLR_RESET << std::endl;
        else
            std::cout << CLR_ERROR << "Falha: arquivo não encontrado: " << fname << CLR_RESET << std::endl;
        delete sh;
    }

    // Test 2: Robotomy: low grade fail to sign, high grade sign and execute multiple times
    std::cout << CLR_INFO << "Teste 2: Robotomy - várias tentativas" << CLR_RESET << std::endl;
    AForm *rr = i.makeForm("robotomy request", "Bender_test");
    if (rr) {
        Bureaucrat low("Low", 100);
        low.signForm(*rr);
        Bureaucrat high("High", 1);
        high.signForm(*rr);
        for (int k = 0; k < 3; ++k)
            high.executeForm(*rr);
        delete rr;
    }

    // Test 3: Presidential pardon
    std::cout << CLR_INFO << "Teste 3: Perdão presidencial" << CLR_RESET << std::endl;
    AForm *pp = i.makeForm("presidential pardon", "Marvin_test");
    if (pp) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*pp);
        boss.executeForm(*pp);
        delete pp;
    }

    // Teste 4: Formulário desconhecido
    std::cout << CLR_INFO << "Teste 4: Formulário desconhecido" << CLR_RESET << std::endl;
    AForm *unk = i.makeForm("form xyz", "target");
    if (!unk)
        std::cout << CLR_SUCCESS << "Comportamento correto ao tentar criar form desconhecido" << CLR_RESET << std::endl;

    // Teste 5: Alias em PT-BR
    std::cout << CLR_INFO << "Teste 5: Alias PT-BR (pedido de robotomia)" << CLR_RESET << std::endl;
    AForm *r2 = i.makeForm("pedido de robotomia", "Bender_br");
    if (r2) {
        Bureaucrat h("H", 1);
        h.signForm(*r2);
        h.executeForm(*r2);
        delete r2;
    }

    std::cout << CLR_HEADER << "=== fim dos testes ex03 ===" << CLR_RESET << std::endl;
}
