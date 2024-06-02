#include "Menu_Principal.h"
#include "Creditos.h"

using namespace TareaAcademica;


int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Creditos^ creditosForm = gcnew Creditos();
	Menu_Principal^ menuPrincipalForm = gcnew Menu_Principal();

	creditosForm->Show();
	menuPrincipalForm->Show();
	Application::Run();
}