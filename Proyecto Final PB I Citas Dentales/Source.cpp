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

string nom, trt, desc, hora, vac;
float precio = 0, cantidad = 0, total = 0;
int numact = 1, numpac = 0;

Cita* pcita = nullptr;
Cita* ucita = nullptr;
Cita* acita = nullptr;

void imprimir_cita(Cita*);
void agendar_cita(string, string, string, string, float, float, float);
void modificar_cita(int);
void eliminar_cita(int);
void citas_vigentes();
void guardar_citas();
void leer_citas();

int main() {
	
	leer_citas();

	int op = 0;
	char Y_N = ' ';

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
			getline(cin, nom);

			cout << "Ingrese la hora de la cita en formato de 24 horas (Por ejemplo 13:00): ";
			cin >> hora;

			cout << "Ingrese como se llama tratamiento se realizara: ";
			cin.ignore();
			getline(cin, trt);

			cout << "Describa el tratamiento: ";
			getline(cin, desc);

			cout << "Cuanto sera el precio unitario? ";
			cin >> precio;

			cout << "Cual sera la cantidad del tratamiento? ";
			cin >> cantidad;
			total = precio * cantidad;
			
			system("cls");
			
			agendar_cita(nom, hora, trt, desc, precio, cantidad, total);

			cout << "Se ha guardado la cita con los siguientes datos:" << endl;
			imprimir_cita(ucita);

			system("pause");
			system("cls");
			break;

		case 2:

			citas_vigentes();

			if (pcita) {
				cout << "Ingrese el numero de la cita que desea modificar o cualquier letra para regresar al menu principal: ";
				cin >> numpac;

				cin.clear();
				getline(cin, vac);
				
				system("cls");

				modificar_cita(numpac);

			}

			system("pause");

			system("cls");

			break;

		case 3:

			citas_vigentes();
			
			if (pcita) {
				cout << "Ingrese el numero de la cita que desea eliminar o cualquier letra para regresar al menu principal: ";
				cin >> numpac;

				cin.clear();
				getline(cin, vac);

				eliminar_cita(numpac);
			
			}

			system("pause");

			system("cls");

			break;

		case 4:

			citas_vigentes();

			system("pause");

			system("cls");

			break;

		case 5:

			cout << "Teclee 'Y' o 'y' para salir" << endl;
			cin >> Y_N;

			if (Y_N == 'Y' || Y_N == 'y') {

				system("cls");

				guardar_citas();

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
	
	cout << "Cita #" << imp->numc << "\nNombre : " << imp->nom << endl << "Hora : " << imp->hora << endl << "Tratamiento : " << imp->trt << endl << "Descripcion : " << imp->desc << endl << "Precio : " << imp->precio << endl << "Cantidad : " << imp->cantidad << endl << "Total : " << imp->total << endl << endl;

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

void modificar_cita(int numc) {
	
	int op = 0;
	acita = pcita;

	while (acita) {
		if (stoi(acita->numc) == numc) {
			cout << "Eligio la cita con los siguientes datos: " << endl;
			imprimir_cita(acita);
			cout << "Escriba el numero de lo que quiera modificar:\n1 Nombre\n2 Hora\n3 Tratamiento\n4 Descripcion\n5 Tratamiento y Descripcion\n6 Precio\n7 Cantidad\n8 No modificar" << endl;
			cin >> op;

			cin.clear();
			getline(cin, vac);
			
			system("cls");

			switch (op) {
			case 1:
				cout << "Ingrese el nombre completo del paciente" << endl;
				getline(cin, acita->nom);
				break;

			case 2:
				cout << "Ingrese la nueva hora de la cita en formato de 24 horas" << endl;
				cin >> acita->hora;
				break;

			case 3:
				cout << "Ingrese el nuevo tratamiento se realizara:" << endl;
				getline(cin, acita->trt);
				break;

			case 4:
				cout << "Describa lo que se realizara en el tratamiento:" << endl;
				getline(cin, acita->desc);
				break;

			case 5:
				cout << "Ingrese el nuevo tratamiento se realizara:" << endl;
				getline(cin, acita->trt);
				cout << "Describa lo que se realizara en el tratamiento:" << endl;
				getline(cin, acita->desc);
				break;

			case 6:
				cout << "Cuanto sera el precio unitario?" << endl;
				cin >> acita->precio;
				acita->total = acita->precio * acita->cantidad;
				break;

			case 7:
				cout << "Cuanto sera la cantidad del tratamiento?" << endl;
				cin >> acita->cantidad;
				acita->total = acita->precio * acita->cantidad;
				break;

			case 8:
				break;
			default:
				cout << "No ingreso una opcion valida" << endl;
			};

			system("cls");

			if (op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6 || op == 7) {
				cout << "Los nuevos datos de la cita son:" << endl;
				imprimir_cita(acita);
			}
			else if (op == 8) {
				cout << "Los datos no se modificaron" << endl;
			}
			break;
		}
		else {
			acita = acita->sig;
		}

	}
}

void eliminar_cita(int numc) {
	
	acita = pcita;

	while (acita) {
		if (stoi(pcita->numc) == numc) {
			if (pcita->sig != nullptr) {
				pcita = acita->sig;
				acita->sig->ant = nullptr;
			}
			else {
				pcita = nullptr;
			}
			delete acita;
			acita = nullptr;
		}
		else if (stoi(ucita->numc) == numc) {
			ucita = acita->ant;
			acita->ant->sig = nullptr;
			delete acita;
			acita = nullptr;
		}
		else if (stoi(acita->numc) == numc) {
			acita->sig->ant = acita->ant;
			acita->ant->sig = acita->sig;
			delete acita;
			acita = nullptr;
		}			
		else {
			acita = acita->sig;
		}

	}

}

void citas_vigentes() {
	
	if (!pcita) {
		cout << "No hay citas vigentes" << endl;
	}
	else {
		acita = pcita;
		while (acita) {
			imprimir_cita(acita);
			acita = acita->sig;
		}
	}

}

void guardar_citas() {
	
	ofstream citas_guardadas;
	citas_guardadas.open("Citas_Dentales");

	if (citas_guardadas) {
		acita = pcita;
		while (acita) {
			citas_guardadas << acita->nom << endl;
			citas_guardadas << acita->hora << endl;
			citas_guardadas << acita->trt << endl;
			citas_guardadas << acita->desc << endl;
			citas_guardadas << acita->precio << endl;
			citas_guardadas << acita->cantidad << endl;
			citas_guardadas << acita->total << endl;

			acita = acita->sig;
		}

		citas_guardadas.close();
	}
}

void leer_citas() {

	ifstream leer_citas_guardadas;

	leer_citas_guardadas.open("Citas_Dentales");

	if (leer_citas_guardadas) {
		numpac = 1;
		string leer;

		while (getline(leer_citas_guardadas, leer)) {
			if (numpac == 1) {
				nom = leer;
				numpac++;
			}
			else if (numpac == 2) {
				hora = leer;
				numpac++;
			}
			else if (numpac == 3) {
				trt = leer;
				numpac++;
			}
			else if (numpac == 4) {
				desc = leer;
				numpac++;
			}
			else if (numpac == 5) {
				precio = stof(leer);
				numpac++;
			}
			else if (numpac == 6) {
				cantidad = stof(leer);
				numpac++;
			}
			else {
				agendar_cita(nom, hora, trt, desc, precio, cantidad, stof(leer));
				numpac = 1;
			}
		}
	}

}