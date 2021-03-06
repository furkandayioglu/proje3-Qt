#include "hasta.h"
#include "ui_hasta.h"

hasta::hasta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hasta)

{
   /* server = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any,8081)){
       qDebug() <<"server could not start";
 }else{

     qDebug() <<"server start";
 }*/

    ui->setupUi(this);
    QPixmap img1("/home/oem/untitled/icon.png");
    QPixmap img2("/home/oem/untitled/doctor.jpeg");
    QPixmap img3("/home/oem/untitled/nurse.jpeg");
    QPixmap img4("/home/oem/untitled/patient.jpeg");
    ui->icon->setPixmap(img1);
    ui->right_icon->setPixmap(img4);
}

hasta::~hasta()
{
    delete ui;
}

void hasta::on_pushButton_clicked()
{

    QString temp =ui->data->text();
    //ui->icon->setText(temp);
    QByteArray ba = temp.toLatin1();
   // char a[1024] = ba.data();
    sendData(ba.data());


}
void hasta::sendData(char data[]){
    QTcpSocket *tcpClient = new QTcpSocket(this);
   // connect( tcpClient, SIGNAL(readyRead()), NULL );
    tcpClient->connectToHost("192.168.43.166",8081);
    if( tcpClient->waitForConnected() ) {
         tcpClient->write(data);
          ui->icon->setText("send");
          tcpClient->close();
       }

    else{
         ui->icon->setText("temp");
    }




}
void hasta::newConnection(){


    socket = server->nextPendingConnection();
    qDebug() <<"yazildi";

    socket->write("hello ardunio");
    //data = socket->readLine();
    //ui->isim->setText(data);
    socket->close();
}
