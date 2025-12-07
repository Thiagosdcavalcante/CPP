#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"
#include "includes/tests.hpp"

void invalidSituationsForBuroucrats(void)
{
    std::cout << BRIGHT_CYAN "========= Situação inválida =========" RESET << std::endl;
    try {
        std::cout << BRIGHT_CYAN "=== Teste 1: criar Form com grade para assinar = 0 (muito alto) === " RESET << std::endl;
        Form invalidForm1("Falta1", 0, 50);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Teste 2: criar Form com grade para assinar = 151 (muito baixo) === " RESET << std::endl;
        Form invalidForm2("Falta2", 151, 50);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Teste 3: tentar assinar com burocrata de baixa autoridade === " RESET << std::endl;
        Form needSign("Contrato", 10, 10);
        Bureaucrat low("Trabalhador", 50);
        needSign.beSigned(low);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Teste 4: criar Form com grau de execução inválido (0) === " RESET << std::endl;
        Form invalidForm3("Executar", 50, 0);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
    std::cout << BRIGHT_CYAN "=== Teste 5: assinar repetidamente até alcançar limite === " RESET << std::endl;

    Form progressive("Progressivo", 2, 2);
    Bureaucrat signer("Chefe", 50);
    std::cout << progressive << std::endl;

    for (; signer.getGrade() >= 1;) {
        try {
            progressive.beSigned(signer);
            break;
        } catch (const std::exception &e) {
            // tentar melhorar o grade do bureaucrat para conseguir assinar
            try { signer.upGrade(); } catch (...) { break; }
        }
    }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void validSituationsForBuroucrats(void)
{
    std::cout << BRIGHT_CYAN "========= Situações válidas =========" RESET << std::endl;
    std::cout << BRIGHT_CYAN "=== Teste 1: assinar com autoridade suficiente === " RESET << std::endl;
    Form report("Relatório", 50, 25);
    Bureaucrat manager("Gerente", 40);
    std::cout << report << std::endl;
    try {
        report.beSigned(manager);
        std::cout << BRIGHT_CYAN "Assinatura realizada com sucesso." RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    Form *permit = NULL;
    try {
    std::cout << BRIGHT_CYAN "=== Teste 2: assinar com exatamente o grau necessário === " RESET << std::endl;
    permit = new Form("Permissão", 50, 50);
    Bureaucrat exact("Exato", 50);
    std::cout << *permit << std::endl;
    try {
        permit->beSigned(exact);
        std::cout << BRIGHT_CYAN "Assinatura realizada com exatamente o grau necessário." RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    }
    std::cout << BRIGHT_CYAN "=== Teste 3: cópia do formulário assinado === " RESET << std::endl;
    if (permit)
    {
        Form copyForm(*permit);
        std::cout << copyForm << std::endl;
        delete permit;
    }
    else
    {
        std::cout << BRIGHT_RED "Não foi possível criar o formulário 'permit' para copiar." RESET << std::endl;
    }
}
