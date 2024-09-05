#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_ptrCitySql(nullptr)
{
    ui->setupUi(this);


    m_dlgLogin.show();
    auto f=[&](){
        this->show();
    };
    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,f);//登录成功自动跳到主页面
    ui->treeWidget->setColumnCount(1);//主页面左边的tree设置一行
        QStringList l;
    l<<"学生信息管理系统";
        QTreeWidgetItem *pf=new QTreeWidgetItem(ui->treeWidget,l);//创造主干也就是第一行
       ui->treeWidget->addTopLevelItem(pf);//给第一行命名

    l.clear();
        l<<"学生管理";
    QTreeWidgetItem *p1=new QTreeWidgetItem(pf,l);//给一个分支命名
    l.clear();
    l<<"管理员管理";
        QTreeWidgetItem *p2=new QTreeWidgetItem(pf,l);//给第二个分支命名

    pf->addChild(p1);
    pf->addChild(p2);//把p1与p2成为主干的分支

    ui->treeWidget->expandAll();//默认主干打开

    m_ptrCitySql=citySql::getinstance();
    m_ptrCitySql->init();
    m_lNames<<"山西";
    m_lNames<<"山东";
    m_lNames<<"河北";
    m_lNames<<"河南";

    updateTable();

    connect(ui->action,&QAction::triggered,this,&MainWindow::actionSlot);//点击“另存为”进入总文件界面
    connect(ui->action_2,&QAction::triggered,this,&MainWindow::action_2Slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::action_2Slot()
{
    QString fileName = QFileDialog::getOpenFileName(this,"选择一个文件",
                QCoreApplication::applicationFilePath(),"*.cpp");
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else
    {
       // QString fileName = "test.cpp";
        //qDebug() << fileName;
        QFile file(fileName);    //创建文件对象
        file.open(QIODevice::ReadWrite|QIODevice::Text);
        QByteArray ba = file.readAll();
    }
}

void MainWindow::on_btn_exit_clicked()
{
    exit(0);//主页面的退出
}


void MainWindow::on_btn_simulation_clicked()
{
    QRandomGenerator x,y;
    x.seed(0);
    y.seed(0);
    for(int i=0;i<m_lNames.size();i++)
    {
        auto px=x.bounded(7.10);
        auto py=y.bounded(1,8);
        CityInfo info;
        info.name=m_lNames[i];
        info.PointX=px;
        info.PointY=py;
        m_ptrCitySql->addCity(info);
    }
}

void MainWindow::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l ;
    l<<"序号"<<"id"<<"名称"<<"横坐标"<<"纵坐标";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    //只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = m_ptrCitySql->getCityCnt();
    ui->lb_cnt->setText(QString("城市总数:%1").arg(cnt));
    QList<CityInfo>  lCities = m_ptrCitySql->getPageCity(0,cnt);


    ui->tableWidget->setRowCount(cnt);
    for(int i =0;i<lCities.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));//???i变lCities[i].id
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(lCities[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lCities[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(lCities[i].PointX)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lCities[i].PointY)));

    }
}

void MainWindow::on_btn_search_clicked()
{
    QString strFilter= ui->le_search->text();
    if(strFilter.isEmpty())
    {
        QMessageBox::information(nullptr,"警告","名称筛选为空");
        updateTable();
        return;
    }


    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l ;
    l<<"序号"<<"id"<<"名称"<<"横坐标"<<"纵坐标";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    auto cnt = m_ptrCitySql->getCityCnt();
    ui->lb_cnt->setText(QString("城市总数:%1").arg(cnt));
    QList<CityInfo>  lCities = m_ptrCitySql->getPageCity(0,cnt);



    int index = 0;
    for(int i =0;i<lCities.size();i++)
    {
        if(!lCities[i].name.contains(strFilter))
        {
            continue;
        }


        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(index+1)));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(lCities[i].id)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(lCities[i].name));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(QString::number(lCities[i].PointX)));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(QString::number(lCities[i].PointY)));
        index ++;

    }
    ui->tableWidget->setRowCount(index);
}


void MainWindow::on_btn_add_clicked()
{
    m_dlgAddCity.setType(true);
    m_dlgAddCity.exec();
    updateTable();
}


void MainWindow::on_btn_clear_clicked()
{
    m_ptrCitySql->clearCityTable();
    updateTable();
}





void MainWindow::on_btn_del_clicked()
{
    int i=ui->tableWidget->currentRow();
    if(i>=0)
    {
        int id=ui->tableWidget->item(i,1)->text().toUInt();
         m_ptrCitySql->delCity(id);
        updateTable();
         QMessageBox::information(nullptr,"信息","删除成功");
    }

}


void MainWindow::on_btn_update_clicked()
{
    CityInfo info;
    int i=ui->tableWidget->currentRow();
    if(i>=0)
    {
        info.id=ui->tableWidget->item(i,1)->text().toUInt();
        info.name=ui->tableWidget->item(i,2)->text();
        info.PointX=ui->tableWidget->item(i,3)->text().toDouble();
        info.PointY=ui->tableWidget->item(i,4)->text().toDouble();
        m_dlgAddCity.setType(false,info);
        m_dlgAddCity.exec();
    }
    updateTable();
}

