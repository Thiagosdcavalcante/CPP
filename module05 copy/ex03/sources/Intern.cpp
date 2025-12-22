#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

typedef AForm* (*FormCreator)(const std::string &);

static AForm* createShrub(const std::string &t) { return new ShrubberyCreationForm(t); }
static AForm* createRobo(const std::string &t) { return new RobotomyRequestForm(t); }
static AForm* createPres(const std::string &t) { return new PresidentialPardonForm(t); }

Intern::Intern(void) {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

Intern::~Intern(void) {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    struct Entry { const char *name; FormCreator fn; };

    Entry table[] = {
        {"shrubbery creation", &createShrub},
        {"robotomy request", &createRobo},
        {"presidential pardon", &createPres},
        {"pedido de robotomia", &createRobo},
        {NULL, NULL}
    };

    for (int i = 0; table[i].name != NULL; ++i) {
        if (formName == table[i].name) {
            AForm *form = table[i].fn(target);
            std::cout << "Intern cria " << formName << std::endl;
            return form;
        }
    }
    std::cerr << "Intern: formulário desconhecido '" << formName << "'" << std::endl;
    return NULL;
}
