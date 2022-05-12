#include <iostream>;
#include <string>;
#include <fstream>;

using namespace std;

struct Cita {
	string nom, numc, trt, desc, hora;
	float precio = 0, cantidad = 0, total = 0;
	Cita* sig = nullptr;
	Cita* ant = nullptr;
};

int numact = 1, numpac = 0;
Cita* pcita = nullptr;
Cita* ucita = nullptr;
Cita* acita = nullptr;

void imprimir_cita(Cita*);
void agendar_cita(string, string, string, float, float, float);
Cita modificar_cita(Cita, int);
Cita eliminar_cita(Cita, int);
void citas_vigentes();

int main() {
	string nom, numc, trt, desc, hora;
	float precio = 0, cantidad = 0, total = 0;
	int op = 0;
	string vac;
	char Y_N = ' ';

	ifstream citas_guardadas;

	citas_guardadas.open("Citas_Dentales");


	while (true) {		
		cout << "Escoja una de las siguientes opciones:\n1 Agendar cita\n2 Modificar cita\n3 Eliminar cita\n4 Lista de citas vigentes\n5 Salir" << endl;
		cin >> op;
		system("cls");

		//En caso de que se ingrese algo que no fuese un numero se limpia antes de verificar la opcion
		cin.clear(); 
		getline(cin, vac);

		switch (op) {
		case 1:
			cout << "Ingrese el nombre completo del paciente: ";
			cin.ignore();
			getline(cin, nom);

			cout << "Ingrese la hora de la cita en formato de 24 horas: ";
			cin >> hora;

			cout << "Ingrese que tratamiento se realizara: ";
			cin.ignore();
			getline(cin, trt);

			cout << "Describa el tratamiento: ";
			getline(cin, desc);

			cout << "Cuanto sera el precio unitario? ";
			cin >> precio;

			cout << "Cuanto sera la cantidad del tratamiento? ";
			cin >> cantidad;
			total = precio * cantidad;
			
			agendar_cita(nom, hora, trt, desc, precio, cantidad, total);
			system("pause");
			system("cls");
			break;

		case 2:
			cout << 2;
			system("pause");
			system("cls");
			break;

		case 3:
			cout << 3;
			system("pause");
			system("cls");
			break;

		case 4:
			cout << 4;
			system("pause");
			system("cls");
			break;

		case 5:
			cout << "Teclee 'Y' o 'y' para salir" << endl;
			cin >> Y_N;
			if (Y_N == 'Y' || Y_N == 'y') {
				cout << "Gracias por utilizar este programa :)" << endl;

				exit(0);
			}
			system("cls");
			break;

		default:
			cout << "No ingreso una opcion valida" << endl;
			break;
		};
	}


}

void imprimir_cita(Cita* imp) {
	cout << "Cita #" << imp->numc << "\nNombre : " << imp->nom << endl << "Hora : " << imp->hora << endl << "Tratamiento : " << imp->trt << endl << "Descripcion : " << imp->desc << endl << "Precio : " << imp->precio << endl << "Cantidad : " << imp->cantidad << endl << "Total : " << imp->total << endl;
}

void agendar_cita(string nom, string hora, string trt, string desc, float precio, float cantidad, float total) {
	
	Cita* ncita = new Cita;

	ncita->nom = nom;
	ncita->trt = trt;
	ncita->hora = hora;
	ncita->desc = desc;
	ncita->total = total;
	ncita->precio = precio;
	ncita->cantidad = cantidad;
	ncita->numc = to_string(numact);

	cout << endl << "Se ha guardado la cita con los siguientes datos:" << endl;
	imprimir_cita(ncita);
	
	if (numact == 1) {
		pcita = ncita;
		ucita = ncita;
	}
	else {
		ncita->ant = ucita;
		ucita->sig = ncita;
		ucita = ncita;
	}

	numact++;

}

Cita modificar_cita(Cita act, int numpac) {
	int op = 0;
	cout << "Ha elegido la cita con los siguientes datos:\nNombre: " << act.nom << endl << "Hora: " << act.hora << endl << "Tratamiento: " << act.trt << endl << "Descripcion: " << act.desc << endl << "Precio: " << act.precio << endl << "Cantidad: " << act.cantidad << endl << "Total: " << act.total << endl;
	cout << "Escoja una opcion que quiera modificar:\n1 Nombre\n2 Hora\n3 Tratamiento\n4 Descripcion\n5 Tratamiento y Descripcion\n6 Precio\n7 Cantidad\n8 No modificar" << endl;
	cin >> op;
	switch (op) {
	case 1:
		cout << "Ingrese el nombre completo del paciente" << endl;
		cin.ignore();
		getline(cin, act.nom);
		break;
	case 2:
		cout << "Ingrese la nueva hora de la cita en formato de 24 horas" << endl;
		cin.ignore();
		cin >> act.hora;
		break;
	case 3:
		cout << "Ingrese el nuevo tratamiento se realizara:" << endl;
		cin.ignore();
		getline(cin, act.trt);
		break;
	case 4:
		cout << "Describa lo que se realizara en el tratamiento:" << endl;
		cin.ignore();
		getline(cin, act.desc);
		break;
	case 5:
		cout << "Ingrese el nuevo tratamiento se realizara:" << endl;
		cin.ignore();
		getline(cin, act.trt);
		cout << "Describa lo que se realizara en el tratamiento:" << endl;
		getline(cin, act.desc);
		break;
	case 6:
		cout << "Cuanto sera el precio unitario?" << endl;
		cin >> act.precio;
		act.total = act.precio * act.cantidad;
		break;
	case 7:
		cout << "Cuanto sera la cantidad del tratamiento?" << endl;
		cin >> act.cantidad;
		act.total = act.precio * act.cantidad;
		break;
	case 8:
		break;
	default:
		cout << op << " no es una opcion valida" << endl << endl;
	};
	if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6 || op == 7) {
		cout << endl << "Los nuevos datos de la cita " << numpac << " son:\nNombre: " << act.nom << endl << "Hora : " << act.hora << endl << "Tratamiento : " << act.trt << endl << "Descripcion : " << act.desc << endl << "Precio : " << act.precio << endl << "Cantidad : " << act.cantidad << endl << "Total : " << act.total << endl << endl;
	}
	else if (op == 8) {
		cout << "Los datos no se modificaron" << endl;
	}
	return act;
}

Cita eliminar_cita(Cita act, int numpac) {
	cout << "Ha elegido eleminar la cita " << numpac << " con los siguientes datos : \nNombre : " << act.nom << endl << "Hora : " << act.hora << endl << "Tratamiento : " << act.trt << endl << "Descripcion : " << act.desc << endl << "Precio : " << act.precio << endl << "Cantidad : " << act.cantidad << endl << "Total : " << act.total << endl;
	act.nom = " ";
	act.hora = "";
	act.trt = "";
	act.desc = "";
	act.precio = 0;
	act.cantidad = 0;
	act.total = 0;
	cout << "La cita " << numpac << " ha sido eliminada" << endl << endl;
	return act;
}

void citas_vigentes() {
	
	if (!pcita) {
		cout << "No hay citas vigentes";
	}
	else {
		acita = pcita;
		while (acita) {
			imprimir_cita(acita);
			acita = acita->sig;
		}
	}
}