#include "principal.h"
#include "ui_principal.h"

#include <QtDebug>
#include <QFile>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //creamos lienzo

    lienzo = QPixmap(500,500);

    //invocar al metodo dibujar

    this->dibujar();

    //Mostramos el lienzo en eel cuadro
    ui->cuadro->setPixmap(lienzo);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{

    //rellenamos el lienzo de color blanco

    lienzo.fill(Qt::white);

    //creamos el pinto, este trabaja sobre el objeto lienzo

    QPainter painter(&lienzo);

    //Definimos vaariables

    int x=50;
    int y=50;
    int ancho =  100;;
    int alto_1 = ui->inNota1->value();
    int alto_2 = ui->inNota2->value();
    int alto_3 = ui->inNota3->value();

    //Creamos un pincel

    QPen pincel;    //creamos pincel
    pincel.setWidth(5); //Ancho dle pincel
    pincel.setColor(Qt::red);   //seleccionamos el color
    pincel.setJoinStyle(Qt::MiterJoin);

    //Estavlecer el pincel a pinyat

    painter.setPen(pincel);

    //Dibujar la primera barra

    painter.drawRect(x,y+(400-alto_1),ancho, alto_1);

    //Creamoss un nuevo colores

    QColor colorBorde2 (78,3,48);
    QColor colorRelleno2(190,120,162);

    //Establecer el color al poincel

    pincel.setColor(colorBorde2);

    //Volver a establecer al objeto painter

    painter.setPen(pincel);

    //establecer el color de la brovcha

    painter.setBrush(colorRelleno2);

    //estavblecemos el color de relleno barra 2

    painter.drawRect(x+150,y+(400-alto_2),ancho, alto_2);


    //Creanso los colores de la 3ra barra

    QColor colorRelleno3 (253,253,115);
    QColor colorBorde3(174,174,51);

    //seteamos el color del pincel

    pincel.setColor(colorBorde3);

    // setamos el pincel

    painter.setPen(pincel);

    //Hacemos el relleno del color

    painter.setBrush(colorRelleno3);
    //rellenamos con el color dado junto con las operaciones necesarias
    painter.drawRect(x+300,y+(400-alto_3), ancho, alto_3);

    ui->cuadro->setPixmap(lienzo);
}


void Principal::on_cmdGraficar_released()
{
    dibujar();


}

void Principal::on_inNota1_valueChanged(int)
{
    dibujar();
}

//Cerramos el programa la opcion de salir

void Principal::on_actionSalir_triggered()
{
    this->close();
}

//Guardar como png
void Principal::on_actionGuardar_triggered()
{

        QString nombreArchivo = QFileDialog::getSaveFileName(
                    this,"Guardar imagen",QString(),"Imagenes (*.png)");
        if (!nombreArchivo.isEmpty()){
            if (lienzo.save(nombreArchivo))
                QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
            else
                QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
        }

}
