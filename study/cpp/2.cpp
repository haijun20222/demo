#include<iostream>
#include<cstring>
using namespace std;


class Printer 
{
public:
    static Printer* get_printer() {
        return printer;
    }
    void print_content(const char* content) {
        this->times++;
        cout << "printer content  " << content << endl;
        cout << "printer times    " <<  this->times << endl;
    }
private:
    int times;
    Printer() {
        cout << "printer start" << endl;
        this->times = 0;
    }
    Printer(const Printer&);
    static Printer* printer;
};
Printer* Printer :: printer = new Printer;

int main() {
    printf("main start....\n");
    Printer* printer = Printer::get_printer();
    printer->print_content("入职报告");
    printer->print_content("离职报告");
    return 0;
}