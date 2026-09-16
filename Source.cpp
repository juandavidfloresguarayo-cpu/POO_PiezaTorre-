#include <iostream>
#include <string>

using namespace std;

class Torre
{
private:
	
	bool esNegro;

		bool validateMovement(int newFil, int newCol)
	{
		
		if (newCol == columna && newFil != fila)
		{
			return true;
		}

		
		if (newFil == fila && newCol != columna)
		{
			return true;
		}

		
		return false;
	}

public:
	short fila;
	short columna;
	
	Torre(bool black, int initialRow, int initialColumn)
	{
		esNegro = black;
		fila = initialRow;
		columna = initialColumn;
	}

	

	int getFila()
	{
		return fila;
	}

	int getColumna()
	{
		return columna;
	}

	bool getEsNegro()
	{
		return esNegro;
	}

	

	void setFila(int newFila)
	{
		if (newFila >= 1 && newFila <= 8)
		{
			fila = newFila;
		}
		else
		{
			cout << "Error: la fila debe estar entre 1 y 8."
				<< endl;
		}
	}

	void setColumn(int newColumna)
	{
		if (newColumna >= 1 && newColumna <= 8)
		{
			columna = newColumna;
		}
		else
		{
			cout << "Error: la columna debe estar entre 1 y 8."
				<< endl;
		}
	}

	void setEsNegro(bool Negro)
	{
		esNegro = Negro;
	}

	

	bool move(int newFila, int newColumna)
	{
		
		if (newFila < 1 || newFila > 8 ||
			newColumna < 1 || newColumna > 8)
		{
			cout << "Error: la posicion debe estar entre 1 y 8."
				<< endl;

			return false;
		}

		
		if (validateMovement(newFila, newColumna))
		{
			fila = newFila;
			columna = newColumna;

			cout << "Movimiento valido." << endl;

			return true;
		}
		else
		{
			cout << "Error: movimiento invalido." << endl;
			cout << "La torre solo puede moverse horizontal "
				<< "o verticalmente." << endl;

			return false;
		}
	}

	

	string draw()
	{
		if (esNegro)
		{
			return "[##]";
		}
		else
		{
			return "[TT]";
		}
	}

	

	void printState()
	{
		cout << draw();

		if (esNegro)
		{
			cout << " Black";
		}
		else
		{
			cout << " White";
		}

		cout << " at Row: " << fila
			<< ", Col: " << columna << endl;
	}
};


int main()
{
	
	Torre whiteRook(false, 1, 1);
	Torre blackRook(true, 8, 8);

	cout << "===== ESTADO INICIAL =====" << endl;

	cout << "Torre blanca: ";
	whiteRook.printState();

	cout << "Torre negra: ";
	blackRook.printState();


	

	int newRow;
	int newCol;
	bool movimientoValido = false;

	cout << "\n===== TORRE BLANCA =====" << endl;

	
	while (!movimientoValido)
	{
		cout << "\nIngrese nueva fila (1-8): ";
		cin >> newRow;

		cout << "Ingrese nueva columna (1-8): ";
		cin >> newCol;

		movimientoValido = whiteRook.move(newRow, newCol);
	}

	cout << "\nEstado final de la torre blanca:" << endl;
	whiteRook.printState();


	

	movimientoValido = false;

	cout << "\n===== TORRE NEGRA =====" << endl;

	while (!movimientoValido)
	{
		cout << "\nIngrese nueva fila (1-8): ";
		cin >> newRow;

		cout << "Ingrese nueva columna (1-8): ";
		cin >> newCol;

		movimientoValido = blackRook.move(newRow, newCol);
	}

	cout << "\nEstado final de la torre negra:" << endl;
	blackRook.printState();


	return 0;
}
