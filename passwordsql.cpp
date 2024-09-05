// #include "passwordsql.h"
// #include<QMessageBox>
// #include<QSqlDatabase>
// passwordSQL::passwordSQL(QObject *parent)
//     : QObject{parent}
// {

//     if (QSqlDatabase::drivers().isEmpty())
//         QMessageBox::information(nullptr,tr("No database drivers found"),
//                   tr( "This demo requires at least one Qt database driver. "
//                               "please check the documentation how to build the "
//                                              "Qt SQL plugins."));

//     QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE", "D:\\date2.db");
//    db.setDatabaseName( "data2" );
//     if (!db.open())
//        QMessageBox::warning(nullptr,tr("Unable to open database"),tr("An error occurred while "));

// }
