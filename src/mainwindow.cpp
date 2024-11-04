#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <csignal>
#include <qforeach.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    // connect(ui->menuZurueck, &QMenu::triggered, this, &::MainWindow::menuZurueckclicked);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.sqlite3");
    if(!db.open())
    {
        errorDB(db);
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS liste ("
               // "ID INTEGER PRIMARY KEY, "
               "randomWord TEXT UNIQUE"
               ");");
    if(!query.exec())
    {
        errorQuery(query.lastError());
    }

    query.prepare("INSERT OR IGNORE INTO liste (randomWord) VALUES ('Apfel'), ('Banane'), ('Schal'), "
                  "('Buch'), ('Kamera'), ('Sonnenbrille'), ('Hose'), ('Mütze'), ('Zahnbürste'), "
                  "('Sandalen'), ('Notizbuch'), ('Lampe'), ('Decke'), ('Kissen'), ('Rucksack'), "
                  "('Laptop'), ('Ladekabel'), ('Kamm'), ('Shampoo'), ('Seife'), ('Zahnpasta'), "
                  "('Socken'), ('T-Shirt'), ('Jacke'), ('Handschuhe'), ('Gürtel'), ('Badehose'), "
                  "('Parfüm'), ('Schokolade'), ('Wasserflasche'), ('Hut'), ('Brille'), "
                  "('Taschentücher'), ('Sonnencreme'), ('Spiegel'), ('Taschenlampe'), "
                  "('Wecker'), ('Regenschirm'), ('Koffer'), ('Reisepass'), ('Ticket'), "
                  "('Kopfhörer'), ('Föhn'), ('Karte'), ('Trinkflasche'), ('Spielkarten'), "
                  "('Uhr'), ('Badeschlappen'), ('Tasse'), ('Messer'), ('Gabel'), ('Löffel'), "
                  "('Handtuch'), ('Kugelschreiber'), ('Fotoalbum'), ('Kugel'), ('Schlüssel'), "
                  "('Feuerzeug'), ('Hängematte'), ('Badeanzug'), ('Taschenmesser'), "
                  "('Reiseführer'), ('Fernglas'), ('Ohrstöpsel'), ('Luftmatratze'), "
                  "('Schlafsack'), ('Zahnpflegekaugummi'), ('Flip-Flops'), ('Sonnenhut'), "
                  "('Puzzle'), ('Badetuch'), ('Tagebuch'), ('Pfeffer'), ('Salzstreuer'), "
                  "('Pflaster'), ('Streichhölzer'), ('Wanderstiefel'), ('Sonnenuntergangsbrille'), "
                  "('Reisekissen'), ('Reisedecke'), ('Lesezeichen'), ('Kameraobjektiv'), "
                  "('Snacks'), ('Hausschuhe'), ('Thermoskanne'), ('Reisestecker'), "
                  "('Haargummi'), ('Taschenuhr'), ('Postkarte'), ('Sonnencreme'), "
                  "('Waschmittel'), ('Seil'), ('Spielzeug'), ('Handy'), ('Reisetasche'), "
                  "('Handschuhe'), ('Regenjacke'), ('Leselampe'), ('Stromadapter'), "
                  "('Ladegerät'), ('Reisekissen'), ('Schlafbrille'), ('Stadtplan'), "
                  "('Wörterbuch'), ('Sonnenschirm'), ('Reiseführer'), ('Zahnpflege'), "
                  "('Haarbürste'), ('Reisewecker'), ('E-Book-Reader'), ('Reisemappe'), "
                  "('Flip-Flops'), ('Sonnencreme'), ('Sonnenhut'), ('Badelatschen'), "
                  "('Ohrstöpsel'), ('Stirnlampe'), ('Reisetasche'), ('Handgepäck'), "
                  "('Reiseapotheke'), ('Sonnencreme'), ('Rasierapparat'), ('Schminkset'), "
                  "('Haarpflege'), ('Reisematte'), ('Laptop'), ('Tablet'), ('Reiseführer'), "
                  "('Kamera'), ('Akku'), ('Ladegerät'), ('Reisepass'), ('Flugticket'), "
                  "('Handyhülle'), ('Powerbank'), ('Sonnenbrille'), ('Visum'), ('Adapter'), "
                  "('Reisestecker'), ('Schlafmaske'), ('Nackenkissen'), ('Reisedecke'), "
                  "('Reisehandtuch'), ('Wäschebeutel'), ('Kulturbeutel'), ('Kamm'), "
                  "('Sonnencreme'), ('Zahnpasta'), ('Duschgel'), ('Shampoo'), ('Handtuch'), "
                  "('Reiseführer'), ('Snacks'), ('Proviant'), ('Brot'), ('Wasserflasche'), "
                  "('Thermoskanne'), ('Müsliriegel'), ('Früchte'), ('Kaugummi'), ('Chips'), "
                  "('Reiseführer'), ('Stadtplan'), ('Karte'), ('Reiseführer'), ('Sonnenhut'), "
                  "('Badetuch'), ('Badelatschen'), ('Sonnencreme'), ('Reiseführer'), ('Landkarte'), "
                  "('Kompass'), ('Wanderstiefel'), ('Wasserflasche'), ('Regenjacke'), ('Windjacke'), "
                  "('Reisepass'), ('Visum'), ('Flugticket'), ('Sonnenbrille'), ('Ladekabel'), "
                  "('Powerbank'), ('Handy'), ('E-Book-Reader'), ('Reiseführer'), ('Wörterbuch'), "
                  "('Kamera'), ('Akku'), ('Ladegerät'), ('Stromadapter'), ('Kulturbeutel'), "
                  "('Zahnpasta'), ('Zahnseide'), ('Rasierapparat'), ('Duschgel'), ('Shampoo'), "
                  "('Handtuch'), ('Kulturbeutel'), ('Nackenkissen'), ('Schlafmaske'), "
                  "('Ohrenstöpsel'), ('Reisedecke'), ('Flugticket'), ('Reisepass'), ('Visa'), "
                  "('Personalausweis'), ('Taschenmesser'), ('Feuerzeug'), ('Taschenlampe'), "
                  "('Kopfhörer'), ('Notizbuch'), ('Kugelschreiber'), ('Bleistift'), "
                  "('Sonnencreme'), ('After-Sun-Lotion'), ('Haarkur'), ('Haarbürste'), "
                  "('Zahnpasta'), ('Shampoo'), ('Conditioner'), ('Duschgel'), ('Lippenbalsam'), "
                  "('Rasierklinge'), ('Nagelschere'), ('Reiseführer'), ('Stadtkarte'), ('Wanderschuhe'), "
                  "('Regenjacke'), ('Windjacke'), ('Sonnenhut'), ('Koffer'), ('Rucksack'), "
                  "('Reisetasche'), ('Handgepäck'), ('Tagesrucksack'), ('Kulturbeutel'), "
                  "('Nackenkissen'), ('Schlafmaske'), ('Ohrstöpsel'), ('Reisedecke'), "
                  "('Sonnencreme'), ('Snacks'), ('Proviant'), ('Müsliriegel'), ('Früchte'), "
                  "('Wasserflasche'), ('Chips'), ('Powerbank'), ('Ladekabel'), ('Kamera'), "
                  "('Reiseführer'), ('Stadtplan'), ('Wörterbuch'), ('Reisepass'), ('Flugticket'), "
                  "('Visa'), ('Sonnenbrille'), ('Notizbuch'), ('Kugelschreiber'), ('Feuerzeug'), "
                  "('Taschenmesser'), ('Sonnencreme'), ('Nackenkissen'), ('Reisedecke'), "
                  "('Sonnenhut'), ('Badelatschen'), ('Wasserflasche'), ('Landkarte'), "
                  "('Kompass'), ('Wanderstiefel'), ('Regenjacke'), ('Windjacke'), ('Reisepass'), "
                  "('Visum'), ('Flugticket'), ('Sonnenbrille'), ('Ladekabel'), ('Handy'), "
                  "('Reiseführer'), ('Wörterbuch'), ('Kamera'), ('Akku'), ('Ladegerät'), "
                  "('Stromadapter'), ('Kulturbeutel'), ('Zahnpasta'), ('Zahnseide'), ('Rasierapparat'), "
                  "('Duschgel'), ('Shampoo'), ('Handtuch'), ('Kulturbeutel'), ('Nackenkissen'), "
                  "('Schlafmaske'), ('Ohrenstöpsel'), ('Reisedecke'), ('Flugticket'), "
                  "('Reisepass'), ('Visum'), ('Personalausweis'), ('Taschenmesser'), ('Feuerzeug'), "
                  "('Taschenlampe'), ('Kopfhörer'), ('Notizbuch'), ('Kugelschreiber'), "
                  "('Bleistift'), ('Sonnencreme'), ('After-Sun-Lotion'), ('Haarkur'), "
                  "('Haarbürste'), ('Zahnpasta'), ('Shampoo'), ('Conditioner'), ('Duschgel'), "
                  "('Lippenbalsam'), ('Rasierklinge'), ('Nagelschere'), ('Reiseführer'), "
                  "('Stadtkarte'), ('Wanderschuhe'), ('Regenjacke'), ('Windjacke'), "
                  "('Sonnenhut'), ('Koffer'), ('Rucksack'), ('Reisetasche'), ('Handgepäck'), "
                  "('Tagesrucksack'), ('Kulturbeutel'), ('Nackenkissen'), ('Schlafmaske'), "
                  "('Ohrstöpsel'), ('Reisedecke'), ('Sonnencreme'), ('Snacks'), ('Proviant'), "
                  "('Müsliriegel'), ('Früchte'), ('Wasserflasche'), ('Chips'), ('Powerbank'), "
                  "('Ladekabel'), ('Kamera'), ('Reiseführer'), ('Stadtplan'), ('Wörterbuch'), "
                  "('Reisepass'), ('Flugticket'), ('Visa'), ('Sonnenbrille'), ('Notizbuch'), "
                  "('Kugelschreiber'), ('Feuerzeug'), ('Taschenmesser'), ('Sonnencreme'), ('Nackenkissen'), "
                  "('Reisedecke'), ('Sonnenhut'), ('Badelatschen'), ('Wasserflasche'), "
                  "('Landkarte'), ('Kompass'), ('Wanderstiefel'), ('Regenjacke'), ('Windjacke'), "
                  "('Reisepass'), ('Visum'), ('Flugticket'), ('Sonnenbrille'), ('Ladekabel'), "
                  "('Handy'), ('Reiseführer'), ('Wörterbuch'), ('Kamera'), ('Akku'), ('Ladegerät'), "
                  "('Stromadapter'), ('Kulturbeutel'), ('Zahnpasta'), ('Zahnseide'), ('Rasierapparat'), "
                  "('Duschgel'), ('Shampoo'), ('Handtuch')");
    if(!query.exec())
    {
        errorQuery(query.lastError());
    }

    // query.prepare("DELETE FROM liste");
    // if(!query.exec())
    // {
    //     errorQuery(query.lastError());
    // }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::errorQuery(QSqlError error)
{
    QMessageBox::warning(nullptr, tr("Fehler Database"),tr("Fehler: %1").arg(error.text()));

}

void MainWindow::errorDB(QSqlDatabase error)
{
    QMessageBox::warning(nullptr, tr("Fehler Query"),tr("Fehler: %1").arg(error.lastError().text()));
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::menuZurueckclicked()
{
    int indexWidget = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(indexWidget - 1);
    ui->label_3->setText("Bereit?\n\n Dann drücke auf 'Starten'");
    ui->textBrowser->clear();
    ui->label_4->setText("Drücke 'Wort zeigen', um die Wörter aufzulisten.");
    ui->pushButton_6->isDefault();
    counter = 0;
    counterText = 0;
    nameList.clear();
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->radioButton->isChecked() || ui->radioButton_2->isChecked() || ui->radioButton_3->isChecked())
    {
        if(ui->radioButton->isChecked())
        {
            anzahl = 3;
        }
        else if(ui->radioButton_2->isChecked())
        {
            anzahl = 7;
        }
        else if(ui->radioButton_3->isChecked())
        {
            anzahl = 11;
        }
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        NachrichtFenster.warning(this, "Keine Schwieriegkeit ausgewählt", "Bitte wählen Sie eine Schwierigkeit aus.");
    }
    // else if (ui->stackedWidget_2->currentIndex() == 1)
    // {
    //     if(ui->spinBox->value() != 0)
    //     {
    //         anzahl = ui->spinBox->value();
    //     }
    //     else
    //     {
    //         NachrichtFenster.warning(this, "Kein Gültiger Wert", "Bitte geben Sie eine Zahl von 1-99 ein.");
    //     }
    // }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    anzahl = counter;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_5->setText("Nächstes Wort");
    QSqlQuery query;
    query.prepare("SELECT randomWord FROM liste "
                  "ORDER BY RANDOM() "
                  "LIMIT 1;");
    if(!query.exec())
    {
        errorQuery(query.lastError());
    }

    if(query.next())
    {
        if(counter == anzahl)
        {
            ui->stackedWidget->setCurrentIndex(3);
        }
        else
        {
            QString name = query.value(0).toString();
            ui->label_3->setText(name);
            nameList.push_back(name);
            counter++;
        }
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_4->clear();
    ui->pushButton_3->setText("Nächstes Wort");
    if(anzahl != counterText && !nameList.empty())
    {
        if(nameList.size() > counterText)
        {
            QString text = nameList.at(counterText);
            ui->textBrowser->append(text);
            counterText++;
            if(counterText == counter)
            {
                ui->label_4->setText("Und?\nHast du es geschafft, dir alle Wörter zu merken?");
                ui->pushButton_7->setEnabled(true);
                ui->pushButton_8->setEnabled(true);
                ui->pushButton_3->setEnabled(false);
            }
        }
    }

}


void MainWindow::on_pushButton_8_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_3->setText("Bereit?\n\n Dann drücke auf 'Starten'");
    ui->textBrowser->clear();
    ui->label_4->setText("Drücke 'Wort zeigen', um die Wörter aufzulisten.");
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->isDefault();

    counter = 0;
    counterText = 0;
    nameList.clear();
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButton_10_clicked()
{

    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_pushButton_11_clicked()
{
    if(ui->spinBox->value() != 0)
    {
        anzahl = ui->spinBox->value();
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        NachrichtFenster.warning(this, "Kein Gültiger Wert", "Bitte geben Sie eine Zahl von 1-99 ein.");
    }
}

