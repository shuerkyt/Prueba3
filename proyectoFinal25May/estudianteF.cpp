#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100
using namespace std;

typedef struct{
    int dia;
    int mes;
    int año;
}fecha;

typedef struct{
    char idUca[9];
    char nombre[30];
    char apellido[30];
    int año;
    char email[100];
    fecha fechaNac;
    float promedio;
}estudiante;

estudiante students[MAX];
int lastReg=0;

/*
Create
Read
Update
Delete
*/

//Create
void addStudent(estudiante est);
/*Read*/
void showStudent(int pos);
int isStudent(char id[]);
void showStudents();
void startStudent(int pos);
estudiante getSTudent(int pos);
/*Update*/
void updateStudent(estudiante est, int pos);
/*Delete*/
void deleteStudent(int pos);

int menu();
void start();


void addStudent(estudiante est){
    students[lastReg]= est;
    lastReg++;
}

void showStudent(int pos){
    cout << "ID: " << students[pos].idUca << endl;
    cout << "NOMBRE: " << students[pos].nombre << endl;
    cout << "APELLIDOS: " << students[pos].apellido << endl;
    cout << "AÑO: " << students[pos].año << endl;
    cout << "EMAIL: " << students[pos].email << endl;
    cout << "FECHA NACIMIENTO: " << students[pos].fechaNac.dia << "/" << students[pos].fechaNac.mes << "/" << students[pos].fechaNac.año << endl;
    cout << "PROMEDIO: " << students[pos].promedio << endl;
}

estudiante getSTudent(int pos){
    return students[pos];
}

int isStudent(char id[]){
int posicion = 0;
for(int i = 0 ; i<lastReg; i++)
{
    if(strcmp(id, students[i].idUca)==0)
    {
        posicion = i;
        break;
    }
 }
 return posicion;

}

void showStudents(int pos){
  for(int i = 0; i < lastReg; i++)
   {
     showStudent(i);
   } 
}

void updateStudent(estudiante est, int pos){
    students[pos]=est;
}

void deleteStudent(int pos){
    if(pos == lastReg){
        cout << "no hay registro\n";
        return;
    }
    for(int i = pos; i < lastReg-1; i++)
    {
        students[i] = students[i+1];
    }
    lastReg--;
    startStudent(lastReg);
}

void startStudent(int pos){
    strcpy(students[pos].idUca, "");
    strcpy(students[pos].nombre, "");
    strcpy(students[pos].apellido, "");
    students[pos].año = 0;
    strcpy(students[pos].email, "");
    students[pos].fechaNac.dia=0;
    students[pos].fechaNac.mes= 0;
    students[pos].fechaNac.año =0;
    students[pos].promedio = 0.00;
}

int menu(){
    int op;
    cout << "UNIVERSIDAD CENTROAMERICANA - UCA\n";
    cout << "1. Agregar Estudiantes \n";
    cout << "2. Editar Estudiantes \n";
    cout << "3. Editar  Estudiantes \n";
    cout << "4. Buscar Estudiantes \n";
    cout << "5. Mostrar todos los Estudiantes \n";
    cout << "6. Salir \n";
    cout << "Digite la opcion: ";
    cin >> op;
    return op;

}


void start(){
    int op,pos;
    char id[9];
    estudiante est;
    do{
        op = menu();
        switch (op){
        case 1:
           
           cout << "ID: ";
           scanf(" %[^\n]", est.idUca);
           cout << "NOMBRE: ";
           scanf("%[^\n]", est.nombre);
           cout << "APELLIDO: ";
           scanf("%[^\n]", est.apellido);
           cout << "AÑO: ";
           cin >> est.año;
           cout << "EMAIL: ";
           scanf("%[^\n]", est.email);
           cout << "Fecha de nacimiento: ";
           scanf("%i, %i %i",&est.fechaNac.dia, &est.fechaNac.mes, &est.fechaNac.año);
           cout << "PROMEDIO: ";
           cin >> est.promedio; 
           addStudent(est);
           system("pause");
           break;
        case 2:
          cout << "ID: ";
           scanf(" %[^\n]", est.idUca);
           cout << "NOMBRE: ";
           scanf("%[^\n]", est.nombre);
           cout << "APELLIDO: ";
           scanf("%[^\n]", est.apellido);
           cout << "AÑO: ";
           cin >> est.año;
           cout << "EMAIL: ";
           scanf("%[^\n]", est.email);
           cout << "Fecha de nacimiento: ";
           scanf("%i, %i %i",&est.fechaNac.dia, &est.fechaNac.mes, &est.fechaNac.año);
           cout << "PROMEDIO: ";
           cin >> est.promedio; 
           updateStudent(est,pos);   
           break;
        case 3:
        cout << " escribe el ID del estudiante: ";
        cin >> id;
        pos = isStudent(id);
        est = getSTudent(pos);
        cout << "¿realmente desas eliminar el estudiante: " << est.nombre << est.apellido << "?\n";
        cout << "Escribe 1 para SI o 2 para NO:" ;
        cin >> resp;
        
        if(resp == 1){
            deleteStudent(pos);
            cout << "Registro Eliminado.... \n";
        }else{
            cout << "operacion cancelada... \n";

        }
           break;   
         case 4:
           break;
        case 5:
            showStudents();
            system("pause");
           break;
         case 6:
           break;
           default:
           cout << "Opcion incalida \n";
           system("pause");
           break;
        
    }

    }while(op !=6 );
}
