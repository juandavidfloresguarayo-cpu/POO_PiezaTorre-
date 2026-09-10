#include <iostream>
#include <string>

using namespace std;

class Rook
{
private:
	int row;
	int column;
	bool isBlack;

		bool validateMovement(int newRow, int newCol)
	{
		
		if (newCol == column && newRow != row)
		{
			return true;
		}

		
		if (newRow == row && newCol != column)
		{
			return true;
		}

		
		return false;
	}

public:

	
	Rook(bool black, int initialRow, int initialColumn)
	{
		isBlack = black;
		row = initialRow;
		column = initialColumn;
	}

	

	int getRow()
	{
		return row;
	}

	int getColumn()
	{
		return column;
	}

	bool getIsBlack()
	{
		return isBlack;
	}

	

	void setRow(int newRow)
	{
		if (newRow >= 1 && newRow <= 8)
		{
			row = newRow;
		}
		else
		{
			cout << "Error: la fila debe estar entre 1 y 8."
				<< endl;
		}
	}

	void setColumn(int newColumn)
	{
		if (newColumn >= 1 && newColumn <= 8)
		{
			column = newColumn;
		}
		else
		{
			cout << "Error: la columna debe estar entre 1 y 8."
				<< endl;
		}
	}

	void setIsBlack(bool black)
	{
		isBlack = black;
	}

	

	bool move(int newRow, int newCol)
	{
		
		if (newRow < 1 || newRow > 8 ||
			newCol < 1 || newCol > 8)
		{
			cout << "Error: la posicion debe estar entre 1 y 8."
				<< endl;

			return false;
		}

		
		if (validateMovement(newRow, newCol))
		{
			row = newRow;
			column = newCol;

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
		if (isBlack)
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

		if (isBlack)
		{
			cout << " Black";
		}
		else
		{
			cout << " White";
		}

		cout << " at Row: " << row
			<< ", Col: " << column << endl;
	}
};


int main()
{
	
	Rook whiteRook(false, 1, 1);
	Rook blackRook(true, 8, 8);

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
