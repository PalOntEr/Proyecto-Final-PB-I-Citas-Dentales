#include <iostream>;
#include <string>
using namespace std;

struct Cita {
	string nom = "", trt = "", desc = "", hora = "";
	float precio = 0, cantidad = 0, total = 0;
};

Cita agendar_cita(int);
Cita modificar_cita(Cita, int);
Cita eliminar_cita(Cita, int);
void citas_vigentes(Cita[], int);

int main() {
	int op = 0, numpac = 0, numpacact = 0;
	Cita citas[100];

	while (op != 6) {
		cout << "Escoja una de las siguientes opciones:\n1 Agendar cita\n2 Modificar cita\n3 Eliminar cita\n4 Lista de citas vigentes\n5 Limpiar pantalla\n6 Salir" << endl;
		cin >> op;

		switch (op) {
		case 1:
			numpacact++;
			citas[numpacact] = agendar_cita(numpacact);
			system("pause");
			break;

		case 2:
			cout << "Ingrese el numero de cita del paciente" << endl;
			cin >> numpac;
			citas[numpac] = modificar_cita(citas[numpac], numpac);
			system("pause");
			break;

		case 3:
			cout << "Ingrese el numero de cita que desea eliminar" << endl;
			cin >> numpac;
			citas[numpac] = eliminar_cita(citas[numpac], numpac);
			system("pause");
			break;

		case 4:
			citas_vigentes(citas, numpacact);
			system("pause");
			break;

		case 5:
			cout << "Se limpiara la pantalla" << endl;
			system("pause");
			system("cls");
			break;

		case 6:
			cout << "Gracias por utilizar este programa :)" << endl;
			system("pause");
			exit(0);
			break;

		default:
			cout << "La opcion " << op << " no es una opcion valida" << endl;
			break;
		};
	}


}

Cita agendar_cita(int numpacact) {
	Cita c;
	cout << "Ingrese el nombre completo del paciente: ";
	cin.ignore();
	getline(cin, c.nom);
	cout << "Ingrese la hora de la cita en formato de 24 horas: ";
	cin >> c.hora;
	cout << "Ingrese que tratamiento se realizara: ";
	cin.ignore();
	getline(cin, c.trt);
	cout << "Describa el tratamiento: ";
	getline(cin, c.desc);
	cout << "Cuanto sera el precio unitario? ";
	cin >> c.precio;
	cout << "Cuanto sera la cantidad del tratamiento? ";
	cin >> c.cantidad;
	c.total = c.precio * c.cantidad;
	cout << endl << "Se ha guardado la cita con los siguientes datos:" << endl << "Numero de cita: " << numpacact << endl << "Nombre: " << c.nom << endl << "Hora: " << c.hora << endl << "Tratamiento: " << c.trt << endl << "Descripcion: " << c.desc << endl << "Precio: " << c.precio << endl << "Cantidad: " << c.cantidad << endl << "Total: " << c.total << endl << endl;
	return c;
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

void citas_vigentes(Cita citas[], int numpacact) {
	int numpac = 0, v = 0, comp = 0;

	while (numpac < numpacact) {
		numpac++;
		if (citas[numpac].nom != " ") {
			if (comp == 0) {
				cout << "Las citas vigentes son:" << endl << endl;
				comp++;
				v++;
			}
			cout << "Numero de cita: " << numpac << endl << "Nombre: " << citas[numpac].nom << endl << "Hora : " << citas[numpac].hora << endl << "Tratamiento : " << citas[numpac].trt << endl << "Descripcion : " << citas[numpac].desc << endl << "Precio : " << citas[numpac].precio << endl << "Cantidad : " << citas[numpac].cantidad << endl << "Total : " << citas[numpac].total << endl << endl;
		};

	}
	if (v == 0) {
		cout << "No hay citas vigentes" << endl;
	}
}