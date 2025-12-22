#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm(target, 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    (void)other;
    return *this;
}

void ShrubberyCreationForm::executeAction(void) const {
    std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (!ofs)
        return;
    ofs << "       _-_\n";
    ofs << "    /~~   ~~\\\n";
    ofs << " /~~         ~~\\\n";
    ofs << "{               }\n";
    ofs << " \\  _-     -_  /\n";
    ofs << "   ~  \\\\ //  ~\n";
    ofs << "_- -   | | _- _\n";
    ofs << "  _ -  | |   -_\n";
    ofs << "      // \\\\" << "\n";
    ofs.close();
}
